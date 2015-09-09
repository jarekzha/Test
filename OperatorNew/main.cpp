/*
 * main.cpp
 *
 *  Created on: 2014年7月11日
 *  Author: jarek
 *  Brief: 
 */
#include <new>
#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

class Base
{
public:
    Base()
    {
        base = 0;
        cout << typeid(*this).name() << endl;
    }
    virtual             ~Base(){}

    void*               operator new(size_t size)
    {
        cout << size << endl;
        return ::operator new(size);
    }

    void                operator delete(void* ptr)
    {
        ::operator delete(ptr);
    }

    void Test(){}
    void Test2() {cout << "sdf";}


private:
    int                 base;
};

class Derived : public Base
{
public:
private:
    int                 derived[10];
};

/**
 * 获取变量的真实类型的名称
 */
template <typename Type>
std::string VariableTypeName(const Type& value)
{
    char buffer[1024];
    size_t size = sizeof(buffer);
    int status = 0;
    const char* name = typeid(value).name();
    char* realName = abi::__cxa_demangle(name, buffer, &size, &status);
    return std::string(realName);
}

int main()
{
    Base* obj1 = new Base;
    Base* obj2 = new Derived;
    delete obj1;
    delete obj2;
    cout << VariableTypeName(&Base::Test) << "  " << &Base::Test << endl;
    cout << VariableTypeName(&Base::Test2) << "  " << &Base::Test2 << endl;
    return 0;
}

