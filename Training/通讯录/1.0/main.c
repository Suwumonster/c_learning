#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*************************************\n");
	printf("*************************************\n");
	printf("******        通讯录           ******\n");
	printf("******  1.添加联系人信息       ******\n");
	printf("******  2.删除指定联系人信息   ******\n");
	printf("******  3.查找指定联系人信息   ******\n");
	printf("******  4.修改指定联系人信息   ******\n");
	printf("******  5.显示所有联系人信息   ******\n");
	printf("******  6.清空所有联系人       ******\n");
	printf("******  7.以名字排序所有联系人 ******\n");
	printf("******  0.退出                 ******\n");
	printf("*************************************\n");
	printf("*************************************\n");
}
int main()
{
	contact con;
	Init_con(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1://添加联系人信息
			add_con(&con);
			break;
		case 2://删除指定联系人信息
			del_con(&con, search_con(&con));
			break;
		case 3://查找指定联系人信息
			print_stu(&con, search_con(&con));
			break;
		case 4://修改指定联系人信息
			revise_con(&con, search_con(&con));
			break;
		case 5://显示所有联系人信息
			print_con(&con);
			break;
		case 6://清空所有联系人
			destroy_con(&con);
			break;
		case 7://以名字排序所有联系人
			sort_con(&con);
			break;
		case 0://退出
			printf("退出成功！\n");
			break;
		default://其他情况
			printf("输入错误！请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}