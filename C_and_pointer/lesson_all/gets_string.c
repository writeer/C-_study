/**
 * @file gets_string.c
 * @author your name (you@domain.com)
 * @brief 从标准输入读取字符串，并且不需要规定字符串大小,题目要求好像是要拷贝，我这没有，其实也简单，加一个新的动态分配的数组复制过去就行了。
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *save_str();

int main()
{
    char *str;
    str = save_str();
    printf("%s",str);
    free(str);
    system("pause");
    return EXIT_SUCCESS;
}

char *save_str()
{
    char *str = NULL;
    int ch,len = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str = realloc(str,(len + 1) * sizeof(char));
        str[len++] = ch;
    }
    
    str = realloc(str,(len + 1) * sizeof(char));
    str[len] = '\0';

    return str;
}