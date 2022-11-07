//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define offsetof(value,StructVal) printf("%d\n", (((char *)&(value)) - ((char *)&StructVal)));
////把对应变量的地址转化为char*指针，再相减就可以得到偏移量。
//typedef struct STU
//{
//	char c;// 占据结构体从0号单元开始的1个字节
//	int a;// 4/8 选4的倍数 所以从4号单元开始，占据结构体从4号单元开始的4个字节
//	double d;// 8/8 8的倍数 占据结构体从8号单元开始的8个字节
//}stu;
//int main()
//{
//	stu s;
//	printf("%d\n", sizeof(stu));
//	offsetof(s.c, s);
//	offsetof(s.a, s);
//	offsetof(s.d, s);
//	return 0;
//}