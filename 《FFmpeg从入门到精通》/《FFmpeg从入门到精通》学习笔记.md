# 《FFmpeg从入门到精通》学习笔记

FFmpeg 的 Filter 是借鉴了 mplayer 的。

> FFmpeg 版本 也由 0. x 升级 到 3. x， 中间 经历 了 巨大 的 架构 变化， 功能 也 越来越 强大。 最早 大家 只是 用 它 作为 mplayer 的 解码 库 之一， 后来 它 逐渐 支持 的 codec、 format、 protocol 逐步 就 超越 了 mplayer， 甚至 把 mplayer 的 filter 也都 支持 了 
>

开源项目通常会解决某个基础性的需求。

> 成功 的 开源 项目 其实 并不 多， 往往 都是 比较 好的 解决 了 某个 基础性 需求， 是 凝聚 了 大量 优秀 程序员 智慧 的 结晶。
>

libavfilter 是 Michael Niedermayer 加入进去 FFmpeg 的。

> Michael Niedermayer 对 FFmpeg 的 贡献 非常 大， 其 将 滤 镜子 系统 libavfilter 加入 FFmpeg 项目 中， 使得 FFmpeg 的 多媒体 处理 更加 多样、 更加 方便。

Filter 的滤镜语法。

![0-1](D:\0-博客\study_log\《FFmpeg从入门到精通》\0-1.png)

![0-1](D:\0-博客\study_log\《FFmpeg从入门到精通》\0-2.png)

注意 avformat 的 avioflags

![1-1](D:\0-博客\study_log\《FFmpeg从入门到精通》\1-1.png)

注意 chromakey 滤镜与 colorkey 滤镜。

![1-2](D:\0-博客\study_log\《FFmpeg从入门到精通》\1-2.png)

Filter 内置的变量。

![1-3](D:\0-博客\study_log\《FFmpeg从入门到精通》\1-3.png)
