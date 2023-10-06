//
//  main_1.cpp
//  Test_10_6
//
//  Created by zht on 2023/10/6.
//

#include <iostream>
#include <vector>
#include <cassert>


namespace my
{
    template<class T>
    class vector
    {
        typedef T* iterator;
    public:
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        vector() : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr) {}
        //拷贝构造
        vector(vector& v) : _start(0), _finish(0), _endOfStorage(0)
        {
            for(auto& e : v)
            {
                push_back(e);
            }
        }
        //赋值重载
        vector& operator=(vector& v)
        {
            if(this != &v)
            {
                this->~vector();
                _start = new T[v.capacity()];
                _endOfStorage = _start + v.capacity();
                _finish = _start;
                for(int i = 0; i < v.size(); ++i)
                {
                    *_finish = v[i];
                    ++_finish;
                }
            }
            return *this;
        }
        ~vector()
        {
            //std::cout << "~vector" << std::endl;
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }
        void resize(int newSize)
        {
            if(newSize > size())
            {
                while(newSize != size())
                {
                    push_back(T());
                }
            }
            else if(newSize < size())
            {
                while(newSize != size())
                {
                    --_finish;
                }
            }
        }
        void reserve(int newCapacity)
        {
            if(newCapacity > capacity())
            {
                int Size = size();
                int* tmp = new T[newCapacity];
                for(int i = 0; i < size(); ++i)
                {
                    tmp[i] = _start[i];
                }
                delete _start;
                _start = tmp;
                _finish = _start + Size;
                _endOfStorage = _start + newCapacity;
            }
        }
        T& operator[](int pos)
        {
            return _start[pos];
        }
        T& at(int pos)
        {
            assert(pos <= size());
            return _start[pos];
        }
        void push_back(T val)
        {
            if(_finish == _endOfStorage)
            {
                int newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
            }
            *_finish = val;
            ++_finish;
        }
        void pop_back()
        {
            if(size() != 0)
            {
                --_finish;
            }
        }
        iterator insert(iterator pos, T val)
        {
            if(size() == capacity())
            {
                int newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
            }
            iterator cur = _finish - 1;
            while(cur != pos)
            {
                *(cur + 1) = *cur;
                --cur;
            }
            *pos = val;
            ++_finish;
            return pos;
        }
        iterator erase(iterator pos)
        {
            if(!empty())
            {
                iterator cur = pos;
                while(cur != end())
                {
                    *cur = *(cur + 1);
                    ++cur;
                }
                --_finish;
            }
            return pos;
        }
        void swap(vector v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }
        iterator find(T val)
        {
            iterator cur = begin();
            while(cur != end())
            {
                if(*cur == val)
                    return cur;
                ++cur;
            }
            return nullptr;
        }
        size_t size()
        {
            return _finish - _start;
        }
        size_t capacity()
        {
            return _endOfStorage - _start;
        }
        bool empty()
        {
            return size() == 0;
        }
        T& front()
        {
            assert(!empty());
            return _start[0];
        }
        T& back()
        {
            assert(!empty());
            return _start[size() - 1];
        }
        void clear()
        {
            this->~vector();
        }
    private:
        T* _start;
        T* _finish;
        T* _endOfStorage;
    };
}

//接下来课后的任务：实现完成vector
//1. 从零开始，实现到我现在的这个情况
//2. 接着写下去：包括但是不限于：拷贝构造，赋值重载，at， resize， empty, front, back, erase, swap, clear,

//int main_1()
//{
//    my::vector<int> v;
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(4);
//    v.push_back(5);
//    my::vector<int> v1(v);
//    //std::cout << "main_1" << std::endl;
////    for(auto& e : v1)
////    {
////        std::cout << e << " ";
////    }
//    auto pos = v1.find(4);
//    v1.insert(pos, 40);
//    //v = v1;
//    v.resize(10);
//    v.clear();
//    v.push_back(1);
//    auto it = v.begin();
//    while (it != v.end())
//    {
//        std::cout << *it << " ";
//        ++it;
//    }
//    std::cout << std::endl;
//    //std::cout << v1[10] << std::endl;
//    return 0;
//}


//输入：第一行输入m，n，其中m表示有m位客户，n表示客户在n个银行存有资产
//接下来输入m行，每一行有n个数
//输出：最富有的客户的资产数
using namespace std;

int func(vector<vector<int>>& accounts)
{
    int Max = 0;
    for(auto& v : accounts)
    {
        int sum = 0;
        for(auto& e : v)
        {
            sum += e;
        }
        Max = max(Max, sum);
    }
    return Max;
}

int main_1()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> accounts(m);
    for(auto& v : accounts)
    {
        v.resize(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
    }
    
    cout << func(accounts) << endl;

    return 0;
}

