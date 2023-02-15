# 《Windows高级编程》学习笔记

早期的 客户机 是用 win95，服务器是 Windows NT。

![1-1](D:\0-博客\study_log\《Windows高级编程》\1-1.png)

win32 API 是什么。

![1-3](D:\0-博客\study_log\《Windows高级编程》\1-3.png)

win32 实现在 4 种平台上。

![1-2](D:\0-博客\study_log\《Windows高级编程》\1-2.png)

Windows NT 的防御机制。

![1-4](D:\0-博客\study_log\《Windows高级编程》\1-4.png)

注意 内核和硬件抽象层。

![1-5](D:\0-博客\study_log\《Windows高级编程》\1-5.png)

Windows NT 支持多 CPU。

![1-6](D:\0-博客\study_log\《Windows高级编程》\1-6.png)

Win32 好像是有 pipe 管道的。

![1-8](D:\0-博客\study_log\《Windows高级编程》\1-8.png)

内核对象的安全性。

![1-9](D:\0-博客\study_log\《Windows高级编程》\1-9.png)

用户对象，设备对象与内核对象。

![2-1](D:\0-博客\study_log\《Windows高级编程》\2-1.png)

进程间通信方式。

![2-2](D:\0-博客\study_log\《Windows高级编程》\2-2.png)

每个线程有自己的 CPU 寄存器组和自己的栈。

![2-3](D:\0-博客\study_log\《Windows高级编程》\2-3.png)

Win95 不支持多线程并发，WinNT 支持。

![2-4](D:\0-博客\study_log\《Windows高级编程》\2-4.png)

![2-5](D:\0-博客\study_log\《Windows高级编程》\2-5.png)

CUI 与 GUI。

![2-6](D:\0-博客\study_log\《Windows高级编程》\2-6.png)

注意，进程的环境变量。

![2-7](D:\0-博客\study_log\《Windows高级编程》\2-7.png)

驱动器的目录是有多个的。

![2-8](D:\0-博客\study_log\《Windows高级编程》\2-8.png)

线程的运行过程。

![3-1](D:\0-博客\study_log\《Windows高级编程》\3-1.png)

繁琐的 PeekMessage 功能。

![3-2](D:\0-博客\study_log\《Windows高级编程》\3-2.png)

窗口部件共享一个线程。

![3-3](D:\0-博客\study_log\《Windows高级编程》\3-3.jpg)

Windows 启动线程的函数 StartOfThread，位于 KERNEL32.DLL

![3-4](D:\0-博客\study_log\《Windows高级编程》\3-4.png)

执行线程栈的大小，默认是 1 M。

![3-5](D:\0-博客\study_log\《Windows高级编程》\3-5.png)

栈限制，阻止应用程序用光大量物理内存。

![3-6](D:\0-博客\study_log\《Windows高级编程》\3-6.png)

TerminateThread 函数不能释放栈。

![3-7](D:\0-博客\study_log\《Windows高级编程》\3-7.png)

Windows 的线程调度算法。

![3-8](D:\0-博客\study_log\《Windows高级编程》\3-8.png)

_beginthreadex 函数是 C运行时库的函数。

![3-9](D:\0-博客\study_log\《Windows高级编程》\3-9.png)

![4-1](D:\0-博客\study_log\《Windows高级编程》\4-1.png)

![4-2](D:\0-博客\study_log\《Windows高级编程》\4-2.png)
