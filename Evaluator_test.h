#ifndef Math_Evaluator_test_h
#define Math_Evaluator_test_h

#include "Evaluator.h"
#include <iostream>
using std::cout;
using std::endl;

void evaluate(Evaluator& eval, PostfixExpression expr) {
    try {
        Object obj = eval.evaluate(expr);
        cout<<obj.symbol()<<" = "<<obj.value().value()<<endl;
    } catch (Token token) {
        cout<<"Error: undefined token \""<<token<<"\"."<<endl;
    }
}

void Evaluator_test() {
    Evaluator eval;
    PostfixExpression postfix1("a = abs(3)");
    PostfixExpression postfix2("b = abs(0-3)");
    PostfixExpression postfix3("c = a * b");
    PostfixExpression postfix4("d = sqrt(c)");
    PostfixExpression postfix5("x = sin(d)");
    PostfixExpression postfix6("y = cos(d)");
    evaluate(eval, postfix1);
    evaluate(eval, postfix2);
    evaluate(eval, postfix3);
    evaluate(eval, postfix4);
    evaluate(eval, postfix5);
    evaluate(eval, postfix6);
}

#endif
