/*tree.h 二叉查找数*/
//树种不允许有重复的项
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
//根据具体情况重新定义 Item
#define SLEN 20

typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
}Item;

#define MAXITEMS 10

typedef struct trnode
{
    Item item;
    struct trnode * left;
    struct trnode * right;
}Trnode;

typedef struct tree
{
    Trnode * root;//指向根节点
    int size; //树的项数
}Tree;

//函数原型

/**
 * @brief 把树初始化为空
 * 
 * @param ptree 指向一棵树
 * @return 树被初始化为空
 */
void InitializeTree(Tree * ptree);

/**
 * @brief 确定树是否为空
 * 
 * @param ptree 指向一棵树
 * @return true 如果树为空返回
 * @return false 否则返回
 */
bool TreeIsEmpty(const Tree * ptree);

/**
 * @brief 确定树是否已满
 * 
 * @param ptree 指向一棵树
 * @return true 如果满返回
 * @return false 否则返回
 */
bool TreeIsFull(const Tree * ptree);

/**
 * @brief 确定树的项数
 * 
 * @param ptree 指向一颗树
 * @return 返回树的项数
 * 
 */
int TreeItemCount(const Tree * ptree);

/**
 * @brief 在数中添加一个项
 * 
 * @param pi 待添加的地址
 * @param ptree 指向一颗已初始化的树
 * @return true 成功添加，返回
 * @return false 否则返回
 */
bool AddItem(const Item * pi, Tree * ptree);

/**
 * @brief 在树中查找一个项
 * 
 * @param pi 指向一个项
 * @param ptree 指向一颗已初始化的树
 * @return true 如果添加一个项，返回
 * @return false 否则
 */
bool InTree(const Item * pi,const Tree * ptree);

/**
 * @brief 从书中删除一个项
 * 
 * @param pi 删除项的地址
 * @param ptree 指向一颗已初始化的树
 * @return true 成功删除返回
 * @return false 否则返回
 */
bool DeleteItem(const Item * pi,Tree * ptree);

/**
 * @brief 把函数应用于树中的每一项
 * 
 * @param ptree 指向一颗树
 * @param pfun 指向一个函数，接受一个Item类型的参数，并无返回值
 * @return pfun 指向的这个函数为树中的每一项执行一次
 */
void Traverse(const Tree * ptree,void(*pfun)(Item item));

/**
 * @brief 删除树中的所有内容
 * 
 * @param ptree 指向一个已初始化的树
 * @return 树为空
 */
void DeleteAll(Tree * ptree);

#endif