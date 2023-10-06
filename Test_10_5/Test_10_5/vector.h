//
//  vector.h
//  Test_10_5
//
//  Created by zht on 2023/10/5.
//

#ifndef vector_h
#define vector_h
#include <iostream>
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
        void reserve()
        {
            int nowSize = size();
            int nowCapacity = capacity();
            int newCapacity = nowCapacity == 0 ? 4 : 2 * nowCapacity;
            int* tmp = new T[newCapacity];
            for(int i = 0; i < size(); ++i)
            {
                tmp[i] = _start[i];
            }
            delete _start;
            _start = tmp;
            _finish = _start + nowSize;
            _endOfStorage = _start + newCapacity;
        }
        T& operator[](int pos)
        {
            if(pos <= size())
                return _start[pos];
            else
            {
                std::cout << "访问越界" << std::endl;
                exit(-1);
            }
        }
        void push_back(T val)
        {
            if(_finish == _endOfStorage)
            {
                reserve();
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
                reserve();
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
    private:
        T* _start;
        T* _finish;
        T* _endOfStorage;
    };
}


//接下来课后的任务：实现完成vector
//1. 从零开始，实现到我现在的这个情况
//2. 接着写下去：包括但是不限于：拷贝构造，赋值重载，at， resize， empty, front, back, erase, swap, clear,


#endif /* vector_h */
