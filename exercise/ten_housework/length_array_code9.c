#include <stdio.h>
#define ROW 3
#define COL 5
//c++不支持变长数组，这个要用gcc编译
//因为要用gcc，而我有懒得改vc，用cmd来弄的，麻烦了很多。
//最主要的问题是我用了局部数组，在第二个函数中新建了一个数组用于储存，结果就是在函数返回后，这个变量就用不了了。
//所以我在主函数新建了一个数组，保证数组不丢失，然后传递指针。
//现在代码可以正常运行了，只是解决问题有点心累。
//复制数组
void copy_array(int row,int col,const double ar[row][col],double copy_ar[][COL]);
//打印数组
void print_array(int row,int col,double ar[row][col], double copy_ar[row][col]);

int main(void){
    double copy_ar[ROW][COL];
    double arr[ROW][COL] = {{8,92,10,55,69},{2,336,25,15,25},{1,89,66,4,99}};
    copy_array(ROW,COL,arr,copy_ar);
    print_array(ROW,COL,arr,copy_ar);
    getchar();
    return 0;
}

void copy_array(int row,int col,const double ar[row][col],double copy_ar[row][col]){
    int i,j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            copy_ar[i][j] = ar[i][j];
        }
        //printf("^^^%.0lf^^^ ",copy_ar[i][j-1]);调试代码，用来查看是否复制成功。
    }
    return;
}

void print_array(int row,int col,double ar[row][col],double copy_ar[row][col]){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%-5.0lf",ar[i][j]);
            printf("copy_ar =%5.0lf\n",copy_ar[i][j]);
        }
    }
    return;
} 