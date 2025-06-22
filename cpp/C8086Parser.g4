parser grammar C8086Parser;

options {
    tokenVocab = C8086Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include <vector>
    #include <utility>
    #include "C8086Lexer.h"
    #include "SymbolTable.h"

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
    extern int syntaxErrorCount;
    
    SymbolTable* symbolTable = new SymbolTable(7);
    int errorCount = 0;
    int lineCount = 0;
    
    struct DeclarationInfo {
        std::string name;
        bool isArray;
        int arraySize;
    };
    
    struct ParameterInfo {
        std::string type;
        std::string name;
    };
}

@parser::members {
    void writeIntoparserLogFile(const std::string message) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }
        parserLogFile << message << std::endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorFile.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl;
        errorFile.flush();
        errorCount++;
    }

    std::string getTypeName(const std::string& type) {
        if (type == "int") return "INT";
        else if (type == "float") return "FLOAT";
        else if (type == "void") return "VOID";
        return type;
    }

    bool isNumericType(const std::string& type) {
        return type == "int" || type == "float";
    }

    std::string getExpressionType(const std::string& left, const std::string& right, const std::string& op) {
        if (left == "float" || right == "float") return "float";
        return "int";
    }
}

start : program
    {
        writeIntoparserLogFile("start : program");
        writeIntoparserLogFile("");
        
        // Print final symbol table
        symbolTable->printCurrentScope();
        
        // Print statistics
        writeIntoparserLogFile("Total lines: " + std::to_string(lineCount));
        writeIntoparserLogFile("Total errors: " + std::to_string(errorCount));
        
        writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");
    }
    ;

program returns [std::string val] 
    : program unit 
    {
        $val = $program.val + "\n" + $unit.val;
        writeIntoparserLogFile("program : program unit");
        writeIntoparserLogFile("");
        writeIntoparserLogFile($val);
        writeIntoparserLogFile("");
    }
    | unit
    {
        $val = $unit.val;
        writeIntoparserLogFile("program : unit");
        writeIntoparserLogFile("");  
        writeIntoparserLogFile($val);
        writeIntoparserLogFile("");
    }
    ;

unit returns [std::string val]
    : var_declaration {
        $val = $var_declaration.val;
        writeIntoparserLogFile("Line " + std::to_string($var_declaration.start->getLine()) + ": unit : var_declaration");
        writeIntoparserLogFile("");
        writeIntoparserLogFile($var_declaration.val);
        writeIntoparserLogFile("");
    }
    | func_declaration {
        $val = $func_declaration.val;
        writeIntoparserLogFile("Line " + std::to_string($func_declaration.start->getLine()) + ": unit : func_declaration");
        writeIntoparserLogFile("");
        writeIntoparserLogFile($func_declaration.val);
        writeIntoparserLogFile("");
    }
    | func_definition {
        $val = $func_definition.val;
        writeIntoparserLogFile("Line " + std::to_string($func_definition.start->getLine()) + ": unit : func_definition");
        writeIntoparserLogFile("");
        writeIntoparserLogFile($func_definition.val);
        writeIntoparserLogFile("");
    }
    ;

func_declaration returns [std::string val]
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
    {
        $val = $type_specifier.val + " " + $ID->getText() + "(" + $parameter_list.val + ");";
        
        // Check if function already exists
        SymbolInfo* existing = symbolTable->lookup($ID->getText());
        if (existing && existing->symbolType == "FUNCTION") {
            // Check if declaration matches previous declaration/definition
            if (existing->funcInfo->returnType != $type_specifier.val) {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Conflicting types for function '" + $ID->getText() + "'");
            }
        } else if (existing) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": '" + $ID->getText() + "' redeclared as different kind of symbol");
        } else {
            // Insert new function declaration
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), $type_specifier.val);
            funcSymbol->setFunction($type_specifier.val);
            funcSymbol->funcInfo->isDeclared = true;
            
            // Add parameters from parameter_list
            for (const auto& param : $parameter_list.params) {
                funcSymbol->addParameter(param.type, param.name);
            }
            
            symbolTable->insert(funcSymbol);
        }
    }
    | type_specifier ID LPAREN RPAREN SEMICOLON
    {
        $val = $type_specifier.val + " " + $ID->getText() + "();";
        
        // Check if function already exists
        SymbolInfo* existing = symbolTable->lookup($ID->getText());
        if (existing && existing->symbolType == "FUNCTION") {
            if (existing->funcInfo->returnType != $type_specifier.val) {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Conflicting types for function '" + $ID->getText() + "'");
            }
        } else if (existing) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": '" + $ID->getText() + "' redeclared as different kind of symbol");
        } else {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), $type_specifier.val);
            funcSymbol->setFunction($type_specifier.val);
            funcSymbol->funcInfo->isDeclared = true;
            symbolTable->insert(funcSymbol);
        }
    }
    ;

func_definition returns [std::string val]
    : type_specifier ID LPAREN parameter_list RPAREN {
        // Check function declaration consistency
        SymbolInfo* existing = symbolTable->lookup($ID->getText());
        if (existing && existing->symbolType == "FUNCTION") {
            if (existing->funcInfo->isDefined) {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Redefinition of function '" + $ID->getText() + "'");
            }
            if (existing->funcInfo->returnType != $type_specifier.val) {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Conflicting types for function '" + $ID->getText() + "'");
            }
            existing->funcInfo->isDefined = true;
        } else if (existing) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": '" + $ID->getText() + "' redeclared as different kind of symbol");
        } else {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), $type_specifier.val);
            funcSymbol->setFunction($type_specifier.val);
            funcSymbol->funcInfo->isDefined = true;
            for (const auto& param : $parameter_list.params) {
                funcSymbol->addParameter(param.type, param.name);
            }
            symbolTable->insert(funcSymbol);
        }
        
        // Enter new scope for function body
        symbolTable->enterScope();
        
        // Add parameters to function scope
        for (const auto& param : $parameter_list.params) {
            if (!param.name.empty()) {
                SymbolInfo* paramSymbol = new SymbolInfo(param.name, param.type);
                symbolTable->insert(paramSymbol);
            }
        }
    } compound_statement
    {
        $val = $type_specifier.val + " " + $ID->getText() + "(" + $parameter_list.val + ")" + $compound_statement.val;
        
        // Exit function scope
        symbolTable->exitScope();
    }
    | type_specifier ID LPAREN RPAREN {
        SymbolInfo* existing = symbolTable->lookup($ID->getText());
        if (existing && existing->symbolType == "FUNCTION") {
            if (existing->funcInfo->isDefined) {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Redefinition of function '" + $ID->getText() + "'");
            }
            existing->funcInfo->isDefined = true;
        } else if (existing) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": '" + $ID->getText() + "' redeclared as different kind of symbol");
        } else {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), $type_specifier.val);
            funcSymbol->setFunction($type_specifier.val);
            funcSymbol->funcInfo->isDefined = true;
            symbolTable->insert(funcSymbol);
        }
        
        symbolTable->enterScope();
    } compound_statement
    {
        $val = $type_specifier.val + " " + $ID->getText() + "()" + $compound_statement.val;
        symbolTable->exitScope();
    }
    ;

parameter_list returns [std::string val, std::vector<ParameterInfo> params]
    : parameter_list COMMA type_specifier ID
    {
        $val = $parameter_list.val + "," + $type_specifier.val + " " + $ID->getText();
        $params = $parameter_list.params;
        ParameterInfo param;
        param.type = $type_specifier.val;
        param.name = $ID->getText();
        $params.push_back(param);
    }
    | parameter_list COMMA type_specifier
    {
        $val = $parameter_list.val + "," + $type_specifier.val;
        $params = $parameter_list.params;
        ParameterInfo param;
        param.type = $type_specifier.val;
        param.name = "";
        $params.push_back(param);
    }
    | type_specifier ID
    {
        $val = $type_specifier.val + " " + $ID->getText();
        ParameterInfo param;
        param.type = $type_specifier.val;
        param.name = $ID->getText();
        $params.push_back(param);
    }
    | type_specifier
    {
        $val = $type_specifier.val;
        ParameterInfo param;
        param.type = $type_specifier.val;
        param.name = "";
        $params.push_back(param);
    }
    ;

compound_statement returns [std::string val]
    : LCURL {
        symbolTable->enterScope();
    } statements RCURL
    {
        $val = "{\n" + $statements.val + "\n}";
        symbolTable->exitScope();
    }
    | LCURL {
        symbolTable->enterScope();
    } RCURL
    {
        $val = "{}";
        symbolTable->exitScope();
    }
    ;

var_declaration returns [std::string val]
    : type_specifier declaration_list SEMICOLON
    {
        $val = $type_specifier.val + " " + $declaration_list.val + ";";
        
        writeIntoparserLogFile("Line " + std::to_string($type_specifier.start->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON");
        writeIntoparserLogFile("");
        writeIntoparserLogFile($val);
        writeIntoparserLogFile("");
        
        // Insert variables into symbol table
        for (const auto& decl : $declaration_list.declarations) {
            SymbolInfo* existing = symbolTable->lookupCurrentScope(decl.name);
            if (existing) {
                writeIntoErrorFile("Line# " + std::to_string($SEMICOLON->getLine()) + ": Redefinition of variable '" + decl.name + "'");
            } else {
                SymbolInfo* symbol = new SymbolInfo(decl.name, $type_specifier.val);
                if (decl.isArray) {
                    symbol->setArray(decl.arraySize);
                }
                symbolTable->insert(symbol);
            }
        }
    }
    ;

type_specifier returns [std::string val]
    : INT { $val = "int"; }
    | FLOAT { $val = "float"; }
    | VOID { $val = "void"; }
    ;

declaration_list returns [std::string val, std::vector<DeclarationInfo> declarations]
    : declaration_list COMMA ID
    {
        $val = $declaration_list.val + "," + $ID->getText();
        $declarations = $declaration_list.declarations;
        DeclarationInfo decl;
        decl.name = $ID->getText();
        decl.isArray = false;
        decl.arraySize = -1;
        $declarations.push_back(decl);
    }
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
    {
        $val = $declaration_list.val + "," + $ID->getText() + "[" + $CONST_INT->getText() + "]";
        $declarations = $declaration_list.declarations;
        DeclarationInfo decl;
        decl.name = $ID->getText();
        decl.isArray = true;
        decl.arraySize = std::stoi($CONST_INT->getText());
        $declarations.push_back(decl);
    }
    | ID
    {
        $val = $ID->getText();
        DeclarationInfo decl;
        decl.name = $ID->getText();
        decl.isArray = false;
        decl.arraySize = -1;
        $declarations.push_back(decl);
    }
    | ID LTHIRD CONST_INT RTHIRD
    {
        $val = $ID->getText() + "[" + $CONST_INT->getText() + "]";
        DeclarationInfo decl;
        decl.name = $ID->getText();
        decl.isArray = true;
        decl.arraySize = std::stoi($CONST_INT->getText());
        $declarations.push_back(decl);
    }
    ;

statements returns [std::string val]
    : statement
    {
        $val = $statement.val;
    }
    | statements statement
    {
        $val = $statements.val + "\n" + $statement.val;
    }
    ;

statement returns [std::string val]
    : var_declaration
    {
        $val = $var_declaration.val;
    }
    | expression_statement
    {
        $val = $expression_statement.val;
    }
    | compound_statement
    {
        $val = $compound_statement.val;
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement
    {
        $val = "for(" + $expression_statement.val + " " + $expression_statement.val + " " + $expression.val + ")" + $statement.val;
    }
    | IF LPAREN expression RPAREN statement
    {
        $val = "if(" + $expression.val + ")" + $statement.val;
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        $val = "if(" + $expression.val + ")" + $statement.val + " else " + $statement.val;
    }
    | WHILE LPAREN expression RPAREN statement
    {
        $val = "while(" + $expression.val + ")" + $statement.val;
    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON
    {
        $val = "println(" + $ID->getText() + ");";
        
        // Check if variable is declared
        SymbolInfo* symbol = symbolTable->lookup($ID->getText());
        if (!symbol) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Undeclared variable '" + $ID->getText() + "'");
        }
    }
    | RETURN expression SEMICOLON
    {
        $val = "return " + $expression.val + ";";
    }
    ;

expression_statement returns [std::string val]
    : SEMICOLON
    {
        $val = ";";
    }
    | expression SEMICOLON
    {
        $val = $expression.val + ";";
    }
    ;

variable returns [std::string val, std::string type]
    : ID
    {
        $val = $ID->getText();
        
        SymbolInfo* symbol = symbolTable->lookup($ID->getText());
        if (!symbol) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Undeclared variable '" + $ID->getText() + "'");
            $type = "error";
        } else {
            if (symbol->symbolType == "ARRAY") {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Array '" + $ID->getText() + "' used without index");
                $type = "error";
            } else {
                $type = symbol->type;
            }
        }
    }
    | ID LTHIRD expression RTHIRD
    {
        $val = $ID->getText() + "[" + $expression.val + "]";
        
        SymbolInfo* symbol = symbolTable->lookup($ID->getText());
        if (!symbol) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Undeclared variable '" + $ID->getText() + "'");
            $type = "error";
        } else {
            if (symbol->symbolType != "ARRAY") {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": '" + $ID->getText() + "' is not an array");
                $type = "error";
            } else {
                if ($expression.type != "int") {
                    writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Array subscript is not an integer");
                }
                $type = symbol->type;
            }
        }
    }
    ;

expression returns [std::string val, std::string type]
    : logic_expression
    {
        $val = $logic_expression.val;
        $type = $logic_expression.type;
    }
    | variable ASSIGNOP logic_expression
    {
        $val = $variable.val + "=" + $logic_expression.val;
        
        if ($variable.type != "error" && $logic_expression.type != "error") {
            if ($variable.type != $logic_expression.type) {
                if ($variable.type == "int" && $logic_expression.type == "float") {
                    writeIntoErrorFile("Line# " + std::to_string($ASSIGNOP->getLine()) + ": Warning: possible loss of data in assignment of FLOAT to INT");
                }
            }
        }
        $type = $variable.type;
    }
    ;

logic_expression returns [std::string val, std::string type]
    : rel_expression
    {
        $val = $rel_expression.val;
        $type = $rel_expression.type;
    }
    | rel_expression LOGICOP rel_expression
    {
        $val = $rel_expression.val + $LOGICOP->getText() + $rel_expression.val;
        $type = "int"; // logical operations return int
    }
    ;

rel_expression returns [std::string val, std::string type]
    : simple_expression
    {
        $val = $simple_expression.val;
        $type = $simple_expression.type;
    }
    | simple_expression RELOP simple_expression
    {
        $val = $simple_expression.val + $RELOP->getText() + $simple_expression.val;
        $type = "int"; // relational operations return int
    }
    ;

simple_expression returns [std::string val, std::string type]
    : term
    {
        $val = $term.val;
        $type = $term.type;
    }
    | simple_expression ADDOP term
    {
        $val = $simple_expression.val + $ADDOP->getText() + $term.val;
        $type = getExpressionType($simple_expression.type, $term.type, $ADDOP->getText());
    }
    ;

term returns [std::string val, std::string type]
    : unary_expression
    {
        $val = $unary_expression.val;
        $type = $unary_expression.type;
    }
    | term MULOP unary_expression
    {
        $val = $term.val + $MULOP->getText() + $unary_expression.val;
        
        // Check modulus operation
        if ($MULOP->getText() == "%") {
            if ($term.type != "int" || $unary_expression.type != "int") {
                writeIntoErrorFile("Line# " + std::to_string($MULOP->getLine()) + ": Operands of modulus must be integers");
            }
            $type = "int";
        } else {
            $type = getExpressionType($term.type, $unary_expression.type, $MULOP->getText());
        }
    }
    ;

unary_expression returns [std::string val, std::string type]
    : ADDOP unary_expression
    {
        $val = $ADDOP->getText() + $unary_expression.val;
        $type = $unary_expression.type;
    }
    | NOT unary_expression
    {
        $val = "!" + $unary_expression.val;
        $type = "int";
    }
    | factor
    {
        $val = $factor.val;
        $type = $factor.type;
    }
    ;

factor returns [std::string val, std::string type]
    : variable
    {
        $val = $variable.val;
        $type = $variable.type;
    }
    | ID LPAREN argument_list RPAREN
    {
        $val = $ID->getText() + "(" + $argument_list.val + ")";
        
        SymbolInfo* symbol = symbolTable->lookup($ID->getText());
        if (!symbol) {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Undeclared function '" + $ID->getText() + "'");
            $type = "error";
        } else if (symbol->symbolType != "FUNCTION") {
            writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": '" + $ID->getText() + "' is not a function");
            $type = "error";
        } else {
            // Check argument count and types
            if (symbol->funcInfo->paramCount != $argument_list.argCount) {
                writeIntoErrorFile("Line# " + std::to_string($ID->getLine()) + ": Too " + 
                    (symbol->funcInfo->paramCount < $argument_list.argCount ? "many" : "few") + 
                    " arguments to function '" + $ID->getText() + "'");
            }
            $type = symbol->funcInfo->returnType;
        }
    }
    | LPAREN expression RPAREN
    {
        $val = "(" + $expression.val + ")";
        $type = $expression.type;
    }
    | CONST_INT
    {
        $val = $CONST_INT->getText();
        $type = "int";
    }
    | CONST_FLOAT
    {
        $val = $CONST_FLOAT->getText();
        $type = "float";
    }
    | variable INCOP
    {
        $val = $variable.val + "++";
        $type = $variable.type;
    }
    | variable DECOP
    {
        $val = $variable.val + "--";
        $type = $variable.type;
    }
    ;

argument_list returns [std::string val, int argCount]
    : arguments
    {
        $val = $arguments.val;
        $argCount = $arguments.argCount;
    }
    |   // Empty alternative
    {
        $val = "";
        $argCount = 0;
    }
    ;

arguments returns [std::string val, int argCount]
    : arguments COMMA logic_expression
    {
        $val = $arguments.val + "," + $logic_expression.val;
        $argCount = $arguments.argCount + 1;
    }
    | logic_expression
    {
        $val = $logic_expression.val;
        $argCount = 1;
    }
    ;