#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vv;
    vv.resize(n);
    for (auto& e : vv)
    {
        e.resize(2*n-1);
    }
    for (size_t i = 0; i < vv.size(); i++)
    {
        for (size_t j = 0; j < vv[i].size(); ++j)
        {
            vv[i][n - i - 1] = 1;
            vv[i][n - 1 + i] = 1;
        }
    }
    //填充内部数据
    for (size_t i = 0; i < vv.size(); i++)
    {
        for (size_t j = 0; j < vv[i].size(); ++j)
        {
            if (j > n - i - 1 && j < n + i - 1)
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j] + vv[i - 1][j + 1];
            }
        }
    }
    //遍历最后一行找到第一个偶数
    for (size_t i = 0; i < vv[n - 1].size(); i++)
    {
        if (vv[n - 1][i] % 2 == 0)
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}