#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>

class SymbolInfo {
public:
    std::string name;
    std::string type;
    std::string varType;
    std::string returnType;
    std::vector<std::pair<std::string, std::string>> parameters;
    int arraySize;
    bool isArray;
    bool isFunction;
    bool isDefined;
    bool isDeclared;
    int lineNo;

    SymbolInfo()
        : arraySize(-1), isArray(false), isFunction(false), isDefined(false),
          isDeclared(false), lineNo(0) {}

    SymbolInfo(const std::string &n, const std::string &t)
        : name(n), type(t), arraySize(-1), isArray(false), isFunction(false),
          isDefined(false), isDeclared(false), lineNo(0) {}
};

class SymbolTable {
private:
    std::map<std::string, SymbolInfo *> currentScope;
    std::vector<std::map<std::string, SymbolInfo *>> scopes;

public:
    void enterScope() {
        scopes.push_back(currentScope);
        currentScope.clear();
    }

    void exitScope() {
        if (!scopes.empty()) {
            currentScope = scopes.back();
            scopes.pop_back();
        }
    }

    bool insert(SymbolInfo *symbol) {
        if (currentScope.find(symbol->name) != currentScope.end()) {
            return false;
        }
        currentScope[symbol->name] = symbol;
        return true;
    }

    SymbolInfo *lookup(const std::string &name) {
        // First check current scope
        if (currentScope.find(name) != currentScope.end()) {
            return currentScope[name];
        }
        
        // Then check parent scopes
        for (int i = static_cast<int>(scopes.size()) - 1; i >= 0; --i) {
            if (scopes[i].find(name) != scopes[i].end()) {
                return scopes[i][name];
            }
        }
        return nullptr;
    }

    void printScope(std::ofstream &logFile) {
        logFile << "ScopeTable# " << scopes.size() << std::endl;
        for (const auto &pair : currentScope) {
            SymbolInfo *symbol = pair.second;
            logFile << symbol->name << " : " << symbol->type;
            if (symbol->isFunction) {
                logFile << " FUNCTION";
                if (!symbol->returnType.empty()) {
                    logFile << " " << symbol->returnType;
                }
                logFile << "(";
                for (size_t i = 0; i < symbol->parameters.size(); i++) {
                    if (i > 0) logFile << ",";
                    logFile << symbol->parameters[i].first;
                }
                logFile << ")";
            } else if (symbol->isArray) {
                logFile << " [" << symbol->arraySize << "]";
            }
            logFile << std::endl;
        }
        logFile << std::endl;
    }

    // Overloaded version for when no file is provided
    void printScope() {
        std::cout << "ScopeTable# " << scopes.size() << std::endl;
        for (const auto &pair : currentScope) {
            SymbolInfo *symbol = pair.second;
            std::cout << symbol->name << " : " << symbol->type;
            if (symbol->isFunction) {
                std::cout << " FUNCTION";
                if (!symbol->returnType.empty()) {
                    std::cout << " " << symbol->returnType;
                }
                std::cout << "(";
                for (size_t i = 0; i < symbol->parameters.size(); i++) {
                    if (i > 0) std::cout << ",";
                    std::cout << symbol->parameters[i].first;
                }
                std::cout << ")";
            } else if (symbol->isArray) {
                std::cout << " [" << symbol->arraySize << "]";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printAllScopes(std::ofstream &logFile) {
        logFile << "Symbol Table:" << std::endl;
        printScope(logFile);
    }
};

#endif // SYMBOL_TABLE_H