#!/bin/bash

# Compile ANTLR grammars (adjust the command based on your ANTLR setup)
antlr4 -Dlanguage=Cpp C2105140Lexer.g4
antlr4 -Dlanguage=Cpp C2105140Parser.g4

# Compile the generated files and your tester (update source list as needed)
g++ -std=c++17 -o test Ctester.cpp *.cpp -I/usr/local/include/antlr4-runtime -lantlr4-runtime

# Run the test (input file should be provided as argument)
if [ "$#" -eq 1 ]; then
    ./test "$1"
else
    echo "Usage: ./run.sh inputfile.c"
fi