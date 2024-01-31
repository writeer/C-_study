#include <stdio.h>


int main()
{
    int sum = 0;
    for (size_t i = 1; i <= 1000; i++)
    {
        sum += i;
    }
    printf("%d\n",sum);
    getchar();
}