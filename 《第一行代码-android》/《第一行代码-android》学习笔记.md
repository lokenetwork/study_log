# 《第一行代码-android》学习笔记

java 虚拟机与 ART 虚拟机。

![1-1](D:\0-博客\study_log\《第一行代码-android》\1-1.png)



ART 虚拟机的历史。

> 2014年Google推出了号称史上版本改动最大的Android 5.0系统，使用ART运行环境替代 了Dalvik虚拟机，大大提升了应用的运行速度，



免安装在国内用不了。

> 一个是用于支持instant apps免安装应用的，这个功能必须配合Google Play服务才能使用，在国内是用不了的。



AndroidX与Android Support Library的区 别

> 因为未来 所有项目都会默认启用AndroidX。想要了解更多AndroidX与Android Support Library的区 别，可以关注我的微信公众号（见封面），回复“AndroidX”即可。



最主流的分辨率目录。drawable-xxhdpi

> 在制作程序的时候， 最好能够给同一张图片提供几个不同分辨率的版本，分别放在这些目录下，然后程序运行的时 候，会自动根据当前运行设备分辨率的高低选择加载哪个目录下的图片。当然这只是理想情 况，更多的时候美工只会提供给我们一份图片，这时你把所有图片都放在drawable-xxhdpi目 录下就好了，因为这是最主流的设备分辨率目录。



如何使用字符串。

![1-2](D:\0-博客\study_log\《第一行代码-android》\1-2.png)



可以自定义日志过滤器。

![1-3](D:\0-博客\study_log\《第一行代码-android》\1-3.png)

Google的NDK 功能。

> 虽然在Android 1.5系统中Google 引入了NDK功能，支持使用C和C++语言来进行一些 本地化开发，但是这丝毫没有影响过Java的正统地位。



Kotlin 是 JetBrains 公司开发的。

> 但其实它并不是一门很新的语言。Kotlin是由 JetBrains公司开发与设计的，早在2011年，JetBrains就公布了Kotlin的第一个版本，并在 2012年将其开源，但在早期，它并没有受到太多的关注。



ART 是移动优化版的虚拟机。

> 而是一种特殊的class文件，这 种class文件只有Java虚拟机（Android中叫ART，一种移动优化版的虚拟机）才能识别



没有主 Activity 的情况

> 另外需要注意，如果你的应用程序中没有声明任何一个Activity作为主 Activity，这个程序仍然是可以正常安装的，只是你无法在启动器中看到或者打开这个程序。这 种程序一般是作为第三方服务供其他应用在内部进行调用的。
>



可以不用 findViewById 了

![1-4](D:\0-博客\study_log\《第一行代码-android》\1-4.png)



finish() 函数可以销毁释放 Activity。

> 当然也可以，Activity类提供了一个 finish()方法，我们只需要调用一下这个方法就可以销毁当前的Activity了



重写 back 键

> 我们可以通 过在SecondActivity中重写onBackPressed()方法来解决这个问题，



Activity 的生命周期。

![1-5](D:\0-博客\study_log\《第一行代码-android》\1-5.png)



Activity  回收之前的回调 onSaveInstanceState

> Activity中还提供了一个onSaveInstanceState()回调方法，这个方法可以保证在 Activity被回收之前一定会被调用，因此我们可以通过这个方法来解决问题。



Bundle 可以通过 Intent 进行传递。

> 这里提醒一点，Intent还可以结合Bundle一起用于传递 数据。首先我们可以把需要传递的数据都保存在Bundle对象中，然后再将Bundle对象存放在 Intent里。到了目标Activity之后，先从Intent中取出Bundle，再从Bundle中一一取出数据



注意这个最佳写法的传参方式。

> 这样写的好处在哪里呢？最重要的一点就是一目了然，SecondActivity所需要的数据在方法参 数中全部体现出来了，这样即使不用阅读SecondActivity中的代码，不去询问负责编写 SecondActivity的同事，你也可以非常清晰地知道启动SecondActivity需要传递哪些数据。



Android 也有 include 模板的功能的。

> 没错！我们只需要通过一行include语句引入标题栏布局就可以了。



ListView 的优化策略。

> 仔细观察你会发现，getView()方法中还有一个convertView参数，这个参数用于将之前加 载好的布局进行缓存，以便之后进行重用，我们可以借助这个参数来进行性能优化。

> 我们新增了一个内部类ViewHolder，用于对ImageView和TextView的控件实例进行缓存， Kotlin中使用inner class关键字来定义内部类。当convertView为null的时候，创建一个 ViewHolder对象，并将控件的实例存放在ViewHolder里，然后调用View的setTag()方 法，将ViewHolder对象存储在View中。当convertView不为null的时候，则调用View的 getTag()方法，把ViewHolder重新取出。这样所有控件的实例都缓存在了ViewHolder里， 就没有必要每次都通过findViewById()方法来获取控件实例了。



RecyclerView 的优势，瀑布流，横向滚动。

> 



注意 Kotlin 的扩展函数。

> 定义好了扩展函数之后，统计某个字符串中的字母数量只需要这样写即可： val count = "ABC123xyz!@#".lettersCount() 是不是很神奇？看上去就好像是String类中自带了lettersCount()方法一样。



接受系统的广播，广播就是通知。

> Android内置了很多系统级别的广播，我们可以在应用程序中通过监听这些广播来得到各种系统 的状态信息。比如手机开机完成后会发出一条广播，电池的电量发生变化会发出一条广播，系 统时间发生改变也会发出一条广播，等等。如果想要接收这些广



![1-6](D:\0-博客\study_log\《第一行代码-android》\1-6.png)



Android 的持久化技术

> Android系统中主要提供了3种方式用于简单地实现数据持久化功能：文件存储、 SharedPreferences存储以及数据库存储。



应用的文件存储目录。

> 注意这里指定的文件名 不可以包含路径，因为所有的文件都默认存储到/data/data//files/目录 下；



SharedPreferences 是一种 key value 的永久存储方式。

> 不同于文件的存储方式，SharedPreferences是使用键值对的方式来存储数据的。也就是说， 当保存一条数据的时候，需要给这条数据提供一个对应的键，这样在读取数据的时候就可以通 过这个键把相应的值取出来。



ContentProvider 跨进程共享数据。

> 在上一章中我们学了Android数据持久化技术，包括文件存储、SharedPreferences存储以及 数据库存储。不知道你有没有发现，使用这些持久化技术所保存的数据只能在当前应用程序中 访问。虽然文件存储和SharedPreferences存储中提供了MODE_WORLD_READABLE和 MODE_WORLD_WRITEABLE这两种操作模式，用于供给其他应用程序访问当前应用的数据，但 这两种模式在Android 4.2版本中都已被废弃了。为什么呢？因为Android官方已经不再推荐使 用这种方式来实现跨程序数据共享的功能，而是推荐使用更加安全可靠的ContentProvider技 术。



微信会读取短信与彩信

> 这还只是微信所申请的一半左右的权限，因为权限太多，一屏截不全。其中有一些权限我并不 认可，比如微信为什么要读取我手机的短信和彩信？但是不认可又能怎样，难道我拒绝安装微 信？没错，这种例子比比皆是，一些软件在让用户产生依赖以后就会容易 “店大欺客”，反正这 个权限我就是要了，你自己看着办吧！



Android 的 MediaPlayer 类，媒体相关的类。

![1-7](D:\0-博客\study_log\《第一行代码-android》\1-7.png)



ios 比 Android 更早出现

> 记得在我上大学的时候，iPhone是属于少数人拥有的稀有物品，Android甚至还没面世，那个 时候全球的手机市场是由诺基亚统治着的。当时我觉得诺基亚的Symbian操作系统做得特别出 色，因为比起一般的手机，它可以支持后台功能。



Android 逐步削减 后台的功能。

> 而Android正好相反，一开始支持丰富的后台功能，后来意识到后台太过开放的 弊端，于是逐渐削减了后台功能。



Service 的特点：

> 不过需要注意的是，Service并不是运行在一个独立的进程当中的，而是依赖于创建Service时 所在的应用程序进程。当某个应用程序进程被杀掉时，所有依赖于该进程的Service也会停止运 行。 另外，也不要被Service的后台概念所迷惑，实际上Service并不会自动开启线程，所有的代码 都是默认运行在主线程当中的。也就是说，我们需要在Service的内部手动创建子线程，并在这 里执行具体的任务，否则就有可能出现主线程被阻塞的情况。



必须在主线程更新 UI

> 和许多其他的GUI库一样，Android的UI也是线程不安全的。也就是说，如果想要更新应用程序 里的UI元素，必须在主线程中进行，否则就会出现异常。



AsyncTask 封装得更好。

> 不过为了更加方便我们在子线程中对UI进行操作，Android还提供了另外一些好用的工具，比如 AsyncTask。借助AsyncTask，即使你对异步消息处理机制完全不了解，也可以十分简单地从 子线程切换到主线程。当然，AsyncTask背后的实现原理也是基于异步消息处理机制的，只是 Android帮我们做了很好的封装而已。



Service 可能会被回收。

> 但是从Android 8.0系统开始，应用的后台功能被大 幅削减。现在只有当应用保持在前台可见状态的情况下，Service才能保证稳定运行，一旦应用 进入后台之后，Service随时都有可能被系统回收。



Activity 可以跟 Service 进行通信的。

> 在上一小节中，我们学习了启动和停止Service的方法。不知道你有没有发现，虽然Service是 在Activity里启动的，但是在启动了Service之后，Activity与Service基本就没有什么关系了。 确实如此，我们在Activity里调用了startService()方



前台 Service 是有图标显示的。



Service 是在主线程里面跑的。Service 跟 Activity 的通信，其实线程内，各个协程间的通信类似的。

> 在本章一开始的时候我们就已经知道，Service中的代码都是默认运行在主线程当中 的，如果直接在Service里处理一些耗时的逻辑，就很容易出现ANR



Android 的库管理特别完善，可以帮你自动安装依赖库，写一句代码就行，不像 C++。

![1-8](D:\0-博客\study_log\《第一行代码-android》\1-8.png)



JSon 相关的解析库。

> 类似地，解析JSON数据也有很多种方法，可以使用官方提供的JSONObject，也可以使用 Google的开源库GSON。另外，一些第三方的开源库如Jackson、FastJSON等也非常不错。本 节中我们就来学习一下前两种解析方式的用法。



Retrofit 更加好用。

> 既然我们这一章讲解Android网络技术，那么就不得不提到Retrofit，因为它实在是太好用了。 Retrofit同样是一款由Square公司开发的网络库，但是它和OkHttp的定位完全不同。OkHttp 侧重的是底层通信的实现，而Retrofit侧重的是上层接口的封装。事实上，Retrofit就是Square 公司在OkHttp的基础上进一步开发出来的应用层网络通信库，



Kotlin 是支持协程的。

> 协程属于Kotlin中非常有特色的一项技术，因为大部分编程语言中是没有协程这个概念的。 那么什么是协程呢？它其实和线程是有点类似的，可以简单地将它理解成一种轻量级的线程。 要知道，我们之前所学习的线程是非常重量级的，它需要依靠操作系统的调度才能实现不同线 程之间的切换。而使用协程却可以仅在编程语言的层面就能实现不同协程之间的切换，从而大 大提升了并发编程的运行效率。



卡片布局 MaterialCardView

> MaterialCardView是用于实现卡片式布局效果的重要控件，由Material库提供。实际上， MaterialCardView也是一个FrameLayout，只是额外提供了圆角和阴影等效果，看上去会有 立体的感觉。 我们先来看一下MaterialCard



刷新控件 SwipeRefreshLayout

> SwipeRefreshLayout就是用于实现下拉刷新功能的核心类，我们把想要实现下拉刷新功能的 控件放置到SwipeRefreshLayout中，就可以迅速让这个控件支持下拉刷新。那么在 MaterialTest项目中，应该支持下拉刷新功能的控件自然就是RecyclerView了。



ViewModel 数据绑定。

> ViewModel应该可以算是Jetpack中最重要的组件之一了。其实Android平台上之所以会出现诸 如MVP、MVVM之类的项目架构，就是因为在传统的开发模式下，Activity的任务实在是太重 了，既要负责逻辑处理，又要控制UI展示，甚至还得处理网络回调，等等。在一个小型项目中 这样写或许没有什么问题，但是如果在大型项目中仍然使用这种写法的话，那么这个项目将会 变得非常臃肿并且难以维护，因为没有任何架构上的划分



Android 有 ORM 框架，叫 room

> 由于许多大型项目中会用到数据库的功能，为了帮助我们编写出更好的代码，Android官方推出 了一个ORM框架，并将它加入了Jetpack当中，就是我们这节即将学习的Room。



WorkManager

> 不过，我们还得先明确一件事情：WorkManager和Service并不相同，也没有直接的联系。 Service是Android系统的四大组件之一，它在没有被销毁的情况下是一直保持在后台运行的。 而WorkManager只是一个处理定时任务的工具，它可以保证即使在应用退出甚至手机重启的情 况下，之前注册的任务仍然将会得到执行，因此WorkManager很适合用于执行一些定期和服务 器进行交互的任务，比如周期性地同步数据，等等。 另外，使用WorkManager注册的周期性任务不能保证一定会准时执行，这并不是bug，而是系 统为了减少电量消耗，可能会将触发时间临近的几个任务放在一起执行，这样可以大幅度地减 少CPU被唤醒的次数，从而有效延长电池的使用时间。



Kotlin 与 java 是可以相互转换的， Android Studio 可以自动转。

> 事 实上，将Java代码转换成Kotlin代码，在语法层面上是有一定规律的，而Android Studio给我 们提供了非常便利的功能来一键完成这种转换工作。



也可以用 Gradle 生成 apk。

> 上一小节中我们使用了Android Studio提供的可视化工具来生成带有正式签名的APK文件，除 此之外，Android Studio其实还提供了另外一种方式——使用Gradle生成。下面我们就来学习 一下。
