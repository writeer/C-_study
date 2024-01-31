/**
 * @file doller_turn.c
 * @author your name (you@domain.com)
 * @brief 按照美分的格式分割数字，比如12345 = $123,45
 * C和指针第九章第15题，这题比较简单，两个数组插字符就行了，可以加点难度，十进制数字转字符，不过我懒得弄了
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dollars(char *dest,char const *src);

int main()
{
    char dollar[25] = {0};
    char dest[30] = {0};
    printf("输入数字(以美分记): ");
    scanf("%s",dollar);
    dollars(dest,dollar);
    printf("输出： %s",dest);
    system("pause");
    return 0;
}

void dollars(char *dest,char const *src)
{
    int j = 0;
    int temp = strlen(src) - 2;//计算字符长度，判断需要几个逗号
    while(temp > 3){
        temp -= 3;
        j++;
    }
    
    for (int i = strlen(src) + j + 1,k = strlen(src),count = 0; i >= 0; i--)//计算后字符串就会刚好匹配合适的大小
    {
        if(i == strlen(src) + j - 2){//k == strlen(src) - 2
            *(dest + i) = '.';
           /*/ i--;
            *(dest + i) = *(src + k);
            k--;*/
            count = 0;//因为上面移动了指针，所以要设为1
        }
        else if (count % 3 == 0 && count != 0)
        {
            *(dest + i) = ',';
            count = 0;
        }
        else{
            *(dest + i) = *(src + k);
            count++;
            k--;
        }
        
    }
    *(dest + strlen(src) + j + 2) = '\0';
}