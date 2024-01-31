#include <stdio.h>
#include <string.h>
char * s_gets(char * st,int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 //书籍的最大数量


struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void title_print(struct book st[],int count); //按照标题字母打印
void price_print(struct book st[],int count); //按照价格打印

int main(void)
{
    struct book library[MAXBKS];//book类型结构的数组
    //我改变了原数组，可以新建指针数组，来存数组中的每一个指针，然后排序时交换指针就行，不会改变原数组。
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Plress [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title,MAXTITL) != NULL
    && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author,MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f",&library[count++].value);
        while(getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
        
        
    }
    if (count > 0)
    {   
        printf("Here is the list of your books:\n");
        for ( index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,
            library[index].value);
        }
       
             
        puts("title :");
        title_print(library,count);
        puts("price :");
        price_print(library,count);
        
    }
    else
        printf("No books?Too bad.\n");
    getchar();
    return 0;
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;;
        
    }
    return ret_val;
}

void title_print(struct book st[],int count){
    struct book  temp;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
        
        if (strcmp(st[i].title,st[j].title) > 0)//升序排列，这个函数用第一个字符串减去第二个字符串，当第一个大于第二个，就交换，这样就把小的换到前面了。
        {
            temp = st[i];
            st[i] = st[j];
            st[j] = temp;
        }
        }
    }
     for (int index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n",st[index].title,st[index].author,
            st[index].value);
        }
    return ;
}

void price_print(struct book st[],int count){
    struct book  temp;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
        
        if (st[i].value > st[j].value)
        {
            temp = st[i];
            st[i] = st[j];
            st[j] = temp;
        }
        }
    }
     for (int index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n",st[index].title,st[index].author,
            st[index].value);
        }
    return ;
}