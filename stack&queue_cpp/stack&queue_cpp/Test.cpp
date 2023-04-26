#include <iostream>
#include <stack>
#include <queue>
#include "stack.h"
using namespace std;
void test()
{
	queue<char> Q;
	char x, y;
	x = 'n'; y = 'g';
	Q.push(x); Q.push('i'); Q.push(y);
	Q.pop(); Q.push('r'); Q.push('t'); Q.push(x);
	Q.pop(); Q.push('s');
	while (!Q.empty())
	{
		x = Q.front();
		Q.pop();
		cout << x;
	};
	cout << y;
}
int main()
{
	test();
	//stack<char> S;
	//char x, y;
	//x = 'n';
	//y = 'g';
	//S.push(x);
	//S.push('i');
	//S.push(y);
	//S.pop();
	//S.push('r');
	//S.push('t');
	//S.push(x);
	//S.pop();
	//S.push('s');
	//while (!S.empty())
	//{
	//	x = S.top();
	//	S.pop();
	//	cout << x;
	//};
	//cout << y;
	return 0;
}