# 《Windows PowerShell实战指南》学习笔记



> 掌握—— 他 知道 管理员 们 并没有 多少 闲暇 时间， 通常 他们 都是 在 需要 的 时候 才会 去 学习。
>



> 请 不要 尝试 一次性 完 成对 整 本书 的 阅读—— 请 坚持 每天 一章 的 方式。 人的 大脑 一次 只能 理解 有限 的 信息， 通过 将 PowerShell 分解 为 小的 片段， 你 实际上 可以 更快、 更 彻底 地 学习 PowerShell。
>



> Manning 出版社 对 读者 的 承诺 是 提供 一个 交流 的 场所。 在 该 场所， 读者 和 读者 以及 读者 和 作者 之间 可以 进行 有价值 的 对话。 但 并不 承诺 作者 需要 花 多少 时间 在 论坛 中， 作者 参与 论坛 都是 志愿 的（ 且不 收 报酬）。 我们 建议 你 尝试 问 作者 一些 有 挑战 性的 问题， 从而 使他 们 保持 兴趣
>



GUI 控制台底层运行的是 PowerShell 命令行。

> 微软 仍然 继续 开发 GUI 的 控制台， 但是 底层 运行 的 仍然是 PowerShell 命令。



PowerShell 居然是开源的。

> 那就 是 完整 开源 了 Windows PowerShell。
>



PowerShell 是一个面向对象的 Shell。



Linux 的守护进程，就是 Windows 的服务。

> 这是 由于 Linux 没有 服务 的 概念（ Linux 有 守护 进程， 类似 Windows 的 服务， 但 略有 区别）。
>



查看 PowerShell 的版本。

> 控制台， 输入 $PSVersionTable， 然后 按 回车 键。 如果 返回 错误 或者 输出 结果 并未 显示 为“ PSVersion 4. 0”， 那么 你 安装 的 版本 就不 是 PowerShell 第 4 版。
>



微软的 Server Core 跟 Nano Server 都是没有桌面的。

> 在 未 包含 完整 GUI 模式 的 操作系统（ 如 Server Core 或 Nano Server 版本 的 系统） 对应 的 安装 程序 中 并没有 包含 ISE 的 安装 程序。
>



可发现性 的易于学习。

> 我们 提到 由于 图形 用户 界面 具有 更 强的 可 发现 性， 所以 更容易 学习 和 使用。 但 对于 像 PowerShell 这样 的 命令行 接口- CLIs（ command- line interfaces） 的 学习 却 往往 要 困难 一些， 因为 它们 缺乏 可 发现 性 这个 特性。
>



> 如果 你 需要 执行 一项 任务， 但是 却不 知道 应该 使用 什么 命令， 帮助 系统 就可以 帮助 你 找到 这个 命令， 而无 需 使用 Google 或者
>



这样可以直接查看示例。

> Help Get- EventLog -example
>



PowerShell 拥有 能够 访问 整个. Net Framework 底层 的 能力

> PowerShell 拥有 能够 访问 整个. Net Framework 底层 的 能力（ 虽然 在 非 Windows 操作系统 中， 只是 整个 Framework 的 子集）， 我们 也 看到 PowerShell“ 脚本” 实际上 与 通过 Visual Studio 编写 的 C# 语言 使用 模式 也 十分 类似。
>



Show-Command 非常有用。

> 尽管 我们 拥有 多年 使用 PowerShell 的 经验， 但 命令 语法 的 复杂度 有时 依然 会 让 我们 抓 狂。 PowerShell v3（ 以及 更新 版本， 虽然 不 包含 非 Windows 操作系统） 提供 的 一个 非常 棒 的 特性 是 Show-Command commlet。
>



> 在 非 Windows 操作系统 中 也是 如此： 你 可以 使用 grep、 bash、 sed、 awk、 ping 以及 任何 可用 的 命令行 工具。 这些 命令 可以 正常 执行， PowerShell 能够 以 传统 shell（ 例如 Bash） 同样 的 方式 展示 输出 结果。
>
