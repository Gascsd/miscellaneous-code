//二进制插入
//#include <iostream>
//using namespace std;
//
//class BinInsert {
//public:
//    int binInsert(int n, int m, int j, int i) {
//        // write code here
//        m <<= j;
//        //std::cout << m << std::endl;
//        int ret = m | n;
//        return ret;
//    }
//};
//
//int main()
//{
//    cout << BinInsert().binInsert(1024, 19, 2, 6) << endl;
//    return 0;
//}


//查找组成一个偶数最接近的两个素数
#include <iostream>
using namespace std;
bool is_prime(int n)
{
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n = 0;
    cin >> n;
    for (int i = n / 2; i >= 2; i--)
    {
        if (is_prime(i) && is_prime(n - i))
        {
            cout << min(i, n - i) << endl;
            cout << max(i, n - i) << endl;
            break;
        }
    }
    return 0;
}