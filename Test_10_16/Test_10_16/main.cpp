//
//  main.cpp
//  Test_10_16
//
//  Created by zht on 2023/10/16.
//

#include <iostream>
using namespace std;

int a[105];//测试点个数
int b[105];//通过的个数

int main()
{
    int n = 0, t = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }
    cin >> t;
    for(int i = 0; i < n; ++i)
    {
        int tmp = 100 / a[i];//求单个测试点分数
        ans += tmp * b[i];//加上当前题目得分
    }
    if(ans >= t)
    {
        cout << "Already Au." << endl;
    }
    else
    {
        t -= ans;//求Au差的分数
        for(int i = 0; i < n; ++i)
        {
            if(a[i] == b[i])//当前题目没有更多分数可得
            {
                cout << "NaN" << endl;
            }
            else
            {
                int tmp = 100 / a[i];//求单个测试点分数
                if(t > tmp * (a[i] - b[i]))//将当前题目所有得分都得到之后不能Au的情况
                    cout << "NaN" << endl;
                else
                {
                    cout << (t + tmp - 1)/ tmp << endl;//
                }
            }
        }
    }
    return 0;
}
