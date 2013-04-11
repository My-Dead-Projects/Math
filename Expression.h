#ifndef Math_Expression_h
#define Math_Expression_h

#include "Number.h"
#include <vector>
using std::vector;

class Token {};

typedef std::vector<Token> Expression;

class Operand : public Number, public Token {
public:
    Operand() {}
    Operand(Number n) : Number(n) {}
};

class Operator : public Token {};

class UnaryOperator {
public:
    virtual Operand call(Operand);
};

class BinaryOperator {
public:
    virtual Operand call(Operand, Operand);
};

#endif
