#include <stdio.h>
#define NUM 1.0

int main(void){
    double sum,dff,i,j;
    int dnt,sum_n2,n2 = 2;//denominator意思为分母
        printf("输入一个整数，规定下面两个无穷数列的计算次数。\n");
        printf("1.0 + 1.0/2.0+1.0/3.0 ....[]1.0-1.0/2.0+1.0/3.0-....\n");
        printf("在这里输入一个整数:");
        scanf("%d",&dnt);
    while (dnt > 0){
        for (sum = 1.0,i = 2.0; i <= dnt; i++)
        {
            sum +=  NUM / i;
        }

        for (dff = 1.0,j = 2.0; j <= dnt; j++)
        {
            sum_n2 = (int)j % n2;
            if(sum_n2 == 0){//我实在想不到解决办法于是用了if语句，其实可以用while语句判断后执行一次，然后退出。可以通过两个条件关联实现，然后在语句外还原第二个条件。
            dff -= NUM / j;//但是那样太麻烦，也太不好读了，所以迫于无奈，我还是用了if语句，充分了解决了这次的题目。
            }
            else{
            dff += NUM / j; }
        }//我终于明白提示的意思了，提取公因式，用1.0/所有偶数相加，判断循环次数，奇数次是负数，偶数次是正数，另外一个1.0除所有偶数相加，两个加起来加上1.0就行了。
        //但是我调试到这里，已经00:41了，懒得改了，知道怎么写就行了，简单的写法就是多加一个变量，然后多一个循环，并且在循环中进行乘法，奇数个-1可以得到-1，然后乘以总数就行，偶数个得到1，也是一样的做法。
        printf("sum = %lf,dff = %lf,sum + dff = %lf,sum - dff = %lf.\n",sum,dff,sum+dff,sum-dff);
        printf("输入下一次的数列极值:");
        scanf("%d",&dnt);
    }
    printf("Done!\n");
    fflush(stdin);
    getchar();
    return 0;
}