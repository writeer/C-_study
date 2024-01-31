#include <stdio.h>

int main(void){
    char ch;
    /*输入
    q
    c
    h
    b
    预计会打印，q，Step 1，Step 2.Step 3
    c,打印,Step 1
    h，打印,Step 1,Step 3.
    b，Step 1,退出循环
    */
    while ((ch = getchar()) != '#')
    {
        if(ch == '\n')
            continue;
        printf("Step 1\n");
        if(ch == 'c')
            continue;
        else if(ch == 'b')
            break;
        else if(ch == 'h')
            goto laststep;
        printf("Step 2\n");
        laststep : printf("Step 3\n");
    }
    printf("Done!");
    fflush(stdin);
    getchar();
    return 0;
}