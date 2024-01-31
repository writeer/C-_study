#include <stdio.h>

int main(void){
    const int sixten = 60;
    printf("这是一个输入分钟，转换为小时和分钟的程序\n");
    int s,minute,hours;
    while(s > 0)
    {
        printf("输入一个数字，小于或等于零程序停止:");
        scanf("%d",&s);
        hours = s / sixten;
        minute = s % sixten;
        printf("转换为:%d时%d分\n",hours,minute);
    }
    
    return 0;
}