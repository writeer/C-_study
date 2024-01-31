#include <stdio.h>
#include <windows.h>
#define SPACE ' '

int main(void){
    char ch;
    ch = getchar();
    while (ch != '\n')
    {
        if (ch == SPACE)
            putchar(ch);
        else
            putchar(ch+1);
        ch = getchar();
    }
    putchar(ch);//打印回车
    system("pause");
    return 0;
}