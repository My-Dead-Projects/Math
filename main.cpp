
#include "Evaluator.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    
    Evaluator eval;
    
    string input;
    
    cout<<"'exit' to quit"<<endl<<endl;
    
    while (true) {
        cout<<"Enter expression: ";
        std::getline(cin, input, '\n');
        if (input == "exit") break;
        try {
            Object obj = eval.evaluate(input);
            cout<<obj.symbol()<<" = "<<obj.value().value()<<endl;
        } catch (Error error) {
            cout<<error.message<<endl;
        }
    }
    
    return 0;
}
