//两种排序方法
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//bool is_length(vector<string> v)
//{
//    for (size_t i = 0; i < v.size() - 1; ++i)
//    {
//        if (v[i].size() > v[i + 1].size())
//            return false;
//    }
//    return true;
//}
//bool is_dic(vector<string> v)
//{
//    for (size_t i = 0; i < v.size() - 1; ++i)
//    {
//        if (v[i] > v[i + 1])
//            return false;
//    }
//    return true;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    vector<string> v;
//    v.reserve(n);
//    string input;
//    for (int i = 0; i < n; i++)
//    {
//        input.resize(0);
//        cin >> input;
//        v.push_back(input);
//    }
//    if (is_dic(v) && is_length(v))
//    {
//        cout << "both" << endl;
//    }
//    else if (is_dic(v) && !is_length(v))
//    {
//        cout << "lexicographically" << endl;
//    }
//    else if (is_length(v) && !is_dic(v))
//    {
//        cout << "length" << endl;
//    }
//    else if (!is_length(v) && !is_dic(v))
//    {
//        cout << "none" << endl;
//    }
//    return 0;
//}

//求最小公倍数
#include <iostream>
using namespace std;

int GetMax(int a, int b)
{
	return a > b ? a : b;
}
int GetMin(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int a, b;
	cin >> a >> b;
	int max = GetMax(a, b);
	int min = GetMin(a, b);
	while (min)
	{
		int tmp = max - min;
		max = GetMax(tmp, min);
		min = GetMin(tmp, min);
	}
	int ret = a * b / max;
	cout << ret << endl;
	return 0;
}