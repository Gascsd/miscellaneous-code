#include "my_vector.h"
#include <vector>
#include <list>
using namespace std;


void Test_Construct()
{
	vector<int> v1;
	vector<int> v2(5, 3);
	string s("aaaaaa");
	vector<char> v3(s.begin(), s.end());
	vector<char> v4(v3);
}
void Test_Capacity1()
{
	vector<int> v;
	v.reserve(10);
	for (size_t i = 0; i < 5; ++i)
	{
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
}
void Test_Capacity2()
{
	vector<int> v(5, 1);
	cout << "before reserve capacity:" << v.capacity() << endl;
	v.reserve(10);
	cout << "after reserve capacity:" << v.capacity() << endl;
}
void Test_Capacity3()
{
	vector<int> v(5, 1);
	cout << "before resize capacity:" << v.size() << endl;
	v.resize(10);
	cout << "after resize capacity:" << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void Test_Access()
{
	vector<int> v(10);
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] = i;
	}
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void Test_Modifity1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
}
void Test_Modifity2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.insert(v.begin() + 3, 30);
	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void Test_erase()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin() + 2;
	cout << *it << endl;
	it = v.erase(it);
	cout << *it << endl;
}
void Test_list()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_back(7);
	list<int>::iterator it = ++lt.begin();
	cout << *it << endl;
	lt.erase(it);
	cout << *it << endl;
}
//int main()
//{
//	//Test_Construct();
//	//Test_Modifity2();
//	Test_list();
//	return 0;
//}



int main()
{
	vector<int> v(10);
	for (size_t i = 0; i < 10; ++i)
	{
		v[i] = i;
	}
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}




