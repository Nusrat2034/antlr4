#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "C2105140Lexer.h"
#include "C2105140Parser.h"
#include "SymbolTable.h"

using namespace std;
using namespace antlr4;

// Global variables that the parser expects
SymbolTable symbolTable;
ofstream logFile;
ofstream errorFile;
int lineCount = 1;
int errorCount = 0;
string currentReturnType = "";
bool insideFunction = false;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // Open input file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file " << argv[1] << endl;
        return 1;
    }

    // Open log and error files
    logFile.open("2105140_log.txt");
    errorFile.open("2105140_error.txt");
    
    if (!logFile.is_open() || !errorFile.is_open()) {
        cerr << "Error: Cannot create output files" << endl;
        return 1;
    }

    try {
        // Read input file content
        string input((istreambuf_iterator<char>(inputFile)),
                     istreambuf_iterator<char>());
        inputFile.close();

        // Create ANTLR input stream
        ANTLRInputStream inputStream(input);
        
        // Create lexer
        C2105140Lexer lexer(&inputStream);
        CommonTokenStream tokens(&lexer);
        
        // Create parser
        C2105140Parser parser(&tokens);
        
        // Parse starting from 'program' rule
        tree::ParseTree* tree = parser.program();
        
        // Print parse tree (optional)
        logFile << "Parse tree: " << tree->toStringTree(&parser) << endl;
        
        cout << "Parsing completed successfully!" << endl;
        cout << "Log file: 2105140_log.txt" << endl;
        cout << "Error file: 2105140_error.txt" << endl;
        cout << "Total errors: " << errorCount << endl;
        
    } catch (const exception& e) {
        cerr << "Error during parsing: " << e.what() << endl;
        errorFile << "Fatal error: " << e.what() << endl;
        return 1;
    }

    // Close files
    logFile.close();
    errorFile.close();
    
    return 0;
}