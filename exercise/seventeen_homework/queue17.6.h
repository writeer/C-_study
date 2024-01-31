//Queue的接口
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

//Item的定义，如
typedef struct item{
    long arrive;
    int processtime;
} Item;
//或者typedef struct item{...} Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node * next;
}Node;

typedef struct queue
{
    Node * front;//指向队列首项的指针
    Node * rear;//指向队列尾项的指针
    int items; //队列中的项数
}Queue;

/**
 * @brief 初始化队列
 * @par PQ指向一个队列
 * @post 队列初始化为空
 * @param pq 
 */
void InitializeQueue(Queue * pq);

/**
 * @brief 检查队列是否已满
 * @par pq指向之前被初始化的队列
 * @post 如果队列已满则返回true，否则返回false
 * @param pq 
 * @return true 
 * @return false 
 */
bool QueueIsFull(const Queue * pq);

/**
 * @brief 检查队列是否为空
 * @par pq指向之前被初始化的队列
 * @param pq 
 * @return 成功返回 true 
 * @return 否则返回 false 
 */
bool QueueIsEmpty(const Queue *pq);

/**
 * @brief 确定队列中的项数
 * @par pq指向之前被初始化的队列
 * @param pq 
 * @return int 返回队列中的项数
 */
int QueueItemCount(const Queue * pq);

/**
 * @brief 在队列末尾添加项
 * 
 * @param item 是要被添加在队列末尾的项
 * @param pq 指向之前被初始化的队列
 * @return  如果队列不为空，item将被添加在队列末尾
 * @return 该函数返回true，否则，队列不改变，该函数返回false
 */
bool EnQueue(Item item,Queue * pq);

/**
 * @brief 从队列开头删除项
 * 
 * @param pitem 
 * @param pq 指向之前被初始化的队列
 * @return 如果队列不为空，队列首段的item将被拷贝到*pitem中并被删除
 *         且函数返回true；如果该操作使得队列为空，则重置队列为空
 *         如果队列在操作前为空，该函数返回false
 * @return false 
 */
bool DeQueue(Item *pitem,Queue * pq);

/**
 * @brief 清空队列
 * 
 * @param pq 指向之前被初始化的队列
 * @return 队列被清空
 * @return false 
 */
void EmptyTheQueue(Queue * pq);

#endif