#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char* my_strncpy(char* strDest, const char* strSource, size_t count)
{
	char* ptr = strDest;
	while (count && (*strDest = *strSource))
	{
		strDest++;
		strSource++;
		count--;
	}
	while (count--)
	{
		*strDest++ = '\0';
	}
	return ptr;
}

int main()
{
	char arr1[20] = "abc";
	char arr2[20] = "ABCDEFG";
	printf("%s\n", my_strncpy(arr2, arr1, 5));
	return 0;
}