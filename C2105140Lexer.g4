lexer grammar C2105140Lexer;

// Keywords
IF : 'if';
ELSE : 'else';
FOR : 'for';
WHILE : 'while';
DO : 'do';
BREAK : 'break';
INT : 'int';
FLOAT : 'float';
DOUBLE : 'double';
CHAR : 'char';
STRING : 'string';
VOID : 'void';
RETURN : 'return';
SWITCH : 'switch';
CASE : 'case';
DEFAULT : 'default';
CONTINUE : 'continue';

// Operators
ASSIGNOP : '=';
INCOP : '++' | '--';
RELOP : '<' | '<=' | '>' | '>=' | '==' | '!=';
LOGICOP : '&&' | '||';
BITOP : '&' | '|' | '^' | '<<' | '>>';
NOT : '!';
ADDOP : '+' | '-';
MULOP : '*' | '/' | '%';

// Delimiters
LPAREN : '(';
RPAREN : ')';
LCURL : '{';
RCURL : '}';
LSQUARE : '[';
RSQUARE : ']';
COMMA : ',';
SEMICOLON : ';';

// Literals
CONST_INT : [0-9]+;
CONST_FLOAT : [0-9]*'.'[0-9]+ | [0-9]+'.'[0-9]*;
CONST_CHAR : '\'' (~['\\\r\n] | '\\' .) '\'';
STRING_LITERAL : '"' (~["\\\r\n] | '\\' .)* '"';

// Identifiers
ID : [a-zA-Z_][a-zA-Z0-9_]*;

// Whitespace and comments
WS : [ \t\r\n]+ -> skip;
COMMENT : '//' ~[\r\n]* -> skip;
MULTILINE_COMMENT : '/*' .*? '*/' -> skip;

// Error handling for unrecognized characters
ERROR_CHAR : .;
