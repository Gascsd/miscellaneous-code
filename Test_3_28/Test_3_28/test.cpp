#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};
class C
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
};
class D
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
};
void Test2()
{
	A* pClassA = new A[5];
	delete pClassA;
}
//C c;
void Test3()
{
	A* pa = new A();
	B b;
	static D d;
	delete pa;
}
void Test1()
{
	vector<int> v;
	v.resize(4);
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	//v[0] = 
}

void Test4()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	cout << v.size() << ":" << v.capacity() << endl;
	v.reserve(100);
	v.resize(20);
	cout << v.size() << ":" << v.capacity() << endl;
	v.reserve(50);
	v.resize(5);
	cout << v.size() << ":" << v.capacity() << endl;
}
void Test5()
{
	vector<int> v1;
	v1.resize(5, 1);
	// cout << v1[6] << endl;
	// cout << v1.at(6) << endl;
}
int main()
{
	Test5();
	return 0;
}

