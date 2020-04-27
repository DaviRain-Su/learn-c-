#pragma once

#include "Noncopyable.h"

#include <pthread.h>

class Thread
: Noncopyable
{
public:
    Thread()
    : _pthid(0),
    _isRuning(false){}
    
    void start();//pthread_create();
    void join();//pthread_join();
    virtual ~Thread();// pthread_detach();
    
private:
    virtual void run()=0;//纯虚函数, 代执行的任务
    static void* threadfunc(void* args);
private:
    pthread_t _pthid;
    bool _isRuning;
};

