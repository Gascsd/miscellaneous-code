#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2)//判断是否为闰年的2月
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				return 29;
			}
		}
		else
		{
			return MonthDay[month];
		}
	}
	// 全缺省的构造函数
	Date (int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 拷贝构造函数
    // d2(d1)
	Date(const Date& d)
	{
		*(this) = d;
	}
	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	// 析构函数
	~Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	// 日期+=天数
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}
	// 日期-天数
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}
	// 日期-=天数
	Date& operator-=(int day)
	{
		while (_day < day)
		{
			day -= _day;
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		_day -= day;
		return *this;
	}
	// 前置++
	Date& operator++()
	{
		*(this) += 1;
		return *this;
	}
	// 后置++
	//Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
			return false;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	// >=运算符重载
	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}
	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		assert(*this >= d);//检查传入的日期大小

	}
private:
	int _year;
	int _month;
	int _day;
};


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