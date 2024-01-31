//用qsort排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 40
struct names{
    char first[NUM];
    char last[NUM];
};


// void fillarray(struct names * , int n);
void showarray(const struct names *,int n);
int mycomp(const void * p1, const void * p2);

// 懒得写随机姓名的代码了。

int main(void)
{
    //double vals[NUM];
    struct names name[100] = {{"bro","no"},{"angle","wlun"},{"eternal","world"}};
    //fillarray(name,NUM);
    puts("Random list:");
    showarray(name,3);
    qsort(name,3,sizeof(struct names),mycomp);
    puts("\nSorted list:");
    showarray(name,3);
    system("pause");
    return 0;
}

/*
void fillarray(struct names * ar, int n)//随机乱码姓名
{
    int index,i;
    for ( index = 0; index < n - 1; index++)
        ar[index]->first[index] = (rand() % 65 )+ 65;
    ar->first[index] = '\0';
    for(i = 0;i < n -1; i++)
        ar->last[i] = (rand() % 65 )+ 65;
    ar->last[i] = '\0';
    
}
*/
void showarray(const struct names * ar,int n)
{
    int index;
    // printf("姓：");
    for (index = 0;index < n;index++)
    {
        printf("%s ",ar[index].first);
        printf("%s\n",ar[index].last);
    }
   /* printf("\n名:");
    for (index = 0;index < n;index++)
    {
        printf("%s\n",ar[index].last);
    }*/
            putchar('\n');
}
//升序排序
int mycomp(const void * p1, const void * p2)
{
    const struct names * a1 = (const struct names *)p1;
    const struct names * a2 = (const struct names *)p2;
    int n;
    n = strcmp(a1->first,a2->first);//比较名
    if(n != 0)//查看名是否相同，如果不同则返回值，相同则比较名
        return n;
    else 
        return n =strcmp(a1->last,a2->last);//返回名的比较值


   /* //因为是不可改的通用指针，所以转换为double类型，并且增加精度
    const double * a1 = (const double *) p1;
    const double * a2 = (const double *) p2;

    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;*/
}