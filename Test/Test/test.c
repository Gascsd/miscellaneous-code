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

//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[] = "AAABBBCCCaaaabbbcc";
//	int count[52] = { 0 };
//	int i = 0;
//	for (int i = 0; i < sizeof(arr) - 1; i++)//��������arr
//	{
//		if (isupper(arr[i]))//��д��ĸ�����
//		{
//			//�����д��ĸ�������ǰ�벿��
//			count[arr[i] - 'A']++;
//		}
//		else if (islower(arr[i]))
//		{
//			//Сд��ĸ�ں�벿��
//			count[arr[i] - 'a' + 26]++;
//		}
//		else
//		{
//			//��ֹ�������
//			printf("������������з���ĸ���ڣ��˳�����\n");
//			return -1;
//		}
//	}
//	//�ҵ�����count�����ֵ���±�
//	int max = count[0];
//	int index = 0;
//	for (int i = 0; i < 52; i++)
//	{
//		if (max < count[i])
//		{
//			max = count[i];
//			index = i;
//		}
//	}
//	//�±껹ԭΪ�ַ�
//	char ret;
//	if (index < 26)//��д��ĸ
//	{
//		ret = index + 'A';
//	}
//	else
//	{
//		ret = index + 'a' - 26;
//	}
//	printf("���ִ���������ĸΪ��%c", ret);
//	return 0;
//}

//#include<stdio.h>
//int factorial(int n)//��׳�
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//int Cmn(int m, int n)
//{
//	int Ann = factorial(n);
//	int Amm = factorial(m);
//	int An_m = factorial(n - m);
//	return Ann / (Amm * An_m);
//}
//int main()
//{
//	int m, n;
//	printf("input m,n:");
//	scanf("%d %d", &m, &n);
//	int ret = Cmn(m, n);
//	printf("%d!/(%d!*(%d-%d)!)=%d", n, m, n, m, ret);
//	return 0;
//}


//#include<stdio.h>
//
//float ff(float* x, float* y, float* z)
//{
//	return *x + *y + *z;
//}
//
//int main()
//{
//	int a[5] = { 1,2,3,4,5 }, * p, i;
//	for (p = a; p < a + 5; p++)
//	{
//		printf("%3d", ++(*p));
//	}
//	printf("\n");
//	for (p = a; p < a + 5; p++)
//	{
//		printf("%3d", ++ * p);
//	}
//	printf("\n");
//
//	return 0;
// }

#include<stdio.h>
void mov(int* x, int n, int m)
{
	int i, j;
	for (i = 0; i < m - 1; i++)
	{
		int tmp = x[n - 1];//����������һ��Ԫ�ؼ�¼��������ֹ�����ƶ�������Ԫ�ص�ʱ��ԭ�����е����һ��Ԫ�ظ���
		for (j = n - 1; j > 0; j--)
			x[j] = x[j - 1];
		x[0] = tmp;
	}

}

int main()
{
	int m, n, i, a[80], * p;
	printf("Input n,m:");
	scanf("%d%d", &n, &m);
	for (p = a, i = 0; i < n; i++)
 		scanf("%d", p++);
	mov(a, n, m);
	printf("After move : ");
	for (i = 0; i < n; i++) 
	{
		printf("%5d", a[i]);
	}
	return 0;
}