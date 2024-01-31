#include <stdio.h>

int main(void){
    char ch;
    /*这个程序会输出文件中的字符和对应的ascll码*/
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n'){
            printf("'\\n' = %d ",ch);
        }
        else if (ch == '\t')
        {
            printf("'\\t' = %d ",ch);
        }
        else if (ch < 32)
        {
            printf("'^%c' = %d ",ch + 64,ch);
        }
        else {
            printf("'%c' = %d ",ch,ch);
        }
    }
    return 0;
}