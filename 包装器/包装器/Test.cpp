#include <iostream>
#include <functional>
using namespace std;

template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "&count:" << &count << endl;

	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor1
{
	double operator()(double d)
	{
		return d / 3;
	}
};
void Test1()
{
	cout << useF(f, 11.11) << endl;//������
	
	cout << useF(Functor1(), 11.11) << endl;//��������
	
	cout << useF([](double d)->double {return d / 4; }, 11.11) << endl;//lambda���ʽ
}


int func(int a, int b)
{
	return a + b;
}
struct Functor
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}
	int plusd(int a, int b)
	{
		return a + b;
	}
};
void Test2()
{
	//������������ָ�룩
	function<int(int, int)> func1 = func;
	cout << func1(1, 2) << endl;
	//�������󣨷º�����
	function<int(int, int)> func2 = Functor();
	cout << func2(1, 2) << endl;
	//lambda���ʽ
	function<int(int, int)> func3 = [](const int a, const int b)->int {return a + b; };
	cout << func3(1, 2) << endl;
	//��ľ�̬��Ա����
	function<int(int, int)> func4 = &Plus::plusi;//������Բ���ȡ��ַ����
	cout << func4(1, 2) << endl;
	//��ĳ�Ա����
	function<int(Plus, int, int)> func5 = &Plus::plusd;//�������Ҫ��ȡ��ַ���ţ�����������ʱ����Ҫ��ʾ�Ĵ�����
	cout << func5(Plus(), 1, 2) << endl;//���õ�ʱ����Ҫ������
}

void Test3()
{
	function<double(double)> func1 = f;
	function<double(double)> func2 = Functor1();
	function<double(double)> func3 = [](double d)->double {return d / 4; };

	cout << useF(func1, 11.11) << endl;
	cout << useF(func2, 11.11) << endl;
	cout << useF(func3, 11.11) << endl;
}

int Sub(int a, int b)
{
	return a - b;
}
void Test4()
{
	function<int(int)> func2 = bind(Sub, placeholders::_1, 10);
	cout << func2(2) << endl;
}
void Test5()
{
	function<int(int, int)> func = bind(Sub, placeholders::_2, placeholders::_1);
	cout << func(1, 2) << endl;
}
int main()
{
	Test5();
	return 0;
}