#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
using namespace std;

int main()
{
	//测试构造函数
	Date d1;
	Date d2(2022, 9, 22);
	//测试构造拷贝
	Date d3(d1);
	//测试赋值运算符重载
	d1 = d2;
	//测试+重载
	d3 = d2 + 50;
	//测试+=重载
	d2 += 50;
	//测试-重载
	d3 = d2 - 50;
	//测试-=重载
	d2 -= 50;
	//测试前置++
	d3 += 8;
	++d3;
	//测试后置++
	//测试后置--
	//测试前置--

	//测试>运算符重载
	cout << (d1 > d2) << endl;
	cout << (d3 > d1) << endl;
	//测试==运算符重载
	cout << (d1 == d2) << endl;
	cout << (d3 == d2) << endl;
	//测试>=运算符重载
	cout << (d1 >= d2) << endl;
	cout << (d2 > d3) << endl;
	//测试<运算符重载
	cout << (d1 < d2) << endl;
	cout << (d1 < d3) << endl;
	//测试<=运算符重载
	cout << (d3 <= d2) << endl;
	cout << (d1 <= d2) << endl;
	//测试!=运算符重载
	cout << (d1 != d2) << endl;
	cout << (d3 != d2) << endl;
	// 测试日期-日期 返回天数


	//测试析构函数
	return 0;
}