# 《深入浅出MFC》学习笔记1

MFC 的全称是 Microsoft Foundation Classes 。微软基础类库。





> MFC 势将成为 Windows 环境上标准的 C++ API（我个人认为这句话已成为事实）。





> MFC 其实就是把 Windows API 做了一层薄薄的包装。





> LIBC.LIB - 这是C Runtime 函数库的静态链接版本。
> MSVCRT.LIB   - 这是C   Runtime 函数库动态链接版本（MSVCRT40.DLL）的 import 函数库。如果链接此一函数库，你的程序执行时必须有  MSVCRT40.DLL 在场。



LIB 导入库。

> 另一组函数，Windows API，由操作系统本身（主要是 Windows 三大模块 GDI32.DLL 和 USER32.DLL 和 KERNEL32.DLL）提供（注）。虽说动态链接是在运行时才发生「链接」事实，但在链接时期，链接器仍需先为调用者（应用程序本身）准备一些适当的资讯，才能够在运行时顺利「跳」到  DLL 执行。如果该  API 所属之函数库尚未加载，系统也才因此知道要先行加载该函数库。这些适当的信息放在所谓的「import 函数库」中。32 位 Windows 的三大模块所对应的 import 函数库分别为 GDI32.LIB 和 USER32.LIB 和 KERNEL32.LIB。



线程优先级。

> 优先权是排程的重要依据。优先权高的线程，永远先获得CPU的青睐。当然啦，作业系统会视情况调整各个线程的优先权。例如前台线程的优先权应该调高一些，后台线程的优先权应该调低一些。

![dissecting-mfc-1-1](dissecting-mfc-1-1.png)



4中不同的对象生存方式。

> 既然谈到了static对象，就让我把所有可能的对象生存方式及其构造函数调用时机做个整理。所有作法你都已经在前一节的小程序中看过。
> 在C++ 中，有四种方法可以产生一个对象。第一种方法是在堆栈（stack）之中产生它：
> void MyFunc()
> {  
>     CFoo foo;  // 在堆栈（stack）中产生 foo 对象
>     ...
> }
>
> 第二种方法是在堆积（heap）之中产生它：
> void MyFunc()
> {
>     ...
>     CFoo* pFoo = new CFoo(); // 在堆积（heap）中产生对象
> }
>
> 第三种方法是产生一个全局对象（同时也必然是个静态对象）：
> CFoo foo; // 在任何函数范围之外做此动作
>
> 第四种方法是产生一个局部静态对象：
> void MyFunc()
> {
>     static CFoo foo;  // 在函数范围（scope）之内的一个静态对象
>     ...
> }



this 是编译器传递给函数的隐藏参数。

> 这个this参数是编译器自行为我们加上的，所以我说它是个 "隐藏指针"。



C++ RTT1

> 这个程序与RTTI相关的地方有三个：
> 1. 编译时需选用/GR 选项（/GR 的意思是enable C++ RTTI）







