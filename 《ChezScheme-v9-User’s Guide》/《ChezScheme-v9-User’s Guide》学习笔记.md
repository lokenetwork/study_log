# 《ChezScheme-v9-User’s Guide》学习笔记

v8 版本跟 v9 版本有本质的区别。

> The compiler has been rewritten for Version 9 and generates substantially faster code than the earlier compiler at the cost of greater compile time. This is the primary difference between Versions 8 and 9.





ChezScheme 的线程语法是基于 Windows API 或者 posix 的 thread 来实现的。

> This chapter describes the *Chez Scheme* thread-system procedures and syntactic forms. With the exception of locks, locked increment, and locked decrement, the features of the thread system are implemented on top of the Posix thread system (pthreads) on non-Windows-based system and directly using the Windows API on Windows-based systems. Consult the appropriate documentation on your system for basic details of thread creation and interaction.
