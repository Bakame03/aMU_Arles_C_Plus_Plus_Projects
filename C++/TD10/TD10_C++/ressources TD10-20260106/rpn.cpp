#include <iostream>
#include <string>
#include <vector>
#include "rpn.hpp"

namespace rpn {

    Expression stringToExpression(const std::string& input){
        Expression expression;
        std::string token;
        
        for (size_t i = 0; i < input.size(); ++i) {
            char c = input[i];
            
            // Skip whitespace
            if (std::isspace(c)) {
                if (!token.empty()) {
                    expression.push_back(token);
                    token.clear();
                }
            }
            // Handle parentheses as separate tokens
            else if (c == '(' || c == ')') {
                if (!token.empty()) {
                    expression.push_back(token);
                    token.clear();
                }
                expression.push_back(std::string(1, c));
            }
            // Handle operators
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (!token.empty()) {
                    expression.push_back(token);
                    token.clear();
                }
                expression.push_back(std::string(1, c));
            }
            // Build numeric tokens (including negative numbers)
            else {
                token += c;
            }
        }
        
        // Don't forget the last token
        if (!token.empty()) {
            expression.push_back(token);
        }
        
        return expression;
    }

    bool isValidOperator(const Token& token){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            return true;
        }
        return false;
    }

    bool isNumeric(const std::string& s){
        size_t sz=0;
        try{
            std::stod(s, &sz);
        }catch(const std::invalid_argument& ia){
        }
        return((sz>0)&&(s.size() == sz));
    }
    
    Expression infixToPostfix(const Expression& infix_expression){
        Expression postfix_expression;
        Expression pile;
        
        for(const Token& token : infix_expression){
            if(isNumeric(token)){
                postfix_expression.push_back(token);
            }
            else if(isValidOperator(token)){
                if(pile.back() == "+" || pile.back() == "-" || pile.back() == "*" || pile.back() == "/"){}
            }
            else if(token == "(" || token == ")"){
            }
        }

        return postfix_expression;
    }

} // namespace rpn