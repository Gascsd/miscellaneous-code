//
//  main.cpp
//  Test_10_20
//
//  Created by zht on 2023/10/20.
//

#include <iostream>
using namespace std;

class base1
{
public:
    ~base1()
    {
        cout << "~base1" << endl;
    }
private:
    int _b1;
};
class base2
{
public:
    ~base2()
    {
        cout << "~base2" << endl;
    }
private:
    int _b2;
};
class device : public base1, public base2
{
public:
    ~device()
    {
        cout << "~device" << endl;
    }
private:
    int _d;
};
class myString : public string
{
public:
    myString(string s, int size = 10) :string(s),  _size(size)
    {
        
    }
    int size() const
    {
        return _size;
    }
private:
    int _size;
};
int main()
{
    device dd;
    myString s("hello");
    cout << s.size() << endl;
    return 0;
}
