#include "test.h"
// C语言深度刨析 - 3

/*

sizeof 关键字:
	1.确定一种类型，对应在开辟空间的时候 的大小
	2.sizeof 关键字 不是一个函数
		在使用一个函数的使用必须使用 () 函数调用操作符
		sizeof i == 4  证明了他不是函数，而是一个关键字
		并且在汇编层面，sizeof 在使用的时候不用压栈

1.C语言中有为什么要有类型？
	为了让程序员可以合理的划分使用内存，按需索取
2.C语言中有丰富的数据类型？
	应用场景不同，解决应用场景对应的计算方式不同，所需空间的大小也是不同的。
	本质：用最小的成本来，解决各种多样化的问题。
	(数据类型 是对应 大小内存块 的别名)
3.变量的命名规则
	字母、数字、下划线的组合(数字不可以作为开头)
	要做到见名知意

	建议：不要在名字中使用数字，除非有一些特殊的需求
	可以在变量上加一些全局限定符(不是特别推荐，有更好的解决办法)
	eg：3. 也可以使用之前的办法 g_val g 就代表他是一个全局变量，不用知道他是哪里来的

	匈牙利式命名不推荐， 见名知意 + 大小驼峰

	特别不推荐，使用仅靠 大小写区分变量；
	禁止 将函数名使用在别处(不要将变量命名为和函数一致)

	所有的 宏定义 枚举常量 只读变量全部使用大写字母命名

	在自己定义的循环因子 i j k

	局部变量在定义的时候一定要初始化，不初始化内容是随机值

	不同的数据类型，从低精度向高精度扩展

*/

//int main()
//{
	// 1.
	//printf("sizeof(char) = [%zu]\n", sizeof(char));
	//printf("%zu\n", sizeof(short));
	//printf("%zu\n", sizeof(int));
	//printf("%zu\n", sizeof(long));
	//printf("%zu\n", sizeof(long long));
	//printf("%zu\n", sizeof(float));
	//printf("%zu\n", sizeof(double));

	// 2.
	//int i = 10;
	//printf("%zu\n", sizeof(int));
	//printf("%zu\n", sizeof(i));
	//printf("%zu\n", sizeof i);
	// printf("%zu\n", sizeof int); // error
	
	//3.
	//printf("%d\n", te_val);

	//printf("%d\n", sizeof(int)*p);

	//system("pause");
	//return 0;
//}



/*

数据的存储：
	1.原反补
		整形在内存中的存储：
			原码 
			反码 = 原码 符号位不变 其他位 按位取反
			补码 = 反码 + 1
	任何数据在计算机中，都必须转化为二进制？为什么？
		计算机中的各种单元都是 两态的 更擅长记 二进制
		最高位 作为符号位 +-  剩下的位数 都是数据位
		有符号数 && 是一个正数 --> 原码 = 反码 = 补码
		有符号数 && 是一个负数 --> 

		在计算的时候，符号位是否需要参与计算呢？
			只要是加法，符号位都要参与运算
		 

	2.十转二，二转十
		1 后面有多少个比特位 就是 2 的 多少次方

*/

int main()
{
	// 计算机只认识二进制，计算机内存储的二进制必须是补码

	int a = 10;
	// 0000 0000 0000 0000 0000 0000 0000 1010
	// 0x00 00 00 0A

	int b = -20;
	// 20 = 16 + 4 = 2 ^ 4 + 2 ^ 2 = 10000 + 100 = 10100
	// 1000 0000 0000 0000 0000 0000 0001 0100 原码
	// 1111 1111 1111 1111 1111 1111 1110 1011 反码
	// 1111 1111 1111 1111 1111 1111 1110 1100 补码
	// 0x FF FF FF EC
	
	// 无符号数
	// 没有符号位 && 原码 = 反码 = 补码

	// 补码 -> 原码  将 原码 -> 补码的操作再来一边
	// 转化是 计算机硬件转化的， 原码 -> 补码  补码 -> 原码 是同一套硬件短路

	// 定义变量： 开辟空间， 将初始化的值转化为二进制， 存入所对应的内存空间
	// 在存储的时候，空间是不关心内容的 

	// 单纯的一个数字是没有意义的，必须带上类型才有意义

	// 类型决定了，如何解释空间内部的二进制序列

	// 在存的时候：字面数据必须先转化为补码，再放到空间当中，
	// 所以，所谓的符号位，完全看数据本身是否携带+-号，和变量是否有符号无关

	// eg： unsigned int i = -10;
	//      1111 1111 1111 1111 1111 1111 1111 0110
	// 1.先看自身类型：signed int
	//     a.先看符号位  为 1 是负数  所以存的是补码
	//	   b.确定原反补
	//	   c.取 （补 -> 原）


	// 

	return 0;
}