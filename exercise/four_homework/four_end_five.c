#include <stdio.h>
#define BOOK "war and Peace"

int main(void){
    float cost = 12.99;
    float percent = 80.0;
    printf("This is copy of %s sells for $%2.2f.\n",BOOK,cost);
    printf("that is %2.0f%% of list",percent);
    getchar();
return 0;
}