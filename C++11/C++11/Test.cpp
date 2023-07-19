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
	//C++98֧�ֵĳ�ʼ����ʽ
	int x1 = 1;
	int x2{ 2 };
	//C++11֧�ֵĳ�ʼ����ʽ
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5]{ 0 };
	//���ֳ�ʼ����ʽҲ����Ӧ����new���ʽ��
	int* pa = new int[5] {1, 2, 3, 4, 5};
}
void Test2()
{
	Date d1(2023, 1, 1);//֮ǰ�Ĵ�����ʽ
	
	//C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
	Date d2{ 2023, 1, 2 };
	Date d3 = { 2023, 1, 3 };
	//ͬ��֧��new���ʽ
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
	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
	map<string, string>::iterator it1 = dict.begin();//������auto�ؼ��ʣ�������̫����
	auto it2 = dict.begin();//ʹ��auto�ؼ��֣�it2�������ɱ������ƶ�begin()�ķ���ֵ����
	//���� it1 �� it2 �ȼ�
}

// decltype��һЩʹ��ʹ�ó���
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
	decltype(x * y) ret; // ret��������double
	decltype(&x) p; // p��������int*
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