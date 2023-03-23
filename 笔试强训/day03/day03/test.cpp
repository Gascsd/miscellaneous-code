#define _CRT_SECURE_NO_WARNINGS 1



//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    string str, res, cur;
//    cin >> str;
//    res.reserve(str.size());
//    cur.reserve(str.size());
//    for (size_t i = 0; i < str.size(); i++)
//    {
//        while (str[i] >= '0' && str[i] <= '9')
//        {
//            cur += str[i];
//            i++;
//        }
//        if (cur.size() > res.size())
//        {
//            res = cur;
//        }
//        else
//        {
//            cur.clear();
//        }
//    }
//    cout << res << endl;
//    return 0;
//}




    //int compar(void* e1, void* e2)
    //{
    //    return *(int*)e1 - *(int*)e2;
    //}
    //int MoreThanHalfNum_Solution(int* numbers, int numbersLen) {
    //    // write code here
    //    qsort(numbers, numbersLen, sizeof(int), compar);
    //    return numbers[numbersLen / 2];
    //}