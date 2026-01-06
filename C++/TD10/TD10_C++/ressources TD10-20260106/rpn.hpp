#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <vector>

namespace rpn {
    using Token = std::string;
    using Expression = std::vector<Token>;

    Expression stringToExpression(const std::string& input);
    bool isValidOperator(const Token& token);
    bool isNumeric(const std::string& s);
    bool isWellParenthesized(const Expression& expression);
    Expression infixToPostfix(const Expression& infix_expression);
    

} // namespace rpn

#endif // RPN_HPP