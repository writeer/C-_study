#include <stdio.h>
#include <stdlib.h>

int is_within(int n,const char * chr);

int main(void){
    char tr[80];
    char cr;
    int n = 1;
    while (n)
    {
    fflush(stdin);
    puts("输入一个字符串：");
    fgets(tr,80,stdin);
    puts("输入一个字符(输入上述字符串中没有的字符退出):");
    scanf("%c",&cr);
    n = is_within(cr,tr);
    if (n)
        printf("n is %d\n",n);
    else
        printf("n is %d\n",n);
    }
    system("pause");
    return 0;

}

int is_within(int n,const char * chr){
    while (*chr != '\0' && *chr != n)
        chr++;
    return (*chr == n? 1 : 0);
}