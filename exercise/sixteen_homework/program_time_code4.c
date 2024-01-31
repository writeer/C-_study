#include <stdio.h>
#include <time.h>
//测试两个命令之间的时间延迟
int main(void)
{
    double first,second,diff;
    first = (double)clock();
    puts("Start count");
    //for(int i = 0;i < 100000;i++)continue;
    //while(scanf("%d",&diff) == 1)continue;
    getchar();
    second = (double)clock();
    puts("Count over.");
    diff = (second - first) / CLOCKS_PER_SEC;
    printf("diff clock = %.5lf",diff);
    return 0;
}