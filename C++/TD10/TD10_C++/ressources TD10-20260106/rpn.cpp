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
        Expression prioriteOperator = {"*", "/", "+", "-"};
        
        for(const Token& token : infix_expression){
            if(isNumeric(token)){
                postfix_expression.push_back(token);
            }
            else if(isValidOperator(token)){
                Token op_top;
                if(!pile.empty())
                    op_top = pile.back();
                do{
                    size_t token_prio = 0;
                    size_t op_top_prio = 0;
                    for(size_t i = 0; i < prioriteOperator.size(); i++){
                        if(prioriteOperator[i] == token){
                            token_prio = i;
                        }
                        if(prioriteOperator[i] == op_top){
                            op_top_prio = i;
                        }
                    }
                    if(op_top_prio >= token_prio){
                        postfix_expression.push_back(op_top);
                        pile.pop_back();
                        if(!pile.empty())
                            op_top = pile.back();
                        else
                            break;
                    }
                    else{
                        break;
                    }
                }while(isValidOperator(op_top));
                pile.push_back(token);
            }
            else if(token == "("){
                pile.push_back(token);
            }
            else if(token == ")"){
                Token op_top = pile.back();
                while(op_top != "("){
                    postfix_expression.push_back(op_top);
                    pile.pop_back();
                    op_top = pile.back();
                }
                pile.pop_back();
            }
        }

        return postfix_expression;

    }

} // namespace rpn