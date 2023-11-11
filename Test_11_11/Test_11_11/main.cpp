//
//  main.cpp
//  Test_11_11
//
//  Created by zht on 2023/11/11.
//

#include <iostream>

int main(int argc, const char * argv[]) 
{
    for(int i = 0; i < argc; ++i)
    {
        std::cout << i << ":" << argv[i] << std::endl;
    }
    return 0;
}
