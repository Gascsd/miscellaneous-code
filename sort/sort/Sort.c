#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
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

void SelectSort1(int* a, int n)
{
	int begin = 0;
	while (begin < n)
	{
		int tmpi = begin;
		for (int i = begin + 1; i < n; ++i)
		{
			if (a[i] < a[tmpi])
			{
				tmpi = i;
			}
		}
		Swap(&a[tmpi], &a[begin]);
		++begin;
	}
}

void SelectSort(int* a, int n)//优化后版本
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

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 1;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid; 
		}
		else if (a[left] > a[right])
		{
			return right;
		}
		else
			return left;
	}
	else//a[left] <= a[mid]
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
			return right;
	}
}

//hoare版本单趟
int part_sort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])//R先走，找小于key的值停下
		{
			--right;
		}
		while (left < right && a[left] <= a[keyi])//L后走，找到大于key的值
		{
			++left;
		}
		//执行交换
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
int part_sort2(int* a, int left, int right)//挖坑法
{
	//三数取中
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)//右边找小的
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)//左边找大的
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
int part_sort3(int* a, int left, int right)//前后指针法
{
	//三数取中
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi = part_sort2(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

//void QuickSort(int* a, int begin, int end)//小区间优化
//{
//	if (begin >= end)
//		return;
//	if (end - begin < 8)
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
//		int keyi = part_sort2(a, begin, end);
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//}


void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		if (left >= right)
			continue;

		int keyi = part_sort1(a, left, right);
		//[left,keyi-1] keyi [keyi+1,right] 
		StackPush(&st, keyi + 1);
		StackPush(&st, right);
		StackPush(&st, left);
		StackPush(&st, keyi - 1);
	}

	StackDestory(&st);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//[begin,mid] [mid+1,end]

	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//拷贝回原数组
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int j = 0; j < n; j += 2 * gap)//gap个数据归并
		{
			//归并
			int begin1 = j, end1 = j + gap - 1;
			int begin2 = j + gap, end2 = j + 2 * gap - 1;
			int i = j;

			//修正边界
			if (end1 >= n)//第一组越界
			{
				break;
			}
			if (begin2 >= n)//第二组全部越界
			{
				break;
			}
			if (end2 >= n)//第二组部分越界
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[i++] = a[begin1++];
				}
				else
				{
					tmp[i++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}
			memcpy(a + j, tmp + j, (end2 - j + 1) * sizeof(int));
		}
		gap *= 2;

	}
	free(tmp);
	tmp = NULL;
}

void CountSort(int* a, int n)
{
	int min, max;
	max = min = a[0];
	for (int i = 1; i < n; ++i)//找到数组中最大和最小的数
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	int range = max - min + 1;//给出映射范围
	int* tmp = (int*)calloc(range, sizeof(int));//开辟新数组
	assert(tmp);
	for (int i = 0; i < n; ++i)//计数
	{
		tmp[a[i] - min]++;
	}

	//将计数以后的值覆盖到原数组
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		while (tmp[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(tmp);
	tmp = NULL;
}