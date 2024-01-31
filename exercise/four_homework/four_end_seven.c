#include <stdio.h>
#include <float.h>

int main(void){
    float Fu = 1.0/3.0;
    double FB = 1.0/3.0;
    printf("float six : %.6f, twelve : %.12f ,sixteen : %.16f \n",Fu,Fu,Fu);
    printf("double six : %.6lf, twelve : %.12lf, sixtent : %.16lf\n",FB,FB,FB);
    printf("FLT : %f,DBL : %f\n",FLT_DIG,DBL_DIG);
    printf("FLT_DIG : %d ,DBL_DIG : %d\n",FLT_DIG,DBL_DIG);
    getchar();
return 0;
}