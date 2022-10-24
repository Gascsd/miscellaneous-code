#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<ctype.h>
#include<limits.h>

enum Status
{
	VALID,
	INVALID
}status = INVALID;//默认非法

int my_atoi(const char* str)
{
	assert(str);//传入空指针
	if (*str == '\0')//空字符串
		return 0;
	while (isspace(*str))//空白字符
	{
		str++;
	}
	long long ret = 0;
	int flag = 1;
	if (*str == '+')//判断正负
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
			if (ret > INT_MAX || ret < INT_MIN)//判断是否越界
			{
				return 0;
			}
		}
		else//传入非数字字符
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
		printf("合法转换：%d", ret);
	else
		printf("非法返回：%d", ret);
	return 0;
}