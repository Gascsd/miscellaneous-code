#define _CRT_SECURE_NO_WARNINGS 1

/*�������С����*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int flag = 0;
	int input = 0;
	printf("����1����ʼ������\n����0�˳�����\n");
	scanf("%d", &input);
	while (1)
	{
		if (input == 1 && flag == 0)
		{
			flag = 1;
			srand((unsigned)time(NULL));
			int a = rand();//���������
			if (a % 2)
				printf("����\n");
			else
				printf("����\n");
		}
		else if (flag == 1)
		{
			printf("�������ֻ����һ�β�����׼�ģ�����ֻ��һ��Ŷ\n");
			break;
		}
		else
		{
			printf("�˳�\n");
			return 0;
		}
	}
	system("pause");
	return 0;
}