# 《Windows程序设计第五版》学习笔记

图形显示接口就是 GDI，实际上就是显卡的接口，或者说是 显示器的接口。

![1-1](1-1.png)

这本中译本是 10 年后才出的。

![1-2](1-2.png)

翻译的技巧。

![1-3](1-3.png)

注意计时器。

![1-4](1-4.png)

注意，视频显示器也是用户输入的一部分。

![1-5](1-5.png)

早期是非抢占型的。

![1-6](1-6.png)

Windows 本身就是一套动态链接程序库。

![1-7](1-7.png)

动态链接是 Windows 先搞出来的东西。

![1-8](1-8.png)

3个关键的动态链接库。

![1-9](1-9.png)

大部分的编程语言都是在 API 上加一层编程语言。

![2-1](2-1.png)

C语言的发明者，同时研发了 unix 操作系统。

![2-2](2-2.png)

sz 意思是 String Terminated with a zero。

![2-3](2-3.png)

Prev 参数没有用了。

![2-4](2-4.png)

`VCVARS32.BAT` 脚本就是用来设置环境变量的。

![2-5](2-5.png)

Windows 环境是 NMAKE。



内存范围。

![2-6](2-6.png)

L 的作用。

![2-7](2-7.png)

 UTF8 是变长编码



Windows 不存在标准输入 和 标准输出的概念。

![2-8](2-8.png)

注意消息队列。

![2-9](2-9.png)

注意，匈牙利标记法，前面的类型。

![3-1](3-1.png)

![3-2](3-2.png)

`lpfn` 的含义，"指向函数的长指针"。

![3-3](3-3.png)

这几个东西是有规律的。

![3-4](3-4.png)

`SendMessage` 可以主动发消息。

![3-5](3-5.png)

注意多线程的情况。

![3-6](3-6.png)

以前的操作系统不是抢占式的。

![3-7](3-7.png)

我靠，Windows 遮住了需要重新绘制的。

![3-8](3-8.png)

GDI 不是完全硬件隔离的。

![3-9](3-9.png)

多线程的概念。

![4-1](D:\0-博客\study_log\《Windows程序设计第五版》\4-1.png)

Windows 里传输数据的方式，剪切板，DDE 等等。

![4-2](D:\0-博客\study_log\《Windows程序设计第五版》\4-2.png)

Windows 的鼠标胖的沙漏图标，这是经典。

![4-3](D:\0-博客\study_log\《Windows程序设计第五版》\4-3.png)

![4-3-2](D:\0-博客\study_log\《Windows程序设计第五版》\4-3-2.png)

1/10 秒规则。

![4-4](D:\0-博客\study_log\《Windows程序设计第五版》\4-4.png)

原来 16 位会加两次，他说的是一个写，一个读，而不是两个写。

![4-5](D:\0-博客\study_log\《Windows程序设计第五版》\4-5.png)

注意这个 _beginthread 函数。

![4-6](D:\0-博客\study_log\《Windows程序设计第五版》\4-6.png)

`/MT` 标记。

![4-7](D:\0-博客\study_log\《Windows程序设计第五版》\4-7.png)

Sleep 可以传 0 ，让操作系统重新调度需要的线程。

![4-8](D:\0-博客\study_log\《Windows程序设计第五版》\4-8.png)

Windows 系统的进程间互斥。

![4-9](D:\0-博客\study_log\《Windows程序设计第五版》\4-9.png)

Windows 的 TLS，线程本地存储功能。

![5-1](D:\0-博客\study_log\《Windows程序设计第五版》\5-1.png)

静态库就是对象库，而导入库是用来包含重定位表格啥的。

![5-2](D:\0-博客\study_log\《Windows程序设计第五版》\5-2.png)

注意 DLL 的入门，DLLMain。

![5-3](D:\0-博客\study_log\《Windows程序设计第五版》\5-3.png)

DLL 里面的共享内存。

![5-4](D:\0-博客\study_log\《Windows程序设计第五版》\5-4.png)

动态链接库中的任何一个能够被其他 Windows 程序或动态库引用的函数必须被导出。

---

音频处理概念。

![5-6](D:\0-博客\study_log\《Windows程序设计第五版》\5-6.jpg)

注意这两个网络套件，WinSock 与 WinInet

![5-7](D:\0-博客\study_log\《Windows程序设计第五版》\5-7.jpg)

![5-8](D:\0-博客\study_log\《Windows程序设计第五版》\5-8.png)

![5-9](D:\0-博客\study_log\《Windows程序设计第五版》\5-9.png)
