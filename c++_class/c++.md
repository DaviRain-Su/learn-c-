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

    class A{ // -----------------> Singleton 单体模式
        public:
        
            static A& geyInstance();
            setup() { ... }
        private:
            A();
            A(const A& rhs);
            ...
    };

    A& A::getInstance() 
    {
        static A a;
        return a;
    }

    A::getInstance().setup(); // call function

## const member fcuntion 


    double real() const { return re; } // --------> const 表示不改变数据
    double imag() const { return im; }

    {
        const complex c1(2, 1); // const object
        cout << c1.real(); // if real() is not const lable will be error , then say to me double real(); will change the word
        cout << c1.imag(); // if imag() is not const lable will be error 
    }

            