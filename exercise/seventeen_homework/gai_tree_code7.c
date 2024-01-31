#include <stdio.h>
#include "tree_code7.h"
#include <stdlib.h>

int menu(void);
void showpets(const Tree * pt);
void search(const Tree * pt);
void printitem(Item item);


int main(void)
{
    FILE * fp;
    Tree ftree;
    int ch;
    Item temp;
    if((fp = fopen("words.txt","r")) == NULL)
    {
        fprintf(stderr,"can't file.\n");
        exit(EXIT_FAILURE);
    }
    InitializeTree(&ftree);
    if(!TreeIsEmpty(&ftree))
    {
        fprintf(stderr,"tree Undefined.\n");
    }
    while (fscanf(fp,"%s",temp.word) != EOF)
    {
        if(TreeIsFull(&ftree)){//搞了半天，是这个函数没改，最多结束十位，好嘛，我的问题
           fprintf(stderr,"The tree is full\n"); break;
        }
        temp.count = 1;
        AddItem(&temp,&ftree);
    }
    
    while ((ch = menu()) != 'q')
    {
        switch (ch)
        {
        case 'a':
            showpets(&ftree);
            break;
        case 'b':
            search(&ftree);
            break;
        default:
            break;
        }
    }
    fclose(fp);
    DeleteAll(&ftree);
    return 0;
}

void search(const Tree * pt)
{
    Item item; //要查找单词的结构
    puts("输入你要查找的单词：");
    scanf("%s",item.word);
    while(getchar() != '\n')continue;
    if(In_Tree(&item,pt)){//其实不用增加方法，只要改一下方法，并且打印当前单词就行了
        item = InTree(&item,pt);
        printf("%s : count: %d\n",item.word,item.count);
    }
    else
        printf("未找到单词\n");
}

int menu()
{
    int ch;
    puts("输入下列选项统计单词出现次数。");
    puts("a) 统计所有单词出现次数");
    puts("b) 输入单词，统计这个单词的出现次数");
    puts("q) quit");
    while((ch = getchar()) != 'a' && ch != 'b' && ch != 'q'){
    fflush(stdin);
    puts("re-enter character:");
    }
    return ch;
}

void showpets(const Tree * pt)
{
    printf("一共有 :%d 项\n",TreeItemCount(pt));
    if(TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt,printitem);
}

void printitem(Item item)
{
    
    printf("word: %-19s  count: %-19d\n",item.word,item.count);
}
