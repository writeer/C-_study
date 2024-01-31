#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
};

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
    //完成任务，释放内存
    current = head;//定位到链表的头指针
    while(current != NULL)//消除这个bug也比较简单，把current改成head就行，因为head指向下一个位置，如果下一个没有了就是NULL
    {
        current = head;//下面这个代码在运行时会出错原因很简单，head指向了NULL，所以current也指向了NULL，然后就找不到current->next
        head = current->next;//让头指针先指向下一位置，再释放内存
        free(current);
    }
    printf("Bye!\n");
    
    return 0;
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