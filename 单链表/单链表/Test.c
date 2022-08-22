#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"



void TestSListPush()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	//SListPopFront(&plist);	
	//SListPrint(plist);
	//SListPopFront(&plist);
	//SListPrint(plist);
	//SListPopFront(&plist);
	//SListPrint(plist);
	//SListPopFront(&plist);
	//SListPrint(plist);
	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);
	SListDestroy(&plist);
	SListPrint(plist);

}

void Test3()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SListNode* pos = SListFind(plist, 3);
	if (pos)
	{
		printf("found it\n");
	}
	else
		printf("not found it\n");
	SListInsertBefore(&plist, pos, 20);
	//SListEraseAfter(&plist, pos);
	SListPrint(plist);

}
int main()
{
	//TestSListPush();
	Test3();
	return 0;
}