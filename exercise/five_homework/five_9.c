#include <stdio.h>
#define AandG 103
//打印a-g的字符
int main(void){
    int n=96;//因为n++在条件对比后会进行运算，所以n的值取96，这样条件对比后的输出值就是97也就是a。
    while (n++ < AandG)
    {
        printf("%-5c",n);//加负号让字母左对齐
    }
    printf("\n");
    getchar();
    return 0;
}