//字符串反转
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string s;
//    cin >> s;
//    reverse(s.begin(), s.end());
//    cout << s << endl;
//    return 0;
//}

//公共子串计算
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int getMaxComSubstr(const string& str1, const string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    //所有值初始化为0
    vector<vector<int>> msc(len1, vector<int>(len2, 0));
    int max_len = 0;
    for (int i = 0; i < len1; ++i)
    {
        for (int j = 0; j < len2; ++j)
        {
            //如果当前结尾的字符相等，则在dp[i-1][j-1]的基础上加1
            if (str2[j] == str1[i])
            {
                if (i >= 1 && j >= 1)
                    msc[i][j] = msc[i - 1][j - 1] + 1;
                else
                    msc[i][j] = 1;
                //更新最大值
                if (msc[i][j] > max_len)
                    max_len = msc[i][j];
            }
        }
    }
    return max_len;
}
int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int max_len = getMaxComSubstr(str1, str2);
        cout << max_len << endl;
    }
    return 0;
}