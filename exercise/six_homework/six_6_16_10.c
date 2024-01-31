#include <stdio.h>
#include <windows.h>

int main(void){
    int max = 1,min = 0;
    int max_sqr;//scanf的返回值
    int sum,i;
    //下面这个代码可以加入一个条件获取scanf的返回值，来判断输入是否是字符，题目没要求我就不写了，记录一下灵感。想了一下还是写写。
    printf("Enter lower and upper integer limits:");
    scanf("%d %d",&min,&max);
    while(max > min){//判断第一次输入是否规范
    do{
        
        for (i = min,sum = 0; i <= max; i++)
        {
            sum += i * i;
        }
        printf("The sums of the square from %d to %d is %d\n",min*min,max*max,sum);
        printf("Enter next set of limits:");
        scanf("%d %d",&min,&max);
    }while(max > min);//出口条件，可以不用多次打印最后的值，当这个不符合，就会跳出整个循环，然后退出程序。
    }//这个程序可以删掉do while，应该也不会用什么影响。
    printf("Done!\n");
    system("pause");
    return 0;
}