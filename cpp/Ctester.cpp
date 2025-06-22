#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "C8086Lexer.h"
#include "C8086Parser.h"
#include "SymbolTable.h"

using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile; // global error stream
ofstream lexLogFile; // global lexer log stream
int syntaxErrorCount = 0;

// Custom error listener for syntax errors
class CustomErrorListener : public BaseErrorListener {
public:
    void syntaxError(Recognizer *recognizer, Token *offendingSymbol, 
                    size_t line, size_t charPositionInLine, 
                    const std::string &msg, std::exception_ptr e) override {
        
        syntaxErrorCount++;
        
        if (errorFile.is_open()) {
            errorFile << "Line# " << line << ": " << msg << std::endl;
            errorFile.flush();
        }
    }
};

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    
    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }
    
    // Output files (matching assignment requirements)
    string logFileName = "log.txt";
    string errorFileName = "error.txt";
    string lexLogFileName = "lexLogFile.txt";
    
    // ---- Output Files ----
    parserLogFile.open(logFileName);
    if (!parserLogFile.is_open()) {
        cerr << "Error opening log file: " << logFileName << endl;
        return 1;
    }
    
    errorFile.open(errorFileName);
    if (!errorFile.is_open()) {
        cerr << "Error opening error file: " << errorFileName << endl;
        return 1;
    }
    
    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open()) {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }
    
    try {
        // ---- Parsing Flow ----
        ANTLRInputStream input(inputFile);
        
        C8086Lexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        
        C8086Parser parser(&tokens);
        
        // Remove default error listeners and add custom one
        parser.removeErrorListeners();
        CustomErrorListener customErrorListener;
        parser.addErrorListener(&customErrorListener);
        
        // Start parsing at the 'start' rule
        parser.start();
        
    } catch (const std::exception& e) {
        cerr << "Parsing error: " << e.what() << endl;
        syntaxErrorCount++;
    }
    
    // Clean up
    inputFile.close();
    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();
    
    cout << "Parsing completed." << endl;
    cout << "Check log.txt for parsing details." << endl;
    cout << "Check error.txt for error messages." << endl;
    cout << "Total syntax errors: " << syntaxErrorCount << endl;
    
    return 0;
}