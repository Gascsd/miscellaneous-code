#include <iostream>
using namespace std;


//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//void Test1()
//{
//	try 
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...) 
//	{
//		cout << "unkown exception" << endl;
//	}
//}

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ�����������׳�ȥ
	int* arr = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << arr << endl;
		delete[] arr;
		throw;
	}
	//...
	cout << "delete []" << arr << endl;
	delete[] arr;
}
void Test2()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}
}

int main()
{
	Test2();
	return 0;
}