#include <stdio.h>

int main(void){
    int num,n;
    n = 0;
    printf("这个程序会输出你输入数字的后十位。\n");
    printf("Please enter number:");
    scanf("%d",&num);
    while (n++ < 11)//因为包括这个数字本身，所以需要11次循环
    {
        printf("%d\t",num);
        num++;
    }
fflush(stdin);
getchar();
return 0;    
}