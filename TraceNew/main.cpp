/*
 * main.cpp
 *
 *  Created on: 2014年7月12日
 *  Author: jarek
 *  Brief: 
 */
#include <stdio.h>
#include <typeinfo>
class A
{
public:
    A(int a)
    {
        value = a;
    }

    A(const A& a)
    {
        value = a.value;
        printf("A copy\n");
    }

    int value;
};

class B
{
public:
	B(){b= 0;}
	B(A& a)
	{
	    printf("B ctor a %lu \n", (unsigned long)&a);
	    b = a.value;
	}
	int b;
};

template <typename T>
class Creator
{
public:
    Creator(){}

    template<typename P>
    T* operator()(P t)
    {
        return new T(t);
    }

	T* operator()()
	{
		return new T();
	}
};

template <typename T>
T* New()
{
	printf("===new %s\n", typeid(T).name());
	return new T;
}


template <typename T, typename P>
T* New(P& p)
{	
	printf("===new ref %s %s\n", typeid(T).name(), typeid(p).name());
	return new T(p);
}

template <typename T, typename P>
T* New(const P& p)
{
    printf("===new copy %s %s\n", typeid(T).name(), typeid(p).name());
    return new T(p);
}

template <typename T>
void Delete(T* t)
{
	printf("===delete %s\n", typeid(T).name());
	delete t;
}

template <typename T>
T* NewArray(int count)
{
    printf ("===new array %s %d\n", typeid(T).name(), count);
    return new T[count];
}

template <typename T>
void DeleteArray(T* t)
{
	printf("===delete %s %d\n", typeid(T).name(), (int)(sizeof(t)/sizeof(T)));
	delete[] t;
}


int main()
{
 //   A* a = Creator<A>()(1);
//	B* b = Creator<B>()();
 //   delete a;
//	delete b;
	
	A* new_a = New<A>(1);
	printf("--a %lu \n", (unsigned long)&(*new_a));
	B* new_b = New<B>(*new_a);
	Delete(new_a);
	Delete(new_b);
	
/*	B* array = NewArray<B>(100);
	printf("B size:%d array size:%d\n", (int)sizeof(B), (int)(sizeof(array)));
	DeleteArray(array);
*/
    return 0;
}
