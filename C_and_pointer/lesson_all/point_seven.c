/**
 * @file point_seven.c
 * @author your name (you@domain.com)
 * @brief 把一个单词插入到索引表中，本题是第十二章第七题，也是chatgpt生成
 * 因为我大概知道该怎么写了，但是懒得写测试用例，所以选择了Ai帮忙
 * 
 * 我发现Ai写的有点问题，可能是复制的原因，我明天重新写过，还是不能偷懒
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * @brief 二级链表的节点结构体，存储一个单词和指向下一个节点的指针
 */
struct WordNode {
    char* word;             /**< 节点存储的单词 */
    struct WordNode* next;  /**< 指向下一个二级链表节点的指针 */
};
/**
 * @brief 一级链表的节点结构体，存储一个字母和一个指向该字母对应的二级链表的指针
 */
typedef struct Node {
    char letter;            /**< 节点存储的字母 */
    struct WordNode* words; /**< 指向该字母对应的二级链表的指针 */
    struct Node* next;      /**< 指向下一个一级链表节点的指针 */
} Node;



/**
 * 打印索引表中所有单词的信息
 * @param index 索引表的头指针
 */
/**
 * 打印索引表中的所有单词及其对应的页码
 * 
 * @param index 索引表
 */
void printIndexList(Node *index);
 

/**
 * @brief 清空索引表
 * 
 * @param index 指向一级链表的指针
 */
void clearIndexList(Node** index);


/**

@brief 用于插入单词到索引表中

@param list 一个指向指向一级链表的指针的指针

@param word 要插入的单词字符串

@return true 插入成功

@return false 插入失败
*/
bool insertWordToList(Node** list, char* word);
int main()
{
    // 定义索引表指针
    struct Node* index = NULL;
    char *word[] = {"apple","abple","Banana","cherry", "orange"};
    // 测试插入新单词，返回真
    bool success = insertWordToList(&index, word[0]);
    printf("Insert 'apple' success? %d\n", success);

    // 测试插入已存在的单词，返回假
    success = insertWordToList(&index, word[0]);
    printf("Insert 'apple' success? %d\n", success);

    //测试单词插入效果，也可以修改首字母大小写查看排序效果。
    success = insertWordToList(&index, word[0]);
    printf("Insert 'abple' success? %d\n", success);

    // 测试插入非字母开头的单词，返回假
    success = insertWordToList(&index, "123");
    printf("Insert '123' success? %d\n", success);

    // 测试插入新单词，返回真
    success = insertWordToList(&index, word[2]);
    printf("Insert 'banana' success? %d\n", success);

    // 测试插入新单词，返回真
    success = insertWordToList(&index, word[3]);
    printf("Insert 'cherry' success? %d\n", success);

    // 测试插入新单词，返回真
    success = insertWordToList(&index, word[4]);
    printf("Insert 'orange' success? %d\n", success);

    // 打印索引表
    printf("\nIndex list:\n");
    printIndexList(index);

    // 释放索引表内存
    clearIndexList(&index);
    system("pause");
    return 0;
}

bool insertWordToList(Node** list, char* word)
{
    Node *prev = *list; //记录当前一级指针，字母。
    Node *curr = prev; //当前一级指针。
    if(word == NULL || word[0] == '\0'){
        printf("the word is empty");
        return false;
    }
    if(!isalpha(word[0]))//第一位不是字母直接返回
        return false;
    
    int flag = 0;//效验索引是否存在
    while(curr != NULL ) //查找单词是否重复
    {
        if(curr->letter == word[0])//查看索引首字母是否相同
        {
            flag = 1;
            struct WordNode * this = curr->words;
            while(this != NULL)//查找是否有相同单词
            {
                if(strcmp(this->word,word) == 0)
                    return false;
                this = this->next;
            }
        }
        curr = curr->next;
    }

    if(flag == 0)//建立索引
    {
        Node * new = (Node *)malloc(sizeof(Node));
        new->words = NULL;
        new->next = NULL;
        if(new == NULL)
            return false;
        new->letter = word[0];
        curr = prev;//指针指向链头
        if(curr != NULL){
            Node * temp = NULL;
            int fl = 0;//效验位，效验是否成功插入，如果没有说明比所有元素都小，插入到链尾
            while (curr != NULL)//一级指针字母排序
            {
                if(new->letter < curr->letter)
                {
                    if(curr == prev){
                        new->next = *list;
                        *list = new;
                        fl = 1;
                        break;
                    }
                    else{
                        new->next = curr;
                        temp->next = new;
                        fl = 1;
                        break;
                    }
                }
                temp = curr;
                curr = curr->next;
            }
            if(fl == 0)
            {
                new->next = NULL;
                temp->next = new;
            }
        }
        else{
            new->next = NULL;
            *list  = new;
        }
    }
    prev = *list;//重新记录更新后的链头
    struct WordNode * str = (struct WordNode *)malloc(sizeof(struct WordNode)); // 建立二级链表储存单词
    str->next = NULL;
    str->word = word;//本质上是二级链表指针指向输入过来的单词位置，储存位置还是在原来的内存，如果要把数据存在结构中最好还是开辟一点内存，这样不会改动原字符串
    curr = prev; // 回到一级链表头
    while (curr != NULL)
    {
        if(curr->letter == word[0])//找到对应的字母
        {
            struct WordNode * this = curr->words;
            struct WordNode * root = this;//初始指针用于特殊情况，更新头指针
            struct WordNode * prev = NULL;//保存上一个节点
            if(this == NULL)
            {
                str->next = NULL;
                curr->words = str;
                break;
            }
            while(this != NULL){//比较单词排序
                if(strcmp(str->word,this->word) < 0)
                {
                    if(this == root)
                    {
                        str->next = this;
                        curr->words = str;
                        break;
                    }
                    else {
                        str->next = this;
                        prev->next = str;
                        break;
                    }
                }
                else{//如果上面没执行，说明在链尾
                        str->next = NULL;
                        this->next = str;
                        break;
                }
                prev = this;
                this = this->next;
        }
        }
        curr = curr->next;
    }
    return true;
}
    
    /*
    bool insertWordToList(Node** list, char* word)
{
    if (word == NULL || word[0] == '\0') {
        printf("The word is empty.\n");
        return false;
    }

    char first_letter = word[0];
    Node* prev = NULL;
    Node* curr = *list;
    while (curr != NULL && curr->letter < first_letter) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL || prev->letter != first_letter) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        if (new_node == NULL) {
            return false;
        }
        new_node->letter = first_letter;
        new_node->words = NULL;
        new_node->next = curr;
        if (prev == NULL) {
            *list = new_node;
        } else {
            prev->next = new_node;
        }
        prev = new_node;
    }

    struct WordNode* new_word_node = (struct WordNode*) malloc(sizeof(struct WordNode));
    if (new_word_node == NULL) {
        return false;
    }
    new_word_node->word = word;
    new_word_node->next = NULL;

    struct WordNode* prev_word_node = NULL;
    struct WordNode* curr_word_node = prev->words;
    while (curr_word_node != NULL && strcmp(curr_word_node->word, word) < 0) {
        prev_word_node = curr_word_node;
        curr_word_node = curr_word_node->next;
    }

    if (prev_word_node == NULL) {
        new_word_node->next = curr_word_node;
        prev->words = new_word_node;
    } else {
        prev_word_node->next = new_word_node;
        new_word_node->next = curr_word_node;
    }

    return true;
}*/



void printIndexList(Node *index)
{
    Node * curr = index;
    while (curr != NULL)
    {
        printf("首字母: %c\n",curr->letter);
        struct WordNode * second= curr->words;//二级指针
        printf("单词: ");
        while (second != NULL)
        {
            printf("%s ",second->word);
            second = second->next;
        }
        printf("\n");
        curr = curr->next;
    }
    
}

void clearIndexList(Node** index)
{
     if (*index == NULL) {
        return;
    }
    
    Node * prev = *index;
    while (prev != NULL)
    {
        struct WordNode * second = prev->words;//指向第二级链表的指针
        struct WordNode * temp = NULL;//临时指针
        while (second != NULL)
        {
            temp = second;
            second = second->next;
            free(temp);
        }
        
        Node *tempNode = prev;
        prev = prev->next;
        free(tempNode);
    }
    
    *index = NULL;
}