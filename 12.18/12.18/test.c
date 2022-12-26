#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



//int main()
//{
//	int age = 19;
//	if (age < 18)
//	{
//		printf("未成年\n");
//		int x = 0;
//		printf("haha");
//	}
//	else if (age == 18)
//		printf("你今年18啦\n");
//	else
//		printf("恭喜你成年啦，可以自由地打游戏了！！\n");
//	return 0;
//}

//int main()
//{
//	//int a = 0;
//	//int b = 2;
//	//if (a == 1)
//	//{
//	//	if (b == 2)
//	//		printf("hehe\n");
//	//}
//	//else
//	//	printf("haha\n");
//
//	int num = 1;
//	if (5 == num) 
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	scanf("%d", &a);
//	//if (a == 1)
//	//{
//	//	printf("星期一");
//	//}
//	//else if (a == 2)
//	//{
//	//	printf("星期二");
//	//}
//	//else if (a == 3)
//	//{
//	//	printf("星期三");
//	//}
//
//	switch (a)
//	{
//	default:
//		printf("输入错误");
//		break;
//	case 1:
//		printf("星期一");
//		break;
//	case 2:
//		printf("星期二");
//		break;
//	case 3:
//		printf("星期三");
//		break;
//
//	}
//
//	return 0;
//}

//
//int main()
//{
//	extern int a;
//	//int i = 0;
//	//while (i < 6)
//	//{
//	//	printf("haha  ");
//	//	printf("hehe\n");
//	//	if(3 == i)
//	//		continue;
//	//	i++;
//	//}
//	//printf("\n");
//	printf("%d", a);
//	//i = 0;
//	//do
//	//{
//	//	printf("haha  ");
//	//	printf("hehe\n");
//	//	i++;
//	//} while (i < 6);
//	//printf("\n");
//
//	//for (i = 0; i < 6; i++)
//	//{
//	//	printf("haha  ");
//	//	printf("hehe\n");
//	//}
//	//printf("\n");
//	return 0;
//}
//int b = 10;
//void test()
//{
//	static int i = 0;
//	i++;
//	printf("%d\n", i);
//}
//int Add(int x, int y);
//int main()
//{
//	extern int g_val;
//	//int a = 10;//局部变量是在栈上的
//	//for (int a = 0; a < 10; a++)
//	//{
//	//	test();
//	//}
//	//printf("%d\n", Add(2, 4));
//	printf("%d", g_val);
//	return 0;
//}



//使用for循环 在屏幕上打印1-10的数字
//int main()
//{
//	int i;
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);
//	}
//	printf("%d", i);
//	return 0;
//}

//
//int main()
//{
//	int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (i == 5)
//	//		continue;
//	//	printf("%d ", i);
//	//}
//
//	i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int j = 0;
//	//如果省略掉初始化部分，这里打印多少个hehe?
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}

//循环要循环多少次？0次！！！
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//	{
//		k++;
//	}
//	return 0;
//}

//1. 计算 n的阶乘。n*(n-1)*(n-2)...*1
//int main()
//{
//	int sum = 1;
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = n; i > 0; i--)
//	{
//		sum *= i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



//2. 计算 1!+ 2!+ 3!+ …… + 10!
//1!   1*=1
//2!   1*=1   1*=2
//3!   1*=1   1*=2   2*=3
//4!   1*=1   1*=2   2*=3
// 解法一
//#include<time.h>
//#define N 50
//long long count1 = 0;//记录算法一的次数
//long long count2 = 0;//记录算法二的次数
//long f1(int n)
//{
//	long sum = 1;
//	for (int i = n; i > 0; i--)
//	{
//		sum *= i;
//		count1++;
//	}
//	printf("%lld\n", sum);
//	return sum;
//}
//int test1()
//{
//	long sum = 0;
//	for (int i = 1; i < N; i++)
//	{
//		sum += f1(i);
//	}
//	printf("%lld\n", sum);
//	return 0;
//}
//
////解法二：优化
//long long f2(int n)
//{
//	static long long sum = 1;
//	static long long i = 1;
//	for (; i <= n; i++)
//	{
//		sum *= i;
//		count2++;
//	}
//	printf("%lld\n", sum);
//	return sum;
//}
//int test2()
//{
//	long long sum = 0;
//	for (int i = 1; i < N; i++)
//	{
//		sum += f2(i);
//	}
//	printf("%lld\n", sum);
//	return 0;
//}
//int main()
//{
//	//int begin1 = clock();
//	test1();
//	//int end1 = clock();
//	//
//	//int begin2 = clock();
//	test2();
//	//int end2 = clock();
//
//	//printf("解法一的时间是%d，\n", end1 - begin1);
//	//printf("解法二的时间是%d，\n",end2 - begin2);
//	printf("%lld\n%lld", count1, count2);
//	return 0;
//}

////3. 在一个有序数组中查找具体的某个数字n。（讲解二分查找）
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#define N 100
//int* GetArray(int n)//创建一个有序数组
//{
//	int* arr = (int*)malloc(10 * sizeof(int));
//	assert(arr);
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = 2 * i;
//	}
//	return arr;
//}
////0 2 4 6 8 10 12 14 16 18
////begin      mid        end
//int Find(int* arr,int begin,int end, int ret)//查找函数
//{
//	if (begin > end)
//	{
//		return -1;
//	}
//	int mid = (begin + end) / 2;
//	if (arr[mid] == ret)
//	{
//		return mid;
//	}
//	else
//	{
//		if (arr[mid] > ret)
//		{
//			//找[begin,mid-1]
//			Find(arr, begin, mid - 1, ret);
//		}
//		else
//		{
//			//找[mid+1,end]
//			Find(arr, mid + 1, end, ret);
//		}
//	}
//
//}
//int main()
//{
//	//int* arr = GetArray(N);
//	int arr[] = { 1,2,4,5,6,8,10,13,15,18 };
//	int number = 15;
//	scanf("%d", &number);
//	int pos = Find(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, numb	er);
//	if (pos == -1)
//	{
//		printf("没有找到该数\n");
//	}
//	else
//	{
//		printf("找到了，下标为%d", pos);
//	}
//	return 0;
//}


////4. 编写代码，演示多个字符从两端移动，向中间汇聚。
//#include<stdio.h>
//#include<string.h>
//#define N 15
//int main()
//{
//	char arr1[N], arr2[N];
//	//memset(arr1, '*', N-1);
//	for (int i = 0; i < N - 1; i++)
//	{
//		arr1[i] = i + '0';
//	}
//	memset(arr2, '#', N-1);
//	arr1[N - 1] = '\0';
//	arr2[N - 1] = '\0';
//	printf("%s\n", arr1);
//	//for (int i = 0; i < N - 1; i++)
//	//{
//	//	printf("%d", arr1[i]);
//	//}
//	int left = 0;
//	int right = sizeof(arr2) / sizeof(arr2[0]) - 2;
//	//数组内最后一个元素的下标值 = 数组内元素个数 - 1
//	//数组内元素个数 = 整个数组的字节数/数组内元素的大小的字节数
//	//类型大小*元素个数 = 数组大小（数组的字节数）
//	while (left <= right)
//	{
//		Sleep(1000);
//		system("cls");
//		arr1[left] = arr2[left];
//		arr1[right] = arr2[right];
//		left++;
//		right--;
//		printf("%s\n", arr1);
//		//for (int i = 0; i < N - 1; i++)
//		//{
//		//	printf("%d", arr1[i]);
//		//}
//	}
//	return 0;
//}

////5. 编写代码实现，模拟用户登录情景，并且只能登录三次。
////（只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int count = 0;
//	char user[] = "zhangsan";
//	char passwd[] = "123456";
//	char user_input[20] = { 0 }, passwd_input[20] = { 0 };
//	while (count < 3)
//	{
//		printf("请输入用户名：");
//		scanf("%s", user_input);
//		printf("\n请输入密码：");
//		scanf("%s", passwd_input);
//		if (0 == strcmp(passwd, passwd_input) && 0 == strcmp(user,user_input))
//		{
//			printf("恭喜你，登录成功！！！\n");
//			break;
//		}
//		else if(count < 2)
//		{
//			printf("登录失败，请重新登录\n");
//			count++;
//		}
//		else
//		{
//			printf("您已经三次登录失败，退出程序！！！\n");
//			break;
//		}
//	}
//	return 0;
//}














