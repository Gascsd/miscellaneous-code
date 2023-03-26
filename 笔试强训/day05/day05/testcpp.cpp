#define _CRT_SECURE_NO_WARNINGS 1
//统计回文
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//bool isReverse(string& s)
//{
//    string s1(s);
//    reverse(s1.begin(), s1.end());
//    if (s1 == s)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    int count = 0;
//    string a, b;
//    cin >> a >> b;
//    for (size_t i = 0; i <= a.size(); i++)
//    {
//        string cur(a);
//        cur.insert(i, b);
//        if (isReverse(cur))
//            count++;
//    }
//    cout << count << endl;
//    return 0;
//}



//最大连续和
#include <iostream>
#include <vector>
using namespace std;
int GetMax(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int size = 0;
    cin >> size;
    vector<int> nums(size);
    for (size_t i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    int sum, max;
    max = sum = nums[0];
    for (int i = 1; i < size; i++)
    {
        sum = GetMax(sum + nums[i], nums[i]);
        if (sum > max)
            max = sum;
    }
    cout << max << endl;
    return 0;
}