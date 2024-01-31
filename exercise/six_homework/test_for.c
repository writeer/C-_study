#include <stdio.h>

int main(void){
    int n;
    for(n=1;n<5;printf("Please forced close\n"))//第一个语句表达式会执行一次，第二个是条件判断语句，第三个会在每次判断前执行一次。
    //空着的参数默认为真，所以：for(n=1;;printf("Please forced close\n"))与上面的语句是一样的效果，也就是无限打印printf里的内容，直到强行关闭程序。
    ;
    /*for (int i = 0; i < 0; i++)//测试for会不会执行一次，再判断条件
    {
        printf("111")//经过测试，for语句会先初始化第一个表达式，然后进行判断，为真则执行中间代码，为假则跳过。
        //如果为真，会执行内部代码，然后执行尾部语句也就i++，也就是参数汇总第三个表达式，然后再次判断，然后依据结果进行。
    }
    getchar();*/
    return 0;
}