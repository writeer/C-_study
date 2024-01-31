#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_node.h"

/**
 * @brief 反序排列单链表的所有节点
 *
 * @param first 链表的第一个节点指针
 * @return 指向链表新头节点的指针
 */
struct NODE* sll_reverse(struct NODE* first)
{
     if (first == NULL) // 空链表
    {
        return NULL;
    }

    struct NODE* prev = NULL; // 上一个节点指针
    struct NODE* curr = first; // 当前节点指针

    while (curr != NULL)
    {
        struct NODE* next = curr->link; // 下一个节点指针
        curr->link = prev; // 当前节点的指针指向上一个节点
        prev = curr; // 更新上一个节点指针
        curr = next; // 更新当前节点指针
    }

    return prev; // prev指向反序后的第一个节点
}