# item1：视c++为一个语言联邦
    C++高效编程守则视情况而变化，取决于你使用C++的那一部分。
# item 2: 尽量以const，enum，inline替换#define 
    宁以编译器替换预处理器

    #define ASPECT_RATIO 1.653 
    const double AspectRatio = 1.653; 替换上面的那个

    当我们以常量替换#define，有两种特殊情况，
    第一，定义常量指针。由于常量定义式通常放在头文件内，（以便被不同的源码含入），因此有必要将指针（而不是指针所指之物）
    声明为const。
    例如若要在头文件内定义一个常量的（不变的）char*-based字符串，必须写两次const；
    const char* cosnt authorName = “Scott Meyers”；

    const的使用见条款3.

    const std::string authorName("Scott Meyers");

    第二个，calss专属常量。为了将常量的作用域限制于class内，必须让他成为class的一个成员；而为确保次常量至多只有一份实体，
    必须让他成为一个static成员；

    class GamePlayer {
        private:
            static const int NumTurns = 5;//常量声明式
            int scores[NumTruns];//使用该常量
            ...
    };

    通常要求对所使用的任何东西提供一个定义式，但是如果它是class专属常量有时static且为整数类型，则需要特殊处理。
    只要不取他们的地址，可以声明并使用他们而无须提供定义式。
    但是如果你取了某个class专属常量的地址，或即使你不取地址而你的编译器却坚持要看到一个定义式，必须另外提供定义式：

    const int GamerPlayer::NumTurns;//NumTurns的定义式 
    要把这个式子放在一个实现文件中而不是头文件。由于class常量已在声明时获得初值，因此定义式不可以再设置初值。


    旧式编译器也许不支持上述语法，他们不允许static成员在其声明式上获得初值，此处所谓的**in-clas初值设定**，也只允许对整数常量进行。

    class CostEstimate {
        private:
            static const double FudgeFactor;//static class常量声明位于头问津中。
        ...
    };
    const double CostEstimate::FudgeFactor = 1.35;//static class 常量定义位于实现文件内

    但是，例外的式在class编译期间需要一个class常量值。例如第一个例子中的 一个数组需要一个常量作为数组的长度来初始化。
    这是可以该用 the enum hack 补偿做法， 理论就是， 一个属于枚举类型的数值可权充ints被使用。

    class GamePlayer {
        private:
            enum { NumTruns = 5};

            int scores[NumTuns];
            ...
    };

    特点：1， enum hack的行为某些方面比较像#define而不是const， 例如取一个const的地址是可以的，而一个#define的地址是非法的，enum也是。
    如果不想让别人获得一个pointer或reference指向你的某个整数常量，enum可以实现这个约束。

    item18， 通过馔码时的决定实施设计上的约束条件。
    enum和#define一样绝不会导致非必要的内存分配。

    enum hack 是 template mataprogramming 模版元编程的基础技术。

    有了const， enum， inline，对于预处理器的需求降低了，但是并未消除。#include仍然是必须品，
    #ifdef/#ifndef也继续扮演者重要的角色。

    **对于单纯常量，最好以const对象或enum替换#define**
    **对于形似函数的宏，做好该用inline函数替换#define**