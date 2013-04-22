#ifndef Math_Double_test_h
#define Math_Double_test_h

#include "Double.h"
#include <assert.h>
#include <iostream>
using std::cout;
using std::endl;

void Double_test() {
    Double x = 5.7;
    assert(x == 5.7);
    assert(x < 6.5);
    assert(x > 4.2);
    assert(x >= 5.7);
    assert(x >= 5.6);
    assert(x <= 5.7);
    assert(x <= 5.8);
    cout<<"Double test passed."<<endl;
}


#endif
