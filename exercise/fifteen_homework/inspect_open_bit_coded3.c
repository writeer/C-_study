#include <stdio.h>
#include <stdlib.h>

int open_bit_number(int n);

int main(int argc, char const *argv[])
{
    int count = 0;
    if (argc == 2)
    {
        count = open_bit_number(atoi(argv[1]));
    }
    else{
        printf("input error \n");
        exit(EXIT_FAILURE);
        }
    printf("open bit is: %d",count);
    return 0;
}

int open_bit_number(int n){
    int count = 0;
    int size = sizeof(int) * 8;
    for (int i = 0; i < size; i++,n >>= 1)
        if ((n & 01))
            count++;
   
    return count;
}