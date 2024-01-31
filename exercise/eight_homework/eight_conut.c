#include <stdio.h>
#include <ctype.h>
/* 这个程序可以统计字符数量*/

int main(void){
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (isspace(ch) == 0)
        {
            count++;
        }
        else{
            continue;
        }
        
    }
    printf("character is %d",count);
    return 0;
}