# 《Android音视频开发》学习笔记

注意这几个 Android 的音视频组件。

![1-1](D:\0-博客\study_log\《Android音视频开发》\1-1.png)

注意这个 DicX ，好像经常遇到。

![1-2](D:\0-博客\study_log\《Android音视频开发》\1-2.png)

MP3 的压缩原理。

![1-3](D:\0-博客\study_log\《Android音视频开发》\1-3.png)

什么是 5.1 声道。

![1-4](D:\0-博客\study_log\《Android音视频开发》\1-4.png)

注意这里音频帧的概念 与 讲解。

![1-5](D:\0-博客\study_log\《Android音视频开发》\1-5.png)

声道的概念。

![1-6](D:\0-博客\study_log\《Android音视频开发》\1-6.png)

![1-7](D:\0-博客\study_log\《Android音视频开发》\1-7.jpg)

小米盒子 ROM 引入了 VLC 多媒体框架。

![1-8](D:\0-博客\study_log\《Android音视频开发》\1-8.png)

AwesomePlayer 过时了，NuPlayer 才是正道。

![1-9](D:\0-博客\study_log\《Android音视频开发》\1-9.png)

OpenMAX 编解码框架。

![2-1](D:\0-博客\study_log\《Android音视频开发》\2-1.png)

注意这个 MediaCodec 。

![2-2](D:\0-博客\study_log\《Android音视频开发》\2-2.png)

MediaCodec 硬解码。

![2-3](D:\0-博客\study_log\《Android音视频开发》\2-3.png)

修改动态库 so 的后缀名。

![2-4](D:\0-博客\study_log\《Android音视频开发》\2-4.png)

编译 JNI 的 so 的脚本。

![2-5](D:\0-博客\study_log\《Android音视频开发》\2-5.png)

注意这两个字段。

![2-6](D:\0-博客\study_log\《Android音视频开发》\2-6.png)

AVPacket 可以没有编码数据，只有 side data。

![2-7](D:\0-博客\study_log\《Android音视频开发》\2-7.png)

AVPacket 是在栈上面的。不过现在好像改了，在堆，或者在栈里面都可以。

![2-8](D:\0-博客\study_log\《Android音视频开发》\2-8.png)

SDL 里面也是调的 OpenGL。

---

美颜库介绍，GPU Image。

![2-9](D:\0-博客\study_log\《Android音视频开发》\2-9.png)

推流优化，先发音频数据，保证用户能听到声音。

![3-1](D:\0-博客\study_log\《Android音视频开发》\3-1.png)

IJkPlayer 是基于 Android 的 MediaPlayer 扩展来的。

![3-2](D:\0-博客\study_log\《Android音视频开发》\3-2.png)

他这本书讲了很多工程经验。

![3-3](D:\0-博客\study_log\《Android音视频开发》\3-3.png)

注意这个播放器的弱网优化。

![3-4](D:\0-博客\study_log\《Android音视频开发》\3-4.png)

注意这个 HttpDNS 技术。

![3-5](D:\0-博客\study_log\《Android音视频开发》\3-5.png)

最后讲了 H.264 的码流结构。

![3-6](D:\0-博客\study_log\《Android音视频开发》\3-6.png)

H.264 只是表述了编码器的句法。

注意这个 序列的开始跟结束。

![3-7](D:\0-博客\study_log\《Android音视频开发》\3-7.png)

IDR 帧是不是只要放在开头的就是 IDR，结构跟 I 帧是一样的？

![3-8](D:\0-博客\study_log\《Android音视频开发》\3-8.png)

I ,P B 帧的压缩率。

![3-9](D:\0-博客\study_log\《Android音视频开发》\3-9.png)

H.264 的码流格式。

![4-1](D:\0-博客\study_log\《Android音视频开发》\4-1.png)

注意，P 片里面不止有 P 的数据，还有 I 的数据。

![4-2](D:\0-博客\study_log\《Android音视频开发》\4-2.png)

MP4 里面用 sample 表示一个时间帧或者数据单元。

---

TS 流的特点，从任意一个片段开始都可以独立解码。

![4-3](D:\0-博客\study_log\《Android音视频开发》\4-3.png)

Windows 上的 avi 格式。

![4-4](D:\0-博客\study_log\《Android音视频开发》\4-4.png)
