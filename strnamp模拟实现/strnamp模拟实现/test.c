#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int my_strncmp(const char* string1, const char* string2, size_t count)
{
	while (--count && (*string1 == *string2))
	{
		string1++;
		string2++;
	}
	return *string1 - *string2;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcph";
	int ret = my_strncmp(arr1, arr2,3);
	if (ret > 0)
		printf(">");
	else if (ret == 0)
		printf("==");
	else
		printf("<");
	return 0;
}