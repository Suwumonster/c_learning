#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
void menu()
{
	printf("************************\n");
	printf("******   1.play   ******\n");
	printf("******   0.exit   ******\n");
	printf("************************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		printf("�������(1-100):");
		scanf("%d", &guess);
		if (ret < guess)
		{
			printf("�´���\n");
		}
		else if (ret > guess)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ��¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}