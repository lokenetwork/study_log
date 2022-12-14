# 《VC++深入详解》学习笔记1



> MSDN 全称 是 Microsoft Developer Network，
>



离线 MSDN 的安装。

> 在这 个 界面 中， 我们 可以 根据 学习 和 开发 的 需要 将 文档 下载 到 本地。 本书 是 介绍 Visual C++ 开发 的， 因此 我们 先 找到“ Visual Studio 2015: Visual C++ - 英语”， 单击“ 添加” 操作（ 当然 读者 也可以 添加 上方 的 中文 帮助 内容， 或者 将 两个 都 添加）； 接下来 在“ 可用 的 文档” 分支 下， 找到“ Windows” 分支， 添加“ Programming reference for Windows API” 文档； 最后 单击 右下方 的“ 更新” 按钮， 开始 下载 帮助 文档。



> 下载 帮助 文档 可能 会 比较 耗时， 请 耐心 等待。 在下 载 完成 后， 当 我们 需要 查看 某个 函数 的 用法 时， 就可以 直接 在 Visual Studio 2017 中 按下 键盘 上 的 F1 键 调出 帮助 查看 器， 在 本地 文档 中进 行 查找 并 查看。 对于 代码 中的 函数， 在 选中 后 按下 F1 键 也可以 调出 该 函数 的 帮助 文档。
>



> Windows 操作系统 提供 了 1000 多种 API 函数，
>



> 窗口 是 通过 窗口 句柄（ HWND） 来 标识 的。 我们 要对 某个 窗口 进行 操作， 首先 就要 得到 这个 窗口 的 句柄。 句柄（ HANDLE） 是 Windows 程序 中 一个 重要的 概念， 使用 也非 常 频繁。 在 Windows 程序 中， 有 各种各样 的 资源（ 窗口、 图标、 光标 等）， 系统 在 创建 这些 资源 时会 为 它们 分配 内存， 并 返回 标识 这些 资源 的 标识 号， 即 句柄。 在后 面的 内容 中 我们 还会 看到 图标 句柄（ HICON）、 光标 句柄（ HCURSOR） 和 画 刷 句柄（ HBRUSH）
>



> 每一个 Windows 应用 程序 在开 始 执行 后， 系统 都 会为 该 程序 创建 一个 消息 队列， 这个 消息 队列 用来 存放 该 程序 创建 的 窗口 的 消息。
>



> 当 WinMain 函数 结束 或 返回 时， Windows 应用 程序 结束。
>



传递参数给程序。

> 第三 个 参数 lpCmdLine 是 一个 以 空 终止 的 字符串， 指定 传递 给 应用 程序 的 命令行 参数。 例如： 在 D 盘 下有 一个 sunxin. txt 文件， 当 我们 用 鼠标 双击 这个 文件 时 将 启动 记事本 程序（ notepad. exe）， 此时 系统 会 将 D:\ sunxin. txt 作为 命令行 参数 传递 给 记事本 程序 的 WinMain 函数， 记事本 程序 在 得到 这个 文件 的 全路 径 名后， 就在 窗口 中 显示 该 文件 的 内容。 要在 Visual Studio 开发 环境 中 向 应用 程序 传递 参数， 可以 单击 菜单【 项目】 →【 WinMain 属性】（ WinMain 是 本章 程序 的 项目 名）， 在 左侧 配置 属性 窗口 中 选择“ 调试”， 在右 侧 窗口 的“ 命令 参数” 编辑 框 中 输入 你想 传递 给 应用 程序 的 参数， 如图 2. 2 所示。
>



LoadIcon 可以加载系统的标准图标。

>  如果 加载 的 是 系统 的 标准 图标， 那么 第一个 参数 必须 为 NULL
>



多个窗口可以属于同一个线程。

> 通常 我们 将其 设置 为 NULL， 用于 接收 属于 调用 线程 的 所有 窗口 的 窗口 消息。
>



> DispatchMessage 函数 分派 一个 消息 到 窗口 过程， 由 窗口 过程 函数 对消 息 进行 处理。 DispachMessage 实际上 是将 消息 回 传给 操作系统， 由 操作系统 调用 窗口 过程 函数 对消 息 进行 处理（ 响应）。
>



> 程序 开发 人员 可以 基于 这一 框架 开发 Windows 应用 程序。 MFC 采用 面向 对象 设计， 将 大部分 的 Windows API 封装 到 C++ 类 中， 以 类 成员 函数 的 形式 提供 给 程序 开发 人员 调用
>



> 我们 创建 的 这个 MFC 程序 也不例外， 它 也有 一个 WinMain 函数， 但 这个 WinMain 函数 是在 程序 编译 链接 时 由 链接 器 将 该 函数 链接 到 Test 程序 中的。
>



全局变量定义是第一执行指令。

> 我们 在这 个 全局 对象 定义 处 设置 一个 断点， 然后 调试 运行 Test 程序， 将 发现 程序 执行 的 顺序 依次 是： theApp 全局 对象 定义 处、 TestApp 构造 函数、 WinMain 函数。
>



Afx 全称

> Afx 前缀 的 函数 代表 应用 程序 框架（ Application Framework） 函数。
>
> 在 MFC 中， 以 Afx 为 前缀 的 函数 都是 全局 函数， 可以 在 程序 的 任何 地方 调用 它们。
>



:: 符号的妙用。

> 提示： 读者 在 定义 自己的 成员 函数 时， 如果 调用 的 API 函数 名 与 自己的 函数 名 不同， 那么 该 API 函数 名 前 可以 加 也可以 不加“::” 符号， 编译器 会 自动 识别 API 函数。 但是 如果 当前 定义 的 成员 函数 与 内部 调用 的 API 函数 名 相同， 那么 后者 前面 必须 加“::” 符号， 否则 程序 在 编译 或 运行时 就会 出错。
>



> 当 我们 设计 的 这个 C++ 窗口 类 对象 被 销毁 的 时候， 与之 相关 的 窗口 也是 应该 被 销毁 的， 因为 它们 之间 的 纽带（ m_ hWnd） 已经 断了。 另外， 窗口 也是 一种 资源， 它 也占 据 内存。 这样， 在 C++ 窗口 类 对象 析 构 时， 也需 要回 收 相关 的 窗口 资源， 即 销毁 这个 窗口。 因此， 读者 一定 要 注意： C++ 窗口 类 对象 与 窗口 并不是 一回事， 它们 之间 唯一 的 关系 是 C++ 窗口 类 对象 内部 定义 了 一个 窗口 句柄 变量， 保存 了 与 这个 C++ 窗口 类 对象 相关 的 那个 窗口 的 句柄。 当 窗口 被 销毁 时， 与之 对应 的 C++ 窗口 类 对象 被 销毁 与否， 要看 其生 命 周期 是否 结束。 但当 C++ 窗口 类 对象 被 销毁 时， 与之 相关 的 窗口 也 将被 销毁。 在 我们 定义 的 这个 WinMain 程序（ 例 4- 20 所示 代码） 中， 当 程序 运行 到 WinMain 函数 的 右 花 括号（}） 时， 该 函数 内部 定义 的 Wnd 窗口 类 对象 的 生命 周期 也就 结束 了。
>



> 窗口 创建 时 都会 产生 WM_ CREATE 消息， CMainFrame 类 提供 一个 OnCreate 函数， 该 函数 就是 用来 响应 这条 窗口 创建 消息 的。 该 函数 的 默认 实现 代码 如 例 4- 22 所示。
>



> 读者 可能 注意到 了 字符串“ 按钮” 前面 有一个 大写 的 字母 L, Visual Studio 2017 默认 使用 Unicode 字符 集， 这是 和 VC++ 6. 0 不同 的 地方， 大写字母 L 的 使用 就是 告诉 编译器， 该 字符串 应该 编译 为 一个 Unicode 字符串。 不过， 这种 方式 只能 对 字面 常量 使用。
>

