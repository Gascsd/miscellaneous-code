#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void TestHeap()
{
	Heap hp;
	HeapCreate(&hp, NULL, 0);
	int arr[] = { 65,100,70,32,50,60 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}
void TestTopk()
{
	Heap hp;
	HeapCreate(&hp, NULL, 0);
	int arr[] = { 65,100,70,32,50,60,10 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);
	PrintTopK(hp._a, hp._size, 3);
}
int main()
{
	//TestHeap();
	TestTopk();
	return 0;
}