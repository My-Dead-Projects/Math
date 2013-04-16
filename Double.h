#ifndef Math_Double_h
#define Math_Double_h

/**************************/
/** A wrapper for double **/
/**************************/

class Double {
    double _value;
public:
    double operator=(double val) {
        return _value = val;
    }
    Double(double val = 0) : _value(val) {}
    friend bool operator==(const Double&, const Double&);
    friend bool operator<=(const Double&, const Double&);
    friend bool operator>=(const Double&, const Double&);
};
bool operator==(const Double& lhv, const Double& rhv) {
    return lhv._value == rhv._value;
}
bool operator<=(const Double& lhv, const Double& rhv) {
    return lhv._value <= rhv._value;
}
bool operator>=(const Double& lhv, const Double& rhv) {
    return lhv._value >= rhv._value;
}
bool operator!=(const Double& lhv, const Double& rhv) {
    return !(lhv == rhv);
}
bool operator>(const Double& lhv, const Double& rhv) {
    return !(lhv <= rhv);
}
bool operator<(const Double& lhv, const Double& rhv) {
    return !(lhv >= rhv);
}

#include <assert.h>

void Double_test() {
    Double x = 5.7;
    assert(x == 5.7);
    assert(x < 6.5);
    assert(x > 4.2);
    assert(x >= 5.7);
    assert(x >= 5.6);
    assert(x <= 5.7);
    assert(x <= 5.8);
}

#endif
