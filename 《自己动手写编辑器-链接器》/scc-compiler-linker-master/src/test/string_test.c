/* string_test.c源文件 */
/*********************************************************** 
 * 功能:	字符集测试
 **********************************************************/
void characterset_test()
{
  printf("Hello哇，饭已OK了，下来めし吧！\n");
  /*printf("痋琫琭\n");*/
}

/*********************************************************** 
 * 功能:	字符串测试
 **********************************************************/
void string_test()
{
	char str1[] = "abc\n";
	char *str2  = "XYZ\n";
	printf(str1);
	printf(str2);
}

/*********************************************************** 
 * 功能:	字符测试
 **********************************************************/
void char_test()
{
	char c1= 'E';
	char c2= 'GH';
	printf("c1 = %c, c2 = %c\n", c1, c2);
}


/*********************************************************** 
 * 功能:	main函数
 **********************************************************/
int  main()
{
	characterset_test();
	string_test();
	char_test();	
		
	return 0;
}

/*********************************************************** 
 * 功能:	入口函数
 **********************************************************/
void  _entry()
{
	int ret;
	ret = main();
	exit(ret);
}