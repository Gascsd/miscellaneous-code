#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

char* my_strncat(char* strDest, const char* strSource, size_t count)
{
	char* ptr = strDest;
	while (*strDest != '\0')
		strDest++;
	while (count-- && (*strDest = *strSource))
	{
		strDest++;
		strSource++;
	}
	return ptr;
}

int main()
{
	char arr1[20] = "hello ";
	char arr2[20] = "world!!!";
	my_strncat(arr1, arr2, 7);
	printf("%s", arr1);
	return 0;
}