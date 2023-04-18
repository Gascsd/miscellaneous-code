#include <iostream>
#include <string>
using namespace std;


//union _Bxty
//{ // storage for small buffer or pointer to larger one
//	value_type _Buf[_BUF_SIZE];
//	pointer _Ptr;
//	char _Alias[_BUF_SIZE]; // to permit aliasing
//} _Bx;


//int main()
//{
//	string s1("11111");
//	string s2("22222222222222222222222222222222222");
//	cout << "s1: " << sizeof(s1) << endl;
//	cout << "s2: " << sizeof(s2) << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	string s2(s1);
//	return 0;
//}

#include <iostream>
#include <string>
#include <time.h>
using namespace std;
int main()
{
    string s(1024 * 1024 * 10, 'x');
    long begin = clock();
    for (int i = 0; i < 100; i++)
    {
        string tmp = s;
    }
    int end = clock();
    cout << end - begin << endl;
    return 0;
}
