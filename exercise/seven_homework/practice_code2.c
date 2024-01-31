#include <stdio.h>
#include <windows.h>
/*这个程序会打印每个字符相应的ascll码，每八个一行，按#退出*/
int main(void){
    char ch;
    printf("enter (# to quit)\n");
    for (int i = 0; (ch = getchar()) != '#'; i++)
    {
        if (i % 8 == 0){
            i = 0;
            printf("\n");
            }
        if(ch != '\n')
            printf("%d,\'%c\' = %d ",ch,(int)ch);
        else
            i = 0;
            continue;
    }
    system("pause");
    return 0;
}