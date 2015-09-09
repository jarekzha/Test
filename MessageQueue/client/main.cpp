/*
 * main.cpp
 *
 *  Created on: 2014年10月28日
 *  Author: jarek
 *  Brief: 
 */

#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;
using namespace boost::interprocess;

int main()
{
    message_queue mq(open_only, "mq");

    for (int i = 0; i < 10000; ++i)
    {

        mq.send(&i, sizeof(int), i%2);
    }

    return 0;
}

