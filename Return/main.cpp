/*
 * main.cpp
 *
 *  Created on: 2014年8月9日
 *  Author: jarek
 *  Brief: 
 */

#include <iostream>
#include <string>

using namespace std;


class Test
{
    public :
    Test()
    {
        cout << "Test Construct " << a << " " << this << endl;
    }

//    Test(const Test& test)
//    {
//        cout << "Test Copy" << a << " " << this << endl;
//    }

    int a;
};

string Create()
{
    string test;
    cout << "Create" << &test << endl;
    test = "5";
    return test;
}

int main()
{
    string test = Create();
    cout <<  &test << endl;
}

