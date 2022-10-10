#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2)//�ж��Ƿ�Ϊ�����2��
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
	// ȫȱʡ�Ĺ��캯��
	Date (int year = 1900, int month = 1, int day = 1)
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
	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	// ��������
	~Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	// ����+=����
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
	// ����+����
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}
	// ����-����
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}
	// ����-=����
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
	// ǰ��++
	Date& operator++()
	{
		*(this) += 1;
		return *this;
	}
	// ����++
	//Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
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
	// ==���������
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	// >=���������
	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}
	// <���������
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}
	// <=���������
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}
	// ����-���� ��������
	int operator-(const Date& d)
	{
		assert(*this >= d);//��鴫������ڴ�С

	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	//���Թ��캯��
	Date d1;
	Date d2(2022, 9, 22);
	//���Թ��쿽��
	Date d3(d1);
	//���Ը�ֵ���������
	d1 = d2;
	//����+����
	d3 = d2 + 50;
	//����+=����
	d2 += 50;
	//����-����
	d3 = d2 - 50;
	//����-=����
	d2 -= 50;
	//����ǰ��++
	d3 += 8;
	++d3;
	//���Ժ���++
	//���Ժ���--
	//����ǰ��--

	//����>���������
	cout << (d1 > d2) << endl;
	cout << (d3 > d1) << endl;
	//����==���������
	cout << (d1 == d2) << endl;
	cout << (d3 == d2) << endl;
	//����>=���������
	cout << (d1 >= d2) << endl;
	cout << (d2 > d3) << endl;
	//����<���������
	cout << (d1 < d2) << endl;
	cout << (d1 < d3) << endl;
	//����<=���������
	cout << (d3 <= d2) << endl;
	cout << (d1 <= d2) << endl;
	//����!=���������
	cout << (d1 != d2) << endl;
	cout << (d3 != d2) << endl;
	// ��������-���� ��������


	//������������
	return 0;
}