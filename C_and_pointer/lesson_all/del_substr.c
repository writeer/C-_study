/**
 * @file del_substr.c
 * @author your name (you@domain.com)
 * @brief 实现一个简单的函数，删除字符串的一部分
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

/**
 * @brief 我觉得我这个函数写的又精简，又棒，可以说是现在位置我想出来的最棒的写法了
 * 
 * @param str 原字符串
 * @param substr 要删除的字符串
 * @return int 
 */
int del_substr(char *str,char const *substr);

int main()
{
    char array[] = "I love you";
    char del_char[] = "love";
    if(del_substr(array,del_char))
        printf("删除成功:%s\n",array);
    else
        printf("删除失败，目标没有此字符:%s\n",array);
    getchar();
    return 0;
}

int del_substr(char *str,char const *substr)
{
    char *temp = str,*del = substr;//记录起始位置
    int i;
    for (; *str != '\0' ; str++)//检测源字符串是否有这个字符串
    {
        if(*str == *del){
            for (i = 0; *del != '\0' ; i++,del++)
            {
                if(*(str+i) == *del){
                    continue;
                }
                else{
                    del = substr;
                    break;
                }
            }
        }
        if(del > substr)//测试是否找到
            break;
    }
    if(del == substr)//没找到返回0
        return 0;
    temp = str;
    for (str += i; *str != '\0';str++,temp++)
    {
        *temp = *str;
    }
    *temp = '\0';//补上结尾
    return 1;
}