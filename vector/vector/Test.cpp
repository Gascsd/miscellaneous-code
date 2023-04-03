#include <iostream>
#include <vector>
#include "vector.h"
using namespace std;
void stl_test1()
{
	vector<int> v(10);
	cout << "size:" << v.size() << " ";
	cout << "capacity:" << v.capacity() << " " << endl;
}
void my_test1()
{
	my::vector<int> v(10);
	cout << "size:" << v.size() << " ";
	cout << "capacity:" << v.capacity() << " " << endl;
}
void my_test2()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//my::vector<int> v1 = v;
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
}
void my_test3()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	my::vector<int> v1(v.begin(), v.end());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	my::vector<int> v2(v1);

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}
void my_test4()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	my::vector<int> v1(v);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}
void my_test5()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.resize(10);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	v.resize(2);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
}
void my_test6()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}
void my_test7()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	v.insert(v.begin(), 10);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

}
void my_test8()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	auto begin = v.begin();
	while (begin != v.end())
	{
		if (*begin % 2 == 0)
		{
			begin = v.erase(begin);
		}
		++begin;
	}
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	my_test8();
	return 0;
}