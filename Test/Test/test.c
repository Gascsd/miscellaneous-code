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
//	//��һ������������
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int** a = (int**)malloc(sizeof(int) * m);//����һ��һά���飬�������Ԫ����һά����
//	if (a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	for (int i = 0; i < m; i++)//Ϊһά�����Ԫ�أ����飩���ٿռ�
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		if (tmp == NULL)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		a[i] = tmp;
//	}
//	//�ڶ��������������Ԫ��
//	for (int i = 0; i < m; i++)//һ��ѭ������һ��Ԫ�صĺ�
//	{
//		for (int j = 0; j < n; j++)
//		{
//			a[i][j] = i + j;//�����ڵ�Ԫ�����Ϊ��Ԫ��λ�õ�����֮��
//		}
//	}
//
//
//	//����������������
//	for (int i = 0; i < m; i++)//�����ά����
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < m; i++)//һ��ѭ������һ��Ԫ�صĺ�
//	{
//		int sum = 0;
//		for (int j = 0; j < n; j++)
//		{
//			sum += a[i][j];
//		}
//		printf("��%d�е�Ԫ��֮��Ϊ:%d\n", i, sum);
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
	for (int i = 0; i < sizeof(arr) - 1; i++)//��������arr
	{
		if (isupper(arr[i]))//��д��ĸ�����
		{
			//�����д��ĸ�������ǰ�벿��
			count[arr[i] - 'A']++;
		}
		else if (islower(arr[i]))
		{
			//Сд��ĸ�ں�벿��
			count[arr[i] - 'a' + 26]++;
		}
		else
		{
			//��ֹ�������
			printf("������������з���ĸ���ڣ��˳�����\n");
			return -1;
		}
	}
	//�ҵ�����count�����ֵ���±�
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
	//�±껹ԭΪ�ַ�
	char ret;
	if (index < 26)//��д��ĸ
	{
		ret = index + 'A';
	}
	else
	{
		ret = index + 'a' - 26;
	}
	printf("���ִ���������ĸΪ��%c", ret);
	return 0;
}