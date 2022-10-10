#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
//ȫ��������
void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void InsertSort(int* a, int n)
{
	//����[0,end]����Ҫ�������[0,n]
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = 3;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//����[0,end]���򣬲���a[end+gap]��������
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

////�ڿӷ�
//int PartSort1(int* a, int left, int right)
//{
//	int begin = 0, end = 0;
//	int key = begin;
//	while (left < right)
//	{
//		
//
//	}
//}
//
//// ǰ��ָ�뷨
//int PartSort2(int* a, int left, int right)
//{
//	//����ȡ��
//
//	//
//	int prev = 0, cur = 1;
//	int keyi = prev;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi])
//		{
//			++prev;
//			Swap(&a[prev], &a[cur]);
//		}
//		cur++;
//	}
//	Swap(&a[prev], &a[keyi]);
//}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//�Ż���ÿ��ѡ�����ĺ���С�ģ�������������
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		//����֮��maxi��λ�ÿ��ܻᷢ���ı䣬��Ҫ����
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int parent)//�����µ���
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		//�ҵ���С�ĺ���
		if (minChild + 1 < n && a[minChild + 1] > a[minChild])
		{
			minChild++;
		}
		if (a[minChild] > a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//�����һ����Ҷ�ӽڵ����µ�������
	//���򽨴�ѣ�����С��
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//ѡ��
	for (int i = 1; i < n; i++)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
	}
}

