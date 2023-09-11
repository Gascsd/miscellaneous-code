//
//  main.cpp
//  Test_9_11
//
//  Created by zht on 2023/9/11.
//

#include <iostream>
using namespace std;



template<class T, class Compare = greater<T>>
class HeapSort
{
public:
    HeapSort()
    {
        _arr = new T[4];
        _size = 0;
        _capacity = 4;
    }
    void push(T val)
    {
        if(_size == _capacity)//扩容
        {
            T* tmp = new T[2 * _capacity];
            for(int i = 0; i < _size; ++i)
            {
                tmp[i] = _arr[i];
            }
            delete _arr;
            _arr = tmp;
            _capacity *= 2;
        }
        _arr[_size] = val;
        _size++;
        
        adjustUp(_size - 1);
    }
    void adjustUp(int child)
    {
        int parent = (child - 1) / 2;
        while(child > 0)
        {
            if(Compare()(_arr[parent], _arr[child]))
            {
                swap(_arr[parent], _arr[child]);
                child = parent;
                parent = (child - 1) / 2;
            }
            else
            {
                break;;
            }
        }
    }
    T top()
    {
        return _arr[0];
    }
    void pop()
    {
        if(_size > 0)
        {
            swap(_arr[0], _arr[_size - 1]);
            --_size;
            adjustDown(0);
        }
    }
    void adjustDown(int parent)
    {
        int maxChild = parent * 2 + 1;
        while(maxChild < _size)
        {
            if(maxChild + 1 != _size && Compare()(_arr[maxChild], _arr[maxChild + 1]))
            {
                maxChild++;
            }
            if(Compare()(_arr[parent], _arr[maxChild]))
            {
                swap(_arr[parent], _arr[maxChild]);
                parent = maxChild;
                maxChild = parent * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
    bool empty()
    {
        return _size == 0;
    }
private:
    T* _arr;
    size_t _size;
    size_t _capacity;
};

int main()
{
    HeapSort<int> heap;
    vector<int> v = {2,3,2,4,7,1,5,6,8,3,2,7,89,1,0};
    for(auto& e : v)
    {
        heap.push(e);
    }
    
    while(!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
    return 0;
}
