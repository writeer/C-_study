#include <stdio.h>
#include <time.h>//利用时间函数，获取时钟的值。

extern unsigned int rand0(void);
extern void srand1(unsigned int x);

int main(void){
    int count;
    unsigned seed;
  
    printf("Please Enter your choice for seed.\n");
    //while (scanf("%u",&seed))
    //{
        srand1((unsigned int)time(NULL));//然后强制类型转换后生成每次不同的随机数。根据时间每次有新的种子，然后生成一串伪随机数。
         for ( count = 0; count < 5; count++)
            printf("%d\n",rand0());
        printf("Please Enter next seed(q to quit):\n");
        
    //}
    printf("Done!\n");
    fflush(stdin);
    getchar();
    return 0;
}