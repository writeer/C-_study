#include <stdio.h>

double min(double,double);

int main(void){
    double num,numb;
    printf("Enter two numbers:");
    scanf("%lf %lf",&num,&numb);
    printf("The small number:%g",min(num,numb));
    fflush(stdin);
    getchar();
    return 0;
}

double min(double n,double m){
    return (( n > m ) ? m : n);
}