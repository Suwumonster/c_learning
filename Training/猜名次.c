#define _CRT_SECURE_NO_WARNINGS 1
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			if (a != b)
			{
				for (c = 1; c <= 5 ; c++)
				{
					if (a != c && b != c)
					{
						for (d = 1; d <= 5; d++)
						{
							if (a != d && b != d && c != d)
							{
								for (e = 1; e <= 5; e++)
								{
									if (((b == 2 && a != 3) || (a == 3 && b != 2)) && ((b == 2 && e != 4) || (e == 4 && b != 2)) && ((c == 1 && d != 2) || (d == 2 && c != 1)) && ((c == 5 && d != 3) || (d == 3 && c != 5)) && ((e == 4 && a != 1) || (a == 1 && e != 4)) && (a != e && b != e && c != e && d != e))
									{
										printf("A=第%d名，B=第%d名，C=第%d名，D=第%d名，E=第%d名\n", a, b, c, d, e);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}