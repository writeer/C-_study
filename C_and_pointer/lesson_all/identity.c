/**
 * @file identity.c
 * @author your name (you@domain.com)
 * @brief 接受一个10X10的矩阵，并判断是否为单位矩阵
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdbool.h>

bool identity_matrix(int matris[][10]);

int main(void)
{
    int matris[10][10] = {0};
    for (int i = 0,j = 0; i < 10; j++,i++)//生成一个单位矩阵
    {
        matris[i][j] = 1;
    }
    if(identity_matrix(matris))
        printf("是单位矩阵");
    else
        printf("不是单位矩阵");
    getchar();
    return 0;
}

bool identity_matrix(int matris[][10])
{
    //int (*p)[10] = matris;
     for (int i = 0,j = 0; i < 10; j++,i++)
    {
        if(matris[i][j] == 1)
            continue;
        else
            return 0;
    }
    return 1;
}