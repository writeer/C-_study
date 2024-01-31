/**
 * @file function_last.c
 * @author your name (you@domain.com)
 * @brief 写个快排，比较简单,13章第4题。
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief 排序函数
 * 
 * @param str 排序数组的第一个指针
 * @param count 数组中值的个数
 * @param len 数组中元素长度
 * @param cmp 回调函数用于比较
 */
void sort(void *str,int count,size_t len,int (*cmp)(void *,void *,size_t));

int compare(void *dst,void *src,size_t leng);//为了通用排序，加了一个字节长度的参数，否则不知道对比数组里的元素字节数

int main()
{
    int number[] = {5,6,8,9,7,3,1,2,4};
    char str[] = "efbadc";
    sort(number,9,sizeof(int),compare);
    sort(str,strlen(str),sizeof(char),compare);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ",number[i]);
    }
    printf("\n %s ",str);
    getchar();
    return 0;
}

void sort(void *str,int count,size_t len,int (*cmp)(void *,void *,size_t ))
{
    void *temp = malloc(len);
    if (temp == NULL)
    {
        return;
    }
    
    for (int i = 0; i < count * len; i += len)//冒泡排序，快排，或者其他都行，我就随便写了。
    {
        for (int j = i; j < count * len; j += len)
        {
            if (cmp(str + i,str + j,len) > 0)
            {
                memcpy(temp,str + i,len);
                memcpy(str + i,str + j,len);
                memcpy(str + j,temp,len);
            }
            
        }
        
    }
    free(temp);
}

int compare(void *dst,void *src,size_t leng)
{
    return memcmp(dst,src,leng);
}