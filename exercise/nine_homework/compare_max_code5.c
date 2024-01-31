#include <stdio.h>

double larger_of(double *,double *);

int main(void){
    double num,nub;
    printf("比较两个数，并全部替换为较大的\n");
    printf("Enter tow numbers:");
    scanf("%lf %lf",&num,&nub);
    printf("one = %g, two = %g\n",num,nub);
    larger_of(&num,&nub);
    printf("one = %g, two = %g\n",num,nub);
    fflush(stdin);
    getchar();
    return 0;
}

double  larger_of(double * n,double * m){
    double max;
    max = (*n > *m)? *n : *m;
    *n = *m = max;
    return max;
}