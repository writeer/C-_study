/**
 * @file gcd.c
 * @author your name (you@domain.com)
 * @brief 求最大公约数
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int gcd(int m,int n);//一般来说最大公约数都是看整数

int main()
{
    int com = 0;//最大公约数
    com = gcd(72,48);
    printf("最大公约数: %d",com);
    getchar();
    return 0;
}

int gcd(int m, int n)//难怪说不用纠结内部细节，确实，一纠结就难过，好吧，先相信。
{
    int r;
    if((r = m % n) != 0)
       n = gcd(n,r);
    return n;
}