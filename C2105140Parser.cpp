
#include "SymbolTable.h"


// Generated from C2105140Parser.g4 by ANTLR 4.13.2


#include "C2105140ParserListener.h"
#include "C2105140ParserVisitor.h"

#include "C2105140Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105140ParserStaticData final {
  C2105140ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105140ParserStaticData(const C2105140ParserStaticData&) = delete;
  C2105140ParserStaticData(C2105140ParserStaticData&&) = delete;
  C2105140ParserStaticData& operator=(const C2105140ParserStaticData&) = delete;
  C2105140ParserStaticData& operator=(C2105140ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105140parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105140ParserStaticData> c2105140parserParserStaticData = nullptr;

void c2105140parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105140parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105140parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105140ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "var_declaration", "type_specifier", "declaration_list", 
      "func_declaration", "func_definition", "parameter_list", "compound_statement", 
      "statements", "statement", "expression_statement", "variable", "expression", 
      "logic_expression", "rel_expression", "simple_expression", "term", 
      "unary_expression", "factor", "arguments"
    },
    std::vector<std::string>{
      "", "'if'", "'else'", "'for'", "'while'", "'do'", "'break'", "'int'", 
      "'float'", "'double'", "'char'", "'string'", "'void'", "'return'", 
      "'switch'", "'case'", "'default'", "'continue'", "'='", "", "", "", 
      "", "'!'", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", "','", 
      "';'"
    },
    std::vector<std::string>{
      "", "IF", "ELSE", "FOR", "WHILE", "DO", "BREAK", "INT", "FLOAT", "DOUBLE", 
      "CHAR", "STRING", "VOID", "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", 
      "ASSIGNOP", "INCOP", "RELOP", "LOGICOP", "BITOP", "NOT", "ADDOP", 
      "MULOP", "LPAREN", "RPAREN", "LCURL", "RCURL", "LSQUARE", "RSQUARE", 
      "COMMA", "SEMICOLON", "CONST_INT", "CONST_FLOAT", "CONST_CHAR", "STRING_LITERAL", 
      "ID", "WS", "COMMENT", "MULTILINE_COMMENT", "ERROR_CHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,377,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,58,8,1,10,
  	1,12,1,61,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,72,8,2,1,3,1,3,
  	1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,85,8,4,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,3,5,95,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,
  	108,8,5,10,5,12,5,111,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,3,6,128,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,147,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,3,8,160,8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,5,8,176,8,8,10,8,12,8,179,9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,3,9,190,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,200,8,
  	10,10,10,12,10,203,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,3,11,245,8,11,1,12,1,12,1,12,1,12,1,12,1,12,3,12,253,8,
  	12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,3,13,269,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,279,8,14,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,289,8,15,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,3,16,299,8,16,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,5,17,310,8,17,10,17,12,17,313,9,17,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,5,18,324,8,18,10,18,12,18,327,9,18,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,340,8,19,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,3,20,364,8,20,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,3,21,375,8,21,1,21,0,6,2,10,16,20,34,36,22,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,0,0,393,0,44,1,
  	0,0,0,2,49,1,0,0,0,4,71,1,0,0,0,6,73,1,0,0,0,8,84,1,0,0,0,10,94,1,0,0,
  	0,12,127,1,0,0,0,14,146,1,0,0,0,16,159,1,0,0,0,18,189,1,0,0,0,20,191,
  	1,0,0,0,22,244,1,0,0,0,24,252,1,0,0,0,26,268,1,0,0,0,28,278,1,0,0,0,30,
  	288,1,0,0,0,32,298,1,0,0,0,34,300,1,0,0,0,36,314,1,0,0,0,38,339,1,0,0,
  	0,40,363,1,0,0,0,42,374,1,0,0,0,44,45,6,0,-1,0,45,46,3,2,1,0,46,47,5,
  	0,0,1,47,48,6,0,-1,0,48,1,1,0,0,0,49,50,6,1,-1,0,50,51,3,4,2,0,51,52,
  	6,1,-1,0,52,59,1,0,0,0,53,54,10,2,0,0,54,55,3,4,2,0,55,56,6,1,-1,0,56,
  	58,1,0,0,0,57,53,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,
  	3,1,0,0,0,61,59,1,0,0,0,62,63,3,6,3,0,63,64,6,2,-1,0,64,72,1,0,0,0,65,
  	66,3,12,6,0,66,67,6,2,-1,0,67,72,1,0,0,0,68,69,3,14,7,0,69,70,6,2,-1,
  	0,70,72,1,0,0,0,71,62,1,0,0,0,71,65,1,0,0,0,71,68,1,0,0,0,72,5,1,0,0,
  	0,73,74,3,8,4,0,74,75,3,10,5,0,75,76,5,33,0,0,76,77,6,3,-1,0,77,7,1,0,
  	0,0,78,79,5,7,0,0,79,85,6,4,-1,0,80,81,5,8,0,0,81,85,6,4,-1,0,82,83,5,
  	12,0,0,83,85,6,4,-1,0,84,78,1,0,0,0,84,80,1,0,0,0,84,82,1,0,0,0,85,9,
  	1,0,0,0,86,87,6,5,-1,0,87,88,5,38,0,0,88,95,6,5,-1,0,89,90,5,38,0,0,90,
  	91,5,30,0,0,91,92,5,34,0,0,92,93,5,31,0,0,93,95,6,5,-1,0,94,86,1,0,0,
  	0,94,89,1,0,0,0,95,109,1,0,0,0,96,97,10,4,0,0,97,98,5,32,0,0,98,99,5,
  	38,0,0,99,108,6,5,-1,0,100,101,10,3,0,0,101,102,5,32,0,0,102,103,5,38,
  	0,0,103,104,5,30,0,0,104,105,5,34,0,0,105,106,5,31,0,0,106,108,6,5,-1,
  	0,107,96,1,0,0,0,107,100,1,0,0,0,108,111,1,0,0,0,109,107,1,0,0,0,109,
  	110,1,0,0,0,110,11,1,0,0,0,111,109,1,0,0,0,112,113,3,8,4,0,113,114,5,
  	38,0,0,114,115,5,26,0,0,115,116,3,16,8,0,116,117,5,27,0,0,117,118,5,33,
  	0,0,118,119,6,6,-1,0,119,128,1,0,0,0,120,121,3,8,4,0,121,122,5,38,0,0,
  	122,123,5,26,0,0,123,124,5,27,0,0,124,125,5,33,0,0,125,126,6,6,-1,0,126,
  	128,1,0,0,0,127,112,1,0,0,0,127,120,1,0,0,0,128,13,1,0,0,0,129,130,3,
  	8,4,0,130,131,5,38,0,0,131,132,5,26,0,0,132,133,3,16,8,0,133,134,5,27,
  	0,0,134,135,6,7,-1,0,135,136,3,18,9,0,136,137,6,7,-1,0,137,147,1,0,0,
  	0,138,139,3,8,4,0,139,140,5,38,0,0,140,141,5,26,0,0,141,142,5,27,0,0,
  	142,143,6,7,-1,0,143,144,3,18,9,0,144,145,6,7,-1,0,145,147,1,0,0,0,146,
  	129,1,0,0,0,146,138,1,0,0,0,147,15,1,0,0,0,148,149,6,8,-1,0,149,150,3,
  	8,4,0,150,151,5,38,0,0,151,152,6,8,-1,0,152,160,1,0,0,0,153,154,3,8,4,
  	0,154,155,5,38,0,0,155,156,5,30,0,0,156,157,5,31,0,0,157,158,6,8,-1,0,
  	158,160,1,0,0,0,159,148,1,0,0,0,159,153,1,0,0,0,160,177,1,0,0,0,161,162,
  	10,4,0,0,162,163,5,32,0,0,163,164,3,8,4,0,164,165,5,38,0,0,165,166,6,
  	8,-1,0,166,176,1,0,0,0,167,168,10,3,0,0,168,169,5,32,0,0,169,170,3,8,
  	4,0,170,171,5,38,0,0,171,172,5,30,0,0,172,173,5,31,0,0,173,174,6,8,-1,
  	0,174,176,1,0,0,0,175,161,1,0,0,0,175,167,1,0,0,0,176,179,1,0,0,0,177,
  	175,1,0,0,0,177,178,1,0,0,0,178,17,1,0,0,0,179,177,1,0,0,0,180,181,5,
  	28,0,0,181,182,6,9,-1,0,182,183,3,20,10,0,183,184,5,29,0,0,184,185,6,
  	9,-1,0,185,190,1,0,0,0,186,187,5,28,0,0,187,188,5,29,0,0,188,190,6,9,
  	-1,0,189,180,1,0,0,0,189,186,1,0,0,0,190,19,1,0,0,0,191,192,6,10,-1,0,
  	192,193,3,22,11,0,193,194,6,10,-1,0,194,201,1,0,0,0,195,196,10,2,0,0,
  	196,197,3,22,11,0,197,198,6,10,-1,0,198,200,1,0,0,0,199,195,1,0,0,0,200,
  	203,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,21,1,0,0,0,203,201,1,
  	0,0,0,204,205,3,6,3,0,205,206,6,11,-1,0,206,245,1,0,0,0,207,208,3,24,
  	12,0,208,209,6,11,-1,0,209,245,1,0,0,0,210,211,3,18,9,0,211,212,6,11,
  	-1,0,212,245,1,0,0,0,213,214,5,3,0,0,214,215,5,26,0,0,215,216,3,24,12,
  	0,216,217,3,24,12,0,217,218,3,28,14,0,218,219,5,27,0,0,219,220,3,22,11,
  	0,220,221,6,11,-1,0,221,245,1,0,0,0,222,223,5,1,0,0,223,224,5,26,0,0,
  	224,225,3,28,14,0,225,226,5,27,0,0,226,227,3,22,11,0,227,228,6,11,-1,
  	0,228,245,1,0,0,0,229,230,5,4,0,0,230,231,5,26,0,0,231,232,3,28,14,0,
  	232,233,5,27,0,0,233,234,3,22,11,0,234,235,6,11,-1,0,235,245,1,0,0,0,
  	236,237,5,13,0,0,237,238,3,28,14,0,238,239,5,33,0,0,239,240,6,11,-1,0,
  	240,245,1,0,0,0,241,242,5,13,0,0,242,243,5,33,0,0,243,245,6,11,-1,0,244,
  	204,1,0,0,0,244,207,1,0,0,0,244,210,1,0,0,0,244,213,1,0,0,0,244,222,1,
  	0,0,0,244,229,1,0,0,0,244,236,1,0,0,0,244,241,1,0,0,0,245,23,1,0,0,0,
  	246,247,5,33,0,0,247,253,6,12,-1,0,248,249,3,28,14,0,249,250,5,33,0,0,
  	250,251,6,12,-1,0,251,253,1,0,0,0,252,246,1,0,0,0,252,248,1,0,0,0,253,
  	25,1,0,0,0,254,255,5,38,0,0,255,269,6,13,-1,0,256,257,5,38,0,0,257,258,
  	5,30,0,0,258,259,3,28,14,0,259,260,5,31,0,0,260,261,6,13,-1,0,261,269,
  	1,0,0,0,262,263,5,38,0,0,263,264,5,30,0,0,264,265,3,28,14,0,265,266,5,
  	31,0,0,266,267,6,13,-1,0,267,269,1,0,0,0,268,254,1,0,0,0,268,256,1,0,
  	0,0,268,262,1,0,0,0,269,27,1,0,0,0,270,271,3,30,15,0,271,272,6,14,-1,
  	0,272,279,1,0,0,0,273,274,3,26,13,0,274,275,5,18,0,0,275,276,3,30,15,
  	0,276,277,6,14,-1,0,277,279,1,0,0,0,278,270,1,0,0,0,278,273,1,0,0,0,279,
  	29,1,0,0,0,280,281,3,32,16,0,281,282,6,15,-1,0,282,289,1,0,0,0,283,284,
  	3,32,16,0,284,285,5,21,0,0,285,286,3,32,16,0,286,287,6,15,-1,0,287,289,
  	1,0,0,0,288,280,1,0,0,0,288,283,1,0,0,0,289,31,1,0,0,0,290,291,3,34,17,
  	0,291,292,6,16,-1,0,292,299,1,0,0,0,293,294,3,34,17,0,294,295,5,20,0,
  	0,295,296,3,34,17,0,296,297,6,16,-1,0,297,299,1,0,0,0,298,290,1,0,0,0,
  	298,293,1,0,0,0,299,33,1,0,0,0,300,301,6,17,-1,0,301,302,3,36,18,0,302,
  	303,6,17,-1,0,303,311,1,0,0,0,304,305,10,1,0,0,305,306,5,24,0,0,306,307,
  	3,36,18,0,307,308,6,17,-1,0,308,310,1,0,0,0,309,304,1,0,0,0,310,313,1,
  	0,0,0,311,309,1,0,0,0,311,312,1,0,0,0,312,35,1,0,0,0,313,311,1,0,0,0,
  	314,315,6,18,-1,0,315,316,3,40,20,0,316,317,6,18,-1,0,317,325,1,0,0,0,
  	318,319,10,1,0,0,319,320,5,25,0,0,320,321,3,40,20,0,321,322,6,18,-1,0,
  	322,324,1,0,0,0,323,318,1,0,0,0,324,327,1,0,0,0,325,323,1,0,0,0,325,326,
  	1,0,0,0,326,37,1,0,0,0,327,325,1,0,0,0,328,329,5,24,0,0,329,330,3,38,
  	19,0,330,331,6,19,-1,0,331,340,1,0,0,0,332,333,5,23,0,0,333,334,3,38,
  	19,0,334,335,6,19,-1,0,335,340,1,0,0,0,336,337,3,40,20,0,337,338,6,19,
  	-1,0,338,340,1,0,0,0,339,328,1,0,0,0,339,332,1,0,0,0,339,336,1,0,0,0,
  	340,39,1,0,0,0,341,342,3,26,13,0,342,343,6,20,-1,0,343,364,1,0,0,0,344,
  	345,5,38,0,0,345,346,5,26,0,0,346,347,3,42,21,0,347,348,5,27,0,0,348,
  	349,6,20,-1,0,349,364,1,0,0,0,350,351,5,26,0,0,351,352,3,28,14,0,352,
  	353,5,27,0,0,353,354,6,20,-1,0,354,364,1,0,0,0,355,356,5,34,0,0,356,364,
  	6,20,-1,0,357,358,5,35,0,0,358,364,6,20,-1,0,359,360,3,26,13,0,360,361,
  	5,19,0,0,361,362,6,20,-1,0,362,364,1,0,0,0,363,341,1,0,0,0,363,344,1,
  	0,0,0,363,350,1,0,0,0,363,355,1,0,0,0,363,357,1,0,0,0,363,359,1,0,0,0,
  	364,41,1,0,0,0,365,366,3,28,14,0,366,367,6,21,-1,0,367,375,1,0,0,0,368,
  	369,3,28,14,0,369,370,5,32,0,0,370,371,3,42,21,0,371,372,6,21,-1,0,372,
  	375,1,0,0,0,373,375,6,21,-1,0,374,365,1,0,0,0,374,368,1,0,0,0,374,373,
  	1,0,0,0,375,43,1,0,0,0,24,59,71,84,94,107,109,127,146,159,175,177,189,
  	201,244,252,268,278,288,298,311,325,339,363,374
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105140parserParserStaticData = std::move(staticData);
}

}

C2105140Parser::C2105140Parser(TokenStream *input) : C2105140Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105140Parser::C2105140Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105140Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105140parserParserStaticData->atn, c2105140parserParserStaticData->decisionToDFA, c2105140parserParserStaticData->sharedContextCache, options);
}

C2105140Parser::~C2105140Parser() {
  delete _interpreter;
}

const atn::ATN& C2105140Parser::getATN() const {
  return *c2105140parserParserStaticData->atn;
}

std::string C2105140Parser::getGrammarFileName() const {
  return "C2105140Parser.g4";
}

const std::vector<std::string>& C2105140Parser::getRuleNames() const {
  return c2105140parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105140Parser::getVocabulary() const {
  return c2105140parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105140Parser::getSerializedATN() const {
  return c2105140parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105140Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::StartContext::EOF() {
  return getToken(C2105140Parser::EOF, 0);
}

C2105140Parser::ProgramContext* C2105140Parser::StartContext::program() {
  return getRuleContext<C2105140Parser::ProgramContext>(0);
}


size_t C2105140Parser::StartContext::getRuleIndex() const {
  return C2105140Parser::RuleStart;
}

void C2105140Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105140Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


std::any C2105140Parser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::StartContext* C2105140Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105140Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    initializeFiles();
    setState(45);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);
    setState(46);
    match(C2105140Parser::EOF);

            antlrcpp::downCast<StartContext *>(_localctx)->text =  antlrcpp::downCast<StartContext *>(_localctx)->p->text;
            logRule("start", _localctx->text);
            closeFiles();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105140Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::UnitContext* C2105140Parser::ProgramContext::unit() {
  return getRuleContext<C2105140Parser::UnitContext>(0);
}

C2105140Parser::ProgramContext* C2105140Parser::ProgramContext::program() {
  return getRuleContext<C2105140Parser::ProgramContext>(0);
}


size_t C2105140Parser::ProgramContext::getRuleIndex() const {
  return C2105140Parser::RuleProgram;
}

void C2105140Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105140Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any C2105140Parser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}


C2105140Parser::ProgramContext* C2105140Parser::program() {
   return program(0);
}

C2105140Parser::ProgramContext* C2105140Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105140Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105140Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105140Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(50);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();
     antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text; logRule("program", _localctx->text); 
    _ctx->stop = _input->LT(-1);
    setState(59);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(53);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(54);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();
         antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->text + antlrcpp::downCast<ProgramContext *>(_localctx)->u->text; logRule("program", _localctx->text);  
      }
      setState(61);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105140Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::Var_declarationContext* C2105140Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105140Parser::Var_declarationContext>(0);
}

C2105140Parser::Func_declarationContext* C2105140Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105140Parser::Func_declarationContext>(0);
}

C2105140Parser::Func_definitionContext* C2105140Parser::UnitContext::func_definition() {
  return getRuleContext<C2105140Parser::Func_definitionContext>(0);
}


size_t C2105140Parser::UnitContext::getRuleIndex() const {
  return C2105140Parser::RuleUnit;
}

void C2105140Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105140Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}


std::any C2105140Parser::UnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitUnit(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::UnitContext* C2105140Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105140Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      antlrcpp::downCast<UnitContext *>(_localctx)->v = var_declaration();
       antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->v->text; logRule("unit", _localctx->text); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(65);
      antlrcpp::downCast<UnitContext *>(_localctx)->fd = func_declaration();
       antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->text; logRule("unit", _localctx->text); 
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(68);
      antlrcpp::downCast<UnitContext *>(_localctx)->ff = func_definition();
       antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->ff->text; logRule("unit", _localctx->text); 
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105140Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105140Parser::SEMICOLON, 0);
}

C2105140Parser::Type_specifierContext* C2105140Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105140Parser::Type_specifierContext>(0);
}

C2105140Parser::Declaration_listContext* C2105140Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105140Parser::Declaration_listContext>(0);
}


size_t C2105140Parser::Var_declarationContext::getRuleIndex() const {
  return C2105140Parser::RuleVar_declaration;
}

void C2105140Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105140Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}


std::any C2105140Parser::Var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitVar_declaration(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Var_declarationContext* C2105140Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105140Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
    setState(74);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
    setState(75);
    match(C2105140Parser::SEMICOLON);

            antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + ";";
            logRule("var_declaration", _localctx->text);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105140Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Type_specifierContext::INT() {
  return getToken(C2105140Parser::INT, 0);
}

tree::TerminalNode* C2105140Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105140Parser::FLOAT, 0);
}

tree::TerminalNode* C2105140Parser::Type_specifierContext::VOID() {
  return getToken(C2105140Parser::VOID, 0);
}


size_t C2105140Parser::Type_specifierContext::getRuleIndex() const {
  return C2105140Parser::RuleType_specifier;
}

void C2105140Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105140Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}


std::any C2105140Parser::Type_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitType_specifier(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Type_specifierContext* C2105140Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105140Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105140Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        match(C2105140Parser::INT);
         antlrcpp::downCast<Type_specifierContext *>(_localctx)->varType =  "INT"; antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  "int"; logRule("type_specifier", _localctx->text); 
        break;
      }

      case C2105140Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(80);
        match(C2105140Parser::FLOAT);
         antlrcpp::downCast<Type_specifierContext *>(_localctx)->varType =  "FLOAT"; antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  "float"; logRule("type_specifier", _localctx->text); 
        break;
      }

      case C2105140Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(82);
        match(C2105140Parser::VOID);
         antlrcpp::downCast<Type_specifierContext *>(_localctx)->varType =  "VOID"; antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  "void"; logRule("type_specifier", _localctx->text); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105140Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Declaration_listContext::ID() {
  return getToken(C2105140Parser::ID, 0);
}

tree::TerminalNode* C2105140Parser::Declaration_listContext::LSQUARE() {
  return getToken(C2105140Parser::LSQUARE, 0);
}

tree::TerminalNode* C2105140Parser::Declaration_listContext::RSQUARE() {
  return getToken(C2105140Parser::RSQUARE, 0);
}

tree::TerminalNode* C2105140Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105140Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105140Parser::Declaration_listContext::COMMA() {
  return getToken(C2105140Parser::COMMA, 0);
}

C2105140Parser::Declaration_listContext* C2105140Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105140Parser::Declaration_listContext>(0);
}


size_t C2105140Parser::Declaration_listContext::getRuleIndex() const {
  return C2105140Parser::RuleDeclaration_list;
}

void C2105140Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105140Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


std::any C2105140Parser::Declaration_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration_list(this);
  else
    return visitor->visitChildren(this);
}


C2105140Parser::Declaration_listContext* C2105140Parser::declaration_list() {
   return declaration_list(0);
}

C2105140Parser::Declaration_listContext* C2105140Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105140Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105140Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C2105140Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(87);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105140Parser::ID);

              SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : ""), "ID");
              symbol->varType = "INT";
              symbol->lineNo = (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0);
              if (!symbolTable.insert(symbol)) {
                  logError((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0), "Redefinition of variable '" + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "") + "'");
              }
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "");
              logRule("declaration_list", _localctx->text);
          
      break;
    }

    case 2: {
      setState(89);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(90);
      match(C2105140Parser::LSQUARE);
      setState(91);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci = match(C2105140Parser::CONST_INT);
      setState(92);
      match(C2105140Parser::RSQUARE);

              SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : ""), "ID");
              symbol->varType = "INT";
              symbol->isArray = true;
              symbol->arraySize = stoi((antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() : ""));
              symbol->lineNo = (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0);
              if (!symbolTable.insert(symbol)) {
                  logError((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0), "Redefinition of variable '" + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "") + "'");
              }
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "") + "[" + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() : "") + "]";
              logRule("declaration_list", _localctx->text);
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(109);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(107);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(96);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(97);
          match(C2105140Parser::COMMA);
          setState(98);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105140Parser::ID);

                            SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : ""), "ID");
                            symbol->varType = "INT";
                            symbol->lineNo = (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0);
                            if (!symbolTable.insert(symbol)) {
                                logError((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0), "Redefinition of variable '" + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "") + "'");
                            }
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + "," + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "");
                            logRule("declaration_list", _localctx->text);
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(100);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(101);
          match(C2105140Parser::COMMA);
          setState(102);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105140Parser::ID);
          setState(103);
          match(C2105140Parser::LSQUARE);
          setState(104);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci = match(C2105140Parser::CONST_INT);
          setState(105);
          match(C2105140Parser::RSQUARE);

                            SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : ""), "ID");
                            symbol->varType = "INT";
                            symbol->isArray = true;
                            symbol->arraySize = stoi((antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() : ""));
                            symbol->lineNo = (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0);
                            if (!symbolTable.insert(symbol)) {
                                logError((antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine() : 0), "Redefinition of variable '" + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "") + "'");
                            }
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + "," + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() : "") + "[" + (antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci != nullptr ? antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() : "") + "]";
                            logRule("declaration_list", _localctx->text);
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(111);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105140Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105140Parser::LPAREN, 0);
}

tree::TerminalNode* C2105140Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105140Parser::RPAREN, 0);
}

tree::TerminalNode* C2105140Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105140Parser::SEMICOLON, 0);
}

C2105140Parser::Type_specifierContext* C2105140Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105140Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105140Parser::Func_declarationContext::ID() {
  return getToken(C2105140Parser::ID, 0);
}

C2105140Parser::Parameter_listContext* C2105140Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105140Parser::Parameter_listContext>(0);
}


size_t C2105140Parser::Func_declarationContext::getRuleIndex() const {
  return C2105140Parser::RuleFunc_declaration;
}

void C2105140Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105140Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}


std::any C2105140Parser::Func_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitFunc_declaration(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Func_declarationContext* C2105140Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105140Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(112);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(113);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(114);
      match(C2105140Parser::LPAREN);
      setState(115);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(116);
      match(C2105140Parser::RPAREN);
      setState(117);
      match(C2105140Parser::SEMICOLON);

              SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : ""), "ID");
              symbol->isFunction = true;
              symbol->returnType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->varType;
              symbol->isDeclared = true;
              symbol->lineNo = (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine() : 0);
              if (!symbolTable.insert(symbol)) {
                  SymbolInfo* existing = symbolTable.lookup((antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : ""));
                  if (existing && existing->isFunction) {
                      if (existing->returnType != symbol->returnType) {
                          logError((antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine() : 0), "Conflicting return type for function '" + (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : "") + "'");
                      }
                  } else {
                      logError((antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine() : 0), "Redefinition of function '" + (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : "") + "'");
                  }
              }
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : "") + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->text + ");";
              logRule("func_declaration", _localctx->text);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(121);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(122);
      match(C2105140Parser::LPAREN);
      setState(123);
      match(C2105140Parser::RPAREN);
      setState(124);
      match(C2105140Parser::SEMICOLON);

              SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : ""), "ID");
              symbol->isFunction = true;
              symbol->returnType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->varType;
              symbol->isDeclared = true;
              symbol->lineNo = (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine() : 0);
              if (!symbolTable.insert(symbol)) {
                  logError((antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine() : 0), "Redefinition of function '" + (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : "") + "'");
              }
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Func_declarationContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() : "") + "();";
              logRule("func_declaration", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105140Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105140Parser::LPAREN, 0);
}

tree::TerminalNode* C2105140Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105140Parser::RPAREN, 0);
}

C2105140Parser::Type_specifierContext* C2105140Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105140Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105140Parser::Func_definitionContext::ID() {
  return getToken(C2105140Parser::ID, 0);
}

C2105140Parser::Parameter_listContext* C2105140Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105140Parser::Parameter_listContext>(0);
}

C2105140Parser::Compound_statementContext* C2105140Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105140Parser::Compound_statementContext>(0);
}


size_t C2105140Parser::Func_definitionContext::getRuleIndex() const {
  return C2105140Parser::RuleFunc_definition;
}

void C2105140Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105140Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}


std::any C2105140Parser::Func_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitFunc_definition(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Func_definitionContext* C2105140Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 14, C2105140Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(129);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(130);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(131);
      match(C2105140Parser::LPAREN);
      setState(132);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      setState(133);
      match(C2105140Parser::RPAREN);

              SymbolInfo* symbol = symbolTable.lookup((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : ""));
              if (!symbol) {
                  symbol = new SymbolInfo((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : ""), "ID");
                  symbol->isFunction = true;
                  symbol->returnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->varType;
                  symbol->isDefined = true;
                  symbolTable.insert(symbol);
              } else {
                  if (symbol->isDefined) {
                      logError((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine() : 0), "Redefinition of function '" + (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : "") + "'");
                  } else {
                      symbol->isDefined = true;
                      if (symbol->returnType != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->varType) {
                          logError((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine() : 0), "Conflicting return type for function '" + (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : "") + "'");
                      }
                  }
              }
              currentReturnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->varType;
              insideFunction = true;
              symbolTable.enterScope();
          
      setState(135);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

              symbolTable.printScope();
              symbolTable.exitScope();
              insideFunction = false;
              currentReturnType = "";
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : "") + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text + ") " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              logRule("func_definition", _localctx->text);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(139);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(140);
      match(C2105140Parser::LPAREN);
      setState(141);
      match(C2105140Parser::RPAREN);

              SymbolInfo* symbol = symbolTable.lookup((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : ""));
              if (!symbol) {
                  symbol = new SymbolInfo((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : ""), "ID");
                  symbol->isFunction = true;
                  symbol->returnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->varType;
                  symbol->isDefined = true;
                  symbolTable.insert(symbol);
              } else {
                  if (symbol->isDefined) {
                      logError((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine() : 0), "Redefinition of function '" + (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : "") + "'");
                  } else {
                      symbol->isDefined = true;
                      if (symbol->returnType != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->varType) {
                          logError((antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine() : 0), "Conflicting return type for function '" + (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : "") + "'");
                      }
                  }
              }
              currentReturnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->varType;
              insideFunction = true;
              symbolTable.enterScope();
          
      setState(143);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

              symbolTable.printScope();
              symbolTable.exitScope();
              insideFunction = false;
              currentReturnType = "";
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() : "") + "() " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              logRule("func_definition", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105140Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::Type_specifierContext* C2105140Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105140Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105140Parser::Parameter_listContext::ID() {
  return getToken(C2105140Parser::ID, 0);
}

tree::TerminalNode* C2105140Parser::Parameter_listContext::LSQUARE() {
  return getToken(C2105140Parser::LSQUARE, 0);
}

tree::TerminalNode* C2105140Parser::Parameter_listContext::RSQUARE() {
  return getToken(C2105140Parser::RSQUARE, 0);
}

tree::TerminalNode* C2105140Parser::Parameter_listContext::COMMA() {
  return getToken(C2105140Parser::COMMA, 0);
}

C2105140Parser::Parameter_listContext* C2105140Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105140Parser::Parameter_listContext>(0);
}


size_t C2105140Parser::Parameter_listContext::getRuleIndex() const {
  return C2105140Parser::RuleParameter_list;
}

void C2105140Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105140Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


std::any C2105140Parser::Parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitParameter_list(this);
  else
    return visitor->visitChildren(this);
}


C2105140Parser::Parameter_listContext* C2105140Parser::parameter_list() {
   return parameter_list(0);
}

C2105140Parser::Parameter_listContext* C2105140Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105140Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105140Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, C2105140Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(149);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(150);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105140Parser::ID);

              SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : ""), "ID");
              symbol->varType = antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->varType;
              symbolTable.insert(symbol);
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : "");
              logRule("parameter_list", _localctx->text);
          
      break;
    }

    case 2: {
      setState(153);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(154);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(155);
      match(C2105140Parser::LSQUARE);
      setState(156);
      match(C2105140Parser::RSQUARE);

              SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : ""), "ID");
              symbol->varType = antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->varType;
              symbol->isArray = true;
              symbolTable.insert(symbol);
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : "") + "[]";
              logRule("parameter_list", _localctx->text);
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(175);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(161);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(162);
          match(C2105140Parser::COMMA);
          setState(163);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
          setState(164);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105140Parser::ID);

                            SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : ""), "ID");
                            symbol->varType = antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->varType;
                            symbolTable.insert(symbol);
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : "");
                            logRule("parameter_list", _localctx->text);
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(167);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(168);
          match(C2105140Parser::COMMA);
          setState(169);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
          setState(170);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105140Parser::ID);
          setState(171);
          match(C2105140Parser::LSQUARE);
          setState(172);
          match(C2105140Parser::RSQUARE);

                            SymbolInfo* symbol = new SymbolInfo((antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : ""), "ID");
                            symbol->varType = antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->varType;
                            symbol->isArray = true;
                            symbolTable.insert(symbol);
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + (antlrcpp::downCast<Parameter_listContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() : "") + "[]";
                            logRule("parameter_list", _localctx->text);
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105140Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Compound_statementContext::LCURL() {
  return getToken(C2105140Parser::LCURL, 0);
}

tree::TerminalNode* C2105140Parser::Compound_statementContext::RCURL() {
  return getToken(C2105140Parser::RCURL, 0);
}

C2105140Parser::StatementsContext* C2105140Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105140Parser::StatementsContext>(0);
}


size_t C2105140Parser::Compound_statementContext::getRuleIndex() const {
  return C2105140Parser::RuleCompound_statement;
}

void C2105140Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105140Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}


std::any C2105140Parser::Compound_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitCompound_statement(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Compound_statementContext* C2105140Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105140Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(180);
      match(C2105140Parser::LCURL);
       symbolTable.enterScope(); 
      setState(182);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(183);
      match(C2105140Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  "{" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->s->text + "}";
              symbolTable.printScope();
              symbolTable.exitScope();
              logRule("compound_statement", _localctx->text);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(186);
      match(C2105140Parser::LCURL);
      setState(187);
      match(C2105140Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  "{}";
              logRule("compound_statement", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105140Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::StatementContext* C2105140Parser::StatementsContext::statement() {
  return getRuleContext<C2105140Parser::StatementContext>(0);
}

C2105140Parser::StatementsContext* C2105140Parser::StatementsContext::statements() {
  return getRuleContext<C2105140Parser::StatementsContext>(0);
}


size_t C2105140Parser::StatementsContext::getRuleIndex() const {
  return C2105140Parser::RuleStatements;
}

void C2105140Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105140Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


std::any C2105140Parser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}


C2105140Parser::StatementsContext* C2105140Parser::statements() {
   return statements(0);
}

C2105140Parser::StatementsContext* C2105140Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105140Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105140Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C2105140Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(192);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();
     antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text; logRule("statements", _localctx->text); 
    _ctx->stop = _input->LT(-1);
    setState(201);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->s1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(195);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(196);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s2 = statement();
         antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s1->text + " " + antlrcpp::downCast<StatementsContext *>(_localctx)->s2->text; logRule("statements", _localctx->text);  
      }
      setState(203);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105140Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::Var_declarationContext* C2105140Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105140Parser::Var_declarationContext>(0);
}

std::vector<C2105140Parser::Expression_statementContext *> C2105140Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105140Parser::Expression_statementContext>();
}

C2105140Parser::Expression_statementContext* C2105140Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105140Parser::Expression_statementContext>(i);
}

C2105140Parser::Compound_statementContext* C2105140Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105140Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105140Parser::StatementContext::FOR() {
  return getToken(C2105140Parser::FOR, 0);
}

tree::TerminalNode* C2105140Parser::StatementContext::LPAREN() {
  return getToken(C2105140Parser::LPAREN, 0);
}

tree::TerminalNode* C2105140Parser::StatementContext::RPAREN() {
  return getToken(C2105140Parser::RPAREN, 0);
}

C2105140Parser::ExpressionContext* C2105140Parser::StatementContext::expression() {
  return getRuleContext<C2105140Parser::ExpressionContext>(0);
}

C2105140Parser::StatementContext* C2105140Parser::StatementContext::statement() {
  return getRuleContext<C2105140Parser::StatementContext>(0);
}

tree::TerminalNode* C2105140Parser::StatementContext::IF() {
  return getToken(C2105140Parser::IF, 0);
}

tree::TerminalNode* C2105140Parser::StatementContext::WHILE() {
  return getToken(C2105140Parser::WHILE, 0);
}

tree::TerminalNode* C2105140Parser::StatementContext::RETURN() {
  return getToken(C2105140Parser::RETURN, 0);
}

tree::TerminalNode* C2105140Parser::StatementContext::SEMICOLON() {
  return getToken(C2105140Parser::SEMICOLON, 0);
}


size_t C2105140Parser::StatementContext::getRuleIndex() const {
  return C2105140Parser::RuleStatement;
}

void C2105140Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105140Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any C2105140Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::StatementContext* C2105140Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, C2105140Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(204);
      antlrcpp::downCast<StatementContext *>(_localctx)->v = var_declaration();
       antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->v->text; logRule("statement", _localctx->text); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(207);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();
       antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text; logRule("statement", _localctx->text); 
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(210);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement();
       antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->text; logRule("statement", _localctx->text); 
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(213);
      match(C2105140Parser::FOR);
      setState(214);
      match(C2105140Parser::LPAREN);
      setState(215);
      antlrcpp::downCast<StatementContext *>(_localctx)->e1 = expression_statement();
      setState(216);
      antlrcpp::downCast<StatementContext *>(_localctx)->e2 = expression_statement();
      setState(217);
      antlrcpp::downCast<StatementContext *>(_localctx)->e3 = expression();
      setState(218);
      match(C2105140Parser::RPAREN);
      setState(219);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "for(" + antlrcpp::downCast<StatementContext *>(_localctx)->e1->text + antlrcpp::downCast<StatementContext *>(_localctx)->e2->text + antlrcpp::downCast<StatementContext *>(_localctx)->e3->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              logRule("statement", _localctx->text);
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(222);
      match(C2105140Parser::IF);
      setState(223);
      match(C2105140Parser::LPAREN);
      setState(224);
      antlrcpp::downCast<StatementContext *>(_localctx)->ei = expression();
      setState(225);
      match(C2105140Parser::RPAREN);
      setState(226);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->ei->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              logRule("statement", _localctx->text);
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(229);
      match(C2105140Parser::WHILE);
      setState(230);
      match(C2105140Parser::LPAREN);
      setState(231);
      antlrcpp::downCast<StatementContext *>(_localctx)->ew = expression();
      setState(232);
      match(C2105140Parser::RPAREN);
      setState(233);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "while(" + antlrcpp::downCast<StatementContext *>(_localctx)->ew->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              logRule("statement", _localctx->text);
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(236);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105140Parser::RETURN);
      setState(237);
      antlrcpp::downCast<StatementContext *>(_localctx)->er = expression();
      setState(238);
      match(C2105140Parser::SEMICOLON);

              if (!insideFunction) {
                  logError((antlrcpp::downCast<StatementContext *>(_localctx)->returnToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine() : 0), "Return statement outside function");
              } else {
                  if (currentReturnType == "VOID") {
                      logError((antlrcpp::downCast<StatementContext *>(_localctx)->returnToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine() : 0), "Return with value in void function");
                  } else if (currentReturnType != antlrcpp::downCast<StatementContext *>(_localctx)->er->exprType) {
                      if (currentReturnType == "INT" && antlrcpp::downCast<StatementContext *>(_localctx)->er->exprType == "FLOAT") {
                          logError((antlrcpp::downCast<StatementContext *>(_localctx)->returnToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine() : 0), "Warning: possible loss of data in return");
                      }
                  }
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "return " + antlrcpp::downCast<StatementContext *>(_localctx)->er->text + ";";
              logRule("statement", _localctx->text);
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(241);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105140Parser::RETURN);
      setState(242);
      match(C2105140Parser::SEMICOLON);

              if (!insideFunction) {
                  logError((antlrcpp::downCast<StatementContext *>(_localctx)->returnToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine() : 0), "Return statement outside function");
              } else {
                  if (currentReturnType != "VOID") {
                      logError((antlrcpp::downCast<StatementContext *>(_localctx)->returnToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine() : 0), "Return without value in non-void function");
                  }
              }
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "return;";
              logRule("statement", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105140Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105140Parser::SEMICOLON, 0);
}

C2105140Parser::ExpressionContext* C2105140Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105140Parser::ExpressionContext>(0);
}


size_t C2105140Parser::Expression_statementContext::getRuleIndex() const {
  return C2105140Parser::RuleExpression_statement;
}

void C2105140Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105140Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}


std::any C2105140Parser::Expression_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitExpression_statement(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Expression_statementContext* C2105140Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, C2105140Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105140Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(246);
        match(C2105140Parser::SEMICOLON);
         antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  ";"; logRule("expression_statement", _localctx->text); 
        break;
      }

      case C2105140Parser::LPAREN:
      case C2105140Parser::CONST_INT:
      case C2105140Parser::CONST_FLOAT:
      case C2105140Parser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(248);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(249);
        match(C2105140Parser::SEMICOLON);
         antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text + ";"; logRule("expression_statement", _localctx->text); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105140Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::VariableContext::ID() {
  return getToken(C2105140Parser::ID, 0);
}

tree::TerminalNode* C2105140Parser::VariableContext::LSQUARE() {
  return getToken(C2105140Parser::LSQUARE, 0);
}

tree::TerminalNode* C2105140Parser::VariableContext::RSQUARE() {
  return getToken(C2105140Parser::RSQUARE, 0);
}

C2105140Parser::ExpressionContext* C2105140Parser::VariableContext::expression() {
  return getRuleContext<C2105140Parser::ExpressionContext>(0);
}


size_t C2105140Parser::VariableContext::getRuleIndex() const {
  return C2105140Parser::RuleVariable;
}

void C2105140Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105140Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}


std::any C2105140Parser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::VariableContext* C2105140Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105140Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(254);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105140Parser::ID);

              SymbolInfo* symbol = symbolTable.lookup((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : ""));
              if (!symbol) {
                  logError((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine() : 0), "Undeclared variable '" + (antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : "") + "'");
                  antlrcpp::downCast<VariableContext *>(_localctx)->varType =  "INT";
              } else {
                  if (symbol->isArray) {
                      logError((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine() : 0), "Array '" + (antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : "") + "' used without index");
                  }
                  antlrcpp::downCast<VariableContext *>(_localctx)->varType =  symbol->varType;
              }
              antlrcpp::downCast<VariableContext *>(_localctx)->text =  (antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : "");
              logRule("variable", _localctx->text);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(256);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105140Parser::ID);
      setState(257);
      match(C2105140Parser::LSQUARE);
      setState(258);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(259);
      match(C2105140Parser::RSQUARE);

              SymbolInfo* symbol = symbolTable.lookup((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : ""));
              if (!symbol) {
                  logError((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine() : 0), "Undeclared variable '" + (antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : "") + "'");
                  antlrcpp::downCast<VariableContext *>(_localctx)->varType =  "INT";
              } else {
                  if (!symbol->isArray) {
                      logError((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine() : 0), "'" + (antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : "") + "' is not an array");
                  }
                  antlrcpp::downCast<VariableContext *>(_localctx)->varType =  symbol->varType;
              }
              if (antlrcpp::downCast<VariableContext *>(_localctx)->e->exprType != "INT") {
                  logError((antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine() : 0), "Array subscript is not an integer");
              }
              antlrcpp::downCast<VariableContext *>(_localctx)->text =  (antlrcpp::downCast<VariableContext *>(_localctx)->id != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() : "") + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->e->text + "]";
              logRule("variable", _localctx->text);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(262);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105140Parser::ID);
      setState(263);
      match(C2105140Parser::LSQUARE);
      setState(264);
      antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext = expression();
      setState(265);
      match(C2105140Parser::RSQUARE);

              SymbolInfo* symbol = symbolTable.lookup((antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() : ""));
              if (!symbol) {
                  logError((antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine() : 0), "Undeclared variable '" + (antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() : "") + "'");
                  antlrcpp::downCast<VariableContext *>(_localctx)->varType =  "INT";
              } else {
                  if (!symbol->isArray) {
                      logError((antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine() : 0), "'" + (antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() : "") + "' is not an array");
                  }
                  antlrcpp::downCast<VariableContext *>(_localctx)->varType =  symbol->varType;
              }
              if (antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->exprType != "INT") {
                  logError((antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine() : 0), "Array subscript is not an integer");
              }
              antlrcpp::downCast<VariableContext *>(_localctx)->text =  (antlrcpp::downCast<VariableContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() : "") + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->text + "]";
              logRule("variable", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105140Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::Logic_expressionContext* C2105140Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105140Parser::Logic_expressionContext>(0);
}

C2105140Parser::VariableContext* C2105140Parser::ExpressionContext::variable() {
  return getRuleContext<C2105140Parser::VariableContext>(0);
}

tree::TerminalNode* C2105140Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105140Parser::ASSIGNOP, 0);
}


size_t C2105140Parser::ExpressionContext::getRuleIndex() const {
  return C2105140Parser::RuleExpression;
}

void C2105140Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105140Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any C2105140Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::ExpressionContext* C2105140Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105140Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(270);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext = logic_expression();
       antlrcpp::downCast<ExpressionContext *>(_localctx)->exprType =  antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->exprType; antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->text; logRule("expression", _localctx->text); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext = variable();
      setState(274);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105140Parser::ASSIGNOP);
      setState(275);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext = logic_expression();

              if (antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->varType != antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->exprType) {
                  if (antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->varType == "INT" && antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->exprType == "FLOAT") {
                      logError((antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken != nullptr ? antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine() : 0), "Warning: possible loss of data in assignment of FLOAT to INT");
                  }
              }
              antlrcpp::downCast<ExpressionContext *>(_localctx)->exprType =  antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->varType;
              antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->text + "=" + antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->text;
              logRule("expression", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105140Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105140Parser::Rel_expressionContext *> C2105140Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105140Parser::Rel_expressionContext>();
}

C2105140Parser::Rel_expressionContext* C2105140Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105140Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105140Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105140Parser::LOGICOP, 0);
}


size_t C2105140Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105140Parser::RuleLogic_expression;
}

void C2105140Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105140Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}


std::any C2105140Parser::Logic_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitLogic_expression(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Logic_expressionContext* C2105140Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105140Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(280);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();
       
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->exprType =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->exprType; 
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->text; 
              logRule("logic_expression", _localctx->text); 
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(283);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->left = rel_expression();
      setState(284);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105140Parser::LOGICOP);
      setState(285);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->right = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->exprType =  "INT";
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->left->text + (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken != nullptr ? antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() : "") + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->right->text;
              logRule("logic_expression", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105140Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105140Parser::Simple_expressionContext *> C2105140Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105140Parser::Simple_expressionContext>();
}

C2105140Parser::Simple_expressionContext* C2105140Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105140Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105140Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105140Parser::RELOP, 0);
}


size_t C2105140Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105140Parser::RuleRel_expression;
}

void C2105140Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105140Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}


std::any C2105140Parser::Rel_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitRel_expression(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Rel_expressionContext* C2105140Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105140Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(290);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext = simple_expression(0);
       
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->exprType =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->exprType; 
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->text; 
              logRule("rel_expression", _localctx->text); 
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(293);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->left = simple_expression(0);
      setState(294);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105140Parser::RELOP);
      setState(295);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->right = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->exprType =  "INT";
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->left->text + (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken != nullptr ? antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() : "") + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->right->text;
              logRule("rel_expression", _localctx->text);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105140Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::TermContext* C2105140Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105140Parser::TermContext>(0);
}

tree::TerminalNode* C2105140Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105140Parser::ADDOP, 0);
}

C2105140Parser::Simple_expressionContext* C2105140Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105140Parser::Simple_expressionContext>(0);
}


size_t C2105140Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105140Parser::RuleSimple_expression;
}

void C2105140Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105140Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


std::any C2105140Parser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}


C2105140Parser::Simple_expressionContext* C2105140Parser::simple_expression() {
   return simple_expression(0);
}

C2105140Parser::Simple_expressionContext* C2105140Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105140Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105140Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, C2105140Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(301);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);
     
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->exprType =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->exprType; 
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->text; 
            logRule("simple_expression", _localctx->text); 
        
    _ctx->stop = _input->LT(-1);
    setState(311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->left = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(304);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(305);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105140Parser::ADDOP);
        setState(306);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->right = antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);

                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->exprType =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->left->exprType;
                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->left->text + (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken != nullptr ? antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() : "") + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->right->text;
                          logRule("simple_expression", _localctx->text);
                       
      }
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105140Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::FactorContext* C2105140Parser::TermContext::factor() {
  return getRuleContext<C2105140Parser::FactorContext>(0);
}

tree::TerminalNode* C2105140Parser::TermContext::MULOP() {
  return getToken(C2105140Parser::MULOP, 0);
}

C2105140Parser::TermContext* C2105140Parser::TermContext::term() {
  return getRuleContext<C2105140Parser::TermContext>(0);
}


size_t C2105140Parser::TermContext::getRuleIndex() const {
  return C2105140Parser::RuleTerm;
}

void C2105140Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105140Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any C2105140Parser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


C2105140Parser::TermContext* C2105140Parser::term() {
   return term(0);
}

C2105140Parser::TermContext* C2105140Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105140Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105140Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C2105140Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(315);
    antlrcpp::downCast<TermContext *>(_localctx)->factorContext = factor();
     
            antlrcpp::downCast<TermContext *>(_localctx)->exprType =  antlrcpp::downCast<TermContext *>(_localctx)->factorContext->exprType; 
            antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->factorContext->text; 
            logRule("term", _localctx->text); 
        
    _ctx->stop = _input->LT(-1);
    setState(325);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->left = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(318);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(319);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105140Parser::MULOP);
        setState(320);
        antlrcpp::downCast<TermContext *>(_localctx)->right = antlrcpp::downCast<TermContext *>(_localctx)->factorContext = factor();

                          antlrcpp::downCast<TermContext *>(_localctx)->exprType =  antlrcpp::downCast<TermContext *>(_localctx)->left->exprType;
                          antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->left->text + (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken != nullptr ? antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() : "") + antlrcpp::downCast<TermContext *>(_localctx)->right->text;
                          logRule("term", _localctx->text);
                       
      }
      setState(327);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105140Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105140Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105140Parser::ADDOP, 0);
}

C2105140Parser::Unary_expressionContext* C2105140Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105140Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105140Parser::Unary_expressionContext::NOT() {
  return getToken(C2105140Parser::NOT, 0);
}

C2105140Parser::FactorContext* C2105140Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105140Parser::FactorContext>(0);
}


size_t C2105140Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105140Parser::RuleUnary_expression;
}

void C2105140Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105140Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}


std::any C2105140Parser::Unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitUnary_expression(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::Unary_expressionContext* C2105140Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, C2105140Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(339);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105140Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(328);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105140Parser::ADDOP);
        setState(329);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->exprType =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->exprType;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken != nullptr ? antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() : "") + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->text;
                logRule("unary_expression", _localctx->text);
            
        break;
      }

      case C2105140Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(332);
        match(C2105140Parser::NOT);
        setState(333);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->exprType =  "INT";
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  "!" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->text;
                logRule("unary_expression", _localctx->text);
            
        break;
      }

      case C2105140Parser::LPAREN:
      case C2105140Parser::CONST_INT:
      case C2105140Parser::CONST_FLOAT:
      case C2105140Parser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(336);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext = factor();
         antlrcpp::downCast<Unary_expressionContext *>(_localctx)->exprType =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->exprType; antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->text; logRule("unary_expression", _localctx->text); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105140Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::VariableContext* C2105140Parser::FactorContext::variable() {
  return getRuleContext<C2105140Parser::VariableContext>(0);
}

tree::TerminalNode* C2105140Parser::FactorContext::ID() {
  return getToken(C2105140Parser::ID, 0);
}

tree::TerminalNode* C2105140Parser::FactorContext::LPAREN() {
  return getToken(C2105140Parser::LPAREN, 0);
}

C2105140Parser::ArgumentsContext* C2105140Parser::FactorContext::arguments() {
  return getRuleContext<C2105140Parser::ArgumentsContext>(0);
}

tree::TerminalNode* C2105140Parser::FactorContext::RPAREN() {
  return getToken(C2105140Parser::RPAREN, 0);
}

C2105140Parser::ExpressionContext* C2105140Parser::FactorContext::expression() {
  return getRuleContext<C2105140Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105140Parser::FactorContext::CONST_INT() {
  return getToken(C2105140Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105140Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105140Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105140Parser::FactorContext::INCOP() {
  return getToken(C2105140Parser::INCOP, 0);
}


size_t C2105140Parser::FactorContext::getRuleIndex() const {
  return C2105140Parser::RuleFactor;
}

void C2105140Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105140Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any C2105140Parser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::FactorContext* C2105140Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, C2105140Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(341);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
       antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varType; antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->text; logRule("factor", _localctx->text); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(344);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105140Parser::ID);
      setState(345);
      match(C2105140Parser::LPAREN);
      setState(346);
      antlrcpp::downCast<FactorContext *>(_localctx)->argumentsContext = arguments();
      setState(347);
      match(C2105140Parser::RPAREN);

              SymbolInfo* symbol = symbolTable.lookup((antlrcpp::downCast<FactorContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() : ""));
              if (!symbol) {
                  logError((antlrcpp::downCast<FactorContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine() : 0), "Undeclared function '" + (antlrcpp::downCast<FactorContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() : "") + "'");
                  antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  "INT";
              } else {
                  if (!symbol->isFunction) {
                      logError((antlrcpp::downCast<FactorContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine() : 0), "'" + (antlrcpp::downCast<FactorContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() : "") + "' is not a function");
                      antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  "INT";
                  } else {
                      antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  symbol->returnType;
                  }
              }
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  (antlrcpp::downCast<FactorContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() : "") + "(" + antlrcpp::downCast<FactorContext *>(_localctx)->argumentsContext->text + ")";
              logRule("factor", _localctx->text);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(350);
      match(C2105140Parser::LPAREN);
      setState(351);
      antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext = expression();
      setState(352);
      match(C2105140Parser::RPAREN);
       antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext->exprType; antlrcpp::downCast<FactorContext *>(_localctx)->text =  "(" + antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext->text + ")"; logRule("factor", _localctx->text); 
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(355);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C2105140Parser::CONST_INT);
       antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  "INT"; antlrcpp::downCast<FactorContext *>(_localctx)->text =  (antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText() : ""); logRule("factor", _localctx->text); 
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(357);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C2105140Parser::CONST_FLOAT);
       antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  "FLOAT"; antlrcpp::downCast<FactorContext *>(_localctx)->text =  (antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText() : ""); logRule("factor", _localctx->text); 
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(359);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(360);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C2105140Parser::INCOP);
       antlrcpp::downCast<FactorContext *>(_localctx)->exprType =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->varType; antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->text + (antlrcpp::downCast<FactorContext *>(_localctx)->incopToken != nullptr ? antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText() : ""); logRule("factor", _localctx->text); 
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105140Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105140Parser::ExpressionContext* C2105140Parser::ArgumentsContext::expression() {
  return getRuleContext<C2105140Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105140Parser::ArgumentsContext::COMMA() {
  return getToken(C2105140Parser::COMMA, 0);
}

C2105140Parser::ArgumentsContext* C2105140Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105140Parser::ArgumentsContext>(0);
}


size_t C2105140Parser::ArgumentsContext::getRuleIndex() const {
  return C2105140Parser::RuleArguments;
}

void C2105140Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105140Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105140ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any C2105140Parser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C2105140ParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

C2105140Parser::ArgumentsContext* C2105140Parser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105140Parser::RuleArguments);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(374);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(365);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->expr1 = expression();
       
              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->expr1->text; 
              logRule("arguments", _localctx->text); 
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(368);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->expr1 = expression();
      setState(369);
      match(C2105140Parser::COMMA);
      setState(370);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->rest = arguments();

              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->expr1->text + "," + antlrcpp::downCast<ArgumentsContext *>(_localctx)->rest->text;
              logRule("arguments", _localctx->text);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
       
              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  ""; 
              logRule("arguments", _localctx->text); 
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool C2105140Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 8: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105140Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105140Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105140Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105140Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105140Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105140Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void C2105140Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105140parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105140parserParserOnceFlag, c2105140parserParserInitialize);
#endif
}
