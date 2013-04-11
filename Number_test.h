#ifndef Math_Evaluator_test_h
#define Math_Evaluator_test_h

#include "Number.h"
#include <assert.h>

void Number_test() {
    Number integer(static_cast<long>(3));
    Number real(static_cast<double>(2.678));
    integer = static_cast<long>(5);
    assert(integer.value<long>() == static_cast<long>(5));
    assert(integer.value<double>() == static_cast<double>(5));
    
    real = static_cast<double>(6.553);
    assert(real.value<double>() == static_cast<double>(6.553));
    assert(real.value<long>() == static_cast<long>(6.553));
    
    assert((integer + integer).value<long>() == static_cast<long>(10));
}

#endif
