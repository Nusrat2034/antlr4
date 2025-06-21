#!/bin/bash

# Compiler for C Subset Language Parser
# CSE 310 Assignment 3: Syntax and Semantic Analysis

echo "=== C Subset Language Parser Compiler ==="
echo "Student ID: 2105140"
echo

# Check if ANTLR4 is available
if ! command -v antlr4 &> /dev/null; then
    echo "Error: ANTLR4 not found. Please install ANTLR4."
    echo "Download from: https://www.antlr.org/download.html"
    exit 1
fi

# Check if input file is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <input_file.c>"
    echo "Example: $0 test.c"
    exit 1
fi

INPUT_FILE=$1

# Check if input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Error: Input file '$INPUT_FILE' not found."
    exit 1
fi

echo "Input file: $INPUT_FILE"
echo

# Clean previous generated files
echo "Cleaning previous generated files..."
rm -f *.class *.java *.interp *.tokens
rm -f C2105140Lex