#include "complex.h"

inline complex& 
complex::operator+=(const complex& r)
{
    return __doapl(this, r);    
}

inline complex&
__doapl(complex * ths, const complex & r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex
operator + (const complex & x, const complex &y)
{
    return complex( x.real() + y.real, x.imag() + y.imag());
}

inline complex
operator+ (const complex& x, double y)
{
    return complex(x.real() + y, x.imag());
}

inline complex
operator+ (double x, const complex & y)
{
    return complex( x + y.real(), y.imag());
}

#include<iostream>
using std::ostream;
inline ostream&
operator<<(ostream& os, const complex& x)// os 一直在改变
{
    os << '(' << x.real() << ',' << x.imag() << ')';
    return os;
}