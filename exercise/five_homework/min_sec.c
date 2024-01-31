#include <stdio.h>
//输入数字不可小于1,sec > 1
#define SEC_PER_MIN 60
int main(void){
    int sec, min ,left;
    printf("Convert seconds to minutes and seconds.\n");
    printf("Enter number of seconds (<=0 to quit):\n");
    scanf("%d",&sec);
    while (sec > 0)
    {
        /* code */
        min = sec / SEC_PER_MIN; //分钟
        left = sec % SEC_PER_MIN; //剩余秒数
        printf("%d seconds is minutes %d, %d seconds.\n",sec,min,left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d",&sec);
    }
    printf("Done!\n");
    getchar();
return 0;
}