#include <stdio.h>

int data[2] = {100,200};
int moredata[2] = {300,400};

int main(void){
    int * p1,* p2,* p3;
    int * p4;
    //int n = 40;
    //p4 = &n;
    //这几行代码是为了验证书中内容，也就是指针和数组的关系。
    //当指针指向n的地址时，获取值既可以用*也可以用数组的方式表示
    //这是因为在编译器看来是一样的，p4[0]就是(*p4)
    p1 = p2 = data;
    p3 = moredata;
    printf("*p2 = %d, *p2 = %d,*p3 = %d\n",/*p4[0]*/*p1,*p2,*p3);
    printf("*p1++ = %d, *++p2 = %d,*(p3)++ = %d\n",*p1++,*++p2,(*p3)++);
    printf("*p2 = %d, *p2 = %d,*p3 = %d\n",*p1,*p2,*p3);
    getchar();
    return 0;
}