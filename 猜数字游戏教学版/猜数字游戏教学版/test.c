#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int main()
{
	srand((unsigned int)time(NULL));
	int input = -1;
	while (input)
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏...\n");
			break;
		case 1:
			game();
			system("pause");
			system("cls");
			break;
		default:
			printf("输入错误，请重新输入...\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

