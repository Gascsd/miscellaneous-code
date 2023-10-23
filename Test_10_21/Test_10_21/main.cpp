//
//  main.cpp
//  Test_10_21
//
//  Created by zht on 2023/10/21.
//

#include <iostream>
using namespace std;
//int main()
//{
//    int t,x;
//    cin >> t;
//    while(t--)
//    {
//        cin >> x;
//        //x表示大象和朋友之间的距离
//        int ret = 0;
//        while(x > 0)
//        {
//            if(x >= 10)
//            {
//                x -= 10;
//                ret++;
//            }
//            else if(x >= 5)
//            {
//                x -= 5;
//                ret++;
//            }
//            else
//            {
//                x -= 1;
//                ret++;
//            }
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}


//int main()
//{
//    int t,x;
//    cin >> t;
//    while(t--)
//    {
//        cin >> x;
//        //x表示大象和朋友之间的距离
//        int ret = 0;
//        while(x > 0)
//        {
//            if(x >= 10)
//            {
//                ret += x / 10;
//                x %= 10;
//            }
//            else if(x >= 5)
//            {
//                ret++;
//                x -= 5;
//            }
//            else//x > 0 && x < 5
//            {
//                ret += x;
//                x = 0;
//            }
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}


//int main()
//{
//    int t;
//    cin >> t;
//    while(t--)
//    {
//        int m, n, u, f, d;
//        cin >> m >> n >> u >> f >> d;
//        char* str = new char[n];
//        for(int i = 0; i < n; i++)
//        {
//            cin >> str[i];
//        }
//        int i = 0;
//        int ret = 0;
//        int flag = 1;
//        while(m > 0)
//        {
//            while (m > 0 && i < n)
//            {
//                if(str[i] == 'u')//上坡
//                {
//                    if(m >= u) 
//                    {
//                        ret++;
//                        m -= u;
//                    }
//                    else break;
//                }
//                else if(str[i] == 'f')//平地
//                {
//                    if(m >= f) 
//                    {
//                        ret++;
//                        m -= f;
//                    }
//                    else break;
//                }
//                else if(str[i] == 'd')//下拨
//                {
//                    if(m >= d) 
//                    {
//                        ret++;
//                        m -= d;
//                    }
//                    else break;
//                }
//                else
//                {
//                    //cout << "error" << endl;
//                }
//                i += flag;
//            }
//            flag *= -1;
//            i = n - 1;
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}

//#include <vector>
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<vector<int>> ret;
//    ret.resize(n);
//    for(auto& v : ret)
//    {
//        v.resize(n);
//    }
//    //填充其中一个小三角形（1/4三角形）
//    for(int i = 0; i <= (n-1)/2; ++i)
//    {
//        for(int j = i; j <= (n - 1) / 2; ++j)
//        {
//            ret[i][n - j - 1] = ret[i][j] = j - i;
//        }
//    }
//    //对称
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = 0; j < n; ++j)
//        {
//            ret[j][i] = ret[i][j];
//        }
//    }
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = 0; j < n - i; ++j)
//        {
//            ret[n-i-1][n-j-1] = ret[i][j];
//        }
//    }
//    //打印矩阵
//    for(auto& v : ret)
//    {
//        for(auto& e : v)
//        {
//            cout << e << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    return 0;
//}


