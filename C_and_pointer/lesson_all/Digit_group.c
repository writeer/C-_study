/**
 * @file Digit_group.c
 * @author your name (you@domain.com)
 * @brief 操纵位数组，本题的难度在于字符转数字
 * 如果有精力，可以写一个菜单，然后通过菜单来和位数组互动，操纵位数组
 * 我懒得写，所以实现函数后，看看结果就完事了。
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

void set_bit(char bit_array[],unsigned int number);//指定位设置为1
void clear_bit(char bit_array[],unsigned int number);//指定位清理
void assing_bit(char bit_array[],unsigned int number,int value);//value值为零则设置为零，否则设定为1
int test_bit(char bit_array[],unsigned int number);//指定位不是零返回真，否则返回假

int main()
{
    char BitArray[32] = "110010001001";//位数组
    printf("%s \n",BitArray);
    set_bit(BitArray,10);
    printf("%s \n",BitArray);
    clear_bit(BitArray,8);
    printf("%s \n",BitArray);
    if(test_bit(BitArray,11)){
        assing_bit(BitArray,0,0);
        printf("%s \n",BitArray);
    }
    getchar();
    return 0;
}

void set_bit(char bit_array[],unsigned int number)
{
    bit_array[number] = '1';
}
void clear_bit(char bit_array[],unsigned int number)
{
    bit_array[number] = '0';
}

void assing_bit(char bit_array[],unsigned int number,int value)
{
    if(value)
        bit_array[number] = '1';
    else
        bit_array[number] = '0';
}

int test_bit(char bit_array[],unsigned int number)
{
    if(bit_array[number] - '0')
        return 1;
    else
        return 0;

}