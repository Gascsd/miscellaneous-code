#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#define N 10
//int main()
//{
//	//ʲô�г�ʼ����ʲô��ʹ��
//	int arr[10] = { 1,2,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//����������Ԫ�صĸ���
//	//scanf��ʹ�ã�scanf�ĵڶ�������֮������в�������ַ
//	//int n;
//	//scanf("%d", &n);
//	//scanf("%s", arr);
//	//%s��ʾ��ʽ��������߸�ʽ������ַ���
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("arr[%d] : %p\n", i, &arr[i]);
//	}
//	//arr[10] = 20;//���ʹ��������Խ����ʣ�����
//	return 0;
//}

int main()
{
	//��ά���鴴��
	//int arr1[4][10] = { 1,2,3,4,5,6,7,8,9,0 };
	//int arr2[][5] = { 1,2,3,4,5,6,7,8,9,0 };
	//int arr3[4][] = { 1,2,3,4,5,6,7,8,9,0 };//ʡ���в�д����
	//int arr4[][] = { 1,2,3,4,5,6,7,8,9,0 };//ʡ���к��в�д����
	
	//��ά�����ʼ��

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