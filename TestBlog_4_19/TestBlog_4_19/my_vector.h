#pragma once
#include <iostream>


namespace my
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endOfStorage - _start;
		}
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{}
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//经典写法
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			while()
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}
		//现代写法
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			vector<T> tmp(v.begin(), v._end());
			swap(tmp);
		}

		//现代写法
		vector<T>& operator=(vector<T> tmp)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			swap(tmp);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (capacity() < n)
			{
				size_t OldSize = size()
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;
				_start = tmp;
				_finish = _start + OldSize;
				_endOfStorage = _start + n;
			}
		}
	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}