#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int my_memcmp(const void* buf1, const void* buf2, size_t count)
{
	while (--count && (*(char*)buf1 == *(char*)buf2))
	{
		buf1 = (char*)buf1 + 1;
		buf2 = (char*)buf2 + 1;
	}
	return *(char*)buf1 - *(char*)buf2;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[] = { 1,2,3,4,4 };
	int ret = my_memcmp(arr1, arr2, 16);
	if (ret > 0)
		printf(">");
	else if(ret == 0)
		printf("==");
	else
		printf("<");
	return 0;
}