//参数解析

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//void Interpreter(string& input, vector<string>& v)
//{
//    bool flag = false;//标志是否出现左引号
//
//    for (size_t i = 0, j = 0; i < input.size(); ++i)
//    {
//        if (!flag)
//        {
//            if (input[i] == '"')
//            {
//                flag = true;
//            }
//            else if (input[i] == ' ' && !flag)
//            {
//                j++;
//                v.push_back(string());
//            }
//            else
//            {
//                v[j].push_back(input[i]);
//            }
//        }
//        else
//        {
//            if (input[i] != '"')
//                v[j].push_back(input[i]);
//            else
//                flag = false;
//        }
//        
//    }
//}
//int main()
//{
//    string input;
//    // string input = "xcopy /s c:\\\\ d:\\\\e";
//    //xcopy /s "C:\\program files" "d:\"
//    getline(cin, input);
//
//    vector<string> v(1);
//    Interpreter(input, v);
//    cout << v.size() << endl;
//    for (auto e : v)
//    {
//        cout << e << endl;
//    }
//    return 0;
//}

//跳石板
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void get_div(int num, vector<int>& div)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            div.push_back(i);
            if (i != num / i)
                div.push_back(num / i);
        }
    }
}
int Jump(int n, int m)
{
    vector<int> step(m + 1, -1);//-1表示不能够跳到
    step[n] = 0;//初始化当前位置
    for (int i = n; i <= m; i++)
    {
        if (step[i] == -1)
            continue;
        vector<int> div;
        get_div(i, div);
        for (size_t j = 0; j < div.size(); ++j)
        {
            //同一个位置被多种走法走到，找最小的方法
            if (div[j] + i <= m && step[div[j] + i] != -1)
            {
                step[div[j] + i] = step[div[j] + i] < step[i] + 1 ? step[div[j] + i] : step[i] + 1;
            }
            else if (div[j] + i <= m)
            {
                step[div[j] + i] = step[i] + 1;
            }
        }
    }
    return step[m];
}
int main()
{
    int n, m;
    cin >> n >> m;
    int min_step = Jump(n, m);
    cout << min_step << endl;
    return 0;
}



