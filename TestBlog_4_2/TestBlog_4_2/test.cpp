#include <iostream>
using namespace std;

//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void swap(char& a, char& b)
//{
//	char tmp = a;
//	a = b;
//	b = tmp;
//}
//void swap(double& a, double& b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//}

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
void Test_Template()
{
	int a = 10, b = 20;
	char c = 'a', d = 'b';
	double e = 1.1, f = 2.2;
	Swap(a, b);
	Swap(c, d);
	Swap(e, f);
}

int Add(int a, int b)
{
	return a + b;
}
template<class T1, class T2>
T1 Add(const T1 a, const T2 b)
{
	return a + b;
}
void Test2()
{
	int a = 10, b = 20;
	Add(a, b);//与非模板函数匹配，编译器不需要特化
	Add<int>(a, b);//调用编译器特化的Add版本
}
void Test3()
{
	int a = 10, b = 20;
	double c = 1.1;
	Add(a, b);
	Add(a, c);
}

void Test1()
{
	int a = 10, b = 20;
	double e = 1.1, f = 2.2;
	cout << Add(a, b) << endl;//会实例化出Add<int>
	cout << Add(e, f) << endl;//会实例化出Add<double>
	cout << Add(a, f) << endl;//此语句不能通过编译
}


template<class T>
class vector
{
public:
	vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	~vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}
	//......
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};

int main()
{
	Test3();
	return 0;
}