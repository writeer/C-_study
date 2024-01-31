#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4* atanl(1)))
//我使用了代替实现，这就解决了这个问题，所以这个问题在于minGW的编译器问题，以及windows
//原因在于数字正常储存，但是printf不支持双打，所以只能用代替实现，也算学到一点了
#define printf __mingw_printf

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
//经过我用本代码的test测试，以及网络搜索我明白了，先将原因写在下面
/*在windows下使用MinGW编译运行，此行代码输出并非dip数值。调试运行时，数值确实被赋给dip。随即在Linux环境编译运行此段代码，结果正确。

搜索查询得知：Windows环境下，如果使用的是MinGW，则问题在于默认情况下，
MinGW使用I / O响应。Microsoft C运行时提供的格式化功能，
该功能不支持80位浮点数（在Microsoft land中为long double== double）。
但是，MinGW还附带了一组替代实现，它们确实支持长双打
。要使用它们，请在函数名称前加上__mingw_（例如__mingw_printf）。
根据项目的性质，
您可能还想全局#define printf __mingw_printf或使用-D__USE_MINGW_ANSI_STDIO（
这将启用所有printf-family函数的MinGW版本）。*/

int main(void)
{
    float x = 45.;
    double xx = 45;
    long double xxx = 45;

    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    printf("%.17Lf\n",y); //匹配float
    printf("%.17Lf\n",yy);//匹配default
    printf("%.17Lf\n",yy);//匹配long double
    int i = 45;
    yy = SQRT(i); //匹配default
    printf("%.17Lf\n",yy);
    yyy = SIN(xxx); //匹配 long double
    printf("%.17Lf\n",yyy);

    getchar();
    return 0;
}