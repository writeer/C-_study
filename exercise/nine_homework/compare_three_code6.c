#include <stdio.h>
#include <stdlib.h>
double com(double *,double *,double *);

int main(void){
    double num,nub,nu;
    printf("输入三个数，按顺序排列\n");
    printf("Enter three numbers:");
    scanf("%lf %lf %lf",&num,&nub,&nu);
    com(&num,&nub,&nu);
    printf("%g < %g < %g\n",num,nub,nu);
    system("pause");
    return 0;
}

double com(double * min,double * mid,double * max){
    double comp;
    if (*min > *mid)//用第一个数和第二个数比较
    {
        comp = *mid;
        *mid = *min;
        *min = comp;
    }
    if (*min > *max)//无论如何，在这里，min的值都会小于mid,那么这里就看一看第一个数是否大于第三个数
    //如果大于第三个数，就交换，这个时候min的值就是最小的，因为它小于第二数，也小于第三数，如果它大于第三个数，交换后也会小于
    //此时是min<mid && min < max，未知的就只有mid 和max的大小了，所以只用再检查这两个数的大小就行了。
    {
        comp = *max;
        *max = *min;
        *min = comp;
    }
    if (*mid > *max)
    {
        comp = *mid;
        *mid = *max;
        *max = comp;
    }
    
    return comp;
    //这下面写了很多，考虑到很多种情况，但其实都是废话，不需要那么多。
    //重新思考后，我写了上述代码。
   /* if (*min < *mid && *min < *max)
    {
        if (*mid > *max)
        {
         comp = *max;
         *max = *mid;
         *mid = comp;
        }
    }
    else if (*min < *mid && *min > *max)
    {
        comp = *min;
        *min = *mid;
        *mid = comp;
        comp = *max;
        *max = *min;
        *min = comp;
    }
    else if (*min > *mid && *min < *max)
    {
       comp = *min;
       *min = *mid;
       *mid = comp; 
    }
    else if (*min > *mid && *min > *max)
    {
        comp = *max;
        *max = *min;
        *min = comp;
        if (*min > *mid)
        {
            comp = *mid;
            *mid = *min;
            *min = comp;
        }   
    }
    else if (*mid > *min && *mid < *max)
    {
        if (*min > *max)
        {
            comp = *max;
            *max = *min;
            *min = comp;
        }
    }
    */
    
    
    
    
    
    
}