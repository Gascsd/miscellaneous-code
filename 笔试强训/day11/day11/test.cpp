//最近公共祖先
//#include <iostream>
//using namespace std;
//class LCA {
//public:
//    inline int GetMax(int a, int b)
//    {
//        return a > b ? a : b;
//    }
//    inline int GetMin(int a, int b)
//    {
//        return a < b ? a : b;
//    }
//    int getLCA(int a, int b) {
//        // write code here
//        if (a == b)
//            return a;
//        int max = GetMax(a, b);
//        int min = GetMax(a, b);
//        while (max != min)
//        {
//            int tmp = max / 2;
//            max = GetMax(tmp, min);
//            min = GetMin(tmp, min);
//        }
//        return max;
//    }
//};
//
//int main()
//{
//    int a, b;
//    cin >> a >> b;
//    int ret = LCA().getLCA(a, b);
//    cout << ret << endl;
//    return 0;
//}

//求最大连续bit数
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int count = 0, maxCount = 0;
    while (n)
    {
        if (n & 1)
        {
            count++;
            maxCount = max(count, maxCount);
        }
        else
        {
            count = 0;
        }
        n >>= 1;
    }
    cout << maxCount << endl;
    return 0;
}



