#include <stdio.h>
#include <string.h>

int main(void){
    char str[20];//这个代码会使你输入的字符反转输出；
    printf("这个代码会使你输入的字符反转输出\n");
    printf("Enter a character string:");
    scanf("%s",&str);
    for (int i =  strlen(str) - 1;i >= 0;i--)//-1是因为字符串最后会添加\0字符，不打印这个字符可以让代码更加简洁
        printf("%c",str[i]);

fflush(stdin);
getchar();
return 0;
}