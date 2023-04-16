#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
using namespace std;


namespace my
{
	class string
	{
	public:

		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//传统写法
		//string(string& s)
		//{
		//	_str = new char[s.capacity + 1];
		//	strcpy(_str, s._str);
		//	_size = s.size();
		//	_capacity = s.capacity;
		//}
		//现代写法
		string(string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		//void swap(my::basic_string<char>& s)
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		char* c_str()
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	void Test()
	{
		string s("hello");
		string s2(s);
	}
}