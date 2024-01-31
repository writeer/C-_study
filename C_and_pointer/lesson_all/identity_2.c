/**
 * @file identity.c
 * @author your name (you@domain.com)
 * @brief 接受一个任意矩阵，并判断是否为单位矩阵
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#define NUM 15

bool identity_matrix(int *matris,int num);

int main(void)
{
    int matris[NUM][NUM] = {0};
    for (int i = 0,j = 0; i < NUM; j++,i++)//生成一个单位矩阵
    {
        matris[i][j] = 1;
    }
    //matris[5][5] = 0;
    if(identity_matrix(matris,NUM))
        printf("是单位矩阵");
    else
        printf("不是单位矩阵");
    getchar();
    return 0;
}

bool identity_matrix(int *matris,int num)
{
    int (*p)[num] = matris;
     for (int i = 0,j = 0; i < num; j++,i++)
    {
        if(p[i][j] == 1)
            continue;
        else
            return 0;
    }
    return 1;
}