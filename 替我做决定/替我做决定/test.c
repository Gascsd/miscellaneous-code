#define _CRT_SECURE_NO_WARNINGS 1

/*随机决定小程序*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int flag = 0;
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
			if (a % 2)
				printf("放弃\n");
			else
				printf("继续\n");
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
	system("pause");
	return 0;
}