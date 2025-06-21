parser grammar C2105140Parser;

options {
    tokenVocab = C2105140Lexer;
}

@header {
#include "SymbolTable.h"
}

@members {
SymbolTable symbolTable;
ofstream logFile;
ofstream errorFile;
int lineCount = 1;
int errorCount = 0;
string currentReturnType = "";
bool insideFunction = false;

void logRule(string rule, string code) {
    logFile << rule << " : " << code << endl;
}

void logError(int line, string message) {
    errorFile << "Line no " << line << ": " << message << endl;
    errorCount++;
}

string typeConvert(string type1, string type2) {
    if (type1 == "FLOAT" || type2 == "FLOAT") return "FLOAT";
    if (type1 == "INT" || type2 == "INT") return "INT";
    return "INT";
}

void initializeFiles() {
    logFile.open("log.txt");
    errorFile.open("error.txt");
}

void closeFiles() {
    logFile << "Total lines: " << lineCount << endl;
    logFile << "Total errors: " << errorCount << endl;
    symbolTable.printScope();
    logFile.close();
    errorFile.close();
}
}

start
    returns [std::string text]
    : {initializeFiles();} p=program EOF {
        $text = $p.text;
        logRule("start", $text);
        closeFiles();
    }
;

program
    returns [string text]
    : p=program u=unit { $text = $p.text + $u.text; logRule("program", $text); }
    | u=unit { $text = $u.text; logRule("program", $text); }
    ;

unit
    returns [string text]
    : v=var_declaration { $text = $v.text; logRule("unit", $text); }
    | fd=func_declaration { $text = $fd.text; logRule("unit", $text); }
    | ff=func_definition { $text = $ff.text; logRule("unit", $text); }
    ;

var_declaration
    returns [string text]
    : t=type_specifier dl=declaration_list SEMICOLON {
        $text = $t.text + " " + $dl.text + ";";
        logRule("var_declaration", $text);
    }
    ;

type_specifier
    returns [string varType, string text]
    : INT   { $varType = "INT"; $text = "int"; logRule("type_specifier", $text); }
    | FLOAT { $varType = "FLOAT"; $text = "float"; logRule("type_specifier", $text); }
    | VOID  { $varType = "VOID"; $text = "void"; logRule("type_specifier", $text); }
    ;

declaration_list
    returns [string text]
    : dl=declaration_list COMMA id=ID {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = "INT";
        symbol->lineNo = $id.line;
        if (!symbolTable.insert(symbol)) {
            logError($id.line, "Redefinition of variable '" + $id.text + "'");
        }
        $text = $dl.text + "," + $id.text;
        logRule("declaration_list", $text);
    }
    | dl=declaration_list COMMA id=ID LSQUARE ci=CONST_INT RSQUARE {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = "INT";
        symbol->isArray = true;
        symbol->arraySize = stoi($ci.text);
        symbol->lineNo = $id.line;
        if (!symbolTable.insert(symbol)) {
            logError($id.line, "Redefinition of variable '" + $id.text + "'");
        }
        $text = $dl.text + "," + $id.text + "[" + $ci.text + "]";
        logRule("declaration_list", $text);
    }
    | id=ID {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = "INT";
        symbol->lineNo = $id.line;
        if (!symbolTable.insert(symbol)) {
            logError($id.line, "Redefinition of variable '" + $id.text + "'");
        }
        $text = $id.text;
        logRule("declaration_list", $text);
    }
    | id=ID LSQUARE ci=CONST_INT RSQUARE {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = "INT";
        symbol->isArray = true;
        symbol->arraySize = stoi($ci.text);
        symbol->lineNo = $id.line;
        if (!symbolTable.insert(symbol)) {
            logError($id.line, "Redefinition of variable '" + $id.text + "'");
        }
        $text = $id.text + "[" + $ci.text + "]";
        logRule("declaration_list", $text);
    }
    ;

func_declaration
    returns [string text]
    : t=type_specifier id=ID LPAREN pl=parameter_list RPAREN SEMICOLON {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->isFunction = true;
        symbol->returnType = $t.varType;
        symbol->isDeclared = true;
        symbol->lineNo = $id.line;
        if (!symbolTable.insert(symbol)) {
            SymbolInfo* existing = symbolTable.lookup($id.text);
            if (existing && existing->isFunction) {
                if (existing->returnType != symbol->returnType) {
                    logError($id.line, "Conflicting return type for function '" + $id.text + "'");
                }
            } else {
                logError($id.line, "Redefinition of function '" + $id.text + "'");
            }
        }
        $text = $t.text + " " + $id.text + "(" + $pl.text + ");";
        logRule("func_declaration", $text);
    }
    | t=type_specifier id=ID LPAREN RPAREN SEMICOLON {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->isFunction = true;
        symbol->returnType = $t.varType;
        symbol->isDeclared = true;
        symbol->lineNo = $id.line;
        if (!symbolTable.insert(symbol)) {
            logError($id.line, "Redefinition of function '" + $id.text + "'");
        }
        $text = $t.text + " " + $id.text + "();";
        logRule("func_declaration", $text);
    }
    ;

func_definition
    returns [string text]
    : t=type_specifier id=ID LPAREN pl=parameter_list RPAREN {
        SymbolInfo* symbol = symbolTable.lookup($id.text);
        if (!symbol) {
            symbol = new SymbolInfo($id.text, "ID");
            symbol->isFunction = true;
            symbol->returnType = $t.varType;
            symbol->isDefined = true;
            symbolTable.insert(symbol);
        } else {
            if (symbol->isDefined) {
                logError($id.line, "Redefinition of function '" + $id.text + "'");
            } else {
                symbol->isDefined = true;
                if (symbol->returnType != $t.varType) {
                    logError($id.line, "Conflicting return type for function '" + $id.text + "'");
                }
            }
        }
        currentReturnType = $t.varType;
        insideFunction = true;
        symbolTable.enterScope();
    } cs=compound_statement {
        symbolTable.printScope();
        symbolTable.exitScope();
        insideFunction = false;
        currentReturnType = "";
        $text = $t.text + " " + $id.text + "(" + $pl.text + ") " + $cs.text;
        logRule("func_definition", $text);
    }
    | t=type_specifier id=ID LPAREN RPAREN {
        SymbolInfo* symbol = symbolTable.lookup($id.text);
        if (!symbol) {
            symbol = new SymbolInfo($id.text, "ID");
            symbol->isFunction = true;
            symbol->returnType = $t.varType;
            symbol->isDefined = true;
            symbolTable.insert(symbol);
        } else {
            if (symbol->isDefined) {
                logError($id.line, "Redefinition of function '" + $id.text + "'");
            } else {
                symbol->isDefined = true;
                if (symbol->returnType != $t.varType) {
                    logError($id.line, "Conflicting return type for function '" + $id.text + "'");
                }
            }
        }
        currentReturnType = $t.varType;
        insideFunction = true;
        symbolTable.enterScope();
    } cs=compound_statement {
        symbolTable.printScope();
        symbolTable.exitScope();
        insideFunction = false;
        currentReturnType = "";
        $text = $t.text + " " + $id.text + "() " + $cs.text;
        logRule("func_definition", $text);
    }
    ;

parameter_list
    returns [string text]
    : pl=parameter_list COMMA t=type_specifier id=ID {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = $t.varType;
        symbolTable.insert(symbol);
        $text = $pl.text + "," + $t.text + " " + $id.text;
        logRule("parameter_list", $text);
    }
    | pl=parameter_list COMMA t=type_specifier id=ID LSQUARE RSQUARE {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = $t.varType;
        symbol->isArray = true;
        symbolTable.insert(symbol);
        $text = $pl.text + "," + $t.text + " " + $id.text + "[]";
        logRule("parameter_list", $text);
    }
    | t=type_specifier id=ID {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = $t.varType;
        symbolTable.insert(symbol);
        $text = $t.text + " " + $id.text;
        logRule("parameter_list", $text);
    }
    | t=type_specifier id=ID LSQUARE RSQUARE {
        SymbolInfo* symbol = new SymbolInfo($id.text, "ID");
        symbol->varType = $t.varType;
        symbol->isArray = true;
        symbolTable.insert(symbol);
        $text = $t.text + " " + $id.text + "[]";
        logRule("parameter_list", $text);
    }
    ;

compound_statement
    returns [string text]
    : LCURL { symbolTable.enterScope(); } s=statements RCURL {
        $text = "{" + $s.text + "}";
        symbolTable.printScope();
        symbolTable.exitScope();
        logRule("compound_statement", $text);
    }
    | LCURL RCURL {
        $text = "{}";
        logRule("compound_statement", $text);
    }
    ;

statements
    returns [string text]
    : s1=statements s2=statement { $text = $s1.text + " " + $s2.text; logRule("statements", $text); }
    | s=statement { $text = $s.text; logRule("statements", $text); }
    ;

statement
    returns [string text]
    : v=var_declaration { $text = $v.text; logRule("statement", $text); }
    | es=expression_statement { $text = $es.text; logRule("statement", $text); }
    | cs=compound_statement { $text = $cs.text; logRule("statement", $text); }
    | FOR LPAREN e1=expression_statement e2=expression_statement e3=expression RPAREN s=statement {
        $text = "for(" + $e1.text + $e2.text + $e3.text + ")" + $s.text;
        logRule("statement", $text);
    }
    | IF LPAREN ei=expression RPAREN s=statement {
        $text = "if(" + $ei.text + ")" + $s.text;
        logRule("statement", $text);
    }
    | WHILE LPAREN ew=expression RPAREN s=statement {
        $text = "while(" + $ew.text + ")" + $s.text;
        logRule("statement", $text);
    }
    | RETURN er=expression SEMICOLON {
        if (!insideFunction) {
            logError($RETURN.line, "Return statement outside function");
        } else {
            if (currentReturnType == "VOID") {
                logError($RETURN.line, "Return with value in void function");
            } else if (currentReturnType != $er.exprType) {
                if (currentReturnType == "INT" && $er.exprType == "FLOAT") {
                    logError($RETURN.line, "Warning: possible loss of data in return");
                }
            }
        }
        $text = "return " + $er.text + ";";
        logRule("statement", $text);
    }
    | RETURN SEMICOLON {
        if (!insideFunction) {
            logError($RETURN.line, "Return statement outside function");
        } else {
            if (currentReturnType != "VOID") {
                logError($RETURN.line, "Return without value in non-void function");
            }
        }
        $text = "return;";
        logRule("statement", $text);
    }
    ;

expression_statement
    returns [string text]
    : SEMICOLON { $text = ";"; logRule("expression_statement", $text); }
    | e=expression SEMICOLON { $text = $e.text + ";"; logRule("expression_statement", $text); }
    ;

variable
    returns [string varType, string text]
    : id=ID {
        SymbolInfo* symbol = symbolTable.lookup($id.text);
        if (!symbol) {
            logError($id.line, "Undeclared variable '" + $id.text + "'");
            $varType = "INT";
        } else {
            if (symbol->isArray) {
                logError($id.line, "Array '" + $id.text + "' used without index");
            }
            $varType = symbol->varType;
        }
        $text = $id.text;
        logRule("variable", $text);
    }
    | id=ID LSQUARE e=expression RSQUARE {
        SymbolInfo* symbol = symbolTable.lookup($id.text);
        if (!symbol) {
            logError($id.line, "Undeclared variable '" + $id.text + "'");
            $varType = "INT";
        } else {
            if (!symbol->isArray) {
                logError($id.line, "'" + $id.text + "' is not an array");
            }
            $varType = symbol->varType;
        }
        if ($e.exprType != "INT") {
            logError($id.line, "Array subscript is not an integer");
        }
        $text = $id.text + "[" + $e.text + "]";
        logRule("variable", $text);
    }
    | ID LSQUARE expression RSQUARE {
        SymbolInfo* symbol = symbolTable.lookup($ID.text);
        if (!symbol) {
            logError($ID.line, "Undeclared variable '" + $ID.text + "'");
            $varType = "INT";
        } else {
            if (!symbol->isArray) {
                logError($ID.line, "'" + $ID.text + "' is not an array");
            }
            $varType = symbol->varType;
        }
        if ($expression.exprType != "INT") {
            logError($ID.line, "Array subscript is not an integer");
        }
        $text = $ID.text + "[" + $expression.text + "]";
        logRule("variable", $text);
    }
    ;

expression
    returns [string exprType, string text]
    : logic_expression { $exprType = $logic_expression.exprType; $text = $logic_expression.text; logRule("expression", $text); }
    | variable ASSIGNOP logic_expression {
        if ($variable.varType != $logic_expression.exprType) {
            if ($variable.varType == "INT" && $logic_expression.exprType == "FLOAT") {
                logError($ASSIGNOP.line, "Warning: possible loss of data in assignment of FLOAT to INT");
            }
        }
        $exprType = $variable.varType;
        $text = $variable.text + "=" + $logic_expression.text;
        logRule("expression", $text);
    }
    ;

logic_expression
    returns [string exprType, string text]
    : rel_expression { 
        $exprType = $rel_expression.exprType; 
        $text = $rel_expression.text; 
        logRule("logic_expression", $text); 
    }
    | left=rel_expression LOGICOP right=rel_expression {
        $exprType = "INT";
        $text = $left.text + $LOGICOP.text + $right.text;
        logRule("logic_expression", $text);
    }
    ;
rel_expression
    returns [string exprType, string text]
    : simple_expression { 
        $exprType = $simple_expression.exprType; 
        $text = $simple_expression.text; 
        logRule("rel_expression", $text); 
    }
    | left=simple_expression RELOP right=simple_expression {
        $exprType = "INT";
        $text = $left.text + $RELOP.text + $right.text;
        logRule("rel_expression", $text);
    }
    ;

simple_expression
    returns [string exprType, string text]
    : term { 
        $exprType = $term.exprType; 
        $text = $term.text; 
        logRule("simple_expression", $text); 
    }
    | left=simple_expression ADDOP right=term {
        $exprType = $left.exprType;
        $text = $left.text + $ADDOP.text + $right.text;
        logRule("simple_expression", $text);
    }
    ;


term
    returns [string exprType, string text]
    : factor { 
        $exprType = $factor.exprType; 
        $text = $factor.text; 
        logRule("term", $text); 
    }
    | left=term MULOP right=factor {
        $exprType = $left.exprType;
        $text = $left.text + $MULOP.text + $right.text;
        logRule("term", $text);
    }
    ;

unary_expression
    returns [string exprType, string text]
    : ADDOP unary_expression {
        $exprType = $unary_expression.exprType;
        $text = $ADDOP.text + $unary_expression.text;
        logRule("unary_expression", $text);
    }
    | NOT unary_expression {
        $exprType = "INT";
        $text = "!" + $unary_expression.text;
        logRule("unary_expression", $text);
    }
    | factor { $exprType = $factor.exprType; $text = $factor.text; logRule("unary_expression", $text); }
    ;

factor
    returns [string exprType, string text]
    : variable { $exprType = $variable.varType; $text = $variable.text; logRule("factor", $text); }
    | ID LPAREN arguments RPAREN {
        SymbolInfo* symbol = symbolTable.lookup($ID.text);
        if (!symbol) {
            logError($ID.line, "Undeclared function '" + $ID.text + "'");
            $exprType = "INT";
        } else {
            if (!symbol->isFunction) {
                logError($ID.line, "'" + $ID.text + "' is not a function");
                $exprType = "INT";
            } else {
                $exprType = symbol->returnType;
            }
        }
        $text = $ID.text + "(" + $arguments.text + ")";
        logRule("factor", $text);
    }
    | LPAREN expression RPAREN { $exprType = $expression.exprType; $text = "(" + $expression.text + ")"; logRule("factor", $text); }
    | CONST_INT { $exprType = "INT"; $text = $CONST_INT.text; logRule("factor", $text); }
    | CONST_FLOAT { $exprType = "FLOAT"; $text = $CONST_FLOAT.text; logRule("factor", $text); }
    | variable INCOP { $exprType = $variable.varType; $text = $variable.text + $INCOP.text; logRule("factor", $text); }
    ;

arguments
    returns [string text]
    : expr1=expression { 
        $text = $expr1.text; 
        logRule("arguments", $text); 
    }
    | expr1=expression ',' rest=arguments {
        $text = $expr1.text + "," + $rest.text;
        logRule("arguments", $text);
    }
    | /* empty */ { 
        $text = ""; 
        logRule("arguments", $text); 
    }
    ;