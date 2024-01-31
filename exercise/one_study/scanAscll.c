#include <stdio.h>

int main(void){
    unsigned int u_ascall;
    printf("Please input Ascll:");
    scanf("%u",&u_ascall);
    printf("you Ascll code corresponding:%c",u_ascall);
    fflush(stdin);//刷新键盘缓冲区，把scanf留下的回车去掉
    //getchar();
    getchar();//因为getchar会读取键盘缓冲区，所以在scanf输入的时候，最后的回车会被下面的getchar读取，所以要用两个
    return 0;//用system("pause")可以解决这个问题，不过getchar很方便。
}