#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("***********************************\n");
	printf("**************1. play**************\n");
	printf("**************0. exit**************\n");
	printf("***********************************\n");
	printf("������ѡ�0/1����");
}

void game()
{
	printf("����Ϸ...\n");
	int anchor = rand();
	int num = 0;
	while (1)
	{
		printf("������µ������֣�");
		scanf("%d", &num);
		if (num == anchor)
		{
			printf("��ϲ�㣬�µ��ˣ�����\n");
			return;
		}
		else//�´��˵����
		{
			if (num > anchor)
			{
				printf("�´���\n");
			}
			else
			{
				printf("��С��\n");
			}
		}
	}
}