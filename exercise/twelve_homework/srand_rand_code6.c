#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define seed 1
#define count 100

int main(void){
    int nu = 0;
    int next[10] = {1,2,3,4,5,6,7,8,9,1};
    int temp;
    int count_num[10] = {0};
    for(int j = 0;j < 10;j++){
        srand(next[j]);
    for (int i = 0; i < count; i++)
    {        //我在网上看到另一个方法，可以用数组下标来计数，更加方便
            //count_num[nu]当随机到1，就会在这个数组对应的值下加一
            //count_num[nu]++，更加方便，代码更简洁
        nu = (rand() % 10) + 1;
        switch (nu)
        {
        case 1:
            count_num[0]++;
            break;
        case 2:
            count_num[1]++;
            break;
        case 3:
            count_num[2]++;
            break;
        case 4:
            count_num[3]++;
            break;
        case 5:
            count_num[4]++;
            break;
        case 6:
            count_num[5]++;
            break;
        case 7:
            count_num[6]++;
            break;
        case 8:
            count_num[7]++;
            break;
        case 9:
            count_num[8]++;
            break;
        case 10:
            count_num[9]++;
            break;
        default:
            break;
        }
    }
    for (int n = 0; n < 10; n++)
    {
        printf("%d : \"%3d\" , ",n + 1,count_num[n]);
    }
    printf("\n");
    for (int n = 0; n < 10; n++)
    {
        count_num[n] = 0;
    }
    
    //printf("1 : %d , 2 : %d , 3 : %d , 4 : %d , 5 : %d , 6 : %d , 7 : %d , 8 : %d , 9 : %d")
    }
    getchar();
    return 0;
}