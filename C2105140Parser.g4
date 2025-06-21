parser grammar C2105140Parser;

options {
    tokenVocab = C2105140Lexer;
}

@header {
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

class SymbolInfo {
public:
    string name;
    string type;
    string varType;
    string returnType;
    vector<pair<string, string>> parameters;
    int arraySize;
    bool isArray;
    bool isFunction;
    bool isDefined;
    bool isDeclared;
    int lineNo;
    
    SymbolInfo() {
        arraySize = -1;
        isArray = false;
        isFunction = false;
        isDefined = false;
        isDeclared = false;
        lineNo = 0;
    }
    
    SymbolInfo(string n, string t) {
        name = n;
        type = t;
        arraySize = -1;
        isArray = false;
        isFunction = false;
        isDefined = false;
        isDeclared = false;
        lineNo = 0;
    }
};

class SymbolTable {
public:
    map<string, SymbolInfo*> currentScope;
    vector<map<string, SymbolInfo*>> scopes;
    
    void enterScope() {
        scopes.push_back(currentScope);
        currentScope.clear();
    }
    
    void exitScope() {
        if (!scopes.empty()) {
            currentScope = scopes.back();
            scopes.pop_back();
        }
    }
    
    bool insert(SymbolInfo* symbol) {
        if (currentScope.find(symbol->name) != currentScope.end()) {
            return false;
        }
        currentScope[symbol->name] = symbol;
        return true;
    }
    
    SymbolInfo* lookup(string name) {
        if (currentScope.find(name) != currentScope.end()) {
            return currentScope[name];
        }
        for (int i = scopes.size() - 1; i >= 0; i--) {
            if (scopes[i].find(name) != scopes[i].end()) {
                return scopes[i][name];
            }
        }
        return nullptr;
    }
    
    void printScope() {
        logFile << "ScopeTable# " << scopes.size() << endl;
        for (auto& pair : currentScope) {
            SymbolInfo* symbol = pair.second;
            logFile << symbol->name << " : " << symbol->type;
            if (symbol->isFunction) {
                logFile << " FUNCTION";
                if (!symbol->returnType.empty()) {
                    logFile << " " << symbol->returnType;
                }
                logFile << "(";
                for (size_t i = 0; i < symbol->parameters.size(); i++) {
                    if (i > 0) logFile << ",";
                    logFile << symbol->parameters[i].first;
                }
                logFile << ")";
            } else if (symbol->isArray) {
                logFile << " [" << symbol->arraySize << "]";
            }
            logFile << endl;
        }
        logFile << endl;
    }
};

extern SymbolTable symbolTable;
extern ofstream logFile;
extern ofstream errorFile;
extern int lineCount;
extern int errorCount;
extern string currentReturnType;
extern bool insideFunction;
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

start : {initializeFiles();} program EOF {
    logRule("start", "program");
    closeFiles();
};

program : program unit {
    logRule("program", "program unit");
} | unit {
    logRule("program", "unit");
};

unit : var_declaration {
    logRule("unit", "var_declaration");
} | func_declaration {
    logRule("unit", "func_declaration");  
} | func_definition {
    logRule("unit", "func_definition");
};

var_declaration : type_specifier declaration_list SEMICOLON {
    logRule("var_declaration", $type_specifier.text + " " + $declaration_list.text + ";");
};

type_specifier returns [string varType] : INT {
    $varType = "INT";
    logRule("type_specifier", "int");
} | FLOAT {
    $varType = "FLOAT";
    logRule("type_specifier", "float");
} | VOID {
    $varType = "VOID";
    logRule("type_specifier", "void");
};

declaration_list : declaration_list COMMA ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    logRule("declaration_list", $declaration_list.text + "," + $ID.text);
} | declaration_list COMMA ID LSQUARE CONST_INT RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->isArray = true;
    symbol->arraySize = stoi($CONST_INT.text);
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    logRule("declaration_list", $declaration_list.text + "," + $ID.text + "[" + $CONST_INT.text + "]");
} | ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    logRule("declaration_list", $ID.text);
} | ID LSQUARE CONST_INT RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->isArray = true;
    symbol->arraySize = stoi($CONST_INT.text);
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    logRule("declaration_list", $ID.text + "[" + $CONST_INT.text + "]");
};

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->isFunction = true;
    symbol->returnType = $type_specifier.varType;
    symbol->isDeclared = true;
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        SymbolInfo* existing = symbolTable.lookup($ID.text);
        if (existing && existing->isFunction) {
            if (existing->returnType != symbol->returnType) {
                logError($ID.line, "Conflicting return type for function '" + $ID.text + "'");
            }
        } else {
            logError($ID.line, "Redefinition of function '" + $ID.text + "'");
        }
    }
    logRule("func_declaration", $type_specifier.text + " " + $ID.text + "(" + $parameter_list.text + ");");
} | type_specifier ID LPAREN RPAREN SEMICOLON {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->isFunction = true;
    symbol->returnType = $type_specifier.varType;
    symbol->isDeclared = true;
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of function '" + $ID.text + "'");
    }
    logRule("func_declaration", $type_specifier.text + " " + $ID.text + "();");
};

func_definition : type_specifier ID LPAREN parameter_list RPAREN {
    SymbolInfo* symbol = symbolTable.lookup($ID.text);
    if (!symbol) {
        symbol = new SymbolInfo($ID.text, "ID");
        symbol->isFunction = true;
        symbol->returnType = $type_specifier.varType;
        symbol->isDefined = true;
        symbolTable.insert(symbol);
    } else {
        if (symbol->isDefined) {
            logError($ID.line, "Redefinition of function '" + $ID.text + "'");
        } else {
            symbol->isDefined = true;
            if (symbol->returnType != $type_specifier.varType) {
                logError($ID.line, "Conflicting return type for function '" + $ID.text + "'");
            }
        }
    }
    currentReturnType = $type_specifier.varType;
    insideFunction = true;
    symbolTable.enterScope();
} compound_statement {
    symbolTable.printScope();
    symbolTable.exitScope();
    insideFunction = false;
    currentReturnType = "";
    logRule("func_definition", $type_specifier.text + " " + $ID.text + "(" + $parameter_list.text + ") " + $compound_statement.text);
} | type_specifier ID LPAREN RPAREN {
    SymbolInfo* symbol = symbolTable.lookup($ID.text);
    if (!symbol) {
        symbol = new SymbolInfo($ID.text, "ID");
        symbol->isFunction = true;
        symbol->returnType = $type_specifier.varType;
        symbol->isDefined = true;
        symbolTable.insert(symbol);
    } else {
        if (symbol->isDefined) {
            logError($ID.line, "Redefinition of function '" + $ID.text + "'");
        } else {
            symbol->isDefined = true;
        }
    }
    currentReturnType = $type_specifier.varType;
    insideFunction = true;
    symbolTable.enterScope();
} compound_statement {
    symbolTable.printScope();
    symbolTable.exitScope();
    insideFunction = false;
    currentReturnType = "";
    logRule("func_definition", $type_specifier.text + " " + $ID.text + "() " + $compound_statement.text);
};

parameter_list : parameter_list COMMA type_specifier ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbolTable.insert(symbol);
    logRule("parameter_list", $parameter_list.text + "," + $type_specifier.text + " " + $ID.text);
} | parameter_list COMMA type_specifier ID LSQUARE RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbol->isArray = true;
    symbolTable.insert(symbol);
    logRule("parameter_list", $parameter_list.text + "," + $type_specifier.text + " " + $ID.text + "[]");
} | type_specifier ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbolTable.insert(symbol);
    logRule("parameter_list", $type_specifier.text + " " + $ID.text);
} | type_specifier ID LSQUARE RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbol->isArray = true;
    symbolTable.insert(symbol);
    logRule("parameter_list", $type_specifier.text + " " + $ID.text + "[]");
};

compound_statement : LCURL {
    symbolTable.enterScope();
} statements RCURL {
    symbolTable.printScope();
    symbolTable.exitScope();
    logRule("compound_statement", "{" + $statements.text + "}");
} | LCURL RCURL {
    logRule("compound_statement", "{}");
};

statements : statements statement {
    logRule("statements", $statements.text + " " + $statement.text);
} | statement {
    logRule("statements", $statement.text);
};

statement : var_declaration {
    logRule("statement", $var_declaration.text);
} | expression_statement {
    logRule("statement", $expression_statement.text);
} | compound_statement {
    logRule("statement", $compound_statement.text);
} | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
    logRule("statement", "for(" + $expression_statement.text + $expression_statement.text + $expression.text + ")" + $statement.text);
} | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
    logRule("statement", "if(" + $expression.text + ")" + $statement.text);
} | IF LPAREN expression RPAREN statement ELSE statement {
    logRule("statement", "if(" + $expression.text + ")" + $statement.text + "else" + $statement.text);
} | WHILE LPAREN expression RPAREN statement {
    logRule("statement", "while(" + $expression.text + ")" + $statement.text);
} | RETURN expression SEMICOLON {
    if (!insideFunction) {
        logError($RETURN.line, "Return statement outside function");
    }
    logRule("statement", "return " + $expression.text + ";");
} | RETURN SEMICOLON {
    if (!insideFunction) {
        logError($RETURN.line, "Return statement outside function");
    }
    logRule("statement", "return;");
};

expression_statement : SEMICOLON {
    logRule("expression_statement", ";");
} | expression SEMICOLON {
    logRule("expression_statement", $expression.text + ";");
};

variable returns [string varType] : ID {
    SymbolInfo* symbol = symbolTable.lookup($ID.text);
    if (!symbol) {
        logError($ID.line, "Undeclared variable '" + $ID.text + "'");
        $varType = "INT";
    } else {
        if (symbol->isArray) {
            logError($ID.line, "Array '" + $ID.text + "' used without index");
        }
        $varType = symbol->varType;
    }
    logRule("variable", $ID.text);
} | ID LSQUARE expression RSQUARE {
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
    logRule("variable", $ID.text + "[" + $expression.text + "]");
};

expression returns [string exprType] : logic_expression {
    $exprType = $logic_expression.exprType;
    logRule("expression", $logic_expression.text);
} | variable ASSIGNOP logic_expression {
    if ($variable.varType != $logic_expression.exprType) {
        if ($variable.varType == "INT" && $logic_expression.exprType == "FLOAT") {
            logError($ASSIGNOP.line, "Warning: possible loss of data in assignment of FLOAT to INT");
        }
    }
    $exprType = $variable.varType;
    logRule("expression", $variable.text + "=" + $logic_expression.text);
};

logic_expression returns [string exprType] : rel_expression {
    $exprType = $rel_expression.exprType;
    logRule("logic_expression", $rel_expression.text);
} | rel_expression LOGICOP rel_expression {
    $exprType = "INT";
    logRule("logic_expression", $rel_expression.text + $LOGICOP.text + $rel_expression.text);
};

rel_expression returns [string exprType] : simple_expression {
    $exprType = $simple_expression.exprType;
    logRule("rel_expression", $simple_expression.text);
} | simple_expression RELOP simple_expression {
    $exprType = "INT";
    logRule("rel_expression", $simple_expression.text + $RELOP.text + $simple_expression.text);
};

simple_expression returns [string exprType] : term {
    $exprType = $term.exprType;
    logRule("simple_expression", $term.text);
} | simple_expression ADDOP term {
    $exprType = typeConvert($simple_expression.exprType, $term.exprType);
    logRule("simple_expression", $simple_expression.text + $ADDOP.text + $term.text);
};

term returns [string exprType] : unary_expression {
    $exprType = $unary_expression.exprType;
    logRule("term", $unary_expression.text);
} | term MULOP unary_expression {
    if ($MULOP.text == "%" && ($term.exprType != "INT" || $unary_expression.exprType != "INT")) {
        logError($MULOP.line, "Operands of modulus must be integers");
    }
    $exprType = typeConvert($term.exprType, $unary_expression.exprType);
    logRule("term", $term.text + $MULOP.text + $unary_expression.text);
};

unary_expression returns [string exprType] : ADDOP unary_expression {
    $exprType = $unary_expression.exprType;
    logRule("unary_expression", $ADDOP.text + $unary_expression.text);
} | NOT unary_expression {
    $exprType = "INT";
    logRule("unary_expression", "!" + $unary_expression.text);
} | factor {
    $exprType = $factor.exprType;
    logRule("unary_expression", $factor.text);
};

factor returns [string exprType] : variable {
    $exprType = $variable.varType;
    logRule("factor", $variable.text);
} | ID LPAREN argument_list RPAREN {
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
    logRule("factor", $ID.text + "(" + $argument_list.text + ")");
} | LPAREN expression RPAREN {
    $exprType = $expression.exprType;
    logRule("factor", "(" + $expression.text + ")");
} | CONST_INT {
    $exprType = "INT";
    logRule("factor", $CONST_INT.text);
} | CONST_FLOAT {
    $exprType = "FLOAT";
    logRule("factor", $CONST_FLOAT.text);
} | variable INCOP {
    $exprType = $variable.varType;
    logRule("factor", $variable.text + $INCOP.text);
};

argument_list : arguments {
    logRule("argument_list", $arguments.text);
} | /* empty */ {
    logRule("argument_list", "");
};

arguments : arguments COMMA logic_expression {
    logRule("arguments", $arguments.text + "," + $logic_expression.text);
} | logic_expression {
    logRule("arguments", $logic_expression.text);
};