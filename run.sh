#!/bin/bash
set -e

# === CONFIG ===
ANTLR_JAR=~/antlr-4.13.2-complete.jar
INCLUDE_DIR=/usr/local/include/antlr4-runtime
SRC_FILES=("C2105140Lexer.cpp" "C2105140Parser.cpp" \
           "C2105140ParserListener.cpp" "C2105140ParserBaseListener.cpp" \
           "C2105140ParserVisitor.cpp" "C2105140ParserBaseVisitor.cpp")

# === CLEAN ===
echo "🔄 Cleaning old build artifacts..."
rm -f C2105140Lexer.cpp C2105140Parser.cpp C2105140Lexer.h C2105140Parser.h *.o *.tokens *.interp test


# === GENERATE ===
echo "⚙️ Generating lexer and parser with -listener and -visitor..."
java -jar "$ANTLR_JAR" -Dlanguage=Cpp -listener -visitor C2105140Lexer.g4
java -jar "$ANTLR_JAR" -Dlanguage=Cpp -listener -visitor C2105140Parser.g4

# === LIST GENERATED FILES ===
echo "📄 Generated files:"
ls -1 C2105140*.{h,cpp} 2>/dev/null || echo "⚠️ No parser/lexer files found!"

# === COMPILE ===
echo "🛠️ Compiling generated and custom source files..."
for file in "${SRC_FILES[@]}"; do
    if [ -f "$file" ]; then
        echo "✔️ Compiling $file"
        g++ -std=c++17 -I"$INCLUDE_DIR" -c "$file"
    else
        echo "⏭️  Skipping missing file: $file"
    fi
done

if [ ! -f Ctester.cpp ]; then
    echo "❌ Error: Ctester.cpp not found!"
    exit 1
fi

echo "✔️ Compiling Ctester.cpp"
g++ -std=c++17 -I"$INCLUDE_DIR" -c Ctester.cpp

# === LINK ===
echo "🔗 Linking all object files..."
g++ -std=c++17 -I"$INCLUDE_DIR" *.o -lantlr4-runtime -o test

# === RUN ===
if [ $# -eq 0 ]; then
    echo "ℹ️ Usage: ./run.sh input.c"
    echo "❗ No input file provided, exiting."
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "❌ Error: Input file '$1' not found."
    exit 1
fi

echo "🚀 Running test on '$1'..."
./test "$1"

echo "✅ Finished. Check log.txt and error.txt for output."
