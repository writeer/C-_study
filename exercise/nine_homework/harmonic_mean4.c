#include <stdio.h>
double har_mean(double,double);

int main(void){
    double num,numb;
    printf("这个程序会计算两个数的调和平均数\n");
    printf("Enter two number:");
    scanf("%lf %lf",&num,&numb);
    printf("它们的调和平均数是： %g",har_mean(num,numb));
    fflush(stdin);
    getchar();
    return 0;
}

double har_mean(double n,double m){
    double sum;
    n = 1 / n;
    m = 1 / m;
    sum = (n + m) / 2;
    sum = 1 / sum;
    return sum;
}