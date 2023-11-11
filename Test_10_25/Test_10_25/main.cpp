//
//  main.cpp
//  Test_10_25
//
//  Created by zht on 2023/10/25.
//



#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    string s = "hello world!";
//    cout << s.capacity() << ":" << s.size() << ":" << s << endl;
//    s.resize(20);
//    s.reserve(50);
//    cout << s.capacity() << ":" << s.size() << ":" << s << endl;
//    s.clear();
//    s.~basic_string<char>();
//    cout << s << s.capacity() << endl;
    
    //1.
    for(int i = 0; i < s.size(); ++i)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    //2.
    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    //3.
    for(auto& e : s)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}


class string
{
public:
    
private:
    
};


