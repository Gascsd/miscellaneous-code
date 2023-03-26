#define _CRT_SECURE_NO_WARNINGS 1
//计算糖果
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int A, B, C;
//    int val[4];
//    for (int i = 0; i < 4; i++)
//    {
//        cin >> val[i];
//    }
//    A = (val[0] + val[2]) / 2;
//    B = (val[2] - val[0]) / 2;
//    C = val[3] - B;
//    if (B - C == val[1])
//        cout << A << " " << B << " " << C << endl;
//    else
//        cout << "No" << endl;
//    return 0;
//}



//进制转换
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int m, n, flag = 1;
    cin >> m >> n;
    if (m < 0)
    {
        flag = -1;
        m = 0 - m;
    }

    string s, tab = "0123456789ABCDEF";
    while (m)
    {
        s += tab[m % n];
        m /= n;
    }
    if (flag == -1)
        s += '-';

    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
