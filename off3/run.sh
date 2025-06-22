#!/bin/bash

# Remove previously generated files
rm -f C2105140Lexer.cpp C2105140Parser.cpp \
      C2105140ParserListener.cpp C2105140ParserBaseListener.cpp \
      C2105140ParserVisitor.cpp C2105140ParserBaseVisitor.cpp \
      C2105140Lexer.h C2105140Parser.h \
      C2105140ParserListener.h C2105140ParserBaseListener.h \
      C2105140ParserVisitor.h C2105140ParserBaseVisitor.h \
      C2105140Lexer.o C2105140Parser.o Ctester.o Ctester.out \
      C2105140Lexer.interp C2105140Parser.interp\
      C2105140Lexer.tokens C2105140Parser.tokens

# # Generate lexer and parser from ANTLR4 grammar
 antlr4 -Dlanguage=Cpp C2105140Lexer.g4
 antlr4 -Dlanguage=Cpp C2105140Parser.g4

# # Compile generated lexer and parser
 g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c C2105140Lexer.cpp C2105140Parser.cpp

# # Compile your test file
 g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c Ctester.cpp

# # Link all object files
 g++ -std=c++17 -w C2105140Lexer.o C2105140Parser.o Ctester.o -L/usr/local/lib -lantlr4-runtime -o Ctester.out -pthread

# # Run the parser
 LD_LIBRARY_PATH=/usr/local/lib ./Ctester.out "$1"