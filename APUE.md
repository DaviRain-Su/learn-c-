# 文件I/O

文件I/O函数 - 打开文件，读文件，写文件等。
unix系统中大多数文件IO只用到了5个函数，open， read， write， lseek以及close。
然后说明不同缓冲区长度对read和write函数的影响。

本章所有的函数都是不带缓冲的IO（ unbuffered IO).
术语中的不带缓冲指的是每个read和write都调用内核中的一个系统调用。
这些不带缓冲的IO函数不是ISO C的组成部分，但是他们是POSIX 1 和Single UNIX Specification的组成部分。

只要设计在多个进程间共享资源，原子操作就变得非常重要。通过文件IO和open函数的参数来讨论此概念。进一步讨论在多进程间如何共享文件，
以及所涉及的内核数据结构。
将说明dup， dcntl， sync， fsync 和ioctl函数。

## 文件描述符

对于内核来说，所有打开的文件都是通过文件描述符引用。文件描述符是一个非负数，当打开一个现有文件或者创建一个新文件时，内核向进程返回一个文件描述符，
当读或者写一个文件时，使用open或者create返回的文件描述符标示该文件，将其作为参数传递给read或write。

按照管理，UNIX系统shell使用文件描述符0于进程的标准输入相关联。文件描述符1与标准输出相关联，文件描述符2与标准出错输出相关联。

幻数0， 1， 2， 应当替换成符号常量STDIN_FILENO， STDOUT_FILENO和STDERR_FILENO.这下都定义在头文件<unistd.h>

文件描述符的变化范围是0～OPEN_MAX。linux2.3.22对于每个进程的文件描述符数的硬限制1 048 576.

## open函数

调用open函数可以打开或创建一个文件。
#include <fcntl.h>
int open(const char *pathname, int oflags, .../* mode_t mode */);
返回值： success return fd， failed return -1；

将第三个参数写为..., ISO C 用这种方法表明余下参数的数量以及其类型根据具体的调用会有所不同。

对于open函数而言， 仅在创建新文件时才使用第三个参数。在函数原型中将此参数放置在注释。

pathname是要打开或创建的文件的名字。oflags参数可用来说明此函数的多个选项。
用下列一个或者多个常量进行 或 运算构成 oflag参数， 这些常量定义在<fcntl.h>

O_RDONLY 只读打开
O_WRONLY 只写打开
O_RDWR 读写打开
  