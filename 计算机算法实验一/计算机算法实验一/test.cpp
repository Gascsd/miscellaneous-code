#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//int* is_prime(int* a, int n)
//{
//
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* a = (int*)malloc(sizeof(int) * n);
//	
//	return 0;
//}

//#include<stdio.h>
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y; 
//	y = tmp;
//}
//
//void BubbleSort(int a[], int n)//≈≈–Ú
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
//void disp(int a[], int n)//¥Ú”°
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
//	printf("≈≈–Ú«∞£∫");
//	disp(a, n);
//	BubbleSort(a, n);
//	printf("≈≈–Ú∫Û£∫");
//	disp(a, n);
//}



#include <ctime>
#include<iostream>
using namespace std;

void perm(int* A,int k,int n)
{
	if (k == 1)
	{

	}

}
int main()
{
	int n;
	cin >> n;
	if (n < 0)
	{
		cerr << "requires n >= 0" << endl;
		return -1;
	}
	clock_t start, end;
	start = clock();
	sum(n);//ƒ„µƒ»´≈≈¡–µ›πÈ∫Ø ˝
	end=clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}