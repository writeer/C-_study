/**
 * @file sll_remove.c
 * @author your name (you@domain.com)
 * @brief 从链表中移除一个节点
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_linked_node.h"

/**
 * @brief 删除一个节点
 * 
 * @param rootp 根指针
 * @param node 需要删除的节点指针
 * @return int 
 */
bool sll_remove(struct NODE **rootp,struct NODE *node);
void printList(struct NODE* first);

int main()
{
    struct NODE* first = NULL;
    struct NODE* curr = NULL;//记录要删除的指针

    // 创建单链表
    for (int i = 1; i <= 5; i++)
    {
        struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
        newNode->data = i;
        newNode->link = first;
        first = newNode;//每次建立一个新链头
        if(i == 2)//不能删除链头，除非多声明一个结构用来保存链头，否则删除链头后，找不到新链头，依靠函数返回不方便，最好是有单独变量
            curr = newNode;
    }

    printf("Original list: ");
    printList(first);

    if(sll_remove(&first,curr)){
        printf("Reversed list: ");
        printList(first);
    }
    else{
        printf("defeated.\n");
    }
   

    // 释放链表内存
    while (first != NULL)
    {
        struct NODE* temp = first;
        first = first->link;
        free(temp);
    }

    system("pause");
    return 0;
}

/**
 * @brief 输出单链表的所有节点的值
 *
 * @param first 链表的第一个节点指针
 */
void printList(struct NODE* first)
{
    struct NODE* curr = first;

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }

    printf("\n");
}

bool sll_remove(struct NODE **rootp,struct NODE *node)
{
    struct NODE *prev = *rootp;//记录上一个节点
    struct NODE *curr = prev;
    if(prev == NULL)
        return false;
    while (curr != NULL)
    {
        if(curr == node){
            prev->link = curr->link;
            free(curr);
            return true;
        }
        prev = curr;
        curr = prev->link;
    }
    return false;
}