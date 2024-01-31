#include <stdio.h>
#include <stdarg.h>
double sum(int,...);

int main(void)
{
    double s, t;
    s = sum(3, 1.1, 2.5,13.3);
    t = sum(6, 1.1, 2.1 ,13.1, 4.1, 5.1, 6.1);
    printf("return value for sum(3, 1.1, 2.5, 13.3):            %g\n",s);
    printf("return value for sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n",t);
    getchar();
    return 0;
}

double sum(int lim,...)
{
    va_list ap; // 用于储存参数
    double tot = 0;
    int i;
    va_start(ap,lim); //初始化参数列表
    for(i = 0;i < lim;i++)
        tot += va_arg(ap,double); //访问参数中的每一项
    va_end(ap);
    
    return tot;
}