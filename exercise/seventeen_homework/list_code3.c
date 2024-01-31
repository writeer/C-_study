#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_code3.h"

//局部函数原型
static void CopyToNode(Item item,Item * pnode);

/**
 * @brief 接口函数 把链表设置为空
 * 
 */
void InitializeList(List * plist)
{
    plist->items = 0;
    plist->entries[0].title[0] = plist->entries[MAXSIZE -1].title[0] = '0';
    plist->entries[0].rating = plist->entries[MAXSIZE -1].rating = 0;
}

bool ListIsEmpty(const List * plist)
{
    if(plist->entries[0].title[0] == '0')
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    bool full;
    if(plist->entries[MAXSIZE - 1].title[0] != '0')
        full = true;
    else
        full = false;

    return full;
}

unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

bool AddItem(Item item,List * plist)
{
    Item * temp = &(plist->entries[plist->items]);

    CopyToNode(item,temp);
    if(plist->entries[plist->items].title[0] == '0')
        return false;
    plist->items++;
    return true;
}

void Traverse(const List * plist,void(*pfun)(Item item))
{

    for (int i = 0; i < plist->items; i++)
    {
        (*pfun)(plist->entries[i]);
    }
    
    
}

void EmptyTheList(List * plist)
{
    Item zero = {'0',0};
    for (int i = 0; i < MAXSIZE;i++)
    {
        plist->entries[i] = zero;
    }
    plist->items = 0;
}


/**
 * @brief 把一个项目拷贝到节点中
 * 局部函数定义
 * 
 */
static void CopyToNode(Item item,Item * pnode)
{
    *pnode = item;
}