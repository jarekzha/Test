/*
 * main.cpp
 *
 *  Created on: 2014年10月21日
 *  Author: jarek
 *  Brief: 
 */


#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace boost;
using namespace std;

class Number
{
public:
    Number(int n):num(n)
    {
        cout << "Construct " << num << endl;
    }

    virtual ~Number()
    {
        cout << "Deconstruct " << num << endl;
    }

    int Num() const
    {
        return num;
    }

    void Set(int n)
    {
        num = n;
    }

private:
    int num;
};

int main()
{
    {
        Number* p = new Number(10);
        Number* p0 = NULL;
        shared_ptr<const Number> p1(p);
        shared_ptr<Number> p2 = p1;

        Number* praw = p1.get();
        cout << praw->Num() << endl;
        cout << "Use Count " << p1.use_count() << " " << p2.use_count() << endl;
        //p1->Set(11);
        p1.reset();
        cout << "Use Count " << p1.use_count() << " " << p2.use_count() << endl;
        p2.reset();
        cout << "Use Count " << p1.use_count() << " " << p2.use_count() << endl;
    }
    cout << "Scope end" << endl;

    return 0;
}



