# 《深入理解Linux网络》学习笔记

Java 的 NIO 跟 Golang 的 net 包 只是对 epoll 的包装。



这种 ... 的伪代码风格不错，学习。

![linux-net-1-1](linux-net-1-1.png)



查看 RingBuffer 满没满。 overruns。

![linux-net-1-2](linux-net-1-2.png)

 RingBuffer 满 是丢弃后面的，不是丢弃前面的。

![linux-net-1-3](linux-net-1-3.png)



查看 CPU 执行了多少次软中断。

![linux-net-1-4](linux-net-1-4.png)



sendfile 函数的零拷贝。

![linux-net-1-5](linux-net-1-5.png)



用 哈希表管理半链接状态，udp 实现的 也可以参考这种做法。

![linux-net-1-6](linux-net-1-6.png)



半链接队列长度。

![linux-net-1-7](linux-net-1-7.png)

内核的保留端口参数。

![linux-net-1-8](linux-net-1-8.png)



端口不足导致 connect 自旋锁不断执行。

![linux-net-1-9](linux-net-1-9.png)



file-max 不限制 root 用户。

![linux-net-2-1](linux-net-2-1.png)



客户端还是阻塞性的。可以考虑用协程。

![linux-net-2-2](linux-net-2-2.png)



SYN 的 TCP 重传，可能是服务器的连接队列有问题。

![linux-net-2-3](linux-net-2-3.png)



关注公众号，获取配套源码这个法子不错。

![linux-net-2-4](linux-net-2-4.png)

注意 Docker 的Brige 。

![linux-net-2-5](linux-net-2-5.png)
