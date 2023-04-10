//汽水瓶
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        if (n != 0)
//            cout << n / 2 << endl;
//        else
//            break;
//    }
//    return 0;
//}



//查找两个字串a，b的最长公共子串
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string GetComSubstr(string& s1, string s2)
{
    if (s1.size() > s2.size())
    {
        s1.swap(s2);
    }
    int start = 0, max_length = 0;
    vector<vector<int>> MSC(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i < s1.size(); ++i)
    {
        for (int j = 1; j < s2.size(); ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                MSC[i][j] = MSC[i - 1][j - 1] + 1;
            //更新最大长度
            if (MSC[i][j] > max_length)
            {
                max_length = MSC[i][j];
                start = i - max_length;
            }
        }
    }
    return s1.substr(start, max_length);
}
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        string ret = GetComSubstr(a, b);
        cout << ret << endl;
    }

    return 0;
}