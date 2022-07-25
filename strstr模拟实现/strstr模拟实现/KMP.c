#define _CRT_SECURE_NO_WARNINGS 1

#include"KMP.h"


void GetNext(int* next, const char* sub)
{
	assert(next);
	int len = strlen(sub);
	*(next + 0) = -1;
	*(next + 1) = 0;
	int i = 2;//下一项的下标
	int k = 0;//next[i -1]的值
	while (i <= len)
	{
		if (sub[i - 1] == sub[k] || k == -1)//值相等的时候，加一
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else//值不相等的时候回退到k下标的位置
		{
			k = next[k];
		}
	}
}

//str表示主串，sub表示子串，pos表示开始查找的位置
int KMP(const char* str, const char* sub, int pos)
{
	assert(str && sub);
	int i = pos;//遍历主串
	int j = 0;//遍历子串
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr == 0 || lenSub == 0)//判断传入的字符串是否合法
		return -1;
	if (pos >= lenStr || pos < 0)//判断查找位置是否合法
		return -1;
	int* next = (int*)malloc(lenSub * sizeof(int));//开辟next数组
	assert(next);

	GetNext(next, sub);//为next数组赋值

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])//回退到-1位置，或者匹配成功
		{
			i++;
			j++;
		}
		else//匹配失败，j回退到next数组保存的j下标位置
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= lenSub)//判断结束循环的原因
		return i - j;
	else
		return -1;
}
