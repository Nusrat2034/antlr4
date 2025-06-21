
// Generated from C2105140Lexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  C2105140Lexer : public antlr4::Lexer {
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

  explicit C2105140Lexer(antlr4::CharStream *input);
  ~C2105140Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

