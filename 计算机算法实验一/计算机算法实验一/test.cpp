#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y; 
//	y = tmp;
//}
//
//void BubbleSort(int a[], int n)
//{
//	int i, j;
//	for (i = 0; i < n - 1;i++)
//	{
//		for (j = n - 1; j > i; j--)
//		{
//			if (a[j] < a[j - 1])
//				Swap(a[j], a[i]);
//		}
//	}
//}
//
//void disp(int a[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//}
//
//void main()
//{
//	int n = 10;
//	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
//	printf("����ǰ��");
//	disp(a, n);
//	BubbleSort(a, n);
//	printf("�����");
//	disp(a, n);
//}



#include <ctime>
#include<iostream>
using namespace std;
int main()
{
	clock_t start, end;
	start = clock();
	f();//���ȫ���еݹ麯��end=clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}