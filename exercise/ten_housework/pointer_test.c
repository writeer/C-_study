#include <stdio.h>

int main(void){
    int ref[] = {8,4,0,2};
    int *ptr;
    int index;
    for ( index = 0,ptr = ref; index < 4; ptr++,index++)
    {
        printf("%d %d\n",ref[index],*ptr);
    }
    getchar();
    return 0;
    /*
    //下面这个是复习题，第一个输出16，是因为数组按顺序存储，在地址中是连续的，所以从[0][0],[0][1]，这样顺序存了数字。
    //第二个输出14，因为按照[0][0],[0][1]，因为有括号，所以是按照括号的优先级来存储的，所以[0][1]被填充为零，然后存储后面两个数字
    //而ptr+2指向的是[0][0]后面的地址，所以后面的地址的值是多少，解引用就会得到多少
    int * ptr;
    int torf[2][2]={12,14,16};
    ptr = torf[0];
    printf("%d",*(ptr+2));
    int * ptr;
    int frot[2][2]= {{12},{14,16}};
    ptr = frot[0];
    printf("%d",*(ptr));
    getchar();*/
}