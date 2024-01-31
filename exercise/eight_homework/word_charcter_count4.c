#include <stdio.h>
#include <ctype.h>

int end_word(int word);
/*这个程序会统计每个单词的字符数*/
int main(void){
    char ch;
    int word_ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if(ch == ' '){
           word_ch = end_word(word_ch);
        }
        else if (ch == '\n')
        {
            word_ch = end_word(word_ch);
        }
        else if(ispunct(ch) == 0){
            word_ch++;
            putchar(ch);
        }
        else{
            word_ch = end_word(word_ch);
        }
        
    }
    return 0;
}

int end_word(int word){
    if (word == 0)//如果没有读取到单词，比如连续两个空格或者回车之类的情况下，不会多打印。
    {
        return word;
    }
    
            printf(") this word have are %d character.\n",word);
            word = 0;
            return word;
}