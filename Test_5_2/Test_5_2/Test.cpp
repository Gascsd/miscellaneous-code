#include <iostream>
using namespace std;

//class A {
//public:
//    A() { cout << "A constructed\n"; }
//};
//class B {
//public:
//    B() { cout << "B constructed\n"; }
//};
//class C : public B, public A {
//public:
//    C() : A(), B() { cout << "C constructed\n"; }
//};
//
//int main() 
//{
//    C objC;
//    return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() {}
//};
//class Benz : public Car
//{
//public:
//	virtual void Drive(int a) override { cout << "Benz" << endl; }
//};



//class A final
//{};
//class B : public A
//{
//
//};

//class Base
//{
//public:
//	virtual void func() { cout << "func" << endl; }
//private:
//	int _b = 1;
//};
//void Test4()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//}
//class person
//{
//public:
//	virtual void BuyTicket() { cout << "person::买票-全价" << endl; }
//};
//class student : public person
//{
//public:
//	virtual void BuyTicket() { cout << "student::买票-半价" << endl; }
//};
//class soldier : public person
//{
//public:
//	virtual void BuyTicket(char a) { cout << "soldier::买票-优先" << endl; }
//};
//void func(person& p)
//{
//	p.BuyTicket();
//}
//void Test3()
//{
//	person pn;
//	student st;
//}
//void Test2()
//{
//	person pn;
//	student st;
//	soldier sr;
//	func(pn);
//	func(st);
//	func(sr);
//}
//void Test1()
//{
//	person* p1 = new person;
//	person* p2 = new student;
//	delete p1;
//	delete p2;
//}


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
void Test4()
{
	Base b;
	Derive d;
}
void print()
{
	Base b;
	cout << (void*)(*(int*)&b) << endl;//拿到b对象的地址，强转成int*，拿到前四个字节的地址，解引用就是虚表的地址
}
void Test5()
{
	int a = 10;
	int* b = new int(20);
	static int c = 30;
	const char* d = "aaaa";
	cout << "栈：" << &a << endl;
	cout << "堆：" << b << endl;
	cout << "静态区：" << &c <<endl;
	cout << "代码段：" << (void*)d << endl;
	cout << "虚表地址";
	print();
}
int main()
{
	Test5();
	return 0;
}