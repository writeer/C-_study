#include <stdio.h>
/*这个程序会记录输入字符数量以及空格和换行的数量，输入#停止*/
int main(void){
    char ch;
    int n_space,n_enter,n_character;
    n_space = n_enter = n_character = 0;
    while((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '\n':
            n_enter++;
            break;
        case ' ':
            n_space++;
            break;
        default:
            n_character++;
            break;//tab会被统计为字符
        }
    }
    printf("space = %d,enter = %d,character = %d",n_space,n_enter,n_character);
    fflush(stdin);
    getchar();
    return 0;
}