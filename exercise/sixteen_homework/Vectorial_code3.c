#include <stdio.h>
#include <math.h>
//a是弧度

#define X_COS(a,r) (r) * cos(a) 
#define Y_Sin(a,r) (r) * sin(a)
#define PI 3.1415926535

struct Vectorial
{
    double randin;
    double r;
};

struct coordinates
{
    double x;
    double y;
};

struct coordinates tranformation(struct Vectorial pe);

int main(void)
{
    struct Vectorial Vectorials = {PI / 3, 15};
    struct coordinates angle =  tranformation(Vectorials);
   /* double x,y;
    x = X_COS(radin,r);
    y = Y_Sin(radin,r);*/
    printf("this Vectorial is x = %.2lf , y = %.2lf .\n",angle.x,angle.y);
    getchar();
    return 0;
}

struct coordinates tranformation(struct Vectorial pe)
{
    struct coordinates temp;
    temp.x = X_COS(pe.randin,pe.r);
    temp.y = Y_Sin(pe.randin,pe.r);
    return temp;
}