#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void TestList1()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);

	ListPrint(plist);

	ListPushFront(plist, 10);
	ListPrint(plist);
	ListPushFront(plist, 20);
	ListPrint(plist); 
	ListPushFront(plist, 30);
	ListPrint(plist);
	ListPushFront(plist, 40);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);

}
void TestList2()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	printf("%d\n", (ListFind(plist, 1)->_data));
	printf("%d\n", (ListFind(plist, 5)->_data));
	//printf("%s", ListFind(plist, 10));

	ListInsert(plist->_next->_next, 50);
	ListPrint(plist);

	ListErase(plist->_next->_next);
	ListPrint(plist);

}
int main()
{
	//TestList1();
	TestList2();
	return 0;
}