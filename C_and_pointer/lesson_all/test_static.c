/**
 * @file test_static.c
 * @author your name (you@domain.com)
 * @brief 测试局部静态变量效果
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
    for (int i = 0; i < 8; i++)
    {
        static int j = 0;
        j++;
        printf("%d",j);
    }
    getchar();

    return 0;
}