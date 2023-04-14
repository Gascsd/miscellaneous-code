#include <iostream>
#include <string>
using namespace std;





void Test_Construct()
{
	char str[] = "hello string";//����һ��C���Ե��ַ���
	string s1;//Ĭ�Ϲ��캯�������ô����κβ�����������s1��ֻ��һ��\0
	string s2(str);//ʹ��C���Ե��ַ�������һ��string���͵Ķ���
	string s3(s2);//ʹ��s2��������һ��string���͵Ķ���
	string s4(s3, 2, 5);//ʹ��s3�еĵڶ���λ�ÿ�ʼ����Ϊ5���Ӵ��������
	string s5(str, 8);//ʹ��C���Ե��ַ�������һ��ָ�����ȵ�string����
	string s6(10, 'a');//ʹ��ָ���ַ�����һ������Ϊ10������Ϊa�Ķ���
	auto first = s2.begin();
	auto last = s2.end();
	string s7(first, last);//ʹ�õ��������乹��һ��[first,last)�Ķ���
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
	//��Χfor
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//������
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
	cout << "���������" << endl;
	string::iterator it1 = s.begin();
	while (it1 != s.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	cout << "���������" << endl;
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