# C++

C++98(1.0)
C++03(TR1)
C++11(2.0)
C++14

C++ 语言 + 标准库

## BOOK 

C++ primer (C++11) 5th

The C++ programming language 4th

Effective C++ 3th Scott Meyers (55 Specifific way)

The C++ standard library 2th (c++11)

STL 源码剥析

## C vs C++，关于数据和函数

C (Data(Type, built-in, struct) and fcuntions ) ---->  Variables

C++ (Data Member (class <==> struct), Member function) -----> Object

Complex --------> c1, c2, c3, c4,  Object Based 基于对象
    i, j（数据可以有多分）
    function (函数只有一份)

    complex c1(2, 1);
    complex c2;
    complex *pc = new complex(0, 1);

String --------> s1, s2, s3, s4 面向对象
    char * ptr;
    function

    string s1("hello");


## C++ programs 代码形式

.h(class declaration )/.cpp(ex.main() )/.h(head file standrd library)

衍生文件名不一定时.h / .cpp

## output C vs C++

C(#include <stdio.h> / printf() ) 
C++(#include <iostream> / cout << endl;)

## head 头文件中的防卫式声明

complex.h (guard)
#ifndef __COMPLEX__
#define __COMPLEX__

....

#endif

## Head file

    #ifndef __COMPLEX__
    #define __COMPLEX__

    class complex //----------------------------------// class head
    { //----------------------------------// class body
        public:

            complex(double r = 0, double i = 0)
                : re(r), im (i)
            {}

            complex& operator += (const complex& ); // -------------- 只是一个声明
            double real() const { return re; } // ------------------ 在本体直接定义
            double imag() const { return im; } 
        private:
            double re, im; 

        friend complex & __doapl (complex* , const complex&);
    };

    #endif

## class template 

    #ifndef __COMPLEX__
    #define __COMPLEX__

    template< typename T> --------------------// template 模版
    class complex
    {
        public://-------------------- access level 
            complex(T r = 0, T i = 0)
                : re(r), im (i)
            {}

            complex& operator += (const complex& );
            T real() const { return re; } // ------------------- 函数在class内部直接定义， 就会成为inline函数
            T imag() const { return im; } 
        private: // --------- access level 
            T re, im; 

        friend complex & __doapl (complex* , const complex&);
    };

    ostream & operator << (ostream &os, const complex& x)
    {
        return os << '(' << real(x) << ',' << imag(x) << ')' ;
    }
    #endif

useage:
    
    {
        complex<double> c1(2.3, 4.5);
        complex<int> c2(2, 3);
    }
    



    
## inline function

    inline function 有宏的特性， 比较快

    inline double 
    image(const complex& x)
    {
        return x.imag();
    }

    你的inline只是对编译器的一个建议，最终由编译器决定。

## access level 

    {
        complex c1(2, 1);
        cout << c1.re; //----- X private : re, im 
        cout << c1.im; //----- X 
    }

    {
        complex c1(2, 1);
        cout << c1.real(); // ------ OK public function real () 
        cout << c2.imag(); // ------ OK
    }

## constructor ctor
                  ------------------------> default argument  
                  |        | 
        complex(T r = 0, T i = 0) // ---------> default argument 
           : re(r), im (i) // ---------------> initialization list 初值列
        { } // ------- ctor 用来创建对象

        // 一个对象的初始化有两个阶段， 1 初值列， 2， 赋值

        {
            complex c2(2, 1);
            complex c2; // ----------------> call dafault constructor
            complex *p  = new complex(4);
        }

## ctor可以有多个 -- overloading 重载

    double real() const { return re; } // ---------> overload 
    void real(double r) { re = r; } 


    complex(double r = 0, double i = 0) //----------> (1) default argument
        : re(r), im(i)
    {}

    complex () : re(0), im(0) {} // -------> (2) error

    {
        complex c1; // -------- ambigus call (1) (2)
        complex c2();
    }

# ctor 构造函数被放到private区域

    这是就不能构造对象

    class A{ // -----------------> Singleton 单例模式
        public:
        
            static A& geyInstance(); // -----------> 注意static
            setup() { ... }
        private:
            A(); // ------------> 构造函数放在private区域
            A(const A& rhs); 
            ...
    };

    A& A::getInstance() 
    {
        static A a; // --------------> 注意static
        return a;
    }


    // 单例模式的使用方法
    A::getInstance().setup(); // call function

## const member fcuntion 


    在函数的后面加const

    double real() const { return re; } // --------> const 表示不改变数据
    double imag() const { return im; }

    {
        const complex c1(2, 1); // const object
        cout << c1.real(); // if real() is not const lable will be error , then say to me double real(); will change the word
        cout << c1.imag(); // if imag() is not const lable will be error 
    }


## pass by value Vs pass by reference (to const) ---> Reference 引用


    template< typename T> 
    class complex
    {
        public:
            complex(T r = 0, T i = 0) // ------> pass by value 
                : re(r), im (i)
            {}

            complex& operator += (const complex& ); // ------> pass by reference
            T real() const { return re; } 
            T imag() const { return im; } 
        private:  
            T re, im; 

        friend complex & __doapl (complex* , const complex&); // ------> (para 1) pass by value , (para 2)pass by reference (const )
    };

    ostream & operator << (ostream &os, const complex& x) // ------> (1) pass by reference (这个会改变os), (para 2) pass by reference (const )
    {
        return os << '(' << real(x) << ',' << imag(x) << ')' ;
    }

## return by value Vs return by reference (to const)


    template< typename T> 
    class complex
    {
        public:
            complex(T r = 0, T i = 0)  
                : re(r), im (i)
            {}

            complex& operator += (const complex& ); // ---> return by reference
            T real() const { return re; }  // ----> return by value 
            T imag() const { return im; } 
        private:  
            T re, im; 

        friend complex & __doapl (complex* , const complex&);  // ------> return by reference
    };

    ostream & operator << (ostream &os, const complex& x) // ------> return by reference
    {
        return os << '(' << real(x) << ',' << imag(x) << ')' ;
    }   


## friend 

    template< typename T> 
    class complex
    {
        public:
            complex(T r = 0, T i = 0) 
                : re(r), im (i)
            {}

            complex& operator += (const complex& ); 
            T real() const { return re; } 
            T imag() const { return im; } 
        private:  
            T re, im;  // ----------------->    外部不能随意取数据

        friend complex & __doapl (complex* , const complex&);  // --------> 对这个函数是我的朋友可以访问我的私有成员
    };

    inline complex &
    __doapl( complex * ths, const complex & r)
    {
        ths-> re += r.re;
        rhs-> im += r.im;
        return *this;
    }

    ostream & operator << (ostream &os, const complex& x) 
    {
        return os << '(' << real(x) << ',' << imag(x) << ')' ;
    }

## 相同class的各个object互为friend

    class complex {
        public:
        complex( double r = 0, double i = 0)
            : re(r), im(i)
        {}

        int func(const complex & param) // -------------
        {
            return param.re + param.im;
        }
        private:
            double re, im;
    };

    {
        complex c1(2, 1);
        complex c2;

        c2.func(c1);
    }

## class body 外部各种定义

什么情况下可以 pass by reference
什么情况下可以 return by reference


    do assignment plus

    inline complex& 
    __doapl (complex* ths, const complex& r)
    {
        ths-> re += r.re; // 第一个参数将会被改变
        ths-> im += r.im; // 第二个参数不会被改变
        return *this;
    }

    inline complex &
    complex::operator += (const complex& r)
    {
        return __doapl(this, r);
    }

     a += b;  // 可以传引用

     c = a + b; // return by reference 是错误的 不可以传引用

参数和返回的传递首先考虑传引用，考虑行不行呢，再进一步的区分。

## 操作符重载   operator overloading (成员函数) this

    inline complex& 
    __doapl (complex* ths, const complex& r)
    {
        ths-> re += r.re; // 第一个参数将会被改变
        ths-> im += r.im; // 第二个参数不会被改变
        return *this;
    }

    inline complex &
    complex::operator += (const complex& r)
    {
        return __doapl(this, r);
    }


    {
        complex c1(2, 1);
        complex c2(5);

        c2 += c1;

        c2(this) <----> c1(r)
    }

    inline complex& complex::operator += (this, const complex& r)
    {
        return __doapl(thism r);
    }


## return by reference 语法分析

传递着无需知道接受者是以reference形式接受

    inline complex& // ----> refenence 接收
    __doapl (complex* ths, const complex& r)
    {
        ths-> re += r.re; // 第一个参数将会被改变
        ths-> im += r.im; // 第二个参数不会被改变
        return *this; // *******
    }

    inline complex & // ----> refenence 接收
    complex::operator += (const complex& r)
    {
        return __doapl(this, r); 
    }


    {
        complex c1(2, 1);
        complex c2(5);

        c2 += c1;
    }

## class body 之外各种定义

    inline double imag(const complex& x)
    {
        return x.imag();
    }

    inline double real(const complex& x)
    {
        return x.real();
    }

## operator overloading (操作符重载 非成员函数) 无this

为了应对client的三种可能用法， 这对应开发三个函数

    inline complex 
    operator + (const complex &x, const complex& y){
        return compelx( real(x) + real(y), 
                        imag(x) + imag(y));
    }

    inline complex operator + (const complex& x, double y)
    {
        return complex( real(x), imag(y));
    }

    inline complex operator + (double x, const complex & y)
    {
        return complex (x + real(y), imag(y));
    }

## temp object 临时对象  | typename();

下面这些函数绝对不可以return by reference 
因为， 返回的是 local object

      inline complex 
    operator + (const complex &x, const complex& y){
        return compelx( real(x) + real(y), 
                        imag(x) + imag(y));
    }

    inline complex operator + (const complex& x, double y)
    {
        return complex(real (x), imag(y)); // 创建的临时对象 typename()
    }

    inline complex operator + (double x, const complex & y);

