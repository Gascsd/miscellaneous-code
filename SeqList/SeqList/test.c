#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


void TestSeqListInit()
{
	SeqList s;
	SeqListInit(&s);
	SeqListDestroy(&s);
}

void TestSeqListPushPop()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);

	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListDestroy(&s);
}

void TestSeqListFind()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListInsert(&s, 0, 30);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListPrint(&s);
	SeqListErase(&s, 4);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);

	int i = SeqListFind(&s, 8);
	printf("%d", i);
}

int main()
{
	TestSeqListInit();
	TestSeqListPushPop();
	TestSeqListFind();
	return 0;
}