#ifndef Math_Expression_test_h
#define Math_Expression_test_h

#include "Expression.h"
#include <iostream>
using std::cout;
using std::endl;

void Expression_test() {
    InfixExpression infix;
    infix.parse("d = a * b + c / a");
    PostfixExpression postfix(infix);
    cout<<"Postfix:"<<endl;
    while (!postfix.empty()) {
        cout<<postfix.front()<<endl;
        postfix.pop();
    }
}

#endif
