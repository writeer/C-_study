
#include <stdio.h>

#define MYTYPE(x) _Generic((x),\
    int : "int",\
    float : "float",\
    double : "double",\
    default: "other"\
    )

int main(void)
{
    int d = 5;
    printf("%s\n",MYTYPE(d)); //d = int类型
    printf("%s\n",MYTYPE(2.0*d));//利用C的自动类型转换转为double类型
    printf("%s\n",MYTYPE(3L)); //3L是长整型
    printf("%s\n",MYTYPE(&d)); //&d是int *
    return 0;
}