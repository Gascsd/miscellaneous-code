//
//  main.cpp
//  Test_10_2
//
//  Created by zht on 2023/10/2.
//

#include <iostream>
using namespace std;

#define N 10;

class SeqListStatic//静态的顺序表
{
public:
    SeqListStatic()
    {
        _arr = new int[10];
        _size = 0;
    }
    SeqListStatic(const SeqListStatic& obj)
    {
        _arr = new int[10];
        for(int i = 0; i < 10; ++i)
        {
            _arr[i] = obj._arr[i];
        }
        _size = obj._size;
    }
    SeqListStatic& operator=(const SeqListStatic& obj)
    {
        if(this != &obj)
        {
            for(int i = 0; i < 10; ++i)
            {
                _arr[i] = obj._arr[i];
            }
            _size = obj._size;
        }
        return *this;
    }
    ~SeqListStatic()
    {
        delete[] _arr;
        _arr = nullptr;
        _size = 0;
    }
    bool push(int val)
    {
        if(_size == 10)
        {
            cout << "容量已经满了" << endl;
            return false;
        }
        else
        {
            _arr[_size++] = val;
            return true;
        }
    }
    void Print()
    {
        for(int i = 0; i < _size; ++i)
        {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }
private:
    int* _arr;
    int _size;
};

void test()
{
    SeqListStatic l1;
    SeqListStatic l2;
    l2 = l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(4);
    l1.push(5);
    l1.push(6);
    l1.push(7);
    l1.Print();
    l1.push(8);
    l1.push(9);
    cout << l1.push(10) << endl;
    cout << l1.push(11) << endl;
    l1.Print();
}

int main_1();
int main_2();


int main()
{
    main_2();
    return 0;
}


