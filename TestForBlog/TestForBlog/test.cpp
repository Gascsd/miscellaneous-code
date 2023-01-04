#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int& x = a;
//	int& y = x;
//	return 0;
//}


//>1. 引用在定义时必须初始化
//> 2. 一个变量可以有多个引用
//> 3. 引用一旦引用一个实体，再不能引用其他实体
//int main()
//{
//	int a = 10;
//	int& ra;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& ra = a;
//	ra = b;
//	cout << ra << endl;
//	return 0;
//}

//void TestConstRef()
//{
//	int a = 10;
//	int& ra = a;
//	const int& ra = a;
//	int& b = 10;
//	const int& b = 10;
//	double d = 12.34;
//	int& rd = d;
//	const int& rd = d;
//}
//
//int main()
//{
//	TestConstRef();
//	return 0;
//}



//void Func(int& x)//假设传一个参数
//{
//	//做一些操作 
//	//...
//}
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	const int& rra = ra;
//	Func(a);
//	Func(ra);
//	Func(rra);
//	return 0;
//}


//int main()
//{
//	const int& b = 10;
//
//	double d = 12.34;
//
//	int i = d;// 这句代码有问题吗？
//
//	int& ri = d;// 这句代码有问题吗？
//	return 0;
//}
//
//
////强转  截断  提升


//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	Swap(a, b);
//	cout << "a=" << a << " b=" << b << endl;
//	return 0;
//}


//typedef int SDataType;
//typedef struct SListNode
//{
//	SDataType data;
//	struct SLDataType* next;
//}SLNode,*PSLNode;
//
////void SListPushBack(SLNode** pphead)
//void SListPushBack(PSLNode& pphead, SDataType x)
//{
//
//}
//
//int main()
//{
//	SLNode* plist = NULL;
//	SListPushBack(plist, 1);
//	SListPushBack(plist, 2);
//	SListPushBack(plist, 3);
//	SListPushBack(plist, 4);
//	return 0;
//}


//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//	return 0;
//}

//int& Count()
//{
//	int n = 0;
//	n++;
//	// ...
//	return n;
//}
//void Func()
//{
//	int x = 100;
//}
//int main()
//{
//	int& ret = Count();
//	cout << ret << endl;
//	Func();
//	cout << ret << endl;
//	cout << ret << endl;
//	return 0;
//}


//#include"SeqList.h"
//int SeqListSize(SeqList* ps)
//{
//	assert(ps);
//	return ps->size;
//}
//
//SLDataType& SeqListAt(SeqList* ps, size_t pos)
//{
//	assert(ps);
//	assert(pos < ps->size);
//
//	return ps->a[pos];
//}
//
//int main()
//{
//	SeqList sl;
//	SeqListInit(&sl);
//	SeqListPushBack(&sl, 1);
//	SeqListPushBack(&sl, 2);
//	SeqListPushBack(&sl, 3);
//	SeqListPushBack(&sl, 4);
//
//	for (int i = 0; i < SeqListSize(&sl); ++i)
//	{
//		if (SeqListAt(&sl, i) % 2 == 0)
//		{
//			SeqListAt(&sl, i) *= 2;
//		}
//	}
//	for (int i = 0; i < SeqListSize(&sl); ++i)
//	{
//		cout << SeqListAt(&sl, i) << endl;
//	}
//	SeqListDestroy(&sl);
//	return 0;
//}


//#include <time.h>
//struct A { 
//	int a[10000];
//};
//void TestFunc1(A a) 
//{}
//void TestFunc2(A& a) 
//{}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}



//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}


//void Func(int& x = 10)
//{
//    cout << x << endl;
//}
//int main()
//{
//    Func();
//    return 0;
//}

//struct b
//{
//	int _a;
//	void Init()
//	{
//		_a = 0;
//	}
//};
//int main()
//{
//	b man;
//	man.Init();
//	cout << man._a << endl;
//}

//class A;
//
//class B;
//
//void F() {
//
//	A a;
//
//	B b;
//
//}



//#include<stdio.h>
//int main()
//{
//	int a;
//	printf("请输入a:");
//	scanf("%d", &a);
//	float x = 2.5f, y = 4.3f;
//	printf("%f\n", x + a % 3 * (int)(x + y) / 2);
//	return 0;
//}

//#include<math.h>
//
//int main()
//{
//	int sum = pow(2, 5);
//
//	int a = 6, b = 6, x, y;
//	x = (++a)++;
//	y = ++(++a);
//	printf("x=%d,y=%d\n", x, y);
//	return 0;
//}

//int main()
//{
//	double a, v;
//	scanf("%lf", &a);
//	v = 4 / 3.0 * 3.14159 * a * a * a;
//	printf("%6.1f", v);
//	return 0;
//}


//int main()
//{
//	float d;
//	scanf("%f", &d);//输入路程
//	float f;
//	if (d >= 0 && d <= 2)//小于2
//	{
//		f = 5;
//	}
//	else if (d > 2 && d <= 4)//2到4
//	{
//		f = 2.5 * d;
//	}
//	else//大于4
//	{
//		f = 3.5 * d - 4;
//	}
//	printf("%.2f", f);
//	return 0;
//}



//int main()
//{
//	int x;
//	scanf("%d", &x);
//	while (x != 0)
//	{
//		int a = x % 10;
//		printf("%d", a);
//		x /= 10;
//	}
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'A';
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}



//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0; 
//}

//int main()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0;
//	return 0;
//}
//void TestAuto()
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4，5，6 };
//}
//int main()
//{
//	TestAuto();
//	return 0;
//}


//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}


//inline int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int ret = Add(1, 2);
//	return 0;
//}



//typedef int DataType;
//struct Stack
//{
//	void Init(size_t capacity)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const DataType& data)
//	{
//		// 扩容
//		_array[_size] = data;
//		++_size;
//	}
//	DataType Top()
//	{
//			return _array[_size - 1];
//	}
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//};
//int main()
//{
//	Stack s;
//	s.Init(10);
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	cout << s.Top() << endl;
//	s.Destroy();
//	return 0;
//}

//class date
//{
//public:
//	void print() const
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//	date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	date(const date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	date* operator&()
//	{
//		return this;
//	}
//	const date* operator&() const
//	{
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////int main()
////{
////	date d1;
////	date d2(d1);
////	d2.print();
////	return 0;
////}
//int main()
//{
//	date d1(2022, 12, 1);
//	const date d2(d1);
//	d1.print();
//	d2.print();
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//	void Push(int x)
//	{
//		if (_top == _capacity)
//		{
//			perror("capacity is full");
//			exit(-1);
//		}
//		_a[_top] = x;
//		_top++;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	Stack st1();
//	return 0;
//}
//class MyQueue
//{
//public:
//	void Push(int x)
//	{
//		_pushST.Push(x);
//	}
//private:
//	Stack _pushST;
//	Stack _popST;
//};
//int main()
//{
//	MyQueue q;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_ref(ref)
//		,_n(10)
//	{}
//private:
//	A _aobj;
//	int& _ref;
//	const int _n;
//};


//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}


//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//		,_month(1)
//		,_day(1)
//	{}
//
//	ostream& operator<<(ostream out) const
//	{
//		out << _year << "年" << _month << "月" << _day << "日" << endl;
//		return out;
//	}
//	istream& operator>>(istream in)
//	{
//		in >> _year;
//		in >> _month;
//		in >> _day;
//		return in;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022);
//	d1.Print();
//	d1 = 2023;
//	d1.Print();
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////流插入
//ostream& operator<<(ostream& out, const Date& d) 
//{
//	cout << d._year << "/" << d._month << "/" << d._day;
//	return out;
//}
////流提取
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year;
//	in >> d._month;
//	in >> d._day;
//	return in;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		N++;
//	}
//	A(const A& t)
//	{
//		N++;
//	}
//	~A()
//	{
//		N--;
//	}
//	static int GetN()
//	{
//		return N;
//	}
//private:
//	static int N;
//};
//int A::N = 0;
//void TestA()
//{
//	cout << A::GetN() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetN() << endl;
//}
//int main()
//{
//	TestA();
//	return 0;
//}


//class Time
//{
//	friend class Date;  //声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};

//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//int main()
//{
//	A::B b;
//	b.foo(A());
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 10)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	//创建有名对象的方式
//	A a1;
//	A a2(15);
//	A a3 = 5;
//	//创建匿名对象，不用取名字
//	A();
//	return 0;
//}

//class Solution
//{
//public:
//	int Sun_Solution(int n)
//	{
//		//...
//		return n;
//	}
//};
//int main()
//{
//	Solution().Sun_Solution(10);
//	return 0;
//}

class A
{
public:
	A(int a = 10)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	A(const A& a)
	{
		_a = a._a;
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
A f3()
{
	return A(10);
}
int main()
{
	A ret = f3();
	return 0;
}



 

void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
//int main()
//{
//	cout << "场景一" << endl;
//	A a1(1);
//	f1(a1);
//	cout << "场景二" << endl;
//	f1(A(1));
//	return 0;
//}

