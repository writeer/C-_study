#include <stdio.h>
//这个程序会比较出数组中最大的数，并返回
int comp_max(int *,int n);

int main(void){
    int nubmer[10] = {1580,969,4658,3121,4643,4821,454,3453,4582,525};
    printf("The maximum value of this array is:%d",comp_max(nubmer,10));
    getchar();

    return 0;
}

int comp_max(int * nub,int n){
    for (int i = 0; i < n; i++)
    {
       for (int j = i; j < n; j++)
       {
        if (nub[i] >= nub[((j + 1) > 9)? 9 : j +1]){
            if (j == 9)
                return nub[i];
        }//调试半天，发现原来问题是差一个花括号，照常理来说if下面加个if是正常执行判断的，不过算了。
        else
            break;
        if (i == 9)
        {
            return nub[i];
        }
       }
    }
    return n;
}