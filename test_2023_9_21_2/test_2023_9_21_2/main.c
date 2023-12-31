#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>


// -1 的 补码 是 全 1111111111111111111111111111111
//
//


//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	//-1 ~ -128 ~ 127 ~ 0
//	//128 + 127 = 255
//	printf("%d", strlen(a));
//	// '\0' == 数字0
//	return 0;
//}


// 可以将其想象成一个圆环，右边圆 0 ~ 127 左边圆 -128 ~ - 1
//                       00000000...01111111    10000000...11111111
//
// 从-1 到 -128 再减为什么就是127，而不是-129
// 10000000 00000000 00000000 10000001
// 11111111 11111111 11111111 01111110
// 11111111 11111111 11111111 01111111
// 
// 01111111
// 存在char类型中，只能是01111111，在整型提升的时候补零就是，那就是-127
// 
//

//int main()
//{
//	if (strlen("abc") - strlen("abcdef") >= 0)
//		printf(">\n");
//	else
//		printf("<\n");
//	return 0;
//}

//
// 整形家族的范围定义在：limits.h头文件中
// 浮点类型家族的范围定义在：float.h头文件中
//
// 浮点数在内存中的存储：
// 1E10 == 1乘以10的10次方
// 
// 

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}
// 根据国际标准IEEE（电气和电子工程协会） 754，任意一个二进制浮点数V可以表示成下面的形式：
// (-1)^S * M * 2^E
// (-1)^S表示符号位，当S=0，V为正数；当S=1，V为负数。
// M表示有效数字，大于等于1，小于2
// 2^E表示指数位
// 
// eg:5.0F
// V = 5.0F, 101.0   1.01 * 2^2  类比：123.45 = 1.2345 * 10^2   S=0，M=1.01，E=2。
// V = 9.5F, 1001.1   S=1，M=1.01，E=2。
// tips:二进制表示中，小数点前第一位权重是2^0,在前一位是2^1，小数点后第一位的权重是2^-1,第二位是2^-2, 以此类推
// V = 9.6, 1001.100....1010001000
// 
// 0.525f 0.11
// s = 0, m = 1.1 e = -1
// 
// 
// IEEE 754对有效数字M和指数E，还有一些特别规定。
// 前面说过， 1 ≤ M < 2 ，也就是说，M可以写成 1.xxxxxx 的形式，其中xxxxxx表示小数部分。
// IEEE 754规定，在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的
// xxxxxx部分。比如保存1.01的时
// 候，只保存01，等到读取的时候，再把第一位的1加上去。这样做的目的，是节省1位有效数字。以32位
// 浮点数为例，留给M只有23位，
// 将第一位的1舍去以后，等于可以保存24位有效数字。
//

//int main()
//{
//	float num = 0.5f;
//	//0011 1111 0000 0000 0000 0000 0000 0000 
//	//0011 1111 0000 0110 0110 0110 0110 0110
//
//	if (num == 0.5)
//		printf("1\n");
//	return 0;
//}

// 0.5f
// v = 0.5f 
//   = 0.1
//   = -1^0 * 1.0 * 2^(-1) 
// s = 0, m = 1.0, e = -1
// 
// float 中的 e = 计算出的来e + e的中间值（+ 127）
// double 中的 e = 计算出的来e + e的中间值（+ 1023）
//

/*
至于指数E，情况就比较复杂。
首先，E为一个无符号整数（unsigned int）
这意味着，如果E为8位，它的取值范围为0~255；如果E为11位，它的取值范围为0~2047。但是，我们
知道，科学计数法中的E是可以出
现负数的，所以IEEE 754规定，存入内存时E的真实值必须再加上一个中间数，对于8位的E，这个中间数
是127；对于11位的E，这个中间
数是1023。比如，2^10的E是10，所以保存成32位浮点数时，必须保存成10+127=137，即
															10001001。

*/


//int main()
//{
//	float f = 5.5f;
//	// 101.1
//	// 1.011 * 2 ^ 2
//	// s = 0 m = 1.011 e = 2
//	// 2 + 127 = 129
//	// 0 1000 0001 01100000000000000000000
//	// 0x40 b0 00 00
//	// 
//	printf("%d\n", f);
//	return 0;
//}

// 往出取的时候，又有不同的规定

/*
E不全为0或不全为1
这时，浮点数就采用下面的规则表示，即指数E的计算值减去127（或1023），得到真实值，再将
有效数字M前加上第一位的1。


E全为0
这时，浮点数的指数E等于1-127（或者1-1023）即为真实值，
有效数字M不再加上第一位的1，而是还原为0.xxxxxx的小数。这样做是为了表示±0，以及接近于
0的很小的数字。

如果e为零，那么真实的 e 将会是 -127 如果真实的e是-127，那么它将是一个极小极小的值，无限接近于0


E全为1
这时，如果有效数字M全为0，表示±无穷大（正负取决于符号位s）；

*/


// 再分析下面的代码

//int main()
//{
//	int n = 9;
//	// 0  00000000  00000000000000000001001
//	// s = 0, e = -126, m = 0.000000000000000001001
//	// 
//	// 
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	// 1001.0
//	// 1.001 * 2 ^ 3
//	// s = 0, e = 130, m = 00100000000000000000000
//	// 0 10000010 00100000000000000000000
//	printf("num的值为：%d\n", n);
//	
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}


// 一个数组中，前面全是奇数，后面全是偶数
//
//
//
int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int left = 0, right = sizeof(arr1) / sizeof(arr1[0]) - 1;
	while (left < right)
	{
		while (left < right && arr1[left] % 2 == 1)
		{
			left++;
		}
		while (left < right && arr1[right] % 2 == 0)
		{
			right--;
		}
		int tmp = arr1[left];
		arr1[left] = arr1[right];
		arr1[right] = tmp;
		
		left++, right--;
	}


	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", arr1[i]);
	}

	return 0;
}

