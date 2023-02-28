#define _CRT_SECURE_NO_WARNINGS 1

//顺序表的增删查改

//顺序表 == 数组

//1.固定存储容量的顺序表
#define N 10
typedef struct SeqList
{
	int a[N];//存储元素的位置
	int size;//顺序表中存放的元素个数
}SeqList;

void SeqListInit(SeqList* pL)//初始化
{
	for (int i = 0; i < N; i++)
	{
		pL->a[i] = 0;
	}
	pL->size = 0;
}
//顺序表的增加元素
void SeqListPushBack(SeqList* pL, int x)//顺序表的尾插
{
	pL->a[pL->size] = x;
	pL->size++;
}
void SeqListInsert(SeqList* pL, int x, int i)//顺序表的从中间插入
{
	
	int j = pL->size;
	while (j >= i)
	{
		pL->a[j] = pL->a[j - 1];
		j--;
	}
	pL->a[i - 1] = x;
	pL->size++;
}
void SeqListPushFront(SeqList* pL)
{

}
int main()
{
	int i;
	SeqList L1;
	SeqListInit(&L1);
	SeqListPushBack(&L1, 1);
	SeqListPushBack(&L1, 2);
	SeqListPushBack(&L1, 3);
	SeqListPushBack(&L1, 4);
	SeqListPushBack(&L1, 5);
	SeqListPushBack(&L1, 6);
	SeqListPushBack(&L1, 7);
	SeqListPushBack(&L1, 8);
	SeqListPushBack(&L1, 9);
	SeqListInsert(&L1, 10, 5);
	return 0;
}



