#include "Thread.h"

#include <stdlib.h>//rand(), srand()
#include <time.h>//clock();
#include <unistd.h>//sleep();

#include <iostream>
#include <memory>
using namespace std;

class MyThread 
: public Thread
{
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



int main()
{
    unique_ptr<Thread> thread(new MyThread());
    thread->start();

    thread->join();

    //MyThread thread1;

    //MyThread thread2 = thread1;
    
    return 0;
}