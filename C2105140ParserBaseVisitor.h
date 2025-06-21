
#include "SymbolTable.h"


// Generated from C2105140Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105140ParserVisitor.h"


/**
 * This class provides an empty implementation of C2105140ParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  C2105140ParserBaseVisitor : public C2105140ParserVisitor {
public:

  virtual std::any visitStart(C2105140Parser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(C2105140Parser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit(C2105140Parser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(C2105140Parser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_specifier(C2105140Parser::Type_specifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration_list(C2105140Parser::Declaration_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration(C2105140Parser::Func_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_definition(C2105140Parser::Func_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list(C2105140Parser::Parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_statement(C2105140Parser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(C2105140Parser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(C2105140Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement(C2105140Parser::Expression_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(C2105140Parser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(C2105140Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_expression(C2105140Parser::Logic_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_expression(C2105140Parser::Rel_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression(C2105140Parser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(C2105140Parser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression(C2105140Parser::Unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(C2105140Parser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(C2105140Parser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

