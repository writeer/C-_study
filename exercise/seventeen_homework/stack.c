#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static void CopyItem(Item * item,Stack * st); 
static void CopyItem_Pop(Item * item,Stack * st);

void InitializeStack(Stack * ps){
    ps->prev = NULL;
    ps->next = NULL;
    ps->i = 0;
}

bool FullStack(const Stack * ps)
{
    Stack * pnew;
    bool full;
    pnew = (Stack *) malloc(sizeof(Stack));
    if(pnew == NULL)
        full = true;
    else
        full = false;
    free(pnew);
    return full;
}

bool EmptyStack(const Stack * ps)
{
    return (ps->i == 0) ? true : false;
}

bool Push(Item item, Stack * ps)
{
    Stack * temp,* ptemp = ps;
    temp = (Stack *) malloc(sizeof(Stack));
    if(temp == NULL)
        return false;
    if(EmptyStack(ps)){
            ps->next = NULL;
            ps->prev = NULL;
            CopyItem(&item,ps);
            ps->i++;
    }
    else
        {
            while(ptemp->next)
                ptemp = ptemp->next;
            ptemp->next = temp; // 链接到后面
            temp->prev = ptemp; //记录上一个指针的位置，结果我还是用了双向链表
            temp->next = NULL;
            CopyItem(&item,temp);
            // printf("%c\n",temp->items.ch);
            ps->i++;
        }
    
        
    return true;

}

bool Pop(Item * pitem, Stack * ps)
{
    Stack * temp = ps;
    if(EmptyStack(ps))
        return false;
    while(temp->next)//找到最后一个元素
        temp = temp->next;
    CopyItem_Pop(pitem,temp);
    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        temp->next = NULL;
    free(temp);
    ps->i--;
    return true;
        
}

static void CopyItem(Item * item,Stack * st)
{
    st->items = *item;
}

static void CopyItem_Pop(Item * item,Stack * st)
{
    *item = st->items;
}