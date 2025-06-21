parser grammar C2105140Parser;

options {
    tokenVocab = C2105140Lexer;
}

@header {
#include "SymbolTable.h"
#include <fstream>
#include <string>
using namespace std;

extern SymbolTable symbolTable;
extern ofstream logFile;
extern ofstream errorFile;
extern int lineCount;
extern int errorCount;
extern string currentReturnType;
extern bool insideFunction;
}

@members {
string currentReturnType = "";
bool insideFunction = false;

void logRule(const string& rule, const string& code) {
    logFile << rule << " : " << code << endl;
}

void logError(int line, const string& message) {
    errorFile << "Line no " << line << ": " << message << endl;
    errorCount++;
}

string typeConvert(const string& type1, const string& type2) {
    if (type1 == "FLOAT" || type2 == "FLOAT") {
        return "FLOAT";
    }
    return "INT";
}
}

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
    string code = $type_specifier.text + " " + $declaration_list.text + ";";
    logRule("var_declaration", code);
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

declaration_list returns [string text] : declaration_list COMMA ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    $text = $declaration_list.text + "," + $ID.text;
    logRule("declaration_list", $text);
} | declaration_list COMMA ID LSQUARE CONST_INT RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->isArray = true;
    symbol->arraySize = stoi($CONST_INT.text);
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    $text = $declaration_list.text + "," + $ID.text + "[" + $CONST_INT.text + "]";
    logRule("declaration_list", $text);
} | ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    $text = $ID.text;
    logRule("declaration_list", $text);
} | ID LSQUARE CONST_INT RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = "INT";
    symbol->isArray = true;
    symbol->arraySize = stoi($CONST_INT.text);
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of variable '" + $ID.text + "'");
    }
    $text = $ID.text + "[" + $CONST_INT.text + "]";
    logRule("declaration_list", $text);
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
    string code = $type_specifier.text + " " + $ID.text + "(" + $parameter_list.text + ");";
    logRule("func_declaration", code);
} | type_specifier ID LPAREN RPAREN SEMICOLON {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->isFunction = true;
    symbol->returnType = $type_specifier.varType;
    symbol->isDeclared = true;
    symbol->lineNo = $ID.line;
    if (!symbolTable.insert(symbol)) {
        logError($ID.line, "Redefinition of function '" + $ID.text + "'");
    }
    string code = $type_specifier.text + " " + $ID.text + "();";
    logRule("func_declaration", code);
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
    symbolTable.printScope(logFile);
    symbolTable.exitScope();
    insideFunction = false;
    currentReturnType = "";
    string code = $type_specifier.text + " " + $ID.text + "(" + $parameter_list.text + ") " + $compound_statement.text;
    logRule("func_definition", code);
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
    symbolTable.printScope(logFile);
    symbolTable.exitScope();
    insideFunction = false;
    currentReturnType = "";
    string code = $type_specifier.text + " " + $ID.text + "() " + $compound_statement.text;
    logRule("func_definition", code);
};

parameter_list returns [string text] : parameter_list COMMA type_specifier ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbolTable.insert(symbol);
    $text = $parameter_list.text + "," + $type_specifier.text + " " + $ID.text;
    logRule("parameter_list", $text);
} | parameter_list COMMA type_specifier ID LSQUARE RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbol->isArray = true;
    symbolTable.insert(symbol);
    $text = $parameter_list.text + "," + $type_specifier.text + " " + $ID.text + "[]";
    logRule("parameter_list", $text);
} | type_specifier ID {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbolTable.insert(symbol);
    $text = $type_specifier.text + " " + $ID.text;
    logRule("parameter_list", $text);
} | type_specifier ID LSQUARE RSQUARE {
    SymbolInfo* symbol = new SymbolInfo($ID.text, "ID");
    symbol->varType = $type_specifier.varType;
    symbol->isArray = true;
    symbolTable.insert(symbol);
    $text = $type_specifier.text + " " + $ID.text + "[]";
    logRule("parameter_list", $text);
};

compound_statement returns [string text] : LCURL {
    symbolTable.enterScope();
} statements RCURL {
    symbolTable.printScope(logFile);
    symbolTable.exitScope();
    $text = "{" + $statements.text + "}";
    logRule("compound_statement", $text);
} | LCURL RCURL {
    $text = "{}";
    logRule("compound_statement", $text);
};

statements returns [string text] : statements statement {
    $text = $statements.text + " " + $statement.text;
    logRule("statements", $text);
} | statement {
    $text = $statement.text;
    logRule("statements", $text);
};

statement returns [string text] : var_declaration {
    $text = $var_declaration.text;
    logRule("statement", $text);
} | expression_statement {
    $text = $expression_statement.text;
    logRule("statement", $text);
} | compound_statement {
    $text = $compound_statement.text;
    logRule("statement", $text);
} | FOR LPAREN expression_statement1=expression_statement expression_statement2=expression_statement expression RPAREN statement {
    $text = "for(" + $expression_statement1.text + $expression_statement2.text + $expression.text + ")" + $statement.text;
    logRule("statement", $text);
} | IF LPAREN expression RPAREN statement1=statement ELSE statement2=statement {
    $text = "if(" + $expression.text + ")" + $statement1.text + "else" + $statement2.text;
    logRule("statement", $text);
} | IF LPAREN expression RPAREN statement {
    $text = "if(" + $expression.text + ")" + $statement.text;
    logRule("statement", $text);
} | WHILE LPAREN expression RPAREN statement {
    $text = "while(" + $expression.text + ")" + $statement.text;
    logRule("statement", $text);
} | RETURN expression SEMICOLON {
    if (!insideFunction) {
        logError($RETURN.line, "Return statement outside function");
    }
    $text = "return " + $expression.text + ";";
    logRule("statement", $text);
} | RETURN SEMICOLON {
    if (!insideFunction) {
        logError($RETURN.line, "Return statement outside function");
    }
    $text = "return;";
    logRule("statement", $text);
};

expression_statement returns [string text] : SEMICOLON {
    $text = ";";
    logRule("expression_statement", $text);
} | expression SEMICOLON {
    $text = $expression.text + ";";
    logRule("expression_statement", $text);
};

variable returns [string varType, string text] : ID {
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
    $text = $ID.text;
    logRule("variable", $text);
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
    $text = $ID.text + "[" + $expression.text + "]";
    logRule("variable", $text);
};

expression returns [string exprType, string text] : logic_expression {
    $exprType = $logic_expression.exprType;
    $text = $logic_expression.text;
    logRule("expression", $text);
} | variable ASSIGNOP logic_expression {
    if ($variable.varType != $logic_expression.exprType) {
        if ($variable.varType == "INT" && $logic_expression.exprType == "FLOAT") {
            logError($ASSIGNOP.line, "Warning: possible loss of data in assignment of FLOAT to INT");
        }
    }
    $exprType = $variable.varType;
    $text = $variable.text + "=" + $logic_expression.text;
    logRule("expression", $text);
};

logic_expression returns [string exprType, string text] : rel_expression {
    $exprType = $rel_expression.exprType;
    $text = $rel_expression.text;
    logRule("logic_expression", $text);
} | rel_expression1=rel_expression LOGICOP rel_expression2=rel_expression {
    $exprType = "INT";
    $text = $rel_expression1.text + $LOGICOP.text + $rel_expression2.text;
    logRule("logic_expression", $text);
};

rel_expression returns [string exprType, string text] : simple_expression {
    $exprType = $simple_expression.exprType;
    $text = $simple_expression.text;
    logRule("rel_expression", $text);
} | simple_expression1=simple_expression RELOP simple_expression2=simple_expression {
    $exprType = "INT";
    $text = $simple_expression1.text + $RELOP.text + $simple_expression2.text;
    logRule("rel_expression", $text);
};

simple_expression returns [string exprType, string text] : term {
    $exprType = $term.exprType;
    $text = $term.text;
    logRule("simple_expression", $text);
} | simple_expression ADDOP term {
    $exprType = typeConvert($simple_expression.exprType, $term.exprType);
    $text = $simple_expression.text + $ADDOP.text + $term.text;
    logRule("simple_expression", $text);
};

term returns [string exprType, string text] : unary_expression {
    $exprType = $unary_expression.exprType;
    $text = $unary_expression.text;
    logRule("term", $text);
} | term MULOP unary_expression {
    if ($MULOP.text == "%" && ($term.exprType != "INT" || $unary_expression.exprType != "INT")) {
        logError($MULOP.line, "Operands of modulus must be integers");
    }
    $exprType = typeConvert($term.exprType, $unary_expression.exprType);
    $text = $term.text + $MULOP.text + $unary_expression.text;
    logRule("term", $text);
};

unary_expression returns [string exprType, string text] : ADDOP unary_expression {
    $exprType = $unary_expression.exprType;
    $text = $ADDOP.text + $unary_expression.text;
    logRule("unary_expression", $text);
} | NOT unary_expression {
    $exprType = "INT";
    $text = "!" + $unary_expression.text;
    logRule("unary_expression", $text);
} | factor {
    $exprType = $factor.exprType;
    $text = $factor.text;
    logRule("unary_expression", $text);
};

factor returns [string exprType, string text] : variable {
    $exprType = $variable.varType;
    $text = $variable.text;
    logRule("factor", $text);
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
    $text = $ID.text + "(" + $argument_list.text + ")";
    logRule("factor", $text);
} | LPAREN expression RPAREN {
    $exprType = $expression.exprType;
    $text = "(" + $expression.text + ")";
    logRule("factor", $text);
} | CONST_INT {
    $exprType = "INT";
    $text = $CONST_INT.text;
    logRule("factor", $text);
} | CONST_FLOAT {
    $exprType = "FLOAT";
    $text = $CONST_FLOAT.text;
    logRule("factor", $text);
} | variable INCOP {
    $exprType = $variable.varType;
    $text = $variable.text + $INCOP.text;
    logRule("factor", $text);
};

argument_list returns [string text] : arguments {
    $text = $arguments.text;
    logRule("argument_list", $text);
} | /* empty */ {
    $text = "";
    logRule("argument_list", "");
};

arguments returns [string text] : arguments COMMA logic_expression {
    $text = $arguments.text + "," + $logic_expression.text;
    logRule("arguments", $text);
} | logic_expression {
    $text = $logic_expression.text;
    logRule("arguments", $text);
};