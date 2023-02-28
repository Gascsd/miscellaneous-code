#define _CRT_SECURE_NO_WARNINGS 1

////将a数组中最后一个元素移到数组开头, 其余数据依次往后平移一个位置。
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//int main()
//{
//	//int a[] = { 1,2,3,4,5,6,7,8,9,0 };
//	//int a[10];
//	int n = 0;
//	scanf("%d", &n);
//	int* a = (int*)malloc(sizeof(int) * n);
//	assert(a);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	int tmp = a[n-1];
//	for (int i = n - 1; i > 0; i--)
//	{
//		a[i] = a[i - 1];
//	}
//	a[0] = tmp;
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
//
//
//
////给定一个数，在数组中查找如果数组中存在，将其从数组删除其余数据依次往前平移一个位置
//#include<stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < 10; i++)
//	{
//		if (n == a[i])
//		{
//			for (int j = i; j < 9; j++)
//			{
//				a[j] = a[j + 1];
//			}
//		}
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
#include<stdio.h>
void func(int n)
{
	if (n != 0)
	{
		func(n / 10);
		printf("%d ", n % 10);
	}
}
//尾递归

//int fib1(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1 || n == 2)
//		return 1;
//	return fib(n - 1) + fib(n - 2);
//	//开辟函数栈帧
//}
typedef long long ll;
ll fib2(int n)
{
	int i = 3;
	ll a, b, c;
	a = b = 1;
	if (n == 1 || n == 2)
		return a;
	while (i <= n)
	{
		c = a + b;
		a = b;
		b = c;
		i++;
	}
	return b;
}
#include<iostream>
using namespace std;
int main()
{
	int n = 123;
	//循环做法
	//int tmp = n % 10;
	//printf("%d ", tmp);
	//while (n /= 10)
	//{
	//	tmp = n % 10;
	//	printf("%d ", tmp);
	//}
	//递归做法
	//func(n);
	//printf("%d", fib2(50));
	cout << fib2(50) << endl;
	return 0;
}

