#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4* atanl(1)))
//泛型平方根函数
#define SQRT(X) _Generic((X),\
    long double : sqrtl,\
    default: sqrt,\
    float: sqrtf)(X)
//泛型正弦函数，角度的单位为度
#define SIN(X) _Generic((x), \
    long double : sinl((X) / RAD_TO_DEG),\
    default: sin((X)/ RAD_TO_DEG),\
    float : sinf((X)/RAD_TO_DEG)\
)
//泛型正常，但是不知道为什么，输出的数是补码，或者是别的什么
int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0l;
    // 泛型函数一切正常但是不知为什么，一用到sqrtl时就会出错
    //现在我明白了，是因为long double类型的原因，sqrt的返回值储存为long double就会出错，但我不知道为什么
    x = SQRT(x);
    xx = SQRT(xx);
    xxx = sqrtl(xxx);
    printf("%.17Lf\n",x); //匹配float
    printf("%.17Lf\n",xx);//匹配default
    printf("%.17g\n",xxx);//匹配long double
   /* int i = 45;
    yy = SQRT(i); //匹配default
    printf("%.17Lf\n",yy);
    yyy = SIN(xxx); //匹配 long double
    printf("%.17Lf\n",yyy);*/

    getchar();
    return 0;
}