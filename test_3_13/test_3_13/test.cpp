#define _CRT_SECURE_NO_WARNINGS 1

#define N 10

#include<iostream>
using namespace std;

template<class T>
class Array
{
public:
	T& operator[](size_t i)
	{
		//assert(i < N);
		return _a[i];
	}
private:
	T _a[N];
};
int main()
{
	Array<int> a;
	for (size_t i = 0 ; i < N; ++i)
	{
		a[i] = i;
	}
	for (size_t i = 0; i < N; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}





