#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define seed 1
int main(void){
    int num[100];
    int nu = 0;
    int temp;
    srand(seed);
    for (int i = 0; i < 100; i++)
    {
        num[i] = (rand() % 10)+1;
    }
    for (int j = 0; j < 100; j++)
    {
        for (int m = j; m < 100; m++)
        {
            if (num[j] > num[m])
            {
                temp = num[j];
                num[j] = num[m];
                num[m] = temp;
            }
            
        }
        
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%d ",num[i]);
    }
    
    getchar();
    return 0;
}