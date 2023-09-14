//
//  main.cpp
//  Test_9_14
//
//  Created by zht on 2023/9/14.
//

#include <iostream>
using namespace std;

//struct Student
//{
//    char name[15];
//    int age;
//};
//
//union UN
//{
//    int i;
//    char c;
//};
//int main()
//{
//    UN un;
//    Student s1 = {"zhangsan", 18};
//    cout << s1.name << " " << s1.age << endl;
//    cout << sizeof(UN) << " " << sizeof(un) << endl;
//    return 0;
//}

#define FILENAME "log.txt"
int main()
{
    FILE *fp = fopen(FILENAME, "w");
    if(nullptr == fp)
    {
        perror("fopen");
        return 1;
    }
    cout << "open success" << endl;
    int cnt = 5;
    while(cnt--)
    {
        cout << "write sucess" << endl;
        fprintf(fp, "hello world! %d", cnt);
    }
    return 0;
}
