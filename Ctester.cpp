#include <iostream>
#include "antlr4-runtime.h"
#include "C2105140Lexer.h"
#include "C2105140Parser.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source.c>" << std::endl;
        return 1;
    }

    try {
        ANTLRFileStream input;
        input.loadFromFile(argv[1]);

        C2105140Lexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        C2105140Parser parser(&tokens);

        // Parse from the top-level rule, assumed "program"
        tree::ParseTree* tree = parser.program();

        std::cout << "=== Parse Tree ===" << std::endl;
        std::cout << tree->toStringTree(&parser) << std::endl;
    } catch (std::exception& e) {
        std::cerr << "❌ Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
