#pragma once
#include<iostream>

namespace zht
{
	ostream& operator<<(ostream& _cout, const zht::string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			_cout << s[i];
		}
		return _cout;
	}
	istream& operator>>(istream& _cin, zht::string& s)
	{
		s.clear();
		char ch = _cin.get();
		while (ch != ' ' && ch != '\0')
		{
			s += ch;
			ch = _cin.get();
		}
		return _cin;
	}
	istream& operator>>(istream& _cin, zht::string& s)
	{
		s.clear();
		char buff[128] = { '\0' };
		size_t i = 0;
		char ch = _cin.get();
		while (ch != ' ' && ch != '\0')
		{
			if (i == 127)
			{
				s += buff;
				i = 0;
			}
			buff[i++] = ch;
			ch = _cin.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return _cin;
	}
	class string
	{
		friend ostream& operator<<(ostream& _cout, const zht::string& s);
		friend istream& operator>>(istream& _cin, zht::string& s);
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_capacity = strlen(str);
			_size = _capacity; 
			_str = new char[_capacity + 1];
		}
		string(const string& s)
		{
			string tmp(s);
			swap(tmp);
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
		string& operator=(const string& s)
		{
			_str = new char[s._capacity + 1];
			_capacity = s._capacity;
			_size = s._size;
		}
		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		//////////////////////////////////////////////////////////////
		// iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		/////////////////////////////////////////////////////////////
		// modify
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				int newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newCapacity);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void clear()
		{

		}
		//void swap(string& s)
		//{
		//	std::swap(_str, s._str);
		//	std::swap(_size, s._size);
		//	std::swap(_capacity, s._capacity);
		//}
		const char* c_str() const
		{
			return _str;
		}
		/////////////////////////////////////////////////////////////
		// capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		bool empty() const
		{
			return _size == 0;
		}
		void resize(size_t n, char c = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (int i = _size; i < n; i++)
				{
					_str[i] = '\0';
				}
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
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
		/////////////////////////////////////////////////////////////
		// access
		char& operator[](size_t index)
		{
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}
		/////////////////////////////////////////////////////////////
		//relational operators
		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator<=(const string& s)
		{
			return strcmp(_str, s._str) <= 0;
		}
		bool operator>(const string& s)
		{
			return !(*this <= s);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return npos;
		}
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, s);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newCapacity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = c;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			size_t end = _size + len;
			while (end > pos + len -1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[0] = '\0';
				_size = 0;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		const static size_t npos = -1;
	};
};
 
