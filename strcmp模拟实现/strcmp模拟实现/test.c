#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int my_strcmp(const char* string1, const char* string2)
{
	while (*string1 == *string2)
	{
		string1++;
		string2++;
	}
	return *string1 - *string2;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcp";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
		printf(">");
	else if (ret == 0)
		printf("==");
	else
		printf("<");
	return 0;
}