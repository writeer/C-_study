#include <stdio.h>
#include <windows.h>
int main(void){
    int num,modulo,tow;
    printf("这个程序可以用作求整数的模。\n");
    printf("This porgram computes modulo.\n");
    printf("Enter an integer to serve as the second operand:");
    scanf("%d",&tow);
    num = 1;
    printf("Now enter the first operand:");//上面保证第一次执行
    fflush(stdin);
    scanf("%d",&num);
    modulo = num % tow;
    printf("%d %% %d is %d \n",num,tow,modulo);
        while (num > 0)
        {
            printf("Enter next number for first operand(<= 0 tp quit):");//第二次开始循环可以保证语言通顺
            scanf("%d",&num);
            modulo = num % tow;
            printf("%d %% %d is %d \n",num,tow,modulo);
        }
    //经过后面第六章的学习这里可以用for循环来解决printf的问题，可以这样构造
   /* for(printf("Now enter the first operand:");num>0;printf("Enter next number for first operand(<= 0 tp quit):")){
        scanf("%d",&num);
        modulo = num % tow;
        printf("%d %% %d is %d \n",num,tow,modulo);
    }
    //这样代码更加简洁，并且效果也是一样的。
    后面学习后，我发现这样代码还是有瑕疵，应该把条件改为从scanf的返回值，这样可以判断字符输入。并且出口条件也不行，会多执行一次，多打印一次。
    最好还是引入if语句用break，可惜现在还没学到，要改动正常会让代码变得冗长，就暂时保持这样。
    或者用do while来解决，但是scanf的返回值判断是必须的，我不太清楚这里有没有学到了，但是比如要scanf的返回值才能检测是否输入数字，所以应该是学到了。
    后面的代码我用do whlie成功解决了多次打印的问题，这里好像没有学到嵌套循环，如果用嵌套循环会比较好解决，如果不用，就很麻烦，几乎解决不了。
    */
        printf("Done!\n");
        system("pause");
    return 0;

}