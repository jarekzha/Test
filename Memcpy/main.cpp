/*
 * main.cpp
 *
 *  Created on: 2014年10月25日
 *  Author: jarek
 *  Brief: 
 */
#include <iostream>
#include <string.h>

using namespace std;


int main()
{
    char a[10] = "1234565";
    char b[10];
    int c = 100;
    memcpy(b, a, sizeof(a));
    c-= 10;

    cout << b << " " << c << endl;

    return 0;
}


