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
#include <assert.h>

using namespace std;
using namespace boost::interprocess;

int main()
{
    message_queue::remove("mq");

    return 0;
}


