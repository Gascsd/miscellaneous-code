#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#define N 10
//int main()
//{
//	//什么叫初始化？什么叫使用
//	int arr[10] = { 1,2,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组内元素的个数
//	//scanf的使用：scanf的第二个参数之后的所有参数传地址
//	//int n;
//	//scanf("%d", &n);
//	//scanf("%s", arr);
//	//%s表示格式化输入或者格式化输出字符串
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("arr[%d] : %p\n", i, &arr[i]);
//	}
//	//arr[10] = 20;//典型错误：数组的越界访问！！！
//	return 0;
//}

int main()
{
	//二维数组创建
	//int arr1[4][10] = { 1,2,3,4,5,6,7,8,9,0 };
	//int arr2[][5] = { 1,2,3,4,5,6,7,8,9,0 };
	//int arr3[4][] = { 1,2,3,4,5,6,7,8,9,0 };//省略列不写不行
	//int arr4[][] = { 1,2,3,4,5,6,7,8,9,0 };//省略行和列不写不行
	
	//二维数组初始化

	int arr[4][10] = { {0,1,2,3,4}, {5,6,7,8,9}, {3}, {1,5} };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}