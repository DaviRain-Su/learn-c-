#include "Thread.h"

#include <iostream>
using std::endl;
using std::cout;

void Thread::start()
{
    //线程的创建
    // int pthread_create(pthread_t * thread, const pthread_attr_t *att, void*(*start_routinr), void *args);
    pthread_create(&_pthid,nullptr, threadfunc, this); 
    _isRuning = true;
}

void* Thread::threadfunc(void *args)
{
    Thread *pthread = static_cast<Thread*>(args);
    if(pthread)
        pthread->run();
    return nullptr;
}

void Thread::join()
{
    if(_isRuning)
        pthread_join(_pthid, nullptr);//将线程的资源交还给系统
}

Thread::~Thread()
{
    if(_isRuning)
        pthread_detach(_pthid);
}