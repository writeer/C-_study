#include <stdio.h>

double copy_arr(double [],double [],int n);
double copy_ptr(double *,double *,int n);

double copy_ptrs(double *,double *,double *);

int main(void){
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1,source,5);
    copy_ptr(target2,source,5);

    copy_ptrs(target3,source,(double *)(&source + 1)/*source + 5*/);//这两种表示方法都行

    for (int i = 0; i < 5; i++)
    {
        printf("%lf\n",source[i]);
        printf("%lf\n",target1[i]);
        printf("%lf\n",target2[i]);
        printf("%lf\n",target3[i]);
    }
    getchar();

    return 0;
}

double copy_arr(double ar[],double element[],int n){
    for (int i = 0; i < n; i++)
    {
        ar[i] = element[i];
    }
    return n;
}

double copy_ptr(double * ar,double * element,int n){
    for (int i = 0; i < n; i++)
    {
        *ar++ = *element++;
    }
    return n;
}

double copy_ptrs(double * ar,double * element,double * m){
    for (double * i = element; i < m; i++)
    {
        *ar++ = *element++;
    }
    return 0;
}