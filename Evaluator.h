#ifndef Math_Evaluator_h
#define Math_Evaluator_h

#include "Double.h"
#include "Expression.h"
#include "Hash.h"
#include <cmath>
#include <cstdlib>

typedef Double number;

class Object {
    Token _symbol;
    number _value;
public:
    Token symbol() { return _symbol; }
    void sumbol(Token symbol) { _symbol = symbol; }
    number value() { return _value; }
    void value(number value) { _value = value; }
    Object() : _symbol(""), _value(0) {}
    Object(Token symbol, number value) : _symbol(symbol), _value(value) {}
};

class Error {
public:
    string message;
    Error(string m = "unknown cause") : message("Error: "+m+".") {}
};

class UndefinedSymbolError : public Error {
public:
    UndefinedSymbolError(string m = "encountered") : Error("undefined symbol "+m) {}
};

class SyntaxError : public Error {
public:
    SyntaxError() : Error("syntax error") {}
};

class Evaluator {
    
    class HashForToken {
    public:
        size_t operator()(Token value) {
            size_t hashcode = 0;
            for (char c : value) {
                hashcode += static_cast<size_t>(c);
            }
            return hashcode;
        }
    };
    
    UnorderedMap<Token, number, HashForToken> symbol_table;
    
public:
    
    Object evaluate(string str) {
        return evaluate(PostfixExpression(str));
    }
    
    Object evaluate(PostfixExpression expr) {
        Object result(expr.front(), 0);
        Stack<number> stack;
        expr.pop();
        while (!expr.empty()) {
            if (Expression::is_operator(expr.front())) {
                if (expr.front() == "+" or
                    expr.front() == "-" or
                    expr.front() == "*" or
                    expr.front() == "/" or
                    expr.front() == "%" or
                    expr.front() == "^")
                {
                    if (!stack.size() >= 2) throw SyntaxError();
                    number lval = stack.top();
                    stack.pop();
                    number rval = stack.top();
                    stack.pop();
                    if (expr.front() == "+") stack.push(rval+lval); else
                    if (expr.front() == "-") stack.push(rval-lval); else
                    if (expr.front() == "*") stack.push(rval*lval); else
                    if (expr.front() == "/") stack.push(rval/lval); else
                    if (expr.front() == "%") stack.push(rval%lval); else
                    if (expr.front() == "^") stack.push(pow(rval, lval));
                }
                if (expr.front() == "abs" or
                    expr.front() == "sqrt" or
                    expr.front() == "sin" or
                    expr.front() == "cos")
                {
                    if (!stack.size() >= 1) throw SyntaxError();
                    number val = stack.top();
                    stack.pop();
                    if (expr.front() == "abs") stack.push(fabs(val.value())); else
                    if (expr.front() == "sqrt") stack.push(sqrt(val.value())); else
                    if (expr.front() == "sin") stack.push(sin(val.value())); else
                    if (expr.front() == "cos") stack.push(cos(val.value()));
                    
                }
            } else
            if (Expression::char_category(expr.front()[0]) == Expression::alphabetic) {
                try {
                    stack.push(symbol_table.find(expr.front()));
                } catch (Token token) {
                    throw UndefinedSymbolError(token);
                }
            } else
            if (Expression::char_category(expr.front()[0]) == Expression::numeric) {
                stack.push(atof(expr.front().c_str()));
            }
            expr.pop();
        }
        if (stack.size() != 1) throw SyntaxError();
        result.value(stack.top());
        symbol_table.insert(result.symbol(), result.value());
        return result;
    }
    
};

#endif
