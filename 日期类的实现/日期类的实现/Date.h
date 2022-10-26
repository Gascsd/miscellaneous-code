#pragma once
#include<iostream>
#include<assert.h>

class Date
{
public:
	//判断是否为闰年
	bool is_leap_year(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2)//判断是否为闰年的2月
		{
			if (is_leap_year(year))
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
	Date(int year = 1900, int month = 1, int day = 1)
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
	// 析构函数
	~Date()
	{
		_year = 1970;
		_month = 1;
		_day = 1;
	}
	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
