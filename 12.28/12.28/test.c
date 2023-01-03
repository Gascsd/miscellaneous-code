#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<Windows.h>
//int main()
//{
//	char input[10] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
//	scanf("%s", input);
//		if (0 == strcmp(input, "我是猪"))
//		{
//			system("shutdown -a");
//		}
//		else
//		{
//			goto again;
//		}
//	return 0;
//}

//int main()
//{
//	char input[10] = { 0 };
//	system("shutdown -s -t 60");
//	while (strcmp(input, "我是猪"))
//	{
//		printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
//		scanf("%s", input);
//	}
//	system("shutdown -a");
//	return 0;
//}


//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//	// \62被解析成一个转义字符
//	printf("%d\n", strlen("c:\test\628\test.c"));
//	char ch = 62;
//	printf("%c", ch);
//	return 0;
//}
//
////设计函数的原则：高内聚低耦合
//int Max(int a, int b)
//{
//	/*if (a > b)
//		return a;
//	else
//		return b;*/
//	return a > b ? a : b;
//}
//int main()
//{
//	int a, b, t;
//	scanf("%d%d", &a, &b);
//	t = Max(a, b);
//	printf("%d", t);
//	return 0;
//}


////从大到小输出3个整数
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int arr[3];
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//从大到小排序这个数组中的三个元素
//	for (int j = 0; j < 3; j++)
//	{
//		for (int i = 0; i < 3 - j; i++)
//		{
//			if (arr[i] < arr[i + 1])
//			{
//				Swap(&arr[i], &arr[i + 1]);
//			}
//		}
//	}
//
//	//输出这个数组
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int f(int x, int y)
//{
//	int tmp = 0;
//	int max = x;
//	int min = y;
//	if (max < min)
//	{
//		max = y;
//		min = x;
//	}
//	while (min)
//	{
//		tmp = max % min;
//		max = min;
//		min = tmp;
//	}
//	return max;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int ret = f(a, b);
//	printf("%d", ret);
//	return 0;
//}

////打印1000-2000闰年
//int main()
//{
//	for (int i = 1000; i < 2001; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//
//int main()
//{
//	for (int i = 101; i < 201; i+=2)
//	{
//		int flag = 1;
//		for (int j = 2; j < i/2; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//0表示该数不是素数
//				break;
//			}
//		}
//		if(flag)
//			printf("%d ", i);
//	}
//	return 0;
//}