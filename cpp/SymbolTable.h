#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

extern std::ofstream parserLogFile;

class FunctionInfo {
public:
    std::string returnType;
    std::vector<std::string> paramTypes;
    std::vector<std::string> paramNames;
    int paramCount;
    bool isDefined;
    bool isDeclared;
    
    FunctionInfo() : paramCount(0), isDefined(false), isDeclared(false) {}
    
    FunctionInfo(const std::string& retType) 
        : returnType(retType), paramCount(0), isDefined(false), isDeclared(false) {}
};

class SymbolInfo {
public:
    std::string name;
    std::string type;
    std::string symbolType; // "ID", "ARRAY", "FUNCTION"
    int arraySize;
    FunctionInfo* funcInfo;
    SymbolInfo* next;
    
    SymbolInfo() : arraySize(-1), funcInfo(nullptr), next(nullptr) {}
    
    SymbolInfo(const std::string& n, const std::string& t, const std::string& st = "ID") 
        : name(n), type(t), symbolType(st), arraySize(-1), funcInfo(nullptr), next(nullptr) {}
    
    ~SymbolInfo() {
        if (funcInfo) {
            delete funcInfo;
        }
    }
    
    // Copy constructor
    SymbolInfo(const SymbolInfo& other) 
        : name(other.name), type(other.type), symbolType(other.symbolType), 
          arraySize(other.arraySize), next(nullptr) {
        if (other.funcInfo) {
            funcInfo = new FunctionInfo(*other.funcInfo);
        } else {
            funcInfo = nullptr;
        }
    }
    
    // Assignment operator
    SymbolInfo& operator=(const SymbolInfo& other) {
        if (this != &other) {
            name = other.name;
            type = other.type;
            symbolType = other.symbolType;
            arraySize = other.arraySize;
            
            if (funcInfo) {
                delete funcInfo;
            }
            
            if (other.funcInfo) {
                funcInfo = new FunctionInfo(*other.funcInfo);
            } else {
                funcInfo = nullptr;
            }
        }
        return *this;
    }
    
    void setFunction(const std::string& returnType) {
        symbolType = "FUNCTION";
        if (!funcInfo) {
            funcInfo = new FunctionInfo(returnType);
        } else {
            funcInfo->returnType = returnType;
        }
    }
    
    void setArray(int size) {
        symbolType = "ARRAY";
        arraySize = size;
    }
    
    void addParameter(const std::string& paramType, const std::string& paramName = "") {
        if (funcInfo) {
            funcInfo->paramTypes.push_back(paramType);
            funcInfo->paramNames.push_back(paramName);
            funcInfo->paramCount++;
        }
    }
    
    std::string toString() const {
        std::string result = "< " + name + " : ";
        
        if (symbolType == "ARRAY") {
            result += "ARRAY [" + std::to_string(arraySize) + "] OF " + type;
        } else if (symbolType == "FUNCTION") {
            result += "FUNCTION, " + type;
            if (funcInfo && funcInfo->paramCount > 0) {
                result += " : (";
                for (int i = 0; i < funcInfo->paramCount; i++) {
                    if (i > 0) result += ", ";
                    result += funcInfo->paramTypes[i];
                }
                result += ")";
            }
        } else {
            result += type;
        }
        
        result += " >";
        return result;
    }
};

class ScopeTable {
public:
    SymbolInfo** table;
    int bucketCount;
    int id;
    ScopeTable* parentScope;
    int symbolCount;
    
    ScopeTable(int buckets = 7, int scopeId = 1) 
        : bucketCount(buckets), id(scopeId), parentScope(nullptr), symbolCount(0) {
        table = new SymbolInfo*[bucketCount];
        for (int i = 0; i < bucketCount; i++) {
            table[i] = nullptr;
        }
    }
    
    ~ScopeTable() {
        for (int i = 0; i < bucketCount; i++) {
            SymbolInfo* current = table[i];
            while (current) {
                SymbolInfo* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    
    int hash(const std::string& name) {
        unsigned int hashValue = 0;
        for (char c : name) {
            hashValue = (hashValue * 31 + c) % bucketCount;
        }
        return hashValue;
    }
    
    bool insert(SymbolInfo* symbol) {
        if (lookup(symbol->name)) {
            return false; // Symbol already exists in this scope
        }
        
        int index = hash(symbol->name);
        
        // Insert at the beginning of the chain
        symbol->next = table[index];
        table[index] = symbol;
        symbolCount++;
        
        return true;
    }
    
    SymbolInfo* lookup(const std::string& name) {
        int index = hash(name);
        SymbolInfo* current = table[index];
        
        while (current) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    bool deleteSymbol(const std::string& name) {
        int index = hash(name);
        SymbolInfo* current = table[index];
        SymbolInfo* prev = nullptr;
        
        while (current) {
            if (current->name == name) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next;
                }
                delete current;
                symbolCount--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    
    void print() {
        if (parserLogFile.is_open()) {
            parserLogFile << "\tScopeTable# " << id << std::endl;
            for (int i = 0; i < bucketCount; i++) {
                if (table[i]) {
                    parserLogFile << "\t" << i << "--> ";
                    SymbolInfo* current = table[i];
                    bool first = true;
                    while (current) {
                        if (!first) {
                            parserLogFile << " : ";
                        }
                        parserLogFile << current->toString();
                        current = current->next;
                        first = false;
                    }
                    parserLogFile << std::endl;
                }
            }
        }
    }
};

class SymbolTable {
public:
    ScopeTable* currentScope;
    int bucketCount;
    int scopeIdCounter;
    
    SymbolTable(int buckets = 7) : bucketCount(buckets), scopeIdCounter(1) {
        currentScope = new ScopeTable(buckets, scopeIdCounter++);
    }
    
    ~SymbolTable() {
        while (currentScope) {
            exitScope();
        }
    }
    
    void enterScope() {
        ScopeTable* newScope = new ScopeTable(bucketCount, scopeIdCounter++);
        newScope->parentScope = currentScope;
        currentScope = newScope;
    }
    
    void exitScope() {
        if (currentScope) {
            if (parserLogFile.is_open()) {
                parserLogFile << "\tSymbolTable printing scope# " << currentScope->id << std::endl;
                currentScope->print();
            }
            
            ScopeTable* temp = currentScope;
            currentScope = currentScope->parentScope;
            delete temp;
        }
    }
    
    bool insert(SymbolInfo* symbol) {
        if (currentScope) {
            return currentScope->insert(symbol);
        }
        return false;
    }
    
    SymbolInfo* lookup(const std::string& name) {
        ScopeTable* scope = currentScope;
        while (scope) {
            SymbolInfo* result = scope->lookup(name);
            if (result) {
                return result;
            }
            scope = scope->parentScope;
        }
        return nullptr;
    }
    
    SymbolInfo* lookupCurrentScope(const std::string& name) {
        if (currentScope) {
            return currentScope->lookup(name);
        }
        return nullptr;
    }
    
    void printCurrentScope() {
        if (currentScope && parserLogFile.is_open()) {
            parserLogFile << "\tSymbolTable printing scope# " << currentScope->id << std::endl;
            currentScope->print();
        }
    }
    
    void printAllScopes() {
        if (parserLogFile.is_open()) {
            parserLogFile << "\tSymbolTable printing all scopes:" << std::endl;
            ScopeTable* scope = currentScope;
            while (scope) {
                scope->print();
                scope = scope->parentScope;
            }
        }
    }
};