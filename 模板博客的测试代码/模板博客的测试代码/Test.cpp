#include <iostream>
#include "Date.h"

using namespace std;
template<class T, size_t N = 10>
class Array
{
public:
	//...
private:
	T _a[N];
};
//函数模板 -- 参数匹配
template<class T>
bool Less(T left, T right)
{
	cout << "Less(T left, T right)" << endl;
	return left < right;
}
//函数重载
bool Less(Date* left, Date* right)
{
	cout << "Less(Date* left, Date* right)" << endl;
	return *left < *right;
}
////对Less函数模板进行特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	cout << "Less<Date*>(Date* left, Date* right)" << endl;
//	return *left < *right;
//}
void Test1()
{
	cout << Less(1, 2) << endl; // 可以比较，结果正确
	Date d1(2023, 4, 30);
	Date d2(2023, 5, 1);
	cout << Less(d1, d2) << endl; // 可以比较，结果正确
	Date* p1 = new Date(2023, 4, 30);
	Date* p2 = new Date(2023, 5, 1);
	cout << Less(p1, p2) << endl; // 可以比较，结果错误
	cout << p1 << endl;
	cout << p2 << endl;
}
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}
};
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int, char>" << endl;
	}
};
void Test2()
{
	Data<int, int> d1;
	Data<int, char> d2;
}
//部分特化:将第二个参数特化为int
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}
};
//参数限制：将两个参数偏特化为指针类型
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>" << endl;
	}
};
//参数限制：将两个参数偏特化为引用类型
template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data()
	{
		cout << "Data<T1&, T2&>" << endl;
	}
};
void Test3()
{
	Data<int, double> d1;//调用基础的类模板
	Data<double, int> d2;//调用特化int版本
	Data<int*, int*> d3;//调用特化的指针版本
	Data<double&, int&> d4;//调用特化的引用版本
}

//// a.h
//template<class T>
//T Add(const T & left, const T & right);
//// a.cpp
//template<class T>
//T Add(const T & left, const T & right)
//{
//	return left + right;
//}
//// main.cpp
//#include"a.h"
//int main()
//{
//	Add(1, 2);
//	Add(1.0, 2.0);
//	return 0;
//}
int main()
{
	Test3();
	return 0;
}