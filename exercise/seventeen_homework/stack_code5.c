#include <stdio.h>
#include <string.h>
#include "stack.h"

char * s_gets(char * st,int n);


int main(void)
{
    Item temp;
    Stack stacks;
    char chr[25];
    InitializeStack(&stacks);
    puts("Enter your character(empty to quit):");
    while(s_gets(chr,25) != NULL && chr[0] != '\0'){
        for (int i = 0; chr[i] != '\0'; i++)
        {
            temp.ch = chr[i];
            // printf("%c",temp.ch);
            Push(temp,&stacks);
            if(FullStack(&stacks)) break;
        }
        puts("Enter your character(empty to quit):");
    }
    while (!EmptyStack(&stacks))
    {
        
        Pop(&temp,&stacks);
        printf("%c",temp.ch);
    }
    printf("\n");

    return 0;
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