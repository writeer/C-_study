#include <stdio.h>

int main(void){
    float cm = 2.54;
    float in;
    printf("Please input your height(In inches):");
    scanf("%f",&in);
    printf("\nyour height transformation cm to:%f cm",cm * in);
    fflush(stdin);
    getchar();
    return 0;
}