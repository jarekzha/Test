/*
 * main.cpp
 *
 *  Created on: 2014年8月4日
 *  Author: jarek
 *  Brief: 
 */


#include <stddef.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;



void print(const char* vec[])
{
    for (size_t i = 0; i < 2; ++i)
    {
        cout << vec[i] << endl;
    }
}

int main()
{
    string str = "123";

    str += '\0';
    str += '\0';

    str += "32";

    str += '\0';
    str += '0';

    cout << str <<endl;
    cout << str.size() << endl;

    stringstream strStream(str);
//    for (size_t i = 0; i < str.size(); ++i)
//    {
//        strStream.put(str[i]);
//    }
    cout << strStream.str() <<  endl;

    const char* vec[]={"aaa", "bbb"};
    print(vec);

    return 0;
}
