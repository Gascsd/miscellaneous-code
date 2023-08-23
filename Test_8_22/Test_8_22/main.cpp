//
//  main.cpp
//  Test_8_22
//
//  Created by zht on 2023/8/22.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    //找VK，并标记
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'V' && s[i+1] == 'K')
        {
            count++;
            s[i] = 'v';
            s[i+1] = 'k';
        }
    }
    //找到一个VV或KK并更改，然后count++
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == s[i+1])
        {
            count++;
            break;
        }
    }
    cout << count;
    return 0;
}
