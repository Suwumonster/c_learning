//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define offsetof(value,StructVal) printf("%d\n", (((char *)&(value)) - ((char *)&StructVal)));
////�Ѷ�Ӧ�����ĵ�ַת��Ϊchar*ָ�룬������Ϳ��Եõ�ƫ������
//typedef struct STU
//{
//	char c;// ռ�ݽṹ���0�ŵ�Ԫ��ʼ��1���ֽ�
//	int a;// 4/8 ѡ4�ı��� ���Դ�4�ŵ�Ԫ��ʼ��ռ�ݽṹ���4�ŵ�Ԫ��ʼ��4���ֽ�
//	double d;// 8/8 8�ı��� ռ�ݽṹ���8�ŵ�Ԫ��ʼ��8���ֽ�
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