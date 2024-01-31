/**
 * @file simple_data_structure.c
 * @author your name (you@domain.com)
 * @brief 其实就是个简化版链表
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    size_t num;
    struct queue *queue = NULL;
};

struct head
{
    struct queue *queue;
};


int main()
{
    struct head head;
    head.queue = (struct queue *)malloc(sizeof(struct queue));

    //下面这个写个循环，循环三次，queue.queue = (struct queue *)malloc(sizeof(struct queue));
    head.queue->queue = (struct queue *)malloc(sizeof(struct queue));
    return 0;
}

