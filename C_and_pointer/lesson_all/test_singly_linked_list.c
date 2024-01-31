/**
 * @file test_singly_linked_list.c
 * @author your name (you@domain.com)
 * @brief 本题完全由chatgpt生成
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_node.h"

void printList(struct NODE* first);

int main()
{
    struct NODE* first = NULL;

    // 创建单链表
    for (int i = 1; i <= 5; i++)
    {
        struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
        newNode->data = i;
        newNode->link = first;
        first = newNode;
    }

    printf("Original list: ");
    printList(first);

    first = sll_reverse(first);

    printf("Reversed list: ");
    printList(first);

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