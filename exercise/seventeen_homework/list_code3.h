#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

//特定程序的声明

#define TSIZE 45 ///储存电影名的数组大小
#define MAXSIZE 100

struct film
{
    char title[TSIZE];
    int rating;
};

//一般类型定义

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct list{
    Item entries[MAXSIZE]; //内涵项的数组
    int items; //list中的项数
}List; 

/*函数原型*/

/**
 * @brief 初始化一个列表
 * @pre plist 指向一个链表
 * @post 链表初始化为空
 */
void InitializeList(List * plist);

/**
 * @brief  确定链表是否为空定义，plist指向一个已初始化的链表
 * @post 后置条件： 如果链表为空，该函数返回true；否则返回false
 * 
 */
bool ListIsEmpty(const List * plist);

/**
 * @brief 确定链表是否已满，plist指向一个已初始化的链表
 * 
 * @post 如果链表已满，该函数返回真，否则返回假
 * @return true 
 * @return false 
 */
bool ListIsFull(const List *plist);

/**
 * @brief 确定链表中的项数，plist指向一个已初始化的链表
 * @post  该函数返回链表中的项数
 * @param plist 
 * @return unsigned int 
 */
unsigned int ListItemCount(const List *plist);

/**
 * @brief 在链表末尾添加项
 * @par item是一个待添加至链表的项，plist指向一个已初始化的链表
 * @post 如果可以，该函数在链表末尾添加一个项，且返回true；否则返回false
 * @param item 
 * @param plist 
 * @return true 
 * @return false 
 */
bool AddItem(Item item,List * plist);

/**
 * @brief 把函数作用于链表中的每一项
 * 
 * @param plist 指向一个已初始化的链表
 * @param pfun 指向一个函数，该函数接受一个Item类型的参数，且无返回值
 * @post pfun指向的函数作用于链表中的每一项一次
 */
void Traverse(const List *plist,void(*pfun)(Item item));

/**
 * @brief 释放已分配的内存
 * 
 * @param plist 指向一个已初始化的列表
 * @post  释放了为链表分配的所有内存，链表设置为空
 */
void EmptyTheList(List * plist);

#endif