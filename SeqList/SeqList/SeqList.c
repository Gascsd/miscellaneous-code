#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListDestroy(SeqList* ps)
{

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;

}

void SLCheckCapacity(SeqList* ps)
{
	//¼ì²éÈÝÁ¿
	if (ps->capacity == ps->size)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, 
							newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail:");
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}

}

void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (ps->size > 0)
	{
		ps->size--;
	}
	else
	{
		return;
	}
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 0;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}

	ps->size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	if (ps->size <= 0)
		return -1;
	else
	{
		for (int i = 0; i < ps->size; i++)
		{
			if (x == ps->a[i])
				return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size);

	SLCheckCapacity(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(ps->size > pos);
	size_t begin = pos;
	while (begin <= ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}