#ifndef Math_Expression_test_h
#define Math_Expression_test_h

#include "Expression.h"
#include <iostream>
using std::cout;
using std::endl;

void Expression_test() {
    InfixExpression infix;
    infix.parse("y = a + (b + c) / ((d + 2) * 3) - 3 - 7 - (4 - 1)");
    PostfixExpression postfix(infix);
    while (!postfix.empty()) {
        cout<<postfix.front()<<endl;
        postfix.pop();
    }
}

#endif
