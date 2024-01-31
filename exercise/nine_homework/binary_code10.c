#include <stdio.h>
#include <stdlib.h>
/*以任何进制形式打印整数，因为字符的转换方式是用的数字相加后强行转换，所以最多支持到十进制*/
//如果加上一个数字转字符的函数，然后打印时使用%s就可以实现转换任何进制。
//void to_binary(unsigned long n);
void to_binary_n(unsigned long n,unsigned long m);

int main(void){
    unsigned long number,m;
    printf("输入一个整数，并且输入想要转换的进制\n");
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu %lu",&number,&m) == 2)
    {
        printf("Binary equivalent: ");
        //to_binary(number);
        to_binary_n(number,m);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done!\n");
    system("pause");
    return 0;
}
/*
void to_binary(unsigned long n){
    int r;
    r = n % 2;
    if (n >= 2)
        to_binary(n/2);
    putchar(r == 0 ? '0':'1');
    return;
}*/

void to_binary_n(unsigned long n,unsigned long m){
    int r;
     r = n % m;
    if (n >= m)
        to_binary_n(n/m,m);
    putchar(r == 0 ? '0' : (char)(r+0x30));//数字加0x30然后强行转字符，可以正常显示，需要支持ascll码。
    return;
}