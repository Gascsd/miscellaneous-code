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

using namespace std;

int GetMaxFactor(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
            return n / i;
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a = 0;
    int count = 0;
    while (n < m)
    {
        a = GetMaxFactor(n);
        n += a;
        ++count;
    }

    return 0;
}



