#define _CRT_SECURE_NO_WARNINGS 1

/*随机决定小程序*/


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
	int flag = 0;//判断是否是只做了一次决定的标志
	int input = 0;
	printf("输入1来开始做决定\n输入0退出程序\n");
	scanf("%d", &input);
	while (1)
	{
		if (input == 1 && flag == 0)
		{
			flag = 1;
			srand((unsigned)time(NULL));
			int a = rand();//产生随机数
			system("pause");
			if (a % 2)
			{
				printf("肯定\n");
				fprintf(fp, "时间：%d年%d月%d日%d时%d分%d秒->肯定\n", 
					1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
			}
			else
			{
				printf("否定\n");
				fprintf(fp, "时间：%d年%d月%d日%d时%d分%d秒->否定\n", 
					1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
			}
		}
		else if (flag == 1)
		{
			printf("随机决定只有做一次才是最准的，建议只做一次哦\n");
			break;
		}
		else
		{
			printf("退出\n");
			return 0;
		}
	}
	fclose(fp);
	system("pause");
	return 0;
}