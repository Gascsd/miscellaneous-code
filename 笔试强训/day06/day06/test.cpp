#define _CRT_SECURE_NO_WARNINGS 1
//不要二
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int w, h;
//    cin >> w >> h;
//    vector<vector<int>> vv;
//    vv.resize(h);
//    for (size_t i = 0; i < vv.size(); i++)
//    {
//        vv[i].resize(w, 1);
//    }
//    for (size_t i = 0; i < vv.size(); i++)
//    {
//        for (size_t j = 0; j < vv[i].size(); j++)
//        {
//            if (vv[i][j] == 1)
//            {
//                if (j + 2 < w)
//                {
//                    vv[i][j + 2] = 0;
//                }
//                if (i + 2 < h)
//                {
//                    vv[i + 2][j] = 0;
//                }
//            }
//        }
//    }
//    int sum = 0;
//    for (size_t i = 0; i < vv.size(); i++)
//    {
//        for (size_t j = 0; j < vv[i].size(); j++)
//        {
//            sum += vv[i][j];
//        }
//    }
//    cout << sum << endl;
//    return 0;
//}



//把字符串转换成整数
class Solution {
public:
    int StrToInt(string str) {
        //处理符号
        int flag = 1;
        if (str[0] == '-')
        {
            flag = -1;
            str.erase(0, 1);
        }
        if (str[0] == '+')
            str.erase(0, 1);
        //遍历str处理数值
        int sum = 0;
        for (auto e : str)
        {
            if (e < '0' || e > '9')
            {
                return 0;
            }
            sum = sum * 10 + e - '0';
        }
        return sum * flag;

    }
};



