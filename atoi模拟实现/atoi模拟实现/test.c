#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<ctype.h>
#include<limits.h>

enum Status
{
	VALID,
	INVALID
}status = INVALID;//Ĭ�ϷǷ�

int my_atoi(const char* str)
{
	assert(str);//�����ָ��
	if (*str == '\0')//���ַ���
		return 0;
	while (isspace(*str))//�հ��ַ�
	{
		str++;
	}
	long long ret = 0;
	int flag = 1;
	if (*str == '+')//�ж�����
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			ret = ret * 10 + flag * (*str - '0');
			if (ret > INT_MAX || ret < INT_MIN)//�ж��Ƿ�Խ��
			{
				return 0;
			}
		}
		else//����������ַ�
		{
			return (int)ret;
		}
		str++;
	}
	if (*str == '\0')
	{
		status = VALID;
		return (int)ret;
	}
}
int main()
{
	char arr[] = "-123ab45";
	int ret = my_atoi(arr);
	if (status == VALID)
		printf("�Ϸ�ת����%d", ret);
	else
		printf("�Ƿ����أ�%d", ret);
	return 0;
}