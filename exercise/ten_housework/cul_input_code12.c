#include <stdio.h>
#include <stdlib.h>
//这是十三题，十四题只要把形参改成变长数组就行了
#define ROW 3
#define COL 5

double row_avg(double [][COL]);//每行平均值
double avg(double [][COL]);//总平均值
double max_number(double [][COL]);//最大数

int main(void){
    printf("Please Enter 15 numbers:");
    double ar[ROW][COL];
    for (int i = 0; i < ROW; i++)//这个循环可以用指针表示法，我个人认为更好用。
    {
        for (int j = 0; j < COL; j++)
        {
            scanf("%lf",&ar[i][j]);
        }
    }
    row_avg(ar);
    printf("Total average: %.2lf\n",avg(ar));
    printf("The maximum value of this array is: %g\n",max_number(ar));
    system("pause");
    return 0;
}

double row_avg(double arr[][COL]){
    double avg_row = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            avg_row += arr[i][j];
        }
        printf("avg_row = %.2lf\n",avg_row / 5);
        avg_row = 0;
    }
    return avg_row;
}

double avg(double arr[][COL]){
    double avg = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            avg += arr[i][j];
        }
    }
    return avg / (ROW * COL);
}

double max_number(double arr[][COL]){
    //用指针表示法，把这个二维数组看成一个连续的一维数组。
    //这题是第三题代码改的，毕竟数组的指针是一样的，所以我就想试试二维数组看做一维，毕竟它们在内存中的储存是连续的
     for (int i = 0; i < ROW * COL; i++)
    {
       for (int j = i; j < COL * ROW; j++)
       {
        if (*(arr[0]+i) >= *(arr[0]+(((j + 1) > ROW * COL)? ROW * COL : j +1))){
            if (j == COL * ROW - 1)
                return *(arr[0]+i);
        }
        else
            break;
       }
    }
    return *arr[0];
}