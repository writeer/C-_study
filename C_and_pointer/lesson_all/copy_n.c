/**
 * @file copy_n.c
 * @author your name (you@domain.com)
 * @brief 写一个strncpy函数，作用也相同
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

void copy_n(char *dst,char *src,int);

int main(void)
{
    char dst[15],src[15]= "I don't no";//10个字符
    copy_n(dst,src,10);//这个函数的数据可以让用户输入，怕溢出可以限制长度
    //上面这个函数有一个问题，那就是5个字符只能复制4个，因为我预留了一个位置放\0，所以就算字符刚好够放入数组，也会留出这个位置
    //比如上面这里有10个字符,那么只会复制9个，并且dst目标复制，我也没有做边界检查，所以有可能溢出。
    //所以为了不溢出，全看程序员怎么设定了。
    puts(dst);
    getchar();
    return 0;
}

/**
 * @brief 如果不用strlen如何判断src的字符串长度？如果用\0判断，可能会有垃圾值，但是默认src输入的是一个字符串。
 * 那么剩下的问题，是程序员该预防的，那就是进行正确的输入。
*/
void copy_n(char *dst,char *src,int n)
{
    int i,j = 0;
    while (src[j] != '\0')
    {
        j++;
    }
    for (i = 0; i < n -1; i++)
    {
        dst[i] = src[i];
    }
    if (j < n)
        for  (; j < n; j++)
        {
            dst[j] = '\0';
        }
    else if (j == n){
        dst[j] = '\0';
    }
    else
        dst[i] = '\0';
    return;
}