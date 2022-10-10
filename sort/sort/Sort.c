#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
//全部排升序
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
	//假设[0,end]有序，要排序的是[0,n]
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
		//假设[0,end]有序，插入a[end+gap]保持有序
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

////挖坑法
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
//// 前后指针法
//int PartSort2(int* a, int left, int right)
//{
//	//三数取中
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
		//优化：每次选出最大的和最小的，放在数组两侧
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
		//交换之后maxi的位置可能会发生改变，需要修正
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int parent)//堆向下调整
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		//找到较小的孩子
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
	//从最后一个非叶子节点向下调整建堆
	//升序建大堆，降序建小堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//选数
	for (int i = 1; i < n; i++)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
	}
}

