#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

#include "string.h"

void test_string1()
{
	my::string s1("hello world");
	my::string s2(s1);
	my::string s3 = s1;
}

int main()
{
	test_string1();
	return 0;
}
