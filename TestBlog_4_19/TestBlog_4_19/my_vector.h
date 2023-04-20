#pragma once
#include <iostream>
#include <assert.h>

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

		void reserve(size_t n)
		{
			if (capacity() < n)
			{
				size_t OldSize = size();
				T* tmp = new T[n];
				//memcpy(tmp, _start, sizeof(T) * size());
				if (_start)
				{
					for (size_t i = 0; i < OldSize; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + OldSize;
				_endOfStorage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n > capacity())//n>capacity
			{
				reserve(n);
			}
			if (n > size())//size < n < capacity
			{
				while (*_finish > _size + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
				_finish = _start + n;
		}
		T& operator[](size_t pos)//const版本
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const//非const版本
		{
			assert(pos < size());
			return _start[pos];
		}
		void push_back(const T& val)
		{
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newCapacity);
			}
			*_finish = val;
			++_finish;
		}
		bool empty()
		{
			return _start == _finish;
		}
		void pop_back()
		{
			if (!empty())
			{
				--_finish;
			}
		}
		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t len = pos - _start;//这里注意以下，要保存pos的相对位置，否则扩容之后会导致pos位置失效
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
				pos = _start + len;//重新确定pos位置
			}
			//挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
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
		void clear()
		{
			_finish = _start;
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

	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}