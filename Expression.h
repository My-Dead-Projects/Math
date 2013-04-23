#ifndef Math_Expression_h
#define Math_Expression_h

#include "ListTypes.h"
#include <string>
using std::string;

// Token is a string
typedef std::string Token;
// Operator is a Token
typedef Token Operator;
// Operand is a Token
typedef Token Operand;

// Expression inherits Queue<Token>
class Expression : public Queue<Token> {
public:
    enum char_category_type {
        alphabetic = 0,
        numeric = 1,
        special = 2,
        whitespace = 3
    };
    static char_category_type char_category(const char& c) {
        if ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'))
            return alphabetic;
        if ((c >= '0' and c <= '9') or c == '.')
            return numeric;
        if (c == ' ')
            return whitespace;
        return special;
    }
    static short priority(Operator s) {
        if (s == "(" or s == ")")
            return -1;
        if (s == "=")
            return 0;
        if (s == "+" or s == "-")
            return 2;
        if (s == "*" or s == "/" or s == "%")
            return 3;
        if (s == "^")
            return 4;
        if (s == "abs" or s == "sqrt")
            return 5;
        if (s == "sin" or s == "cos")
            return 5;
        throw s;
    }
    static bool is_operator(Token t) {
        if (t=="="||t=="+"||t=="-"||t=="*"||t=="("||t==")"||t=="^"||
            t=="%"||t=="/"||t=="abs"||t=="sqrt"||t=="sin"||t=="cos")
            return true;
        else
            return false;
    }
    void clear() {
        while (!empty()) pop();
    }
};

// InfixExpression inherits Expression
class InfixExpression : public Expression {
public:
    void parse(string str) {
        clear();
        size_t symbol_start = 0;
        char_category_type symbol_category;
        while (true) {
            Token symbol;
            for (size_t i = symbol_start; i < str.size(); i++) {
                if (i == symbol_start) {
                    if (char_category(str[i]) == whitespace) {
                        symbol_start++;
                        continue;
                    }
                    symbol_category = char_category(str[i]);
                    symbol.push_back(str[i]);
                } else {
                    if (symbol_category != char_category(str[i]))
                        break;
                    if (symbol_category != special)
                        symbol.push_back(str[i]);
                    else
                        break;
                }
            }
            if (!symbol.size()) break;
            symbol_start += symbol.size();
            push(symbol);
        }
    }
};

// PostfixExpression inherits Expression
class PostfixExpression : public Expression {
public:
    PostfixExpression() {}
    PostfixExpression(InfixExpression expr) {
        parse(expr);
    }
    PostfixExpression(string str) {
        parse(str);
    }
    void parse(string str) {
        InfixExpression infix;
        infix.parse(str);
        parse(infix);
    }
    void parse(InfixExpression expr) {
        Stack<Operator> op_stack;
        while (!expr.empty()) {
            if (is_operator(expr.front())) {
                while (!op_stack.empty() and
                       op_stack.top() != "(" and
                       expr.front() != "(" and
                       priority(op_stack.top()) >=
                       priority(expr.front())) {
                    push(op_stack.top());
                    op_stack.pop();
                }
                if (!op_stack.empty() and
                    op_stack.top() == "(" and expr.front() == ")") {
                    op_stack.pop();
                    expr.pop();
                } else {
                    op_stack.push(expr.front());
                    expr.pop();
                }
            } else {
                push(expr.front());
                expr.pop();
            }
        }
        while (!op_stack.empty()) {
            push(op_stack.top());
            op_stack.pop();
        }

    }
};

#endif
