//小易的升级之路
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int MaxFactor(int a, int b)
//{
//    //     int max = a > b ? a : b;
//    int Max = max(a, b);
//    //     int min = a < b ? a : b;
//    int Min = min(a, b);
//    int tmp;
//    while (Min)
//    {
//        tmp = Max - Min;
//        Max = max(Min, tmp);
//        Min = min(Min, tmp);
//    }
//    return Max;
//}
//int main()
//{
//    int n, a;
//    while (cin >> n >> a)
//    {
//        int c = a;
//        vector<int> b(n);
//        for (size_t i = 0; i < n; ++i)
//        {
//            cin >> b[i];
//        }
//        for (auto e : b)
//        {
//            if (e <= c)
//            {
//                c += e;
//            }
//            else
//            {
//                c += MaxFactor(c, e);
//            }
//        }
//        cout << c << endl;
//    }
//    return 0;
//}



//找出字符串中第一个字只出现一次的字符
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int* hash = new int[26];
    memset(hash, 0, 26 * sizeof(int));
    for (auto e : s)
    {
        hash[e - 'a']++;
    }
    for (auto e : s)
    {
        if (hash[e - 'a'] == 1)
        {
            cout << e << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}