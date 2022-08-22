#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("BuyListNode");
		exit(-1);
	}
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;
	return newnode;
}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* guard = (ListNode*)malloc(sizeof(ListNode));
	if (guard == NULL)
	{
		perror("BuyListNode");
		exit(-1);
	}
	guard->_next = guard;
	guard->_prev = guard;
	return guard;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	ListNode* next = NULL;
	while (cur != pHead)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	printf("guard<=>");
	while (cur != pHead)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = pHead->_prev;
	tail->_next = newnode;
	newnode->_prev = tail;

	pHead->_prev = newnode;
	newnode->_next = pHead;
}
// 双向链表尾删
bool ListEmpty(ListNode* pHead)
{
	assert(pHead);
	return pHead->_next == pHead;
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!ListEmpty(pHead));
	ListNode* tail = pHead->_prev;

	tail->_prev->_next = pHead;
	pHead->_prev = tail->_prev;
	free(tail);
	tail = NULL;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	newnode->_next = pHead->_next;
	pHead->_next->_prev = newnode;

	pHead->_next = newnode;
	newnode->_prev = pHead;

}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!ListEmpty(pHead));
	ListNode* del = pHead->_next;

	pHead->_next = del->_next;
	del->_next = pHead;

	free(del);
	del = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}
