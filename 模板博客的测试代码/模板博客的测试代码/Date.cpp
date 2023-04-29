#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
using namespace std;

// ��ֵ���������
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// ����+=����
Date& Date::operator+=(int day)
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
// ����+����
Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}
// ����-����
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}
// ����-=����
Date& Date::operator-=(int day)
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
// ǰ��++
Date& Date::operator++()
{
	return *this += 1;
}
// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	tmp += 1;
	return tmp;
}
// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	tmp -= 1;
	return tmp;
}
// ǰ��--
Date& Date::operator--()
{
	return (*this) -= 1;
}
// >���������
bool Date::operator>(const Date& d)
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
// ==���������
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
// >=���������
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
// <���������
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
// <=���������
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
// !=���������
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}
// ����-���� ��������
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (max != min)
	{
		++count;
		++min;
	}
	return flag * count;
}
