
// Generated from C2105140Parser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  C2105140ParserLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, FLOAT = 2, ID = 3, COMMA = 4, SEMICOLON = 5, WS = 6, COMMENT = 7, 
    LINE_COMMENT = 8
  };

  explicit C2105140ParserLexer(antlr4::CharStream *input);

  ~C2105140ParserLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

