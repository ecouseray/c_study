#define _CRT_SECURE_NO_WARNINGS 



/*
结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。

数组是相同元素的集合

*/

//struct Stu
//{
//	// Stu的相关属性
//	char name[20];
//	int age;
//};
//int main()
//{
//
//	return 0;
//}

/*
特殊类型：
// 匿名结构体类型	 只能在声明的时候用一次，别的时候就不能用了
*/

//struct Node
//{
//	int data;
//	struct Node next;
//};


//struct Node
//{
//	int data;           // 数据域
//	struct Node* next;  // 指针域
//};
// 


// 结构体的自引用

// 结构体嵌套

// 结构体内存对齐

/*

1. 第一个成员在与结构体变量偏移量为0的地址处。
2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
VS中默认的值为8
3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

offsetof 可以返回结构体类型中的成员，在结构体中的偏移量
offsetof(type, member)   来自：stddef.h


1. 平台原因(移植原因)：
不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特
定类型的数据，否则抛出硬件异常。

2. 性能原因：
数据结构(尤其是栈)应该尽可能地在自然边界上对齐。
原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访
问。

结构体的内存对齐是拿空间来换取时间的做法。

那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：
让占用空间小的成员尽量集中在一起。

之前我们见过了 #pragma 这个预处理指令，这里我们再次使用，可以改变我们的默认对齐数。
#pragma pack(8)


结构体传参
传值   .
传址   ->

函数传递参数的时候，参数需要压栈，会有时间和空间上的开销，综合考虑使用传址效率更高


位段的声明和结构是类似的，有两个不同：
1.位段的成员必须是 int、unsigned int 或signed int 。（char 也可以）
2.位段的成员名后边有一个冒号和一个数字。

这里的 位 表示 比特位
struct A
{
	int _a:2;
	int _b:5;
	int _c:10;
	int _d:30;
};

位段的内存分配
1. 位段的成员可以是 int unsigned int signed int 或者是 char （属于整形家族）类型
2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
*/


struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	//空间是如何开辟的？
}

/*
位段的跨平台问题
1. int 位段被当成有符号数还是无符号数是不确定的。
2. 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32，写成27，在16位机
器会出问题。
3. 位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
4. 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是
舍弃剩余的位还是利用，这是不确定的

位段的应用：
计算机网络中，网络中的源码中就有使用到位段

位段在以下几个方面常见的应用：

嵌入式系统：在资源受限的嵌入式系统中，位段可以有效地节省存储空间。例如，可以使用位段来表示设备寄存器的各个位，从而在编程过程中方便地对寄存器进行操作。

通信协议：位段可以用于定义和解析通信协议中的数据结构。例如，网络协议中的各个标志位、错误码等信息可以使用位段来表示，从而在传输过程中减少数据的大小和传输的开销。

数据压缩：在需要存储大量布尔类型数据或状态码等信息时，可以使用位段来将多个布尔值压缩为一个整型字段。这样可以显著减少所需的存储空间。

位操作优化：位段可以用于进行位操作优化，例如位掩码、位移等操作。通过合理地使用位段，可以提高程序的执行效率和性能。

尽管位段存在跨平台性的问题，但在特定的应用场景下，合理使用位段仍然可以带来一些好处。在使用位段时，需要仔细考虑平台相关性，并进行充分的测试和验证。
*/