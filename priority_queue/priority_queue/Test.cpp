#include <iostream>
#include <queue>
#include <functional>
using namespace std;
void Test1()
{
	priority_queue<int, vector<int>, greater<int>> heap;
	heap.push(5);
	heap.push(3);
	heap.push(7);
	heap.push(10);
	heap.push(1);
	heap.push(9);
	while (!heap.empty())
	{
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;
}
void Test2()
{
	less<int> lessFunc;
	cout << lessFunc(1, 2) << endl;

	greater<int> greaterFunc;
	cout << greaterFunc(1, 2) << endl;
}
int main()
{
	Test2();
	return 0;
}
