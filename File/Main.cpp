#include <stdio.h>
#include <errno.h>
#include <string.h>



int main()
{
    FILE* file = fopen("1/test", "wb");
    if (file == NULL)
    {
        printf("%s", strerror(errno));
    }
}
