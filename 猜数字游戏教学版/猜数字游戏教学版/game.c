#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("***********************************\n");
	printf("**************1. play**************\n");
	printf("**************0. exit**************\n");
	printf("***********************************\n");
	printf("请输入选项（0/1）：");
}

void game()
{
	printf("玩游戏...\n");
	int anchor = rand();
	int num = 0;
	while (1)
	{
		printf("请输入猜到的数字：");
		scanf("%d", &num);
		if (num == anchor)
		{
			printf("恭喜你，猜到了！！！\n");
			return;
		}
		else//猜错了的情况
		{
			if (num > anchor)
			{
				printf("猜大了\n");
			}
			else
			{
				printf("猜小了\n");
			}
		}
	}
}