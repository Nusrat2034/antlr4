
#include "SymbolTable.h"


// Generated from C2105140Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105140Parser : public antlr4::Parser {
public:
  enum {
    IF = 1, ELSE = 2, FOR = 3, WHILE = 4, DO = 5, BREAK = 6, INT = 7, FLOAT = 8, 
    DOUBLE = 9, CHAR = 10, STRING = 11, VOID = 12, RETURN = 13, SWITCH = 14, 
    CASE = 15, DEFAULT = 16, CONTINUE = 17, ASSIGNOP = 18, INCOP = 19, RELOP = 20, 
    LOGICOP = 21, BITOP = 22, NOT = 23, ADDOP = 24, MULOP = 25, LPAREN = 26, 
    RPAREN = 27, LCURL = 28, RCURL = 29, LSQUARE = 30, RSQUARE = 31, COMMA = 32, 
    SEMICOLON = 33, CONST_INT = 34, CONST_FLOAT = 35, CONST_CHAR = 36, STRING_LITERAL = 37, 
    ID = 38, WS = 39, COMMENT = 40, MULTILINE_COMMENT = 41, ERROR_CHAR = 42
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleVar_declaration = 3, 
    RuleType_specifier = 4, RuleDeclaration_list = 5, RuleFunc_declaration = 6, 
    RuleFunc_definition = 7, RuleParameter_list = 8, RuleCompound_statement = 9, 
    RuleStatements = 10, RuleStatement = 11, RuleExpression_statement = 12, 
    RuleVariable = 13, RuleExpression = 14, RuleLogic_expression = 15, RuleRel_expression = 16, 
    RuleSimple_expression = 17, RuleTerm = 18, RuleUnary_expression = 19, 
    RuleFactor = 20, RuleArguments = 21
  };

  explicit C2105140Parser(antlr4::TokenStream *input);

  C2105140Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C2105140Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


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


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Var_declarationContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105140Parser::ProgramContext *p = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::ProgramContext *p = nullptr;
    C2105140Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Var_declarationContext *v = nullptr;
    C2105140Parser::Func_declarationContext *fd = nullptr;
    C2105140Parser::Func_definitionContext *ff = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnitContext* unit();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Type_specifierContext *t = nullptr;
    C2105140Parser::Declaration_listContext *dl = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    string varType;
    string text;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *ci = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LSQUARE();
    antlr4::tree::TerminalNode *RSQUARE();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *COMMA();
    Declaration_listContext *declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    C2105140Parser::Parameter_listContext *pl = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    C2105140Parser::Parameter_listContext *pl = nullptr;
    C2105140Parser::Compound_statementContext *cs = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Parameter_listContext *pl = nullptr;
    C2105140Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LSQUARE();
    antlr4::tree::TerminalNode *RSQUARE();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::StatementsContext *s = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_statementContext* compound_statement();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::StatementsContext *s1 = nullptr;
    C2105140Parser::StatementContext *s = nullptr;
    C2105140Parser::StatementContext *s2 = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::Var_declarationContext *v = nullptr;
    C2105140Parser::Expression_statementContext *es = nullptr;
    C2105140Parser::Compound_statementContext *cs = nullptr;
    C2105140Parser::Expression_statementContext *e1 = nullptr;
    C2105140Parser::Expression_statementContext *e2 = nullptr;
    C2105140Parser::ExpressionContext *e3 = nullptr;
    C2105140Parser::StatementContext *s = nullptr;
    C2105140Parser::ExpressionContext *ei = nullptr;
    C2105140Parser::ExpressionContext *ew = nullptr;
    antlr4::Token *returnToken = nullptr;
    C2105140Parser::ExpressionContext *er = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    StatementContext *statement();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::ExpressionContext *e = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    string varType;
    string text;
    antlr4::Token *id = nullptr;
    C2105140Parser::ExpressionContext *e = nullptr;
    antlr4::Token *idToken = nullptr;
    C2105140Parser::ExpressionContext *expressionContext = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LSQUARE();
    antlr4::tree::TerminalNode *RSQUARE();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    C2105140Parser::Logic_expressionContext *logic_expressionContext = nullptr;
    C2105140Parser::VariableContext *variableContext = nullptr;
    antlr4::Token *assignopToken = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    C2105140Parser::Rel_expressionContext *rel_expressionContext = nullptr;
    C2105140Parser::Rel_expressionContext *left = nullptr;
    antlr4::Token *logicopToken = nullptr;
    C2105140Parser::Rel_expressionContext *right = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    C2105140Parser::Simple_expressionContext *simple_expressionContext = nullptr;
    C2105140Parser::Simple_expressionContext *left = nullptr;
    antlr4::Token *relopToken = nullptr;
    C2105140Parser::Simple_expressionContext *right = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    C2105140Parser::Simple_expressionContext *left = nullptr;
    C2105140Parser::TermContext *termContext = nullptr;
    antlr4::Token *addopToken = nullptr;
    C2105140Parser::TermContext *right = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    C2105140Parser::TermContext *left = nullptr;
    C2105140Parser::FactorContext *factorContext = nullptr;
    antlr4::Token *mulopToken = nullptr;
    C2105140Parser::FactorContext *right = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    antlr4::Token *addopToken = nullptr;
    C2105140Parser::Unary_expressionContext *unary_expressionContext = nullptr;
    C2105140Parser::FactorContext *factorContext = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    string exprType;
    string text;
    C2105140Parser::VariableContext *variableContext = nullptr;
    antlr4::Token *idToken = nullptr;
    C2105140Parser::ArgumentsContext *argumentsContext = nullptr;
    C2105140Parser::ExpressionContext *expressionContext = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *const_floatToken = nullptr;
    antlr4::Token *incopToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105140Parser::ExpressionContext *expr1 = nullptr;
    C2105140Parser::ArgumentsContext *rest = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

