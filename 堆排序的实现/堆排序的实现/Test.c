#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef int HPDataType;

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(HPDataType* a, int n, int parent)//�����µ���
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


// ��������ж�����
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



void TestHeapSort()
{
	int arr[] = { 15,1,19,25,8,34,65,4,27,7 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	TestHeapSort();
	return 0;
}