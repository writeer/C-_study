/**
 * @file rand.c
 * @author your name (you@domain.com)
 * @brief 这个程序因为编译器优先级不同，会产生不同的结果
 * 根据不同的结果，这个非法表达式，在C和指针中的程序5.3下的表5.2中有。
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main()
{
    int i = 10;
    i = i-- - --i * (i = -3) * i++ + ++i;
    printf("i = %d \n",i);
    getchar();
    return 0;
}