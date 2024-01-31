#include <stdio.h>
//这个程序会计算平方根的近似值
int main(void)
{
    unsigned int n;
    double a = 1;//第一个近似值是1
    printf("输入一个正整数n: ");
    scanf("%d",&n);
    fflush(stdin);
    for (int i = 0; i < 10; i++)
    {
        a = a + n/a;
        a = a/2;
        printf("迭代 %d次:%.10g\n",i+1,a);
    }
    getchar();
    return 0;
}