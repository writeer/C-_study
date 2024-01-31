#include <stdio.h>
#include <ctype.h>
#define SIZE 20 //单词大小

char * first_char(char *);

int main(void){
    char * ptr;
    char c_acter[SIZE];
    ptr = first_char(c_acter);
    puts(ptr);
    fflush(stdin);//通过刷新缓冲区，丢弃剩下的所有字符
    getchar();
    return 0;
}

char * first_char(char * c_acter){
    int i;
    char a;
    a = getchar();
    while (isspace(a) != 0)
        a = getchar();
    for (i = 0; isspace(a) == 0; i++)
    {
        c_acter[i] = a;
        a = getchar();
    }
    c_acter[i] = '\0';
    return c_acter;
}