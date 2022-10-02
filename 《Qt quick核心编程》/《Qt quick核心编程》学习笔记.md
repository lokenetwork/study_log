# 《Qt quick核心编程》学习笔记

Quick 也有 跟 QWidget 一样的布局组件。

> 8.2 　 布局 管理器 8. 2. 1 　 GridLayout 8. 2. 2 　 RowLayout 8. 2. 3 　 ColumnLayout



Qt 是有 命令行环境的，不一定要用 Qt Creator来编译项目。

> Qt SDK 提供 了 一个 命令行 环境， 给 那些 有 特殊 需求 的 开发者， 方便 他们 在 不 使用 Qt Creator 集成 开发 环境 的 情况下 编译 应用 程序。
>



qmlscene 就跟浏览器浏览网页一样，可以直接浏览 qml。

> qmlscene 是 随着 Qt 5 发布 的 一个 工具， 用来 加载 QML 文档， 它 使得 你 可以 在 应用 开发 过程中 随时 查看 QML 代码 的 效果。 它 支持 下列 特性：
>



模块，可以从文档里面找。

>  如果 你 不确定 使用 某种 类型 时 应当 导入 哪个 模块， 可以 使用 Qt 帮助 的 索引 模式 找到 该 类型， 查看 其所 在的 Qt Quick 模块。 图 4- 1 是 Text 的 文档， 我 标注 出 来的 那 行 对 你 需要 引入 的 模块 做了 说明。
>



两种方式。

> 现在 我们有 两种 启动 Qt Quick App 模式： ● QQmlApplicationEngine 搭配 Window。 ● QQuickView 搭配 Item。 两者 的 不同 之处 在于： 使用 QQuickView 显示 QML 文档， 对 窗口 的 控制 权（ 比如 设置 窗口 标题、 Icon、 窗口 的 最小 尺寸 等） 在 C++ 代码； 而使 用 QQmlApplicationEngine 加载 以 Window 为 根 对象 的 QML 文档， QML 文档 则 拥有 窗口 的 完整 控制 权， 可以 直接 设置 标题、 窗口 尺寸 等 属性。
>



实际上就在显示器上画图。

> 作为 一个 GUI 应用， 它 首先 具有 从 操作系统 而来 的 一个 窗口， 这个 窗口 又被 窗口 管理 系统 所 管理。 我们 使用 Qt Quick 开发 的 应用， 首先 是一 个 常规 的 GUI 应用， 拥有 操作系统 底层 为 其 创建 的 窗口， 这个 窗口， 就是 Qt Quick 传布 其 神 迹 的 场景。 Qt Quick 将 在这里 出生、 成长、 生活、 老去， 直至 死亡…… 而 这场 或 短暂 或 漫长的 秀， 是否 精彩， 则 取决于 应用 的 缔造者—— 作为 开发者 的 我们—— 如何 使用 QML 的 十八 般 武器。
>



> 在 Qt Quick 的 世界 里， Window 对象 用于 创建 一个 与 操作系统 相关 的 顶层 窗口， 而 其他 元素， 如 Text、 Rectangle、 Image 等， 都是 在 Window 提供 的 场景 内 表演 的 演员。 Window 还有 一个 派生 类， 即 大名鼎鼎 的 ApplicationWindow， 也可以 作为 QML 文档 的 根 对象。 前面 我们 提到 的 使用 QQuickView 加载 QML 的 方式， 顶层 窗口 是由 QQuickView 创建 的。



ECMAScript 可以简单理解为是一个超集。

> 浏览器 对于 ECMAScript 来讲 是一 个 宿主 环境， 但它 并不是 唯一 的 宿主 环境。 事实上， 还有 很多 非 浏览器 的 其他 宿主 环境， 比如 用于 Flash 与 Director MX 中的 ActionScript， 以及 本书 要 讲的 QML。 那么 ECMAScript 规定了 些 什么 呢？ 简单 地说， 它 描述 了 以下 内容：
>
