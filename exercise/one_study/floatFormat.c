#include <stdio.h>

int main(void){
    float num=64.250;
    printf("Enter a floating-point value:%.2f\n",num);
    printf("fixed-point notation:%f\n",num);
    printf("exponential notation:%e\n",num);
    printf("p notation:%a",num);
    getchar();
    return 0;
}