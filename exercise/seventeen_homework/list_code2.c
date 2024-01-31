#include <stdio.h>
#include <stdlib.h>
#include "list_code2.h"

//局部函数原型
static void CopyToNode(Item item,Node * pnode);

/**
 * @brief 接口函数 把链表设置为空
 * 
 */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

bool ListIsEmpty(const List * plist)
{
    if(plist->head == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head;//设置链表的开始

    while(pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item,List * plist)
{
    Node * pnew;
    Node * scan = plist->head;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;//失败时退出函数

    CopyToNode(item,pnew);
    pnew->next = NULL;
    if (scan == NULL) //空链表
        plist->head = pnew; //把pnew放在链表开头

    else
    {
        while (scan->next)
            scan = scan->next;//找到链表末尾
        scan->next = pnew; //把pnew添加到链表末尾
        plist->end = pnew; //记录末尾的指针
    }
    return true;
}

void Traverse(const List * plist,void(*pfun)(Item item))
{
    Node * pnode = plist->head;

    while (pnode != NULL)
    {
        (*pfun)(pnode->item); //把函数用于链表中的项，直接用函数名也行
        pnode = pnode->next; //指向下一项
    }
    
}

void EmptyTheList(List * plist)
{
    Node * psave;
    while (plist->head != NULL)
    {
        psave = plist->head->next; //保存下一个节点的地址
        free(plist->head); //释放当前节点
        plist->head = psave; //前进至下一个节点
    }
    plist->end = NULL;
}


/**
 * @brief 把一个项目拷贝到节点中
 * 局部函数定义
 * 
 */
static void CopyToNode(Item item,Node * pnode)
{
    pnode->item = item;
}