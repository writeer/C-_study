#include <stdio.h>

int main(void){
    float sec = 3.156E10;
    float year;
    printf("This is a small program that converts your age time to the corresponding number of seconds\n");
    printf("Please input you're age:");
    scanf("%f",&year);
    printf("How many seconds did you live :%fs",year * sec);
    getchar();
    getchar();
    return 0;
}