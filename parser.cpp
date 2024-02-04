#include "parser.h"

parser::parser(const std::vector<std::string>& tokens, std::map<std::string, int>& variables)
    : tokens(tokens), variables(variables) {}

void parser::parse() {
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::string token = tokens[i];

        if (token == "let") {
            parseVariableAssignment(i);
        } else if (token == "print") {
            parsePrintStatement(i);
        } else if (token == "add") {
            parseAddition(i);
        }
        // Add operations from their respective files later 
    }
}

void parser::parseVariableAssignment(size_t& index) {
    std::string varName = tokens[++index];

    int value = std::stoi(tokens[++index]);

    variables[varName] = value;
}

void parser::parsePrintStatement(size_t& index) {
    std::string varName = tokens[++index];
    // Add code to handle printing or storing print statements
}

void parser::parseAddition(size_t& index) {
    std::string varName = tokens[++index];
    
    int value = std::stoi(tokens[++index]);
    
    variables[varName] += value;
}