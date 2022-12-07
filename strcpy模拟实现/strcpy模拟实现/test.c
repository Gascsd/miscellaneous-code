#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//char* my_strcpy(char* strDestination, const char* strSource)
//{
//	char* ptr = strDestination;
//	while (*strDestination++ = *strSource++);
//	return ptr;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = { 0 };
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}


//实现一个函数，将一个字符串内的内容拷贝到另一个字符串中，并且实现链式调用
#include<stdio.h>
#include<string.h>
//char* my_strcpy(char* dst, char* src)
//{
//	char* tmp = dst;
//	while (*dst++ = *src++);
//	return tmp;
//}
int main()
{
	char arr1[] = "abcdefg";
	char arr2[10];
	//把arr1的内容拷贝到arr2中
	printf("%s\n%s,", arr1, strcpy(arr2, arr1));
	//strcmp,strlen,strstr,strtok
	/*printf("%s\n%s", arr1, my_strcpy(arr2, arr1));*/
	return 0;
}