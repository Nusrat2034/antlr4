
// Generated from C2105140Lexer.g4 by ANTLR 4.13.1


#include "C2105140Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C2105140LexerStaticData final {
  C2105140LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105140LexerStaticData(const C2105140LexerStaticData&) = delete;
  C2105140LexerStaticData(C2105140LexerStaticData&&) = delete;
  C2105140LexerStaticData& operator=(const C2105140LexerStaticData&) = delete;
  C2105140LexerStaticData& operator=(C2105140LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105140lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
C2105140LexerStaticData *c2105140lexerLexerStaticData = nullptr;

void c2105140lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105140lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c2105140lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105140LexerStaticData>(
    std::vector<std::string>{
      "INT", "FLOAT", "ID", "SEMICOLON", "COMMA", "WS", "LINE_COMMENT", 
      "BLOCK_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'float'", "", "';'", "','"
    },
    std::vector<std::string>{
      "", "INT", "FLOAT", "ID", "SEMICOLON", "COMMA", "WS", "LINE_COMMENT", 
      "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,8,70,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,5,2,30,8,2,10,
  	2,12,2,33,9,2,1,3,1,3,1,4,1,4,1,5,4,5,40,8,5,11,5,12,5,41,1,5,1,5,1,6,
  	1,6,1,6,1,6,5,6,50,8,6,10,6,12,6,53,9,6,1,6,1,6,1,7,1,7,1,7,1,7,5,7,61,
  	8,7,10,7,12,7,64,9,7,1,7,1,7,1,7,1,7,1,7,1,62,0,8,1,1,3,2,5,3,7,4,9,5,
  	11,6,13,7,15,8,1,0,4,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,
  	122,3,0,9,10,13,13,32,32,2,0,10,10,13,13,73,0,1,1,0,0,0,0,3,1,0,0,0,0,
  	5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,
  	0,0,1,17,1,0,0,0,3,21,1,0,0,0,5,27,1,0,0,0,7,34,1,0,0,0,9,36,1,0,0,0,
  	11,39,1,0,0,0,13,45,1,0,0,0,15,56,1,0,0,0,17,18,5,105,0,0,18,19,5,110,
  	0,0,19,20,5,116,0,0,20,2,1,0,0,0,21,22,5,102,0,0,22,23,5,108,0,0,23,24,
  	5,111,0,0,24,25,5,97,0,0,25,26,5,116,0,0,26,4,1,0,0,0,27,31,7,0,0,0,28,
  	30,7,1,0,0,29,28,1,0,0,0,30,33,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,
  	6,1,0,0,0,33,31,1,0,0,0,34,35,5,59,0,0,35,8,1,0,0,0,36,37,5,44,0,0,37,
  	10,1,0,0,0,38,40,7,2,0,0,39,38,1,0,0,0,40,41,1,0,0,0,41,39,1,0,0,0,41,
  	42,1,0,0,0,42,43,1,0,0,0,43,44,6,5,0,0,44,12,1,0,0,0,45,46,5,47,0,0,46,
  	47,5,47,0,0,47,51,1,0,0,0,48,50,8,3,0,0,49,48,1,0,0,0,50,53,1,0,0,0,51,
  	49,1,0,0,0,51,52,1,0,0,0,52,54,1,0,0,0,53,51,1,0,0,0,54,55,6,6,0,0,55,
  	14,1,0,0,0,56,57,5,47,0,0,57,58,5,42,0,0,58,62,1,0,0,0,59,61,9,0,0,0,
  	60,59,1,0,0,0,61,64,1,0,0,0,62,63,1,0,0,0,62,60,1,0,0,0,63,65,1,0,0,0,
  	64,62,1,0,0,0,65,66,5,42,0,0,66,67,5,47,0,0,67,68,1,0,0,0,68,69,6,7,0,
  	0,69,16,1,0,0,0,5,0,31,41,51,62,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105140lexerLexerStaticData = staticData.release();
}

}

C2105140Lexer::C2105140Lexer(CharStream *input) : Lexer(input) {
  C2105140Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c2105140lexerLexerStaticData->atn, c2105140lexerLexerStaticData->decisionToDFA, c2105140lexerLexerStaticData->sharedContextCache);
}

C2105140Lexer::~C2105140Lexer() {
  delete _interpreter;
}

std::string C2105140Lexer::getGrammarFileName() const {
  return "C2105140Lexer.g4";
}

const std::vector<std::string>& C2105140Lexer::getRuleNames() const {
  return c2105140lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C2105140Lexer::getChannelNames() const {
  return c2105140lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C2105140Lexer::getModeNames() const {
  return c2105140lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C2105140Lexer::getVocabulary() const {
  return c2105140lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105140Lexer::getSerializedATN() const {
  return c2105140lexerLexerStaticData->serializedATN;
}

const atn::ATN& C2105140Lexer::getATN() const {
  return *c2105140lexerLexerStaticData->atn;
}




void C2105140Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105140lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c2105140lexerLexerOnceFlag, c2105140lexerLexerInitialize);
#endif
}
