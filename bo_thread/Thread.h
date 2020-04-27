#pragma once

#include "Noncopyable.h"

#include <pthread.h>
#include <functional>
using std::function;

class Thread
: Noncopyable
{
public:
    using ThreadCallback = function<void()>;
    Thread(ThreadCallback && cb)
    : _pthid(0),
    _isRuning(false),
    _cb(std::move(cb))//注册了回调函数
    {}
    
    void start();//pthread_create();
    void join();//pthread_join();
    ~Thread();// pthread_detach();
private:
    //virtual void run()=0;//纯虚函数, 代执行的任务
    static void* threadfunc(void* args);
private:
    pthread_t _pthid;
    bool _isRuning;
    ThreadCallback _cb;
};

