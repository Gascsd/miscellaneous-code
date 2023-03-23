#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

#include "string.h"

void test_string1()
{
	zht::string s1("hello world");
	zht::string s2(s1);
	zht::string s3 = s1;
}
void test_string2()
{
	std::string s1;
}

int main()
{
	test_string2();
	return 0;
}
