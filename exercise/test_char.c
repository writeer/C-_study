#include <stdio.h>

int main (void){
    char ch = 'ABCD';//因为char是八位储存，所以只会留下最后八位的数据
    printf("ascll_dec= %d ,octal=%o,hex = %x, char=%c \a",ch,ch,ch,ch);// \a是警报转义字符ascll = 7;
    getchar();
    return 0;  
}