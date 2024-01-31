#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i,times;

    if(argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usaga: %s positive-number\n",argv[0]);
    else
        for ( i = 0; i < times; i++)
            puts("Hello,good lunking!");
        
    return 0;
}
