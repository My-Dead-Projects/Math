#ifndef Math_Number_h
#define Math_Number_h

#include <typeinfo>

class inv_type {};

class Number {
protected:
    union {
        long ival;
        long double fval;
    };
    bool integral;
public:
    Number() : integral(true), ival(0) {}
    Number(long val) : integral(true), ival(val) {}
    Number(long double val) : integral(false), fval(val) {}
    Number(int val) : Number(static_cast<long>(val)) {}
    Number(double val) : Number(static_cast<long double>(val)) {}
    Number(float val) : Number(static_cast<long double>(val)) {}
    long operator=(int val) {
        integral = true;
        return ival = val;
    }
    long operator=(long val) {
        integral = true;
        return ival = val;
    }
    long double operator=(float val) {
        integral = false;
        return fval = val;
    }
    long double operator=(double val) {
        integral = false;
        return fval = val;
    }
    long double operator=(long double val) {
        integral = false;
        return fval = val;
    }
    template <class numeric> numeric value() {
        if (typeid(numeric) != typeid(long) and
            typeid(numeric) != typeid(long double))
            throw inv_type();
        if (integral) return static_cast<numeric>(ival);
        else return static_cast<numeric>(fval);
    }
    Number operator+(Number val) {
        Number ret;
        if (integral and val.integral)
            ret = value<long>() + val.value<long>();
            else
                ret = value<long double>() + val.value<long double>();
                return ret;
    }
    Number operator-(Number val) {
        Number ret;
        if (integral and val.integral)
            ret = value<long>() - val.value<long>();
            else
                ret = value<long double>() - val.value<long double>();
                return ret;
    }
    Number operator*(Number val) {
        Number ret;
        if (integral and val.integral)
            ret = value<long>() * val.value<long>();
            else
                ret = value<long double>() *val.value<long double>();
                return ret;
    }
    Number operator/(Number val) {
        Number ret;
        ret = value<long double>() / val.value<long double>();
        return ret;
    }
};

#endif
