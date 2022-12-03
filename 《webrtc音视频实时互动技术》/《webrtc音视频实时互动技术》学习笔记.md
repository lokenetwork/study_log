# 《webrtc音视频实时互动技术》学习笔记

注意这个 Dash 的格式，咱们最好写一篇文章，hls 以及 rtmp，以及 dash 的格式分析。

![1-1](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-1.png)

各平台的采集模块。

![1-2](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-2.png)

什么是 3A 问题？

![1-3](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-3.png)

超过阈值之后，再加大码率就没有意义了。

![1-4](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-4.png)

Webrtc 的选路策略注意看一下。

![1-5](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-5.png)

最近接入。

![1-6](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-6.png)

减少数据量的方法。

![1-7](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-7.png)

Webrtc 的抖动时长是 10ms 。

![1-8](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-8.png)

MediaStream 与 MediaStreamTrack ，两个重要的概念。

![1-9](D:\0-博客\study_log\《webrtc音视频实时互动技术》\1-9.png)

结构与标准不符合。用的是草案。

![2-1](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-1.png)

Candidate 的优先级，host，也就是本地，默认应该是局域网优选的。

![2-2](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-2.png)

一边收集，一边交换。

![2-3](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-3.png)

ICE 机制。

![2-4](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-4.png)

webrtc 连接顺序，内网，P2P，relay。

![2-5](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-5.png)

注意 RFC3489 与 RFC5389 这两个文档。

![2-6](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-6.png)

NAT 的类型检测，怎么知道自己是那种 NAT。

![2-7](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-7.png)

TURN 协议中转。

![2-8](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-8.png)

注意这个 coturn 服务器。

![2-9](D:\0-博客\study_log\《webrtc音视频实时互动技术》\2-9.jpg)

SDP 中的会话描述以及媒体描述。

![3-1](D:\0-博客\study_log\《webrtc音视频实时互动技术》\3-1.png)

注意 sdp 中的这些缩写。

![3-2](D:\0-博客\study_log\《webrtc音视频实时互动技术》\3-2.png)

webrtc 的 sdp 与 标准的 sdp 是有区别的。

![3-3](D:\0-博客\study_log\《webrtc音视频实时互动技术》\3-3.png)

注意 ORTC，微软出的。

![3-4](D:\0-博客\study_log\《webrtc音视频实时互动技术》\3-4.png)

TCP 为什么不够实时。

![3-5](D:\0-博客\study_log\《webrtc音视频实时互动技术》\3-5.png)

考虑把这些功能 NACK，FEC，Jitter-Buffer 全部搬到 UDT 里面

![3-6](D:\0-博客\study_log\《webrtc音视频实时互动技术》\3-6.png)
