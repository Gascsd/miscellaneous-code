#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

size_t my_strlen1(const char* string)//计数器法
{
	size_t count = 0;
	while (*string++ != '\0')
	{
		count++;
	}
	return count;
}

size_t my_strlen2(const char* string)//递归法
{
	if (*string == '\0')
		return 0;
	else
		return 1 + my_strlen2(string + 1);
}

size_t my_strlen3(const char* string)//指针-指针法
{
	const char* ptr = string;
	while (*ptr != '\0')
		ptr++;
	return (size_t)(ptr - string);
}
int main()
{
	char arr1[] = "abcdef";
	size_t ret = my_strlen1(arr1);
	printf("%zu\n", ret);
	ret = my_strlen2(arr1);
	printf("%zu\n", ret);
	ret = my_strlen3(arr1);
	printf("%zu\n", ret);

	return 0;
}