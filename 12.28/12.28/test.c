#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<Windows.h>
//int main()
//{
//	char input[10] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
//	scanf("%s", input);
//		if (0 == strcmp(input, "������"))
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
//	while (strcmp(input, "������"))
//	{
//		printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
//		scanf("%s", input);
//	}
//	system("shutdown -a");
//	return 0;
//}


//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//	// \62��������һ��ת���ַ�
//	printf("%d\n", strlen("c:\test\628\test.c"));
//	char ch = 62;
//	printf("%c", ch);
//	return 0;
//}
//
////��ƺ�����ԭ�򣺸��ھ۵����
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


////�Ӵ�С���3������
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
//	//�Ӵ�С������������е�����Ԫ��
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
//	//����������
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

////��ӡ1000-2000����
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
//				flag = 0;//0��ʾ������������
//				break;
//			}
//		}
//		if(flag)
//			printf("%d ", i);
//	}
//	return 0;
//}