#include<iostream>
#include <stdlib.h>
using namespace std;


//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}

void Test_stack()
{
	int a = 10;
	int b = 20;
	cout << "&a=" << &a << endl;
	cout << "&b=" << &b << endl;
	int* aa = (int*)malloc(sizeof(int) * 2);
	int* bb = (int*)malloc(sizeof(int) * 2);
	cout << "aa=" << aa << endl;
	cout << "bb=" << bb << endl;
}
void Test_new_delete_Built()
{
	//操作内置类型
	//动态申请一个整型大小的空间
	int* ptr1 = new int;
	//动态申请一个整型大小的空间，并初始化为10
	int* ptr2 = new int(10);
	//动态申请10个整型大小的空间
	int* ptr3 = new int[10];
	//对于new申请的空间，使用delete释放
	delete ptr1;
	delete ptr2;
	//对于new[]申请的空间，使用delete[]释放
	delete[] ptr3;
}
void Test_new_malloc()
{
	//对于malloc
	while (1)
	{
		int* p = (int*)malloc(sizeof(int) * 1024 * 1024 * 1024);
		if (p)
		{
			cout << p << endl;
		}
		else
		{
			cout << "申请失败" << endl;
			break;
		}
	}
}
void Test_new()
{
	while (1)
	{
		char* p = new char[1024 * 1024 * 1024];
		cout << (void*)p << endl;
	}
}
//int main()
//{
//	//Test_stack();
//	//Test_new_delete_Built();
//	//Test_new_malloc();
//	try 
//	{
//		Test_new();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

class A
{
public:
	A(int a = 5)
		:_a(a)
	{
		cout << "A()" << this << endl;
	}
	~A()
	{
		cout << "~A()" << this << endl;
	}
private:
	int _a;
};
void Test_replacement_new()
{
	//new (place_address) type
	A* p1 = (A*)malloc(sizeof(A));
	if (p1 == nullptr)
	{
		perror("malloc fail");
		exit(-1);
	}
	new(p1)A();
	p1->~A();
	free(p1);
	//new (place_address) type(initializer-list)
	A* p2 = (A*)operator new(sizeof(A));
	new(p1)A(10);
	p2->~A();
	free(p2);
}


void Test_Custom()
{
	cout << "malloc:" << endl;
	A* pA1 = (A*)malloc(sizeof(A));
	cout << pA1 << endl;
	cout << "------------------------------" << endl;
	free(pA1);
	cout << "new:" << endl;
	A* pA2 = new A();
	delete pA2;
}
void Test()
{
	A* p = new A;

}


void Test_mem()
{
	int* p = new int[10];
	_CrtDumpMemoryLeaks();
}
int main()
{
	//Test_Custom();
	Test_mem();
	return 0;
}


