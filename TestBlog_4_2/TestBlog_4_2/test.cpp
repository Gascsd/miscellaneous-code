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
	Add(a, b);//���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add<int>(a, b);//���ñ������ػ���Add�汾
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
	cout << Add(a, b) << endl;//��ʵ������Add<int>
	cout << Add(e, f) << endl;//��ʵ������Add<double>
	cout << Add(a, f) << endl;//����䲻��ͨ������
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