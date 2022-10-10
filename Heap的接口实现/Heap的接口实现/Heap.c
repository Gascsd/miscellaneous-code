#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

// �ѵĹ���
void HeapInit(Heap* php)
{
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
// �ѵ�����
void HeapDestory(Heap* php)
{
	free(php->_a);
	free(php);
	php->_a = NULL;
	php = NULL;
}
// �ѵĲ���
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)//���ϵ���
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
	if (hp->_capacity == hp->_size)//���������������Ƿ�����
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

	hp->_a[hp->_size] = x;//��������
	hp->_size++;

	//���ϵ���
	AdjustUp(hp->_a, hp->_size - 1);
}
// �ѵ�ɾ��

void AdjustDown(HPDataType* a, int n, int parent)//���µ���
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		//�ҵ���С�ĺ���
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

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//�������ݣ�ɾ���ѵ�����
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}
//��ӡ��
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

 //TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
 //���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
 //��Ҫע�⣺
 //������ǰK��������K������С��
 //����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	//����k������С��
	for (int j = (k - 2) / 2; j > 0; --j)
	{
		AdjustDown(a, k, j);
	}
	//������������N-k����
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