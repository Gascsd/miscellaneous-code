#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	assert(a1);
	assert(a2);
	assert(a3);
	assert(a4);
	assert(a5);
	assert(a6);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("shellsort:%d\n", end2 - begin2);
	printf("selectsort:%d\n", end3 - begin3);
	printf("heapsort:%d\n", end4 - begin4);
	printf("quicksort:%d\n", end5 - begin5);
	printf("mergesort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}


void TestSort()
{
	int a1[] = { 54,38,96,23,15,72,60,45,83 };
	int a2[] = { 54,38,96,23,15,72,60,45,83 };
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	//SelectSort1(a1, sizeof(a1) / sizeof(a1[0]));
	//PrintArr(a1, sizeof(a1) / sizeof(a1[0]));
	//SelectSort(a2, sizeof(a2) / sizeof(a2[0]));
	//PrintArr(a2, sizeof(a2) / sizeof(a2[0]));
	BubbleSort(a1, sizeof(a1) / sizeof(a1[0]));
	PrintArr(a1, sizeof(a1) / sizeof(a1[0]));
}

void TestMergeSort()
{
	int a1[] = { 6,1,2,7,9,3,4,5,10,8 };
	MergeSortNonR(a1, sizeof(a1) / sizeof(a1[0]));
	PrintArr(a1, sizeof(a1) / sizeof(a1[0]));
}   

int main()
{
	TestMergeSort();
	//TestOP();
	return 0;
}



