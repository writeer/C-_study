#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strdes(char * asc);//使字符串颠倒
void Line_feed(char * row);//解决换行

int main(void){
    char s1[40];
    char acter;
    char * chr;
    while (acter != EOF)
    {
    puts("输入一个字符串：");
    fgets(s1,40,stdin);
    Line_feed(s1);
    chr = strdes(s1);
    puts(chr);
    fflush(stdin);
    puts("按回车继续，输入ctrl-z结束。");
    acter = getchar();
    }
    system("pause");
    return 0;
}

char * strdes(char * asc){
    int i,j = strlen(asc) - 1;
    char temp;
    for (i = 0; i < j; j--,i++)
    {
        temp = asc[i];
        asc[i] = asc[j];
        asc[j] = temp;
    }
    return asc;
}

void Line_feed(char * row){
    for (int i = 0; i < strlen(row); i++)
    {
        if (row[i] == '\n')
        {
            row[i] = '\0';
        }
    }
    
}