#define _CRT_SECURE_NO_WARNINGS 1

#include"KMP.h"

char* my_strstr(const char* str1, const char* str2)//BFÀ„∑®
{
	assert(str1 && str2);
	char* s1 = str1;
	char* s2 = str2;
	char* tmp = str1;
	while (*tmp)
	{
		s1 = tmp;
		s2 = str2;
		while (*s1 == *s2 && *s1)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return tmp;
		tmp++;
	}
	return NULL;
}


char* my_strstr_KMP(const char* str1, const char* str2)//KMPÀ„∑®
{
	int ret = KMP(str1, str2, 0);
	printf("%d\n", ret);
	if (ret == -1)
		return NULL;
	else
		return str1 + ret;
}


int main()
{
	char str1[30] = "ababcabcdabcde";
	char str2[10] = "ab";
	//printf("%s", my_strstr(str1, str2));
	printf("%s", my_strstr_KMP(str1, str2));
	return 0;
}