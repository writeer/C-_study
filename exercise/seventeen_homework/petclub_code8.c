//使用二叉查找数
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree_code8.h"
//这题做到这里基本已经完成了，但是如果要根据这个修改菜单的全部功能，就还有一个东西要改。
//那就是删除，在删除时要考虑名字，然后找到对应节点后，在比较宠物名，然后返回一个整数值，并且当前节点的索引index--
//然后根据返回的整数值，清空对应数组中存储的种类名，但是，还有一个偷懒的办法，那就是直接减少当前索引index
//反正数组的内存是分配好的，清空不清空都行，等着写新数据的时候覆盖就好了，和windows的方法一样。
//但是直觉--有一个问题，那就是如果你要删除的字符不在数组最后，那就很麻烦。
//并且删除后，要让被删除数据之后的数组，前进一，这也是书里提到的，数组插入和删除和很费时。
//所以如果我再弄一个链表来储存这个种类名，或者新建一颗树，把种类名的头指针存在结构里，也都是可行的。
//可以复用查找项的方法，还有删除项的方法，以及添加节点的方法。
//也就是一棵树的节点里，存着另一颗树。
//又或者，直接写一个关于数组的插入和删除的方法，并且还得有一个比较方法。
//之所以写了这么多想法，是因为想归纳一下好不好写。所以写这么多字，就是不想写这一段代码。

/**                                   至此，全书完，我的C语言学习也将告一段落                                       **/
char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st,int n);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a': addpet(&pets);
            break;
        case 'l': showpets(&pets);
            break;
        case 'f': findpet(&pets);
            break;
        case 'n': printf("%d pets in club\n",
                    TreeItemCount(&pets));
            break;
        case 'd': droppet(&pets);
            break;
        default: puts("Switching error");
            break;
        }
    }
    DeleteAll(&pets);
    puts("Bye.");
    
}

char menu(void)
{
    int ch;

    puts("Nerfville pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet         l) show list of pets");
    puts("n) number of pet     f) find pets");
    puts("d) delet a pet       q) quit");
    while ((ch = getchar()) != EOF)
    {
        while(getchar() != '\n');

        ch = tolower(ch);
        if(strchr("alrfndq",ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}

void addpet(Tree * pt)
{
    Item temp;

    if(TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname,SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind[0],SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind[0]);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt)
{
    if(TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt,printitem);
}

void printitem(Item item)
{
     for (int i = 0; i <=item.index; i++)
        {
            printf("Pet: %-19s  Kind: %-19s\n",item.petname,item.petkind[i]);
        }
}

void findpet(const Tree * pt)
{
    Item temp;
    Item * rtemp; //接受返回指针
    if(TreeIsEmpty(pt))
    {
        puts("No entries!");
        return ; //如果树为空，则退出该函数
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname,SLEN);
    puts("Please enter pet kind:");
    //s_gets(temp.petkind,SLEN);
    uppercase(temp.petname);
    //uppercase(temp.petkind);
    printf("%s ",temp.petname);
    if((rtemp = InTree(&temp,pt))){
        printf("is a member.\n");
        for (int i = 0; i <= rtemp->index; i++)
        {
            printf("    is petkind: %s \n",rtemp->petkind[i]);
        }
        
    }
    else
        printf("is not a member.\n");
}

void droppet(Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return; //如果树为空，则退出该函数
    }
    
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname,SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind[0],SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s the %s ",temp.petname,temp.petkind[0]);
    if(DeleteItem(&temp, pt)){
        printf("is dropped from the club.\n");
        pt->size--; //我发现原来的 方法没有记录删除的数据，导致一直不会减少树的项数
    }
    else
        printf("is not a member.\n");    
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
    
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}