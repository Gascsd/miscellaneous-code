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
//����ģ�� -- ����ƥ��
template<class T>
bool Less(T left, T right)
{
	cout << "Less(T left, T right)" << endl;
	return left < right;
}
//��������
bool Less(Date* left, Date* right)
{
	cout << "Less(Date* left, Date* right)" << endl;
	return *left < *right;
}
////��Less����ģ������ػ�
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	cout << "Less<Date*>(Date* left, Date* right)" << endl;
//	return *left < *right;
//}
void Test1()
{
	cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
	Date d1(2023, 4, 30);
	Date d2(2023, 5, 1);
	cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ
	Date* p1 = new Date(2023, 4, 30);
	Date* p2 = new Date(2023, 5, 1);
	cout << Less(p1, p2) << endl; // ���ԱȽϣ��������
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
//�����ػ�:���ڶ��������ػ�Ϊint
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}
};
//�������ƣ�����������ƫ�ػ�Ϊָ������
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>" << endl;
	}
};
//�������ƣ�����������ƫ�ػ�Ϊ��������
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
	Data<int, double> d1;//���û�������ģ��
	Data<double, int> d2;//�����ػ�int�汾
	Data<int*, int*> d3;//�����ػ���ָ��汾
	Data<double&, int&> d4;//�����ػ������ð汾
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