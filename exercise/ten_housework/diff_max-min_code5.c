#include <stdio.h>
//这个程序会比较出数组中最小和最大的数，并计算差值
int comp_min(int *,int n);
int comp_max(int * nub,int n);
//这个程序比较简单，用上个程序改改就行。
int main(void){
    int nubmer[10] = {158,569,658,121,643,481,454,453,582,525};
    printf("This minimum array subscript is:%d - %d = %d",comp_max(nubmer,10),comp_min(nubmer,10),comp_max(nubmer,10) - comp_min(nubmer,10));
    getchar();

    return 0;
}

int comp_min(int * nub,int n){
    for (int i = 0; i < n; i++)
    {
       for (int j = i; j < n; j++)
       {
        if (nub[i] <= nub[((j + 1) > 9)? 9 : j +1]){
            if (j == 9)
                return nub[i];
        }
        else
            break;
       }
    }
    return n;
}

int comp_max(int * nub,int n){
    for (int i = 0; i < n; i++)
    {
       for (int j = i; j < n; j++)
       {
        if (nub[i] >= nub[((j + 1) > 9)? 9 : j +1]){
            if (j == 9)
                return nub[i];
        }
        else
            break;
       }
    }
    return n;
}