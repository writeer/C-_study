#include <stdio.h>
#include <ctype.h>
#define SIZE 20 //单词大小
#define N 8 //单个单词上限
//这题把上一题的代码改改就行了
char * first_char(char *,int n);

int main(void){
    char * ptr;
    char c_acter[SIZE];
    puts("输入一个字符串，只会保存前八位字符(除了空格等空字符)：");
    ptr = first_char(c_acter,N);
    puts(ptr);
    fflush(stdin);//通过刷新缓冲区，丢弃剩下的所有字符
    getchar();
    return 0;
}

char * first_char(char * c_acter,int n){
    int i;
    char a;
    a = getchar();
    while (isspace(a) != 0)
        a = getchar();
    for (i = 0; isspace(a) == 0 && i < n; i++)
    {
        c_acter[i] = a;
        a = getchar();
    }
    c_acter[i] = '\0';
    return c_acter;
}