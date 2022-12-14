/* expr_test.c源文件 */
/*********************************************************** 
 * 功能:	算术表达式测试
 **********************************************************/
void expr_arithmetic_test()
{
	int a = 6, b = 2, c, d, e, f, g;
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;
	g = a % b;
	printf("%d + %d = %d\n",a,b,c);
	printf("%d - %d = %d\n",a,b,d);
	printf("%d * %d = %d\n",a,b,e);
	printf("%d / %d = %d\n",a,b,f);
	printf("%d %% %d = %d\n",a,b,g);
}

/*********************************************************** 
 * 功能:	指针运算测试
 **********************************************************/
void pointer_op_test()
{
	char 	*p1 = 0, *p2;
	short *p3 = 0, *p4;
	int  	*p5 = 0, *p6;
	
	p2 = p1 + 1;
	p4 = p3 + 1;
	p6 = p5 + 1;	
	printf("p1=%.8x, p2=%.8x\n",p1,p2);
	printf("p3=%.8x, p4=%.8x\n",p3,p4);
	printf("p5=%.8x, p6=%.8x\n",p5,p6);
}

/*********************************************************** 
 * 功能:	比较运算测试
 **********************************************************/
void expr_cmp_test()
{
    int a, b,c;
        
    a = 123;
    b = 456;    
    printf("%d == %d = %d\n", a, a, a == a);
    printf("%d != %d = %d\n", a, a, a != a);

    printf("%d < %d = %d\n", a, b, a < b);
    printf("%d <= %d = %d\n", a, b, a <= b);
    printf("%d <= %d = %d\n", a, a, a <= a);
    printf("%d >= %d = %d\n", b, a, b >= a);
    printf("%d >= %d = %d\n", a, a, a >= a);
    printf("%d > %d = %d\n", b, a, b > a);
}

/*********************************************************** 
 * 功能:	数组测试
 **********************************************************/
void array_test()
{
	int arr1[2];
	int arr2[2][2];
	
	arr1[0] = 100;
  arr1[1] = 200;
  
  arr2[0][0] = 10; 		   
  arr2[0][1] = 20;  
  arr2[1][0] = 30;
  arr2[1][1] = 40;
	
  printf("arr1[0] = %d, arr1[1] = %d\n", arr1[0], arr1[1]);
  printf("arr2[0][0]=%d, arr2[0][1]=%d\n", arr2[0][0], arr2[0][1]);
  printf("arr2[1][0]=%d, arr2[1][1]=%d\n", arr2[1][0], arr2[1][1]);
}

/*********************************************************** 
 * 功能:	正符号测试
 **********************************************************/
void plus_minus_test()
{
	int a = +7;
	int b = -9;
	
	printf("a = %d, b = %d\n", a, b);
}

/*********************************************************** 
 * 功能:	类型自动转换测试
 **********************************************************/
int cast_test()
{
	int c;
	short b;
	char a;
	
	a = 68;
	b = a;
	c = b;
	printf("a = %d, b = %d, c= %d\n", a, b, c);  
}

/*********************************************************** 
 * 功能:	main函数
 **********************************************************/
int  main()
{

	expr_arithmetic_test();
	pointer_op_test();
	expr_cmp_test();	
	array_test();
	plus_minus_test();
	cast_test();
		
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