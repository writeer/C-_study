#include <stdio.h>
//把数组中的数倒序排列
void des(double [],int n);

int main(void){
    double nubmer[10] = {158,569,658,121,643,481,454,453,582,525};
    des(nubmer,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%.0lf ",nubmer[i]);
    }
    getchar();
    return 0;
}
//冒泡排序
void des(double sort[],int n){
    double temp;
    for (int j = 0; j < n -1; j++)
    {

    for (int i = 0; i < n -1 - j; i++)
    {
        if (sort[i] < sort[i+1])
        {
            temp = sort[i];
            sort[i] = sort[i+1];
            sort[i+1] = temp;
        }
        
    }
    }
    return ;
}