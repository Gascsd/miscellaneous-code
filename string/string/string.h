#pragma once

namespace my
{
	class string
	{
	public:
		//正向迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		//构造函数s1("")
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		
		//构造函数s2(s1) 
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;

			strcpy(_str, s._str);
		}

		//赋值重载  s3 = s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				
				delete[] _str;
				_str = tmp;

				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}
		
		//析构函数 
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		
		//c_str 
		const char* c_str() const
		{
			return _str;
		}

		//size 
		size_t size()
		{
			return _size;
		}
		//capacity 
		size_t capacity()
		{
			return _capacity;
		}

		//两种[]重载 
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		//reserve  
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
		
		//resize
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
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
		
		//push_back 
		void push_back(const char ch)
		{
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newCapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		
		//append
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		//两种+=重载
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		
		//insert
		string& insert(size_t pos, char ch)
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
			_str[pos] = ch;
			++_size;

			return *this;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}



