# 《Windows用户态程序高效排错》学习笔记

explorer 的 process affinity，自动传播

![1-1](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-1.png)

![1-2](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-2.png)

增加数据量来查找 内存泄漏。

![1-3](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-3.png)

 0xcdcdcdcd 是堆内存的默认值。

![1-4](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-4.png)

几个星期没找到问题是很正常的。

![1-5](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-5.png)

WinDbg 的能做到的事情。

![1-6](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-6.png)

PDB 文件包含的就是调试信息。

![1-7](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-7.png)

address 命令可以检查内存页的属性。

![1-8](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-8.png)

WinDbg 查看局部变量的方法。

![1-9](D:\0-博客\study_log\《Windows用户态程序高效排错》\1-9.png)

想到以前网友提到的问题，加载的 DLL 不对，导致运行报错。我当时建议是用 dumpbin /DEPENDECS 查看 依赖的 DLL。
现在发现有个更方便的方法，直接 WinDbg 调试，用 lmf 就可以查看 exe 运行时加载的 DLL，而且是全路径的，排查起来更方便。

![2-1](D:\0-博客\study_log\《Windows用户态程序高效排错》\2-1.jpg)

X 命令可以查找函数的地址。

![2-2](D:\0-博客\study_log\《Windows用户态程序高效排错》\2-2.png)

.frame 切换函数的栈，查看局部变量。

dt 可以格式化查看变量的结构。

![2-3](D:\0-博客\study_log\《Windows用户态程序高效排错》\2-3.png)

强大的自定义功能。

![2-4](D:\0-博客\study_log\《Windows用户态程序高效排错》\2-4.png)

WinDbg 的远程调试功能，.server

![2-5](D:\0-博客\study_log\《Windows用户态程序高效排错》\2-5.png)
