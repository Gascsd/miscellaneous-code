#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

char* my_strstr(const char* str1, const char* str2)
{
	const char* tmp = str1;
	while (*str1)
	{
		if (*str1 == *str2)
		{
			tmp = str1;
			str1++;
			str2++;
			while (*str1 == *str2 && *str1)
			{
				str1++;
				str2++;
			}
			if (*str2 == '\0')
				return tmp;
			else
				str1 = tmp;
		}
		else
			str1++;
	}
	return NULL;
}
int main()
{
	char str1[10] = "abbbcdef";
	char str2[10] = "bbc";
	printf("%s", my_strstr(str1, str2));
	return 0;
}