#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n] = 0;
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d "arr[i]);
//	}
//	return 0;
//}

////�β���ʵ�ε�һ����ʱ����
//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//void Swap1(int x, int y)
//{
//	int tmp = x;
//	x = y; 
//	y = tmp;
//}
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int a = 5, b = 10;
//	printf("a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	Swap1(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	printf("the max value is %d", Max(a, b));
//	return 0;
//}



//1. дһ�����������ж�һ�����ǲ���������
int is_prime(int a)
{
	int i = 0;
	for (i = 2; i < a / 2; i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

//2. дһ�������ж�һ���ǲ������ꡣ
int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

////3. дһ��������ʵ��һ��������������Ķ��ֲ��ҡ�
//#include<stdlib.h>
////[begin...mid...end]
////(begin+end)/2 == begin + (end-begin)/2
//int Find(int* arr, int ret, int begin, int end)//�ҵ�ret��ֵ������ҵ��ˣ����ظ�λ�õ��±꣬���򷵻�-1
//{
//	if (begin > end)
//	{
//		return -1;
//	}
//	int mid = begin + (end - begin) / 2;
//	if (ret == arr[mid])
//	{
//		return mid;
//	}
//	else
//	{
//		if (ret > arr[mid])//��[mid+1,end]
//		{
//			Find(arr, ret, mid + 1, end);
//		}
//		else//��[begin,mid-1]
//		{
//			Find(arr, ret, begin, mid - 1);
//		}
//	}
//}
//
//int* GetArray(int size)
//{
//	int* tmp = (int*)malloc(sizeof(int) * size);//malloc�ķ���ֵ������void*
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	for (int i = 0; i < size; i++)
//	{
//		tmp[i] = 2*i;
//	}
//	return tmp;
//}
//
//void print_arr(int* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int* arr = GetArray(100);
//	//print_arr(arr, 100);
//	int ret = 0;
//	scanf("%d", &ret);
//	int pos = Find(arr, ret, 0, 99);
//	if (pos == -1)
//	{
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ��%d", pos);
//	}
//	return 0;
//}

//4. дһ��������ÿ����һ������������ͻὫnum��ֵ����1��

//�ⷨһ��ʹ��ȫ�ֱ���
//int num = 0;
//int f()
//{
//	num++;
//	return num;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		count = f();
//	}
//
//	printf("%d", count);
//	return 0;
//}

////�ⷨ����ʹ��static���εľ�̬�ֲ�����
//int f()
//{
//	static int num = 0;
//	num++;
//	return num;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		count = f();
//	}
//	printf("%d", count);
//	return 0;
//}


//int main()
//{
//	int a = 3;
//	if (is_prime(a))
//		printf("is prime\n");
//	else
//		printf("is not prime\n");
//	int year = 2000;
//	if (is_leap_year(year))
//		printf("is leap year\n");
//	else
//		printf("is not leap year\n");
//	return 0;
//}
//#include<stdio.h>
//#include"test.h"
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	char arr[] = "hello zhaowan";
//
//	printf("%d", strlen(arr));
//	return 0;
//}

////����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ
//void f(size_t n)
//{
//	if (n > 9)
//	{
//		f(n / 10);
//	}
//	printf("%d ", n % 10);
//
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	f(n);
//	return 0;
//}

//��д��������������ʱ���������ַ����ĳ���
size_t my_strlen2(const char* str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen2(str + 1);
}
size_t my_strlen1(const char* str)
{
	size_t count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char str[] = "I love zhaowan";
	printf("%zd\n", my_strlen1(str));
	printf("%zd\n", my_strlen2(str));
	return 0;
}








