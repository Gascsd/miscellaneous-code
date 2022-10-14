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

void SelectSort(int* a, int n)//�Ż���汾
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

//hoare�汾����
int part_sort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])//R���ߣ���С��key��ֵͣ��
		{
			--right;
		}
		while (left < right && a[left] <= a[keyi])//L���ߣ��ҵ�����key��ֵ
		{
			++left;
		}
		//ִ�н���
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
int part_sort2(int* a, int left, int right)//�ڿӷ�
{
	//����ȡ��
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)//�ұ���С��
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)//����Ҵ��
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
int part_sort3(int* a, int left, int right)//ǰ��ָ�뷨
{
	//����ȡ��
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

//void QuickSort(int* a, int begin, int end)//С�����Ż�
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