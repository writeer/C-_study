#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;

    for ( i = 0; i <= LIMIT; i++)
    {
        total += 2 * i*i + 1;
    #ifdef JUST_CHECKING  //检查是否定义，如果已定义则执行下面的指令，可以是代码，可以是变量声明，也可以是预处理，头文件
        printf("i = %d, running total = %d\n",i,total);
    #endif
    }
    printf("Grand total = %d\n",total);
//我发现我以前从来没想过，其实C的编程思路不过是说给计算机听，宏定义和平常的代码，自然可以随意放，只是预处理因为有头文件，需要合成一个储存单元
//所以预处理本身上是优化代码执行，并且把内容搞到一起，思维现在才真正打开，一切都是代码，不过是先后顺序的差别
    if(i == 5)
        #undef LIMIT
    
    #ifndef LIMIT
        printf("EXIT_FAILURE\n");
    #endif

    return 0;
}