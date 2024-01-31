//指针地址
#include <stdio.h>
#define SIZE 4
int main(void){
    short dates[SIZE];
    short * pti;
    short index;
    double billes[SIZE];
    double * ptf;
    pti = dates;
    ptf = billes;
    printf("%23s %15s\n","short","double");
    for ( index = 0; index < SIZE; index++)
    {
        printf("pointers + %d: %10p %10p\n",index,pti + index,ptf +index);
    }
    getchar();
    return 0;
}  