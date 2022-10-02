# 深入解析Windows操作系统卷一学习笔记

WDK 与 SDK 的区别。

![windows-internal-1-1](windows-internal-1-1.png)



Windows 的版本迭代。

![windows-internal-1-2](windows-internal-1-2.png)

获取Windows 版本号 的方法。

![windows-internal-1-3](windows-internal-1-3.png)



注意看 COM 技术。

![windows-internal-1-4](windows-internal-1-4.png)

WinJS 使用 Windows api。

![windows-internal-1-5](windows-internal-1-5.png)



.Net Framework 默认。

![windows-internal-1-6](windows-internal-1-6.png)



界面可相应：

![windows-internal-1-7](windows-internal-1-7.png)



对象与句柄。

![windows-internal-1-8](windows-internal-1-8.png)





Windows 的字符集。

![windows-internal-1-9](windows-internal-1-9.png)



Windows 工具大全。

![windows-internal-2-1](windows-internal-2-1.png)



Windows 的大部分内核代码都是 C语言写的。

![windows-internal-2-2](windows-internal-2-2.png)

![windows-internal-2-3](windows-internal-2-3.png)



Windows 的对称多处理器系统。

![windows-internal-2-4](windows-internal-2-4.png)



异构CPU。

![windows-internal-2-6](windows-internal-2-6.png)



注意一下 SUA 子系统。



Pico 进程是 WSl 的基础。

![windows-internal-2-7](windows-internal-2-7.png)

![windows-internal-2-8](windows-internal-2-8.png)



WinDbg 断点停下的地方。

![windows-internal-2-9](windows-internal-2-9.png)

注意 syscall 指令。

![windows-internal-3-1](windows-internal-3-1.png)

打开默认文件是通过 Windows Shell 实现的。

![windows-internal-3-2](windows-internal-3-2.png)



Process Explorer 查看进程的颜色。

![windows-internal-3-3](windows-internal-3-3.png)

时间片原来叫 量程 quantum。

![windows-internal-3-4](windows-internal-3-4.png)



调度器的实现是分散的。

![windows-internal-3-5](windows-internal-3-5.png)



可以修改  CPU 密集型进程的优先级，使其不至于影响到常规系统的操作。

![windows-internal-3-6](windows-internal-3-6.png)



Windows 的实时优先级的意义。

![windows-internal-3-7](windows-internal-3-7.png)



CMD 指定优先级启动程序。

![windows-internal-3-8](windows-internal-3-8.png)



注意 CPU Stress 工具。



CPU 饥饿导致的优先级反转。

![windows-internal-3-9](windows-internal-3-9.png)



内存飞地保护。

![windows-internal-4-1](windows-internal-4-1.png)



IO 系统实际上就是把各种设备的二进制数据读进去内存，例如 硬盘数据，麦克风数据，摄像头的视频数据，还有鼠标键盘的输入数据，这些都是二进制数据。

这些都是数字设备。只不过做了分层设计，分层能让整个系统更通用。所以电脑叫通用计算机系统。

分层，通用是有代价的，会牺牲性能，这也就是SOC芯片为什么功能不错，又便宜，因为从某种角度来看，SOC芯片牺牲了通用性。

但是分层的好处也是显而易见的，可以产生更丰富的生态。给一堆积木，上层可以搭建各种东西。

![windows-internal-4-2](windows-internal-4-2.png)



注意 IO 系统。

![windows-internal-4-3](windows-internal-4-3.png)



注意快速 IO。

![windows-internal-4-4](windows-internal-4-4.png)

![windows-internal-4-5](windows-internal-4-5.png)



Windows 本身就有比 Linux epoll 更优的 IO 操作方式。

![windows-internal-4-6](windows-internal-4-6.png)



Windows 有 IO 优先级。

![windows-internal-4-7](windows-internal-4-7.png)





驱动验证程序可以测试驱动。
