/*
 * CGITest.cpp
 *
 *  Created on: 2014年7月16日
 *  Author: jarek
 *  Brief: 
 */


#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

int main(int argc, char* argv[])
{
    const char* optionDes = "c:";
    char str[1024];

    static struct option long_options[] = {
        {"config", 1, 0, 'c'},
    };

    while(1)
    {
        int option_index = 0;
        int c = getopt_long(argc, argv, optionDes, long_options, &option_index);
        if (-1 == c)
            break;

        switch(c)
        {
            case 'c':
                strncpy(str, optarg, sizeof(str));
                break;
        }
    }


    /* Initialization Code */
    int count = 0;

    /* Start of response loop */

    while (FCGI_Accept() >= 0)
    {
        //* body of response loop /*/
        printf("Content-type: text/html\r\n"
               "\r\n"
                ""
                "FastCGI Hello! (C, fcgi_stdio library)"
                "Request number %d running on host %s "
                "Process ID: %d\n"
                "str: %s\n",
                ++count,
                getenv("SERVER_NAME"), getpid(), str);
    }

    printf("Content-type: text/html\r\n"
                   "\r\n"
                    "End");


    /* End of response loop */
    return 0;


}
