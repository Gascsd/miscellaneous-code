#define _CRT_SECURE_NO_WARNINGS 1

/*�������С����*/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	FILE* fp = fopen("log.txt", "a+");
	int flag = 0;//�ж��Ƿ���ֻ����һ�ξ����ı�־
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
			system("pause");
			if (a % 2)
			{
				printf("�϶�\n");
				fprintf(fp, "ʱ�䣺%d��%d��%d��%dʱ%d��%d��->�϶�\n", 
					1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
			}
			else
			{
				printf("��\n");
				fprintf(fp, "ʱ�䣺%d��%d��%d��%dʱ%d��%d��->��\n", 
					1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
			}
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
	fclose(fp);
	system("pause");
	return 0;
}