#ifndef Math_Expression_test_h
#define Math_Expression_test_h

#include "Expression.h"
#include <iostream>
using std::cout;
using std::endl;

void Expression_test() {
    Postfix expr;
    expr.parse("c = a + b");
    while (!expr.empty()) {
        cout<<expr.front()<<endl;
        expr.pop();
    }
}

#endif
