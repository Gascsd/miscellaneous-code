#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	printf("hello world!");
//	return 0;
//}


//char
//short
//int
//long

#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(float));
//
//	char ch = 'a';
//	printf("%c %d", ch, ch);
//	return 0;
//}
//
//
//char ch = 'a';


//ȫ�ֱ����;ֲ�����
////
//int gobal = 20;//����һ��ȫ�ֱ���
//
//void test()
//{
//	int a = 10;
//	printf("%d", b);
//}
//int main()
//{
//	//printf("%d", a);
//	/*test();
//	printf("%d", gobal);*/
//	int i = 0;
//	int b = 10;
//	test();
//	for (i = 0; i < 3; i++)
//	{
//		int b = 15;
//		printf("%d ", b);
//	}
//	printf("%d ", b);
//
//	//if (gobal == 1)
//	//{
//
//	//}
//	return 0;
//}

//������    -�� �����

//#include<stdbool.h>
//#include"test2.h"
//int a = 10;
//int main()
//{
//	int a = 20;
//	if (1)
//	{
//		int a = 30;
//		printf("%d\n", a);
//	}
//	printf("%d\n", a);
//
//	int a;
//	scanf("%d", &a);
//	printf("%d", aaa);
//	return 0;
//}


//����
//ö�ٳ���
//enum Sex
//{
//	MAN,
//	WOMAN,
//	OTHER
//};
//
//#define N 10


///*
//int main()
//{
//	3.14;
//	5;
//	"abcdefg";
//	//woman = 10;
//	/*enum sex a = woman;
//	printf("%d", a);*/
//}
//
//int main()
//{
//	char ch[] = "abcd";
//	char ch2[5] = { 'a', 'b', 'c', 'd', '\0'};
//	printf("%s\n", ch);
//	printf("%s\n", ch2);
//	return 0;
//}
//*/
//int main()
//{
//	printf("%s", "c:\\co\"de\\test.c");
//	return 0;
//}
//
//#include<string.h>
//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//	printf("%d\n", strlen("c:\test\628\test.c"));
//	return 0;
//}

//int main()
//{
//	int coding = 3;
//	//if (coding == 0)
//	//{
//	//	printf("���1");
//	//}
//	//else if(coding == 1)
//	//{
//	//	printf("���2");
//	//}
//	//else
//	//{
//	//	printf("���3");
//	//}
//	switch (coding)
//	{
//	case 0:
//		printf("���1");
//		break;
//	case 1:
//		printf("���2");
//		break;
//	case 2:
//		printf("���3");
//		break;
//	default:
//		printf("default!!");
//		break;
//	}
//	return 0;
//}

//#define N 10
////const���εĳ�����
//int main()
//{
//	const int a = 10;//������
//	//a = 20;
//	printf("%d", a);
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////
//ѭ�����
//
//int main()
//{
//	int a[10] = { 0 };
//	int i = 0;
//	//while (i < 10)
//	//{
//	//	a[i] = i;
//	//	i++;
//	//}
//	//i = 0;
//	//while (i < 10)
//	//{
//	//	printf("%d ", a[i]);
//	//	i++;
//	//}
//	//һ��ѭ������Ҫ�еĶ����У�
//	// 1.ѭ�������ĳ�ʼ������ѭ����ʼǰҪ�����ģ�
//	// 2.ѭ������ 
//	// 3.��ѭ���ڲ���һ���ı�ѭ�����������
//	//for (i = 0; i < 10; i++)
//	//{
//	//	a[i] = i;
//	//}
//
//	//do
//	//{
//	//	a[i] = i;
//	//	i++;
//	//} while (i < 10);
//
//	//	for ()
//	//	{
//
//	//	}
//	return 0;
//}

//int main()
//{
//	float PI = 3.14;
//	int a = (int)PI;
//	
//	return 0;
//}


////////////////////////////////////////////
//����


int add(int x, int y)
{
	int c = 0;
	c = x + y;
	printf("%d", c);
	return 0;
}
//int main()//������
//{
//	//ʵ���������
//	int a, b;
//	scanf("%d%d", &a, &b);
//	//int c = Add(a, b);
//	//printf("%d", c);
//	//printf("%d", Add(a, b));
//	return 0;
//}

//int main()
//{
//	int a, b, c, d, e, f;
//	scanf("%d%d", &a, &b);
//	printf("%d", a + b);
//	Add(c, d);
//	Add(e, f);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	return 0;
//}
//
//exp1 ? exp2 : exp3
//
//if(exp1)
//	exp2
//else
//	exp3
//typedef struct Peo
//{
//	int a;
//	int b;
//}ABC;
//#include<typeinfo>
//int main()
//{
//	//typedef int I;
//	//I a = 10;
//	//int b = 20;
//	//printf("%d", a);
//	//printf("%d", b);
//	ABC c;
//	c.a = 10;
//	c.b = 20;
//	struct Peo b;
//	printf("%d", typeid(c));
//	return 0;
//}


//#include <stdio.h>
//void test()
//{
//	static int i = 0;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}

//#define N 5+3
//int main()
//{
//	int a = 5 + 3 * 5 + 3;//5+3*5+3
//	printf("%d", a);
//	return 0;
//}


//#define ADD(x,y) ((x)+(y))
//#define POW(x,y) ((x)*(y))
//int main()
//{
//	//int sum = ADD(2, 3);
//	//printf("%d ", sum);
//	//sum = 10 * ADD(2, 3);//10*2+3
//	//printf("%d ", sum);
//	int pow = POW(2, 3);
//	printf("%d\n", pow);
//	pow = POW(2+5, 3+2);//2+5*3+2
//	printf("%d\n", pow);
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	int* pi = &i;
//	printf("%p\n", &i);
//	printf("%p\n", pi);
//	*pi = 11;
//	printf("%d\n", *pi);
//	char ch = 'w';
//	char* pch = &ch;
//	printf("%c\n", *pch);
//	printf("%d\n", sizeof(pch));
//	printf("%d\n", sizeof(pi));
//	return 0;
//}



typedef struct Stu
{
	char id[11];//ѧ��
	char name[10];//����
	char sex[6];//�Ա�   man woman other
	int age;//����
	double p;//�ɼ�
}Stu;



Stu a = { "3210701219", "����", "man", 18, 95.0 };

int main()
{
	Stu* pa = &a;
	struct Stu b = { 0 };
	printf("ѧ�ţ�%s\n", a.id);
	printf("������%s\n", a.name);
	printf("�Ա�%s\n", a.sex);
	printf("���䣺%d\n", a.age);
	printf("�ɼ���%.2f\n", a.p);
	printf("\n");
	printf("ѧ�ţ�%s\n", pa->id);
	printf("������%s\n", pa->name);
	printf("�Ա�%s\n", pa->sex);
	printf("���䣺%d\n", pa->age);
	printf("�ɼ���%.2f\n", pa->p);
	return 0;
}















