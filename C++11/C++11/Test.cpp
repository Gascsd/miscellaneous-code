#include <iostream>
#include <string>
#include <map>
#include <array>
using namespace std;


struct Point
{
	int _x;
	int _y;
};

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test1()
{
	//C++98支持的初始化方式
	int x1 = 1;
	int x2{ 2 };
	//C++11支持的初始化方式
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5]{ 0 };
	//这种初始化方式也可以应用于new表达式中
	int* pa = new int[5] {1, 2, 3, 4, 5};
}
void Test2()
{
	Date d1(2023, 1, 1);//之前的创建方式
	
	//C++11支持的列表初始化，这里会调用构造函数初始化
	Date d2{ 2023, 1, 2 };
	Date d3 = { 2023, 1, 3 };
	//同样支持new表达式
	Date* pd = new Date[3]{ {2023,1,4}, {2023,1,5}, {2023,1,6} };
}
void Test3()
{
	auto il = { 1,2,3 };
	cout << typeid(il).name() << endl;
}

initializer_list<int> func()
{
	int a = 1, b = 2;
	return { a, b };
}
void Test4()
{
	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
	map<string, string>::iterator it1 = dict.begin();//不适用auto关键词，类型名太长了
	auto it2 = dict.begin();//使用auto关键字，it2的类型由编译器推断begin()的返回值类型
	//这里 it1 和 it2 等价
}

// decltype的一些使用使用场景
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
void Test5()
{
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret; // ret的类型是double
	decltype(&x) p; // p的类型是int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	F(1, 'a');
}
void Test6()
{
	int arr1[5] = { 0 };
	array<int, 5> arr2 = { 0 };
}








//int main()
//{
//	Test6();
//	return 0;
//}