#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*************************************\n");
	printf("*************************************\n");
	printf("******        ͨѶ¼           ******\n");
	printf("******  1.�����ϵ����Ϣ       ******\n");
	printf("******  2.ɾ��ָ����ϵ����Ϣ   ******\n");
	printf("******  3.����ָ����ϵ����Ϣ   ******\n");
	printf("******  4.�޸�ָ����ϵ����Ϣ   ******\n");
	printf("******  5.��ʾ������ϵ����Ϣ   ******\n");
	printf("******  6.���������ϵ��       ******\n");
	printf("******  7.����������������ϵ�� ******\n");
	printf("******  0.�˳�                 ******\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1://�����ϵ����Ϣ
			add_con(&con);
			break;
		case 2://ɾ��ָ����ϵ����Ϣ
			del_con(&con, search_con(&con));
			break;
		case 3://����ָ����ϵ����Ϣ
			print_stu(&con, search_con(&con));
			break;
		case 4://�޸�ָ����ϵ����Ϣ
			revise_con(&con, search_con(&con));
			break;
		case 5://��ʾ������ϵ����Ϣ
			print_con(&con);
			break;
		case 6://���������ϵ��
			destroy_con(&con);
			break;
		case 7://����������������ϵ��
			sort_con(&con);
			break;
		case 0://�˳�
			printf("�˳��ɹ���\n");
			break;
		default://�������
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}