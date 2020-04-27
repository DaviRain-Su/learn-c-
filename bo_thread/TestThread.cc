#include "Thread.h"

#include <stdlib.h>//rand(), srand()
#include <time.h>//clock();
#include <unistd.h>//sleep();

#include <iostream>
#include <memory>
using namespace std;

class MyTask 
{
public:
    void run()//虚函数的继承覆盖
    {
        ::srand(::clock());

        int cnt = 20;
        while(cnt--){
            int number = ::rand() % 10;
            cout << "sub thread " << pthread_self() << " :number =  " << number << endl;
            sleep(1);
        }
    }
};
void run(int)//虚函数的继承覆盖
{
        ::srand(::clock());

        int cnt = 20;
        while(cnt--){
            int number = ::rand() % 10;
            cout << "sub thread " << pthread_self() << " :number =  " << number << endl;
            sleep(1);
        }
}


int main()
{
    //unique_ptr<Thread> thread(new Thread(std::bind(&MyTask::run, MyTask()))); //MyTask()临时对象
    //std::bind(&MyTask::run, MyTask())
    unique_ptr<Thread> thread(new Thread(std::bind(run, 1)));
    thread->start();

    thread->join();

    //MyThread thread1;

    //MyThread thread2 = thread1; //派生类的构造函数调用基类的构造函数， 派生没有显示定义自己的复制构造函数，会调用基类的复制控制构造函数。
    //当派生类定义了自己的复制构造函数会调用自己的复制控制构造函数。

    
    return 0;
}