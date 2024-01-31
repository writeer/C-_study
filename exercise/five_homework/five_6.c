#include <stdio.h>
#define FORMAT "%s! C is cool\n"
//注释是我对代码执行的推测
int main(void){
    int num = 10;

    printf(FORMAT,FORMAT);//正常显示字符串，推测为[%s! C is cool {换行}! C is cool]
    printf("%d\n",++num);//打印11
    printf("%d\n",num++);//打印11
    printf("%d\n",num--);//打印12
    printf("%d\n",num);//打印11
    getchar();
    return 0;//大致推测成功，只是忘记了常量的换行，以及忽略了num进行过两次运算。
}