#include "list.h"
#include "stl_list.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "test_list.h"

using namespace std;



void Test_construct()
{
	my::list<int> lt1;
	my::list<int> lt2(5, 2);
	//my::list<int> lt3(lt2.begin(), lt2.end());
	my::list<int> lt4(lt2);
}
void Test_Iterator()
{
	zht::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	//写
	zht::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		*it *= 10;
		++it;
	}
	//读
	it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}
void Test_Capacity()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	cout << "size:" << lt.size() << endl;
	lt.resize(5);
	cout << "size:" << lt.size() << endl;
	lt.resize(10, 20);
	cout << "size:" << lt.size() << endl;
	auto begin = lt.begin();
	while (begin != lt.end())
	{
		cout << *begin << " ";
		++begin;
	}
	cout << endl;
	lt.clear();
	cout << "size:" << lt.size() << endl;
}

list<int> Test_insert()
{
	vector<int> v(5, 888);
	list<int> lt;
	//尾插
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	auto it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//头插
	lt.push_front(10);
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//在任意位置插入
	auto it_push = ++lt.begin();//从第二个位置开始
	lt.insert(it_push, 30);//插入一个值
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	++it_push;
	lt.insert(it_push, 5, 50);//插入n个值
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	++it_push;
	lt.insert(it_push, v.begin(), v.end());//插入一个迭代器区间
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	return lt;
}
void Test_erase()
{
	list<int> lt;
	for (int i = 0; i < 10; ++i)
	{
		lt.push_back(i);
	}
	auto it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//头删
	lt.pop_front();
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//尾删
	lt.pop_back();
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//任意位置删除
	auto pos = ++lt.begin();
	pos = lt.erase(pos);//删除某一位置
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	auto start = ++pos;
	auto end = ++(++start);
	lt.erase(start, end);//删除一个迭代器区间
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
}
void Test_remove()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_back(7);
	lt.push_back(8);
	auto it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	lt.remove(5);
	lt.remove(10);
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
}
void Test_Sort()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(10);
	lt.push_back(9);
	lt.push_back(3);
	lt.push_back(6);
	lt.push_back(3);
	lt.push_back(7);
	lt.push_back(6);
	cout << "原list:";
	auto it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	lt.unique();
	cout << "尝试在乱序的情况下使用unique：";
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	lt.sort();
	cout << "排序list：";
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	cout << "对有序的list使用unique：";
	lt.unique();
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
}
void Test1()
{
	zht::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
}
int main()
{
	//Test_Sort();
	//Test_remove();
	//list<int> lt = Test_insert();
	//Test_Capacity();
	//Test1();
	//Test_Iterator();
	//my::Test2();
	Test_construct();
	return 0;
}



