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


//class Base
//{
//public:
//	virtual void Func1() { cout << "Base::Func1()" << endl; }
//	virtual void Func2() { cout << "Base::Func2()" << endl; }
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//	typedef void(*vfptr)();//这里将上面虚函数的指针类型重定义成vfptr，方便使用
//	void print_vftptr()
//	{
//		print((vfptr*)(*(int*)this));
//	}
//private:
//	void print(vfptr table[])
//	{
//		//依次拿到虚表中的所有函数指针
//		for (int i = 0; table[i] != nullptr; ++i)//在VS下，虚表以nullptr结束，所以可以用此方式作为循环条件
//		{
//			printf("[%d]:%p->", i, table[i]);//打印序号和地址
//			table[i]();//调用函数，虚函数与预期相符
//		}
//		cout << endl;
//	}
//	int _a = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1() { cout << "Base::Func1()" << endl; }
//	virtual void Func3() { cout << "Base::Func3()" << endl; }
//	virtual void Func4() { cout << "Base::Func4()" << endl; }
//private:
//	int _b = 2;
//};
//
//void Test4()
//{
//	Base b;
//	Derive d;
//	b.print_vftptr();
//	d.print_vftptr();
//}
//void print()
//{
//	Base b;
//	cout << (void*)(*(int*)&b) << endl;//拿到b对象的地址，强转成int*，拿到前四个字节的地址，解引用就是虚表的地址
//}
//void Test5()
//{
//	int a = 10;
//	int* b = new int(20);
//	static int c = 30;
//	const char* d = "aaaa";
//	cout << "栈：" << &a << endl;
//	cout << "堆：" << b << endl;
//	cout << "静态区：" << &c <<endl;
//	cout << "代码段：" << (void*)d << endl;
//	cout << "虚表地址";
//	print();
//}


class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*vfptr)();
void print(vfptr table[])
{
	for (int i = 0; table[i] != nullptr; ++i)
	{
		printf("[%d]:%p->", i, table[i]);
		table[i]();
	}
	cout << endl;
}
void Test6()
{
	Derive d;
	vfptr* vTableb1 = (vfptr*)(*(int*)&d);
	print(vTableb1);
	vfptr* vTableb2 = (vfptr*)(*(int*)((char*)&d + sizeof(Base1)));
	print(vTableb2);
}
int main()
{
	Test6();
	return 0;
}