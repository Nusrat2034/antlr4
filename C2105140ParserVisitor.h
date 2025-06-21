
#include "SymbolTable.h"


// Generated from C2105140Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105140Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by C2105140Parser.
 */
class  C2105140ParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by C2105140Parser.
   */
    virtual std::any visitStart(C2105140Parser::StartContext *context) = 0;

    virtual std::any visitProgram(C2105140Parser::ProgramContext *context) = 0;

    virtual std::any visitUnit(C2105140Parser::UnitContext *context) = 0;

    virtual std::any visitVar_declaration(C2105140Parser::Var_declarationContext *context) = 0;

    virtual std::any visitType_specifier(C2105140Parser::Type_specifierContext *context) = 0;

    virtual std::any visitDeclaration_list(C2105140Parser::Declaration_listContext *context) = 0;

    virtual std::any visitFunc_declaration(C2105140Parser::Func_declarationContext *context) = 0;

    virtual std::any visitFunc_definition(C2105140Parser::Func_definitionContext *context) = 0;

    virtual std::any visitParameter_list(C2105140Parser::Parameter_listContext *context) = 0;

    virtual std::any visitCompound_statement(C2105140Parser::Compound_statementContext *context) = 0;

    virtual std::any visitStatements(C2105140Parser::StatementsContext *context) = 0;

    virtual std::any visitStatement(C2105140Parser::StatementContext *context) = 0;

    virtual std::any visitExpression_statement(C2105140Parser::Expression_statementContext *context) = 0;

    virtual std::any visitVariable(C2105140Parser::VariableContext *context) = 0;

    virtual std::any visitExpression(C2105140Parser::ExpressionContext *context) = 0;

    virtual std::any visitLogic_expression(C2105140Parser::Logic_expressionContext *context) = 0;

    virtual std::any visitRel_expression(C2105140Parser::Rel_expressionContext *context) = 0;

    virtual std::any visitSimple_expression(C2105140Parser::Simple_expressionContext *context) = 0;

    virtual std::any visitTerm(C2105140Parser::TermContext *context) = 0;

    virtual std::any visitUnary_expression(C2105140Parser::Unary_expressionContext *context) = 0;

    virtual std::any visitFactor(C2105140Parser::FactorContext *context) = 0;

    virtual std::any visitArguments(C2105140Parser::ArgumentsContext *context) = 0;


};

