//
//  main.cpp
//  Test_11_9
//
//  Created by zht on 2023/11/9.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    cout << argc << endl;
    for(int i = 0; i < argc; ++i)
    {
        cout << i << ":" << argv[i] << endl;
    }
    return 0;
}
