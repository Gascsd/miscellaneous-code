//
//  main.cpp
//  Test_11_12
//
//  Created by zht on 2023/11/12.
//

//#include <iostream>
//#include <vector>
//using namespace std;
////若 (K−1) 在第一行但不在最后一列，则将 K 填在最后一行， (K−1) 所在列的右一列；
////若 (K−1) 在最后一列但不在第一行，则将 K 填在第一列， (K−1) 所在行的上一行；
////若 (K−1) 在第一行最后一列，则将 K 填在 (K−1) 的正下方；
////若 (K−1) 既不在第一行，也不在最后一列，如果 (K−1) 的右上方还未填数，则将 K 填在 (K−1) 的右上方，否则将 K 填在 (K−1) 的正下方。
//int main()
//{
//    int n;
//    cin >> n;
//    vector<vector<int>> ret(n, vector<int>(n));
//    ret[0][n / 2] = 1;
//    pair<int, int> pos = {0, n / 2};
//    for(int k = 2; k <= n*n; ++k)
//    {
//        if(pos.first == 0 && pos.second != n - 1)
//        {
//            ret[n - 1][pos.second + 1] = k;
//            pos = {n - 1, pos.second + 1};
//        }
//        else if(pos.second == n - 1 && pos.first != 0)
//        {
//            ret[pos.first - 1][0] = k;
//            pos = {pos.first - 1, 0};
//        }
//        else if(pos.first == 0 && pos.second == n - 1)
//        {
//            ret[pos.first + 1][pos.second] = k;
//            pos = {pos.first + 1, pos.second};
//        }
//        else
//        {
//            if(ret[pos.first - 1][pos.second + 1] == 0)
//            {
//                ret[pos.first - 1][pos.second + 1] = k;
//                pos = {pos.first - 1, pos.second + 1};
//            }
//            else
//            {
//                ret[pos.first + 1][pos.second] = k;
//                pos = {pos.first + 1, pos.second};
//                
//            }
//        }
//    }
//    for(auto& v : ret)
//    {
//        for(auto& e : v)
//        {
//            cout << e << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}




//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n, x, y;
//    cin >> n;
//    vector<vector<int>> input(n, vector<int>(4));
//    vector<vector<int>> floor(200, vector<int>(200));
//    for(auto& v : input)
//    {
//        cin >> v[0] >> v[1] >> v[2] >> v[3];
//    }
//    cin >> x >> y;
//    for(int m = 0; m < n; ++m)
//    {
//        for(int i = input[m][0]; i <= input[m][0] + input[m][2]; ++i)
//        {
//            for(int j = input[m][1]; j <= input[m][1] + input[m][3]; ++j)
//            {
//                floor[i][j] = m + 1;
//            }
//        }
//    }
//    if(x > 200 || y > 200 || floor[x][y] == 0)
//    {
//        cout << -1;
//    }
//    else
//    {
//        cout << floor[x][y];
//    }
//    return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
////找到某一位置下的最长滑坡
//int GetDistance(vector<vector<int>>& floor, pair<int,int> pos)
//{
//    int ret = 1;
//    int x[4] = {1, -1, 0, 0};
//    int y[4] = {0, 0, 1, -1};
//    for(int i = 0; i < 4; ++i)
//    {
//        if(pos.first + x[i] >= 0 && pos.first + x[i] <= (int)floor.size() - 1 && pos.second + y[i] >= 0 && pos.second + y[i] <= (int)floor[0].size() - 1)//判断点的合法性
//        {
//            if(floor[pos.first + x[i]][pos.second + y[i]] < floor[pos.first][pos.second])//判断高度是否合法
//            {
//                int tmp = GetDistance(floor, {pos.first + x[i], pos.second + y[i]}) + 1;
//                ret = max(ret, tmp);
//            }
//            //ret = max(ret, GetDistance(floor, {pos.first + x[i], pos.second + y[i]}));
//        }
//    }
//    return ret;
//}
//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    if(m == 1 && n == 1)
//    {
//        cout << 1;
//        return 0;
//    }
//    vector<vector<int>> floor(m, vector<int>(n));
//    vector<vector<int>> dp(m, vector<int>(n));
//    for(auto& v : floor)
//    {
//        for(auto& e : v)
//        {
//            cin >> e;
//        }
//    }
//    for(int i = 0; i < m; ++i)
//    {
//        for(int j = 0; j < n; ++j)
//        {
//            dp[i][j] = GetDistance(floor, {i, j});
//        }
//    }
//    int ret = 0;
//    for(auto& v : dp)
//    {
//        for(auto& e : v)
//        {
//            ret = max(ret, e);
//        }
//    }
//    cout << ret;
//    return 0;
//}


