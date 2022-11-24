#define _CRT_SECURE_NO_WARNINGS 1
//字符串中找出连续最长的字符串
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str[256];
//	scanf("%s", str);
//	int len = strlen(str);
//	int i = 0;
//	int count = 0, max = 0, max_i = i, index_before = i;
//	while (i < len - 1)
//	{
//		if (str[i] + 1 == str[i + 1])
//		{
//			index_before = i;
//			count = 1; 
//			while (str[i] + 1 == str[i + 1] && i < len - 1)
//			{
//				count++;
//				i++;
//			}
//			if (max < count)
//			{
//				max = count;
//				max_i = index_before;
//			}
//		}
//		i++;  
//	}
//	for (i = 0; i < max; i++)
//	{
//		printf("%c", str[max_i + i]);
//	}
//	return 0;
//}


//数组中出现次数超过一半的数字

