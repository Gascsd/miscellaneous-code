#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i, j, x, y, max;
//	int a[3][4];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	max = a[0][0];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", a[i][j]);
//
//			if (a[i][j] > max)
//			{
//				max = a[i][j];
//				x = i;
//				y = j;
//			}
//		}
//		printf("\n");
//	}
//	printf("%d %d %d", max, x, y);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//第一步：开辟数组
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int** a = (int**)malloc(sizeof(int) * m);//定义一个一维数组，该数组的元素是一维数组
//	if (a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	for (int i = 0; i < m; i++)//为一维数组的元素（数组）开辟空间
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		if (tmp == NULL)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		a[i] = tmp;
//	}
//	//第二步：数组内填充元素
//	for (int i = 0; i < m; i++)//一次循环就是一行元素的和
//	{
//		for (int j = 0; j < n; j++)
//		{
//			a[i][j] = i + j;//数组内的元素填充为该元素位置的行列之和
//		}
//	}
//
//
//	//第三步：输出和求和
//	for (int i = 0; i < m; i++)//输出二维数组
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < m; i++)//一次循环就是一行元素的和
//	{
//		int sum = 0;
//		for (int j = 0; j < n; j++)
//		{
//			sum += a[i][j];
//		}
//		printf("第%d行的元素之和为:%d\n", i, sum);
//	}
//	return 0;
//}

#include<stdio.h>
#include<ctype.h>
int main()
{
	char arr[] = "AAABBBCCCaaaabbbcc";
	int count[52] = { 0 };
	int i = 0;
	for (int i = 0; i < sizeof(arr) - 1; i++)//遍历数组arr
	{
		if (isupper(arr[i]))//大写字母的情况
		{
			//假设大写字母在数组的前半部分
			count[arr[i] - 'A']++;
		}
		else if (islower(arr[i]))
		{
			//小写字母在后半部分
			count[arr[i] - 'a' + 26]++;
		}
		else
		{
			//防止输入错误
			printf("输入的内容中有非字母存在，退出程序\n");
			return -1;
		}
	}
	//找到数组count中最大值的下标
	int max = count[0];
	int index = 0;
	for (int i = 0; i < 52; i++)
	{
		if (max < count[i])
		{
			max = count[i];
			index = i;
		}
	}
	//下标还原为字符
	char ret;
	if (index < 26)//大写字母
	{
		ret = index + 'A';
	}
	else
	{
		ret = index + 'a' - 26;
	}
	printf("出现次数最多的字母为：%c", ret);
	return 0;
}