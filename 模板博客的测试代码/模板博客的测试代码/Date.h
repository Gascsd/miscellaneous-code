#pragma once
#include<iostream>
#include<assert.h>

class Date
{
public:
	//�ж��Ƿ�Ϊ����
	bool is_leap_year(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2)//�ж��Ƿ�Ϊ�����2��
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
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		*(this) = d;
	}
	// ��������
	~Date()
	{
		_year = 1970;
		_month = 1;
		_day = 1;
	}
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
