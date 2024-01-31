#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
//书里提供了两种方法，一种是双向链表结构，也就是加入一个指向上一个结构的指针，一种是递归
//改链表比较简单，就是加一个指针记录最后的位置，形成类似队列一样的结构，并且要有一个指向父级的指针，双向遍历列表。
//但是因为递归用的少，所以这里我选择用递归
struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
};

//把显示单独用一个函数，为递归做准备
void show_movies(struct film * lp);

char * s_gets(char * st,int n);

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    //收集并储存信息
    puts("Enter first movie title:");
    while (s_gets(input,TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if(head == NULL) //第一个结构
            head = current;
        else //后续结构
            prev->next = current;
        current->next = NULL;
        strcpy(current->title,input);
        puts("Enter your rating <0-10>:");
        scanf("%d",&current->rating);
        while(getchar() != '\n')continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    //  显示电影列表
    if(head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n",current->title,current->rating);
        current = current->next;
    }
    //逆序显示
    puts("Reverse order show:");
    show_movies(head);
    //完成任务，释放内存
    current = head;//定位到链表的头指针
    while(head != NULL)//消除这个bug也比较简单，把current改成head就行，因为head指向下一个位置，如果下一个没有了就是NULL
    {
        current = head;//下面这个代码在运行时会出错原因很简单，head指向了NULL，所以current也指向了NULL，然后就找不到current->next
        head = current->next;//让头指针先指向下一位置，再释放内存
        free(current);
    }
    printf("Bye!\n");
    
    return 0;
}

void show_movies(struct film * lp){
    //  逆序显示电影列表
    if(lp == NULL)
        return;
    else
        show_movies(lp->next); //一直走到结尾
    
        printf("Movie: %s Rating: %d\n",lp->title,lp->rating);
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}