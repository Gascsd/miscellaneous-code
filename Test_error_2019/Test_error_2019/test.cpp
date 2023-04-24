#include <iostream>
#include <list>
#include "stl_list.h"
using namespace std;

void Test1()
{
	zht::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
}
int main()
{
	Test1();
	return 0;
}