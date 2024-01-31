//实现栈有两种方式，一个是链表，一个是数组
//区别在于储存方式，其他没什么。
//用链表的话，添加删除都在尾部就行，需要记录尾指针
//用数组的话，需要找到最后一个元素在哪里，并且不要超过数组边界
//所以我决定用链表
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef struct item
{
    char ch;
}Item;

typedef struct stack
{
    Item items;
    struct stack * prev; //上一个所在的位置
    struct stack * next;
    int i;
}Stack;

/**
 * @brief 初始化栈
 * 
 * @param ps 指向一个栈
 * @return 该栈被初始化为空
 */
void InitializeStack(Stack * ps);

/**
 * @brief 检查栈是否已满
 * 
 * @param ps 指向已被初始化的栈
 * @return true 
 * @return false 
 */
bool FullStack(const Stack * ps);

/**
 * @brief 检查栈是否为空
 * 
 * @param ps 指向已被初始化的栈
 * @return true 如果空返回
 * @return false 否则返回
 */
bool EmptyStack(const Stack * ps);

/**
 * @brief 把栈压入栈顶
 * 
 * @param item 待压入栈的项
 * @param ps 指向初始化的栈
 * @return true 栈不满，把item放在栈顶，返回
 * @return false 否则，栈不变，返回
 */
bool Push(Item item, Stack * ps);

/**
 * @brief 从栈顶删除项
 * 
 * @param pitem 
 * @param ps 指向之前已被初始化的栈
 * @return true 如果栈不为空，把栈顶的item拷贝到*pitem
 *         删除栈顶的item，该函数返回true；
 *         如果该操作后栈中没有项，则重置该栈为空
 * @return false 如果删除操作直接栈为空，栈不变，该函数返回
 * 
 */
bool Pop(Item * pitem, Stack * ps);

//因为题目要求返回字符串逆序字符显示，结束后栈刚好为空，所以就不写清空栈了。

#endif