#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
#include <assert.h>
using namespace std;


namespace my
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
	public:
		iterator beign()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator beign() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		//传统写法
		//string(const string& s)
		//{
		//	_str = new char[s.capacity + 1];
		//	strcpy(_str, s._str);
		//	_size = s.size();
		//	_capacity = s.capacity;
		//}
		//现代写法
		string(const string& s)
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
		const char* c_str() const
		{
			return _str;
		}
		//传统写法
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, _str);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}
		// 现代写法1
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(tmp);
		//	}
		//	return *this;
		//}
		//现代写法2
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void reseize(size_t n, char ch = '\0')
		{
			if (n > _capacity)
			{
				reserve(n);
			}
			if (n > _size)
			{
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
			}
			_size = n;
			_str[n] = '\0';
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
		bool empty()
		{
			return _size == 0;
		}
		char operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		void push_back(char ch)
		{
			if (_capacity == _size)
			{
				size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;//扩容扩二倍
				reserve(newCapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';//这里注意尾插之后要对字符串结尾的\0做一下补充
		}
		void append(const char* str)
		{
			//这里需要判断一下需不需要扩容，如果需要的话要扩多大
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		//当pos==0时会出现死循环
		//string insert(size_t pos, char ch)
		//{
		//	assert(pos <= _size);
		//	if (_size == _capacity)
		//	{
		//		size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
		//		reserve(newCapacity);
		//	}
		//	//挪动数据
		//	size_t end = _size;
		//	while (pos <= end)
		//	{
		//		_str[end + 1] = _str[end];
		//		--end;
		//	}
		//	_str[pos] = ch;
		//	++_size;
		//	return *this;
		//}
		string insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newCapacity);
			}
			//挪动数据
			size_t end = _size + 1;
			while (pos < end)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			//判断位置是否合法
			assert(pos <= _size);
			size_t len = strlen(str);
			//扩容
			if (_capacity < len + _size)
			{
				reserve(len + _size);
			}
			//挪动数据
			size_t end = _size + pos;
			while (pos + len - 1 < end)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		void pop_back()
		{
			_str[--_size] = '\0';
		}
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = 0;
			}
			//挪动数据
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		size_t find(size_t pos, char ch)
		{
			assert(pos < _size);
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(size_t pos, const char* str)
		{
			assert(pos < _size);
			const char* ptr = strstr(_str, str);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;

	};

	void Test()
	{
		string s("hellod");
		s.insert(5, " worl");
		s.pop_back();
	}
}