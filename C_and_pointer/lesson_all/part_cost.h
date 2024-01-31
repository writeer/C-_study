
#ifndef safe
#define safe 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char description[20];//零件信息不超过20个字符，所以要限制输入
    int quantity;//零件数量
    double Total_price;//总价值
} cost;

/**
 * @brief 增加新零件
 * 
 * @param part 
 * @return true 
 * @return false 
 */
bool news(cost * costs);

/**
 * @brief 增加现有零件的数量
 * 
 * @param part 
 * @return true 
 * @return false 
 */
bool buy(cost * costs);

/**
 * @brief 从现有零件中减去一定数量
 * 
 */
bool shell(cost * costs);

/**
 * @brief 删除指定零件
 * 
 * @param fp 
 * @param id 零件号
 * @return true 
 * @return false 
 */
bool deletes(cost * costs);

/**
 * @brief 打印指定零件的信息
 * 
 * @param id 如果id不是数字，而是all，则打印所有信息
 */
void print_num(cost * costs);

/**
 * @brief 打印文件中所有零件的总价值
 * 
 * @param fp 
 */
void total(cost * costs);


/**
 * @brief 从文件中读取内容，并存储在临时分配的内存中
 * 
 * @param fp 
 * @return cost* 返回读取内容的数组指针
 */
cost * file_read(FILE *fp);

/**
 * @brief 写入文件
 * 
 * @param fp 
 * @param costs 
 */
void file_write(FILE *fp,cost * costs);



#endif