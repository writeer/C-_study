/**
 * @file Binary_inversion.c
 * @author your name (you@domain.com)
 * @brief 反转二进制数
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bits(unsigned int value);

int main()
{
    unsigned int sum = 0b1000100111;
    unsigned int dst; //用于备份和输出
    char temp[64];
    itoa(sum,temp,2);//转化为数组用于输出
    printf("ten : %d ,%s\n",sum,temp);
    dst = reverse_bits(sum);
    itoa(dst,temp,2);
    printf("ten : %d ,%s\n",dst,temp);
    getchar();
    return 0;
}

unsigned int reverse_bits(unsigned int value)
{
    unsigned int re = 0;
    /*int count = 0; //统计二进制有几位
    while(sum)
    {
        sum >>= 1;
        count++;
    }*/
    for(;value;value >>= 1)
    {
        re <<= 1;
        re |= value & 1;   
    }
    return re;
}