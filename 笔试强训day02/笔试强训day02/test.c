#define _CRT_SECURE_NO_WARNINGS 1

//排序子序列
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);//数组大小
//    int* a = (int*)malloc(sizeof(int) * n);
//    if (a == NULL)
//    {
//        perror("malloc fail");
//        exit(-1);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    //遍历数组，判断前两个是递增还是递减，然后向后判断，遇到相反的就算作开始新的序列
//    int count = 0;//记录序列数
//    int i = 0;
//    while (i < n - 1)
//    {
//        if (a[i] <= a[i + 1])//递增序列
//        {
//            count++;
//            while (a[i] <= a[i + 1] && i < n - 1)
//            {
//                i++;
//            }
//            i++;
//        }
//        if(a[i] > a[i + 1])
//        {
//            count++;
//            while (a[i] >= a[i + 1] && i < n - 1)//递减序列
//            {
//                i++;
//            }
//            i++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//倒置字符串
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reserve(char* str, int len)
{
	int i = 0;
	char* tmp = (char*)malloc(len * sizeof(char));
	if (tmp == NULL)
	{
		perror("mallic fail");
		exit(-1);
	}
	strcpy(tmp, str);
	char* temp = strtok(tmp, " ");
	int c_len = strlen(temp);
	int start = len - 1 - c_len;
	while (temp != NULL)
	{
		memcpy(str + start, temp, c_len);
		if (start > 0)
		{
			start--;
			str[start] = ' ';
			temp = strtok(NULL, " ");
			c_len = strlen(temp);
			start -= c_len;
		}
		else
			break;
	}
}
int main()
{
	char str[100];
	gets(str);
	int len = strlen(str);
	str[len] = '\0';
	reserve(str, len + 1);
	printf("%s", str);
	return 0;
}