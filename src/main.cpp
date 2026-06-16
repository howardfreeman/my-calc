#include <string>
#include <stack>
#include <map>
#include <iostream>

#include "custom-exceptions.hpp"

/*
TODO: 
    fix brackets mismatch (Custom errors)
    custom error if empty brackets
    add multidigit token parsing
*/

void infix_to_postfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix = "";
    std::map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for(const char token : infix) {
        if(std::isdigit(token)) {
            postfix.push_back(token);
            continue;
        }

        // Work on brackets mismatch
        if(token == '(') {
            operators.push(token);
            continue;
        }

        // Work on structure
        if(token == ')') {
            while(!operators.empty() && operators.top() != '(') {
                postfix.push_back(operators.top());
                operators.pop();
            }

            if(operators.empty()) {
                throw CloseBracketException();
            }

            operators.pop();
        }

        if(!precedence.contains(token)) {
            continue;
        }

        while(!operators.empty() && precedence[token] <= precedence[operators.top()]) {
            postfix.push_back(operators.top());
            operators.pop();
        }
        
        operators.push(token);
    }

    while(!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    std::cout << postfix << '\n';
}

int main() {
    std::cout << "Type expression" << std::endl;
    std::string exp;
    getline(std::cin, exp);

    try {
        infix_to_postfix(exp);
    } catch(const CloseBracketException& e) {
        std::cout << "Custom error: " << e.what() << '\n';
    }

    return 0;
}