# 《The Data Compression Book》学习笔记

伪代码 "程序 "缺乏严谨性，常常导致模糊或不完整的定义，

> The use of C to illustrate data-compression algorithms may raise some hackles, although less so these days than when the first edition of this book came out. A more traditional way to write this book would have been to use pseudocode to sketch out the algorithms. But the lack of rigor in a pseudocode “program” often leads to hazy or incomplete definitions full of lines like “PROCESS FILE UNTIL OUT OF DATA.” The result is that pseudocode is easy to read, but not so easy to translate into a working program. 



注意这个词 lingua franca，社交语言。

> If pseudocode is unsatisfactory, the next best choice is to use a conventional programming language. Though hundreds of choices are available, C seems the best choice for this type of book for several good reasons. First, in many respects C has become the lingua franca of programmers. That C compilers support computers ranging from a lowly 8051 microcontroller to supercomputers capable of 100 million instructions per second (MIPS) has had much to do with this. It doesn’t mean that C is the language of choice for all programmers. What it does mean is that most programmers should have a C compiler available for their machines, and most are probably regularly exposed to C code. Because of this, many programmers who use other languages can still manage to code in C, and even more can at least read C. 



C99 标准的历史

> One important portability issue is library function calls. Though the C programming language was fairly well defined by the original K&R book (Brian W. Kernighan and Dennis M. Ritchie, The C Programming Language [Englewood Cliffs, NJ.: Prentice-Hall, 1978]), the run-time library implementation was left totally up to the whims of the implementor. Fortunately, the American National Standards Institute was able to complete the C language specification in 1990, and the result was published as ANSI standard XJ11.34. This standard not only expanded and pinned down the original K&R language specification, but it also took on the definition of a standard C run-time library. This makes it much easier to write code that works the same way from machine to machine. The code in this book will be written with the intention of using only ANSI C library calls. Compiler-dependent extensions to either the language or the library will be avoided wherever possible. 



注意这个 K&R C 语言的标准。

> While the ANSI C committee went to great lengths to make ANSI C upwardly compatible from K&R C, we need to watch out for a few problems. 



注意这里用到的压缩样本数据，有 3 类，我们做相关的比较测试也可以用。

> Throughout this book, there will be references to “compression ratios” and compression statistics. To keep the various forms of compression on a level playing field, compression statistics will always be in relationship to the sample compression files used in the February 1991 Dr. Dobb’s Journal compression contest. These files consist of about 6 megabytes of data broken down into three roughly equal categories. The first category is text, consisting of manuscripts, programs, memos, and other readable files. The second category consists of binary data, including database files, executable files, and spreadsheet data. The third category consists of graphics files stored in raw screen-dump formats.



dawn age 是平明时代，1950 年。

> This book consists of thirteen chapters and a floppy disk. The organization roughly parallels the historical progression of data compression, starting in the “dawn age” around 1950 and working up to the present. 



注意  adaptive Huffman coding （可适应哈夫曼编码）。

> Standard Huffman coding suffers from a significant problem when used for high-performance data compression. The compression program has to pass a complete copy of the Huffman coding statistics to the expansion program. As the compression program collects more statistics and tries to increase its compression ratio, the statistics take up more space and work against the increased compression. Chapter 4 discusses a way to solve this dilemma: adaptive Huffman coding. This is a relatively recent innovation, due to CPU and memory requirements. Adaptive coding greatly expands the horizons of Huffman coding, leading to vastly improved compression ratios



哈夫曼编码与 算术编码的区别，注意这个 fractional number。

> Huffman coding has to use an integral number of bits for each code, which is usually slightly less than optimal. A more recent innovation, arithmetic coding, uses a fractional number of bits per code, allowing it to incrementally improve compression performance. Chapter 5 explains how this recent innovation works, and it shows how to integrate an arithmetic coder with a statistical model. 



早期的 UNIX COMPRESS 程序。

> Chapter 9 takes detailed look at one of the first widely popular dictionary-based compression methods: LZW compression. LZW is the compression method used in the UNIX COMPRESS program and in earlier versions of the MS-DOS ARC program. This chapter also takes a look at the foundation of LZW compression, published in 1978 by Ziv and Lempel. 



注意这段话里面的 symbols 与 code，code是压缩后的数据。

> In general, data compression consists of taking a stream of symbols and transforming them into codes. If the compression is effective, the resulting stream of codes will be smaller than the original symbols. The decision to output a certain code for a certain symbol or set of symbols is based on a model. The model is simply a collection of data and rules used to process input symbols and determine which code(s) to output. A program uses the model to accurately define the probabilities for each symbol and the coder to produce an appropriate code based on those probabilities.



这里的 the last 10 symbols（最后10个符号）是什么意思？

> We think of the model and the program’s coding process as different because of the countless ways to model data, all of which can use the same coding process to produce their output. A simple program using Huffman coding, for example, would use a model that gave the raw probability of each symbol occurring anywhere in the input stream. A more sophisticated program might calculate the probability based on the last 10 symbols in the input stream. Even though both programs use Huffman coding to produce their output, their compression ratios would probably be radically different. 



信息论是 数学的一个分支，诞生于 1940 年。

> Data compression is perhaps the fundamental expression of Information Theory. Information Theory is a branch of mathematics that had its genesis in the late 1940s with the work of Claude Shannon at Bell Labs. It concerns itself with various questions about information, including different ways of storing and communicating messages. 



信息论里面的熵是从热力学里面借来的。

> Information Theory uses the term entropy as a measure of how much information is encoded in a message. The word entropy was borrowed from thermodynamics, and it has a similar meaning. The higher the entropy of a message, the more information it contains. The entropy of a symbol is defined as the negative logarithm of its probability. To determine the information content of a message in bits, we express the entropy using the base 2 logarithm: 



注意 Number of bits 这个公式。

> Number of bits = - Log base 2 (probability) 
>
> The entropy of an entire message is simply the sum of the entropy of all individual symbols. Entropy fits with data compression in its determination of how many bits of information are actually present in a message. If the probability of the character ‘e’ appearing in this manuscript is 1/16, for example, the information content of the character is four bits. So the character string “eeeee” has a total content of 20 bits. If we are using standard 8-bit ASCII characters to encode this message, we are actually using 40 bits. The difference between the 20 bits of entropy and the 40 bits used to encode the message is where the potential for data compression arises



这里的 1% 到 95% 是怎么算出来的？

> The different order models can yield drastically different probabilities for a character. The letter ‘u’
> under an order-0 model, for example, may have only a 1 percent probability of occurrence. But
> under an order-1 model, if the previous character was ‘q,’ the ‘u’ may have a 95 percent probability. 



人的大脑思维是一个模型。

> While these experiments are useful, they don’t circumvent the notion that a symbol’s probability depends on the model. The difference with these experiments is that the model is the one kept inside the human brain. This may be one of the best models available, but it is still a model, not an absolute truth. 



概率越高，它携带的信息熵越小。也就只需要很少的比特就能表达这个信息熵。

> In order to compress data well, we need to select models that predict symbols with high probabilities. A symbol that has a high probability has a low information content and will need fewer bits to encode. Once the model is producing high probabilities, the next step is to encode the symbols using an appropriate number of bits.



注意这两种编码 Shannon-Fano coding（香农编码） 与 Huffman coding（哈夫曼编码）

> Solving this coding problem in a reasonable manner was one of the first problems tackled by practitioners of Information Theory. Two approaches that worked well were Shannon-Fano coding and Huffman coding—two different ways of generating variable-length codes when given a probability table for a given set of symbols. 



Shannon-Fano coding（香农编码） 与 Huffman coding（哈夫曼编码）都不能表达小数。

> The problem with Huffman or Shannon-Fano coding is that they use an integral number of bits in each code. If the entropy of a given character is 2.5 bits, the Huffman code for that character must be either 2 or 3 bits, not 2.5. Because of this, Huffman coding can’t be considered an optimal coding method, but it is the best approximation that uses fixed codes with an integral number of bits. Here is a sample of Huffman codes: 
>



哈夫曼的 paper 是在 1952 年发布的。

> Though Huffman coding is inefficient due to using an integral number of bits per code, it is relatively easy to implement and very economical for both coding and decoding. Huffman first published his paper on coding in 1952, and it instantly became the most-cited paper in Information Theory. It probably still is. Huffman’s original work spawned numerous minor variations, and it dominated the coding world till the early 1980s. 



算术编码可以表达小数。

> Arithmetic coding is somewhat more complicated in both concept and implementation than standard variable-width codes. It does not produce a single code for each symbol. Instead, it produces a code for an entire message. Each symbol added to the message incrementally modifies the output code. This is an improvement because the net effect of each input symbol on the output code can be a fractional number of bits instead of an integral number. So if the entropy for character ‘e’ is 2.5 bits, it is possible to add exactly 2.5 bits to the output code. 



无损压缩的两种方法，statistical（统计），dictionary-based（基于字典）

注意这段话，a single code 是算术编码的精髓。

> Lossless data compression is generally implemented using one of two different types of modeling: statistical or dictionary-based. Statistical modeling reads in and encodes a single symbol at a time using the probability of that character’s appearance. Dictionary-based modeling uses a single code to replace strings of symbols. In dictionary-based modeling, the coding problem is reduced in significance, leaving the model supremely important. 



什么是 order-0，什么是 higher order table（更高的 order table）。

> For an order-0 compression table, the actual statistics used to create the table may take up as little as 256 bytes—not a very large amount of overhead. But trying to achieve better compression through use of a higher order table will make the statistics that need to be passed to the decoder grow at an alarming rate. Just moving to an order 1 model can boost the statistics table from 256 to 65,536 bytes. Though compression ratios will undoubtedly improve when moving to order-1, the overhead of passing the statistics table will probably wipe out any gains. 



adpative model，可适应模型。

> For this reason, compression research in the last 10 years has concentrated on adaptive models. Y 3 4.00 bits 4 bits 12 12.0 Z 2 4.58 bits 4 bits 8 9.16 89 83.56 When using an adaptive model, data does not have to be scanned once before coding in order to generate statistics. Instead, the statistics are continually modified as new characters are read in and coded. The general flow of a program using an adaptive model looks something like that shown in Figures 2.2 and 2.3. 



注意 two passes

> This type of compression frequently makes two passes. A first pass over the data performs a highlevel, signal-processing function. This frequently consists of transforming the data into the frequency domain, using algorithms similar to the well-known Fast Fourier Transform (FFT). Once the data has been transformed, it is “smoothed,” rounding off high and low points. Loss of signal occurs here. Finally, the frequency points are compressed using conventional lossless techniques. 



将代码排列成二进制树，则解决了对这些变长代码的解码问题 是什么意思？

```
The first two properties go hand in hand. Developing codes that vary in length according to theprobability of the symbol they are encoding makes data compression possible. And arranging thecodes as a binary tree solves the problem of decoding these variable-length codes
```



哈夫曼编码具有独特的前缀属性，这是什么意思？

> Huffman coding shares most characteristics of Shannon-Fano coding. It creates variable-length codes that are an integral number of bits. Symbols with higher probabilities get shorter codes. Huffman codes have the unique prefix attribute, which means they can be correctly decoded despite being variable length. Decoding a stream of Huffman codes is generally done by following a binary decoder tree. 

![1-1](D:\0-博客\study_log\《The Data Compression Book》\1-1.png)



构建哈夫曼解码树 与 Shannon-Fano树 是不一样的。

> Building the Huffman decoding tree is done using a completely different algorithm from that of the Shannon-Fano method. The Shannon-Fano tree is built from the top down, starting by assigning the most significant bits to each code and working down the tree until finished. Huffman codes are built from the bottom up, starting with the leaves of the tree and working progressively closer to the root. 



哈夫曼编码是一种理论方式，有非常多的实战论文寻求更好的方法来使用这种理论。

> Since D. A. Huffman first published his 1952 paper, “A Method for the Construction of MinimumRedundancy Codes,” his coding algorithm has been the subject of an overwhelming amount ofadditional research. Information theory journals to this day carry numerous papers on theimplementation of various esoteric flavors of Huffman codes, searching for ever better ways to usethis coding method. Huffman coding is used in commercial compression programs, FAX machines,and even the JPEG algorithm. The next logical step in this book is to outline the C code needed toimplement the Huffman coding scheme.



什么是 0 阶 建模与 1 阶 建模，为什么需要传递 257 个概率表。

> The problem with this “minor drawback” is that as we attempt to improve the compression ability of our program, the penalty becomes more and more significant. If we move from order-0 to order-1 modeling, for example, we now have to transmit 257 probability tables instead of just one. So by using a technique that enables us to predict characters more accurately, we incur a penalty in terms of added overhead. Unless the files we are going to compress are very large, this added penalty will frequently wipe out any improvements made by increasing the order. 
>

补充，他指的应该是实时性，不断读取不断建模，如果是之前的方式，就是要传递 257 个概率表。



超过最大值就除以 2 ，作为系数。

> From this we can deduce that if the weight at the root node of a Huffman tree equals fib(i), then thelongest code for that tree is i - 1. This means that if the integers used with our Huffman codes areonly 16 bits long, a root value of 4181 could potentially introduce an overflow. (This low value isfrequently overlooked in simple Huffman implementations. Setting up a file with Fibonacci countsup to fib[18] is a good way to test a Huffman program). When we update the tree, we ought to checkfor a maximum value. Once we reach that value, we need to rescale all the counts, typically dividingthem by a fixed factor, often two.



哈夫曼 是 最好的固定长度编码方法

> Huffman coding has been proven the best fixed-length coding method available. 



在压缩双色图像时，这将是一个问题，

> This would be a problem when compressing two-color images, like those coming from a fax machine. Since there are only two colors, an ordinary coding method would assign the 1 bit to one color and the 0 bit to the other. Since both codes have only a single bit, Huffman coding is not going to be able to compress this data at all. No matter how high the probability of one of the bits, we are still going to have to encode it using one bit. 
>



将比特分组并应用Huffman编码 来解决 哈夫曼整形问题。

> The conventional solution to this problem is to group the bits into packets and apply Huffman coding. But this weakness prevents Huffman coding from being a universal compressor. 



解决一开始 概率不准确的问题。

> The simple order-1 program does in fact do a creditable job of compression, but it has a couple of problems to address. First, the model for this program makes it a slow starter. Every context starts off with 257 symbols initialized to a single count, meaning every symbol starts off being encoded in roughly eight bits. As new symbols are added to the table, they will gradually begin to be encoded in fewer bits. This process, however, will not happen very quickly. 



大多数著名的字典算法是自适应的

> At present, dictionary-based compression schemes using static dictionaries are mostly ad hoc, implementation dependent, and not general purpose. Most well-known dictionary algorithms are adaptive. Instead of having a completely defined dictionary when compression begins, adaptive schemes start out either with no dictionary or with a default baseline dictionary. As compression proceeds, the algorithms add new phrases to be used later as encoded tokens. 



GIF使用了 LZW 算法。

> Compuserve Information Service developed a dictionary-based compression scheme used to encode bit-mapped graphical images. The GIF format uses an LZW variant to compress repeated sequences in screen images. Compression is clearly needed when using these type of images. Computer images take up lots of storage space. As video resolutions improve, the size of the saved images grows 



Modern 里面本身就有压缩算法

> Compressing files before transmitting them saves telecommunications bandwidth. But this requires compatible compression software on both ends. A more convenient method of conserving bandwidth’s to build data compression directly into the modem. Microcom Corp. originally developed this idea, which used Huffman coding to compress data before it was transmitted by its modems. Microcom’s compression algorithm, MNP-5, uses a dynamic Huffman coding scheme that performs well as a general-purpose compressor on most data streams. 



音频输出最后会转成 analog format 模拟信号，然后才能被人的耳朵接受。

> For modern computers to manipulate sound, they first have to convert it to a digital format. The sound samples can then be processed, transmitted, and converted back to analog format, where they can finally be received by the human ear.



波形中最大的可识别成分似乎 有一个大约两毫秒的周期

> This particular “snapshot” shows about 5 milliseconds (ms) of output. Notice that the largest recognizable components of the waveform appear to have a period of roughly two milliseconds. This corresponds to a frequency of about 500Hz, a fairly characteristic frequency found in speech or music. 



ADC 把 模拟信号 转成 数字信号

> In most computer systems, this first step of digitization is done with an analog-to-digital converter (ADC). The ADC takes a given voltage and scales it to an appropriate digital measurement. An eight-bit ADC, for example, might have a “full scale” input voltage of 500 millivolts (mv)—it would output an eight-bit value of 255 if the input voltage were 500mv and zero if the input voltage were 



声音通过 DAC 被播放出来

> Eventually, the sound needs to be played back. This is done via another electronic component that is the converse of the ADC: the digital-to-analog converter (DAC). The DAC is responsible for taking a digital value and converting it to a corresponding analog signal. To be effective, the conversion process needs to be the mirror image of that performed when converting the analog signal to digital. While the exact voltages produced at the output of the DAC do not need to be identical to those seen at the input, they do need to be proportional to one another so that one waveform corresponds to the other. In addition, the samples need to be output at exactly the same rate that they were read in. Any deviation here will cause the output frequencies to be shifted up or down from the input, generally not a good thing. 



早期的电脑只能发出哔哔声和嗡嗡声

> 早期的台式电脑并没有真正推动声音再现技术的发展。最初的IBM和苹果电脑都有内置的扬 声器作为标准设备，但他们只给了程序员一个位来控制扬声器。这意味着扬声器通常只能用 来发出哔哔声和嗡嗡声，而不是真正的数字化声音。



Macintosh 增加了 8 位的模转换器

> 然而，在20世纪80年代初，许多计算机制造商看到，真正的数字化声音能力可以以相对较低 的成本添加到他们的计算机。苹果公司是最突出的制造商，在Macintosh上增加了一个八位数 模转换器，这为使用真正的数字化音频打开了大门。



DSP 作为辅助处理器

> 它将数字信号处理器（DSP）芯片作为一个辅助处理器； 其目的是为了从主CPU上卸载工作，如处理数字化的音频。有一段时间，其他制造商也采用 了这种设计，例如，苹果公司的Macintosh电脑的AV系列。



英特尔的P6处理器 让钟摆。

> 最近，似乎钟摆可能 向另一个方向移动，因为CPU中新的大量处理能力将使其除了处理常规任务外，还可以用于 音频和视频处理。英特尔正在用其新的P6处理器颁布这种配置，该处理器有足够的周期，可 用于即时压缩和解压音频和视频，甚至在电子表格中计算数字时也可以。





> LZSS在压缩时利用的是文件中的重复字符串。顺序0哈夫曼编码只是利用了单个序列的整体 频率差异。



不具备 在输入波形中找到这种类型的冗余的能力

> 即使是看这样一个 "繁忙 "的样本，人的眼睛也会挑出模式。波形的波峰和波谷以一 定的时间间隔出现，告诉我们信号中存在正弦波。不幸的是，我们现有的压缩算法并不具备 在输入波形中找到这种类型的冗余的能力。为了做得更好，我们需要转移到一个新的领域： 有损压缩。



找一下 LPC 和 ADPCM 的代码实现。

> 像LPC和ADPCM这样的过程代表了将在桌面上越来越频繁地使用的算法类型。不幸的是，这 些算法的复杂性远远超出了本章中样本程序的范围。



他用了 8 位 的灰度图像来表达振幅。

> In this case, the “signal” is a graphical image. The X and Y axes are the two dimensions of the screen. The amplitude of the “signal” in this case is simply the value of a pixel at a particular point on the screen. For the examples used in this chapter, that is an eight-bit value used to represent a grey-scale value. So a graphical image displayed on the screen can be thought of as a complex threedimensional signal, with the value on the Z axis denoted by the color on the screen at a given point. This is the spatial representation of the signal. 



DCT可用于将空间信息转换为 "频率 "或 "光谱 "信息

> The DCT can be used to convert spatial information into “frequency” or “spectral” information, with the X and Y axes representing frequencies of the signal in two different dimensions. And like the FFT, there is an Inverse DCT (IDCT) function that can convert the spectral representation of the signal back to a spatial one. 



有很多技巧可以加速 傅里叶 跟 DCT 变换的计算。

> 由于DCT与离散傅里叶变换有关，许多用于加速傅里叶变换系列的技术也可以应用于DCT， 这并不令人惊讶。事实上，全世界的人都在全心全意地将数字信号处理技术应用到DCT上。 执行变换所需的时间每减少一个周期，就会有一笔小财富，所以这些研究工作有很好的激励 作用。



JPEG 的量子位

> JPEG算法使用一个量化矩阵来实现量化。对于 DCT 矩阵中的每一个元素位置，量化矩阵中 的对应值给出一个量子值。量子值表明该元素在图片的压缩演绎中的步长是多少，其值范围 从1到255。



JPEG 已经定义好了一套量化矩阵。

> 



彩色图片是把 RGB，YUV 分开多个通道压缩的。

> 颜色是什么？ 本章中的示例程序和大部分文字都谈到了如何压缩只有一种颜色成分的图像，通常是灰度。 这就留下了如何处理彩色图像的问题。 彩色图像一般由三个部分组成，如RGB的红、绿、蓝，或YUV的亮度和色度。在这些情况下 ，JPEG将图像处理成实际上是三个独立的图像。一个RGB图像将首先压缩它的红色成分，然 后是绿色，然后是蓝色。这在本质上只是更多的相同。











