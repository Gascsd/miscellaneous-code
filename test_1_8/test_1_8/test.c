#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
//��д��������������ʱ���������ַ����ĳ��ȡ�
//size_t my_strlen1(const char* str)//������ʱ�����ķ�ʽ
//{
//	assert(str);
//	int count = 0;
//	while (*str++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//
//
//size_t my_strlen2(char* str)//��������ʱ����(�ݹ�)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen2(str + 1);
//	}
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	//printf("strlen:%d", strlen(arr));
//	//printf("my_strlen1:%d\nmy_strlen2:%d", my_strlen1(arr), my_strlen2(arr));
//	size_t a = my_strlen1(arr);
//	return 0;
//}


////��n�Ľ׳ˡ��������������
////1*2*3*4*5...*n
//int f1(int n)//ѭ����
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;//ret = ret * i
//	}
//	return ret;
//}
//int f2(int n)//�ݹ鷨
//{
//	//n! = n * (n-1)!
//	if (n == 1)
//	{
//		return 1;
//	}
//	return n * f2(n - 1);
//}
//
//#include<stdio.h>
//int main()
//{
//	printf("f1(): %d\n", f1(4));
//	printf("f2(): %d\n", f2(4));
//	return 0;
//}

//���n��쳲����������������������
//1 1 2 3 5 8 13 21 34...
//typedef long long ll;
//int feb(int n)//�ݹ鷨
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 1;
//	return feb(n - 1) + feb(n - 2);
//}
//int feb2(int n)//������/ѭ����
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	ll a, b, c;
//	a = 1;
//	b = 1;
//	c = 2;
//	int count = 0;
//	while (count < n - 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		count++;
//	}
//	return c;
//}
//
//int main()
//{
//	ll ret = 0;
//	ret = feb2(50);
//	printf("%lld\n", ret);
//	return 0;
//}



//int main()
//{
//	int a = -13;
//	int b = 13;
//	return 0;
//}


//1. ��ŵ������
//2. ������̨������