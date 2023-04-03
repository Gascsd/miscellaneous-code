#pragma once
#include <assert.h>
namespace my
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
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
        const_iterator cbegin() const
        {
            return _start;
        }
        const_iterator cend() const
        {
            return _finish;
        }
        // construct and destroy
        vector()
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr)
        {}
        vector(int n, const T& value = T())
        {
            reserve(n);
            for (int i = 0; i < n; ++i)
            {
                push_back(value);
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
        vector(const vector<T>& v)
            :_start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
            vector<T> tmp(v.cbegin(), v.cend());
            swap(tmp);
        }
        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }
        // capacity
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _endOfStorage - _start;
        }
        bool empty() const
        {
            return _start == _finish;
        }
        void reserve(size_t n)
        {
            if (capacity() < n)
            {
                size_t oldSize = size();
                T* tmp = new T[n];
                if (_start)
                {
                    for (size_t i = 0; i < oldSize; ++i)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + oldSize;
                _endOfStorage = _start + n;
            }
        }
        void resize(size_t n, const T& value = T())
        {
            if (n > capacity())
            {
                reserve(n);
            }
            if (n > size())
            {
                while (_finish != _start + n)
                {
                    *_finish = value;
                    ++_finish;
                }
            }
            else
            {
                _finish = _start + n;
            }
        }
        ///////access///////////////////////////////
        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }
        const T& operator[](size_t pos)const
        {
            assert(pos < size());
            return _start[pos];
        }
        ///////////////modify/////////////////////////////
        void push_back(const T& x)
        {
            if (_finish == _endOfStorage)
            {
                size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
            }
            *_finish = x;
            ++_finish;
        }
        void pop_back()
        {
            assert(!empty());
            --_finish;
        }
        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }
        iterator insert(iterator pos, const T& x)
        {
            assert(pos >= _start);
            assert(pos < _finish);
            if (_finish == _endOfStorage)
            {
                size_t len = pos - _start;
                size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
                pos = _start + len;
            }
            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }
            *pos = x;
            ++_finish;
            return pos;
        }
        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos < _finish);
            assert(!empty());
            iterator begin = pos;
            while (begin < _finish)
            {
                *(begin) = *(begin + 1);
                ++begin;
            }
            --_finish;
            return pos;
        }
    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾
    };
}