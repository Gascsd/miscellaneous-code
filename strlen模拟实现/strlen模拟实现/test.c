#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

size_t my_strlen(const char* string)
{
	assert(string);
	int count = 0;
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
int main()
{
	char arr1[] = "abcdef";
	size_t ret = my_strlen(arr1);
	printf("%zu", ret);
	return 0;
}