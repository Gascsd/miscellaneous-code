#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
	void* ptr = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ptr;
}
int main()
{
	int arr1[] = {1,2,3,4,5,6,7};
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 28);
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}