#define _CRT_SECURE_NO_WARNINGS 1

//˳������ɾ���

//˳��� == ����

//1.�̶��洢������˳���
#define N 10
typedef struct SeqList
{
	int a[N];//�洢Ԫ�ص�λ��
	int size;//˳����д�ŵ�Ԫ�ظ���
}SeqList;

void SeqListInit(SeqList* pL)//��ʼ��
{
	for (int i = 0; i < N; i++)
	{
		pL->a[i] = 0;
	}
	pL->size = 0;
}
//˳��������Ԫ��
void SeqListPushBack(SeqList* pL, int x)//˳����β��
{
	pL->a[pL->size] = x;
	pL->size++;
}
void SeqListInsert(SeqList* pL, int x, int i)//˳���Ĵ��м����
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



