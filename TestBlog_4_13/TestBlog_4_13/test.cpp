#include <iostream>
#include <string>
using namespace std;





void Test_Construct()
{
	char str[] = "hello string";//创建一个C语言的字符串
	string s1;//默认构造函数，不用传递任何参数，最终是s1中只有一个\0
	string s2(str);//使用C语言的字符串构造一个string类型的对象
	string s3(s2);//使用s2拷贝构造一个string类型的对象
	string s4(s3, 2, 5);//使用s3中的第二个位置开始长度为5的子串构造对象
	string s5(str, 8);//使用C语言的字符串构造一个指定长度的string类型
	string s6(10, 'a');//使用指定字符构造一个长度为10，内容为a的对象
	auto first = s2.begin();
	auto last = s2.end();
	string s7(first, last);//使用迭代器区间构造一个[first,last)的对象
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s6: " << s6 << endl;
	cout << "s7: " << s7 << endl;
}


void Test_Element()
{
	string s = "hello string";
	cout << s.at(4) << endl;
	cout << s[4] << endl;
}

void Test_Element2()
{
	string s = "0123456789";
	//operator[]
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	//范围for
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void Test_Iterator()
{
	string s = "0123456789";
	cout << "正向迭代器" << endl;
	string::iterator it1 = s.begin();
	while (it1 != s.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	cout << "反向迭代器" << endl;
	string::reverse_iterator it2 = s.rbegin();
	while (it2 != s.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}
void Test_capacity()
{
	string s = "0123456789";
	cout << "size" << s.size() << endl;
	cout << "capacity" << s.capacity() << endl;
	s.reserve(20);
	cout << "capacity" << s.capacity() << endl;
	s.resize(5);
	cout << "size" << s.size() << endl;
	if (!s.empty())
	{
		string::iterator it1 = s.begin();
		while (it1 != s.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
	}
	else
	{
		cout << "string is empty" << endl;
	}
}
void Test_Modify()
{
	string s = "abcdefg";
	cout << s << endl;
	s += 'h';
	cout << s << endl;
	s += "ijklm";
	cout << s << endl;
	s.insert(5, 1, 'A');
	cout << s << endl;
	s.erase(5, 1);
	cout << s << endl;
}
int main()
{
	Test_Modify();
	return 0;
}