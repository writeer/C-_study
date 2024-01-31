#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#define STOP '|'

int main(void){
    char c;//读入字符
    char prev;//前一个字符
    long n_chars = 0L;//字符数
    int n_lines = 0;//行数
    int n_words = 0;//单词
    int p_lines = 0;//特殊行
    bool inword = false;

    printf("Enter text to be analyzed(| to terminate):\n");
    prev = '\n';//用于识别完整的行
    while ((c = getchar()) != STOP)
    {
        n_chars++;//统计字符
        if (c == '\n')
            n_lines++;
        if(!isspace(c) && !inword)
        {
            inword = true;//记录单词开始
            n_words++;
        }
        if(isspace(c) && inword)
            inword = false;
        prev = c;
    }

    if(prev != '\n')
        p_lines = 1;
    printf("character = %ld,words = %d,lines = %d\n",n_chars,n_words,n_lines);
    printf("partial lines = %d\n",p_lines);
    system("pause");
    return 0;
}