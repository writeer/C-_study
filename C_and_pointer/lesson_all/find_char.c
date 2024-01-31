#include <stdio.h>
/**
 * @brief 写一个strpbrk函数，查找字符串中的字符返回指针，不适用下标
 * 
 */

char *find_char(char const *source,char const *chars);

int main()
{
    char array[20] = "I can't";
    char chars = 'c';
    char *temp;
    temp = find_char(array,&chars);
    if(temp != NULL)
        printf("%s\n",temp);
    getchar();
    return 0;
}

char *find_char(char const *source,char const *chars)
{
    for (; *source != '\0'; source++)
    {
        if(*source == *chars)
            return source;
    }
    return NULL;
}