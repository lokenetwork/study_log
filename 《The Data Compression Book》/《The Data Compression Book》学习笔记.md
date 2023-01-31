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
