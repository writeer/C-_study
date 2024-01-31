#include <stdio.h>
#include <stdlib.h>
/*以二进制形式打印整数*/
void to_binary(unsigned long n);

/*unsigned long Fibonacci(unsigned n){
   //这个代码是书里实例的斐波那数列当我看到时，我心中就觉得这个代码不正确，所以我实验了一下，事实上也如此。
   //问题在于，书里只是举了一个例子，所以问题不大，进行检验只是因我看到代码后的好奇而已。
    if( n > 2) 
        return Fibonacci(n-1) + Fibonacci(n+2);
    else
        return 1;
}*/

int main(void){
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu",&number) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done!\n");
    system("pause");
    return 0;
}

void to_binary(unsigned long n){
    int r;
    r = n % 2;
    if (n >= 2)
        to_binary(n/2);
    putchar(r == 0 ? '0':'1');
    return;
}