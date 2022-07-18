#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char* my_strcat(char* strDestination, const char* strSource)
{
	char* ptr = strDestination;
	while (*strDestination != '\0')
		strDestination++;
	while (*strDestination++ = *strSource++);
	return ptr;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s", arr1);
	return 0;
}