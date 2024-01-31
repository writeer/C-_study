/**
 * @file store.c
 * @author your name (you@domain.com)
 * @brief 给定值，储存到一个整数中的指定位数
 * C和指针第五章第五题
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
/**
 * @brief 
 * 
 * @param original_value 原始值
 * @param value_to_store 需要储存的值
 * @param starting_bit 起始位
 * @param ending_bit 结束位
 * @return int 返回值
 */
int store_bit_field(int original_value, int value_to_store,unsigned starting_bit,unsigned ending_bit);

int main()
{
    int s;
    //题目第一组数据 0x0,0x1,4,4 return:0x10
    //0xffff,0x123,15,4 return:0x123f
    //0xffff,0x123,13,9 return:0xc7ff
    s = store_bit_field(0xffff,0x123,13,9);
    /*char temp[32];
    itoa(s,temp,2);
    printf("0x%s\n",temp);*/
    printf("0x%x\n",s);
    getchar();
    return 0;
}

int store_bit_field(int original_value, int value_to_store,unsigned starting_bit,unsigned ending_bit)
{
    unsigned dec = starting_bit - ending_bit; //因为起始位始终要大于结束位，用差来表示1的个数，包括起始位
    unsigned mask = 1;//掩码
    unsigned dsimask; //掩码的反码
    for (int i = 0; i < dec; i++)//1的个数
    {
        mask <<= 1;
        mask += 1;
    }
    mask <<= ending_bit;//0的个数
    dsimask = ~mask; //取反
    original_value &= dsimask; //对原值操作，腾出新值的空间
    value_to_store <<= ending_bit;//新值左移到对应位置
    value_to_store &= mask; //把新值移动后，取出需要的位置
    original_value |= value_to_store;
    return original_value;
}