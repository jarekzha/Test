/*
 * main.cpp
 *
 *  Created on: 2014年10月20日
 *  Author: jarek
 *  Brief: 
 */


#include <iostream>
#include <sstream>

using namespace std;

enum Number
{
    Zero = 0,
    One = 1,
    Two = 2,
};

int main()
{
    stringstream Stream("1");
    Number num = One;
  //  Stream >> num;

    cout << num << endl;

    return 0;
}

