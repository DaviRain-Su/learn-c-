#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
public:
    complex(double r = 0, double i = 0)
        : re(r),
        im(i)
    { }

    complex& operator += (const complex &);
    double real() const { return re; }// inline function
    double imag() const { return im; }// inline function 
private:
    double re, im;

    friend complex& __doapl ( complex*, const complex&); //friend function
};

#endif
