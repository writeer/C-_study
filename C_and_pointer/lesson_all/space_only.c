/**
 * @file space_only.c
 * @author your name (you@domain.com)
 * @brief 如果有多个空格，简化为一个
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
/**
 * @brief 这个函数，因为没有返回值，所以有两种做法，一种是用新的数组，不改变原数组，输出一个修改后的。
 * 另一个做法是，直接在原数组上操作。但是数组的插入和删除很不方便，删了中间的空格，要偏移后面的数据。
 * 所以我用第一种做法。
 * 
 * @param string 
 */
void deblank(char string[]);

int main(void)
{
    char src[50]= "Stray   birds   of              summer";
    deblank(src);
    //puts(src);
    getchar();
    return 0;
}

void deblank(char string[])
{
    char dst[150]={0};
    int i = 0,temp = 0,space = 0;//i 计数，temp控制复制,space判断空格
    while(string[i] != '\0')
        i++;
    for (int j = 0; j <= i; j++)
    {
        if(string[j] == ' ' && space == 0){
            dst[temp] = string[j];
            temp++,space++;
        }
        else if (string[j] == ' ' && space != 0){
            space++;
        }
        else{
            dst[temp] = string[j];
            temp++,space = 0;
        }
    }
    puts(dst);//这里直接把新的数组覆盖掉原数组就行了，可以用strcpy，或者循环。
}