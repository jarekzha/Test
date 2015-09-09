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
    message_queue mq(open_or_create, "mq", 20, sizeof(int));

    int number = 0;
    int oldNumber = 0;
    size_t recvSize = 0;
    unsigned priority = 0;
    while (true)
    {
        mq.receive(&number, sizeof(int), recvSize, priority);
       // assert(number >= oldNumber);

        oldNumber = number;

        assert(recvSize == sizeof(int));
        cout << number << endl;
    }

    message_queue::remove("mq");

    return 0;
}


