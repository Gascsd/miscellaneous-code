//另类加法
//class UnusualAdd {
//public:
//    int addAB(int A, int B) {
//        // write code here
//        if (A == 0)
//            return B;
//        if (B == 0)
//            return A;
//        int a = A ^ B;
//        int b = (A & B) << 1;
//        return addAB(a, b);
//    }
//};


//走方格的方案数
#include <iostream>
using namespace std;

int func(int m, int n)
{
    if (m == 0 || n == 0)
        return 1;
    return func(m - 1, n) + func(m, n - 1);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int ret = func(n, m);
    cout << ret << endl;
}

