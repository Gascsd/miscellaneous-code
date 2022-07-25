#define _CRT_SECURE_NO_WARNINGS 1

#include"KMP.h"


void GetNext(int* next, const char* sub)
{
	assert(next);
	int len = strlen(sub);
	*(next + 0) = -1;
	*(next + 1) = 0;
	int i = 2;//��һ����±�
	int k = 0;//next[i -1]��ֵ
	while (i <= len)
	{
		if (sub[i - 1] == sub[k] || k == -1)//ֵ��ȵ�ʱ�򣬼�һ
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else//ֵ����ȵ�ʱ����˵�k�±��λ��
		{
			k = next[k];
		}
	}
}

//str��ʾ������sub��ʾ�Ӵ���pos��ʾ��ʼ���ҵ�λ��
int KMP(const char* str, const char* sub, int pos)
{
	assert(str && sub);
	int i = pos;//��������
	int j = 0;//�����Ӵ�
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr == 0 || lenSub == 0)//�жϴ�����ַ����Ƿ�Ϸ�
		return -1;
	if (pos >= lenStr || pos < 0)//�жϲ���λ���Ƿ�Ϸ�
		return -1;
	int* next = (int*)malloc(lenSub * sizeof(int));//����next����
	assert(next);

	GetNext(next, sub);//Ϊnext���鸳ֵ

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])//���˵�-1λ�ã�����ƥ��ɹ�
		{
			i++;
			j++;
		}
		else//ƥ��ʧ�ܣ�j���˵�next���鱣���j�±�λ��
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= lenSub)//�жϽ���ѭ����ԭ��
		return i - j;
	else
		return -1;
}
