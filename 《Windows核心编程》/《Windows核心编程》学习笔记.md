# 《Windows核心编程》学习笔记

Thread-local Storage 用来存储错误码，线程间不相互干扰。

> 从系统内部来讲，当一个Wi n d o w s 函数检测到一个错误时，它会使用一个称为线程本地存储器(thread-local storage )的机制，将相应的错误代码号码 与调用的线程关联起来(线程本地存储器将在第2 1 章中介绍）。这将使线程能够互相独立地运行，而不会影响各自的错误代码。



VS 的 watch ，里面可以写两个的。一个是 hr 限定符。

![win-kernel-1-1](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-1.png)

Windows 对安全的重视程度。

> 



字符集

> 日文中的汉字，如果第一个字符在0 x 8 1 与0 x 9 F 之间，或者在0 x E 0 与0 x F C 之间，那么就必须观察下一个字节，才能确定字符串中的这个完整的字符。



导出 ANSI 跟 Unicode DLL 函数。

> 





![win-kernel-1-2](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-2.png)

/GS 标记检测缓冲区是否溢出。

![win-kernel-1-3](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-3.png)



实时操作系统。





用户模式和内核模式切换，通常占用 1000个 周期以上。



SwitchToThread 可以让线程主动让出 CPU。



高速缓存行。

![win-kernel-1-4](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-4.png)

微软平台很多函数其实封装得很多，关键段里面自带了自旋锁。

![win-kernel-1-5](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-5.jpg)



纤程是为了兼容 Unix 系统。

![win-kernel-1-6](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-6.png)



空指针区域。

![win-kernel-1-7](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-7.png)

![win-kernel-1-8](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-8.png)



内核的内存会映射到进程空间的。

![win-kernel-1-9](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-1-9.png)

DLL 的加载过程。

![win-kernel-2-1](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-2-1.png)

堆的意义，为什么要创建额外的堆。





提供另一个函数来释放内存。

![win-kernel-2-2](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-2-2.png)



DLL 注入：

![win-kernel-2-3](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-2-3.png)



Try Catch 就是把 正常逻辑 跟 异常逻辑分开处理。

![win-kernel-2-4](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-2-4.png)

Try 里面的 Return 的实现。局部展开。

![win-kernel-2-5](D:\0-博客\学习笔记\《Windows核心编程》\win-kernel-2-5.png)
