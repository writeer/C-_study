#include <stdio.h>

int main(void){
    char ch,t_ch;
    int num = 0;
    printf("输入字母会统计ei的次数\n");
    while ((ch = getchar()) != '#')
    {
           
        if (t_ch == 'e' && ch == 'i')
        {
            num++;
        }
        t_ch = ch;
    }
    printf("The number of occurrences of 'EI' is %d.",num);
    fflush(stdin);
    getchar();
    return 0;
}