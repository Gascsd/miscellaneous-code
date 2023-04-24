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
	//д
	zht::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		*it *= 10;
		++it;
	}
	//��
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
	//β��
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
	//ͷ��
	lt.push_front(10);
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//������λ�ò���
	auto it_push = ++lt.begin();//�ӵڶ���λ�ÿ�ʼ
	lt.insert(it_push, 30);//����һ��ֵ
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	++it_push;
	lt.insert(it_push, 5, 50);//����n��ֵ
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	++it_push;
	lt.insert(it_push, v.begin(), v.end());//����һ������������
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
	//ͷɾ
	lt.pop_front();
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//βɾ
	lt.pop_back();
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	//����λ��ɾ��
	auto pos = ++lt.begin();
	pos = lt.erase(pos);//ɾ��ĳһλ��
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	auto start = ++pos;
	auto end = ++(++start);
	lt.erase(start, end);//ɾ��һ������������
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
	cout << "ԭlist:";
	auto it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	lt.unique();
	cout << "����������������ʹ��unique��";
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	lt.sort();
	cout << "����list��";
	it_out = lt.begin();
	while (it_out != lt.end())
	{
		cout << *it_out << " ";
		++it_out;
	}
	cout << endl;
	cout << "�������listʹ��unique��";
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



