#define _CRT_SECURE_NO_WARNINGS 1

//排序子序列
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int* a = new int[n];
//    int i = 0, count = 0;
//    for (i = 0; i < n; ++i)
//    {
//        cin >> a[i];
//    }
//    i = 0;
//    while (i < n)
//    {
//        if (a[i] < a[i + 1])
//        {
//            i++;
//            count++;
//            while (i < n && a[i] <= a[i + 1])
//            {
//                i++;
//            }
//        }
//        else if (a[i] > a[i + 1])
//        {
//            i++;
//            count++;
//            while (i < n && a[i] >= a[i + 1])
//            {
//                i++;
//            }
//        }
//        i++;
//    }
//    cout << count << endl;
//    return 0;
//}



//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string s;
//    getline(cin, s);
//    //反转整个字符串
//    reverse(s.begin(), s.end());
//    //反转每个单词
//    auto start = s.begin();
//    while (start != s.end())
//    {
//        auto end = start;
//        while (end != s.end() && *end != ' ')
//            end++;
//        reverse(start, end);
//        if (end != s.end())
//            start = end + 1;
//        else
//            start = end;
//    }
//    cout << s << endl;
//    return 0;
//}


//倒置字符串
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;
	return 0;
}
