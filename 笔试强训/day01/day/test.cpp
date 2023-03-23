#define _CRT_SECURE_NO_WARNINGS 1

//删除公共字符
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string s1, s2;
//    getline(cin, s1);
//    getline(cin, s2);
//    for (auto e : s2)
//    {
//        size_t pos = 0;
//        while (pos != string::npos)
//        {
//            pos = s1.find(e, pos);
//            if (pos != string::npos)
//                s1.erase(pos, 1);
//        }
//    }
//    cout << s1 << endl;
//    return 0;
//}

//组队竞赛
//解法一：只能过10%的测试用例
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//int compar(const void* p1, const void* p2)
//{
//    return *(int*)p1 - *(int*)p2;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    int* a_val = new int[3 * n];
//    for (int i = 0; i < 3 * n; ++i)
//    {
//        cin >> a_val[i];
//    }
//    qsort(a_val, 3 * n, sizeof(int), compar);
//    int sum = 0;
//    for (int i = n; i < 2 * n; ++i)
//    {
//        sum += a_val[i];
//    }
//    cout << sum << endl;
//    return 0;
//}


//解法二：（待定）！！
#include <iostream>
#include <stdlib.h>
using namespace std;
int compar(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}
int main()
{
    int n;
    cin >> n;
    long* a_val = new long[3 * n];
    for (int i = 0; i < 3 * n; ++i)
    {
        cin >> a_val[i];
    }
    qsort(a_val, 3 * n, sizeof(long), compar);
    long sum = 0;
    for (int i = n; i < 2 * n; ++i)
    {
        sum += a_val[i];
    }
    cout << sum << endl;
    return 0;
}


