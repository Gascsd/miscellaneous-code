#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

// 堆的构建
void HeapInit(Heap* php)
{
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
// 堆的销毁
void HeapDestory(Heap* php)
{
	free(php->_a);
	free(php);
	php->_a = NULL;
	php = NULL;
}
// 堆的插入
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)//向上调整
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_capacity == hp->_size)//检查堆容量，决定是否扩容
	{
		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->_a = tmp;
		hp->_capacity = newCapacity;
	}

	hp->_a[hp->_size] = x;//插入数据
	hp->_size++;

	//向上调整
	AdjustUp(hp->_a, hp->_size - 1);
}
// 堆的删除

void AdjustDown(HPDataType* a, int n, int parent)//向下调整
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		//找到较小的孩子
		if (minChild + 1 < n && a[minChild + 1] < a[minChild])
		{
			minChild++;
		}
		if (a[minChild] < a[parent])
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
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//交换数据，删除堆底数据
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}
//打印堆
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

 //TopK问题：找出N个数里面最大/最小的前K个问题。
 //比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
 //需要注意：
 //找最大的前K个，建立K个数的小堆
 //找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	//建立k个数的小堆
	for (int j = (k - 2) / 2; j > 0; --j)
	{
		AdjustDown(a, k, j);
	}
	//继续遍历后面N-k个数
	int val = 0;
	for (int i = k; i < n; ++i)
	{
		if (a[i] > a[0])
		{
			Swap(&a[0], &a[i]);
			AdjustDown(a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}