#include <stdio.h>
#include <stdlib.h>
//测试指针

void show_cmp(int * pf);
int main(void)
{
    int nu[] = {1,2,3,4,5,6,7,8,9};
    int * temp = NULL,* pt;
    //temp = (int *) malloc(sizeof(int));
    printf("%p\n",temp);
    pt = temp;
    show_cmp(temp);
    // free(temp);
    printf("%p %p",pt,temp);
    getchar();
    return 0;
}

void show_cmp(int * pf)
{
    int * fm;
    pf = fm;
    printf("%p \n",pf);
}