#include <stdio.h>

int main(void){
    double first[8],second[8];
    printf("Enter eight number:");
    for (int i = 0; i < 8; i++)
    {
        scanf("%lf",&first[i]);
    }
    for (int i = 0; i < 8; i++)
    {
       printf("%5lg ",first[i]);
    }
    printf("\n");
    second[0] = first[0];
    printf("%5lg ",second[0]);
    for (int i = 1; i < 8; i++)
    {
        second[i] = first[i]+second[i-1];
        printf("%5lg ",second[i]);
    }
    fflush(stdin);
    getchar();
    return 0;
}