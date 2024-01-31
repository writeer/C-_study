//与queue.c一起编译
#include <stdio.h>
#include "queue17.6.h"

int main(void)
{
    Queue line;
    Item temp;//因为ADT里的是typedef int Item 可以把Item换成其他任何结构，并修改测试代码就行
    char ch;

    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if(ch != 'a' && ch != 'd') //忽略其他输出
            continue;
        if(ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d",&temp);
            if(!QueueIsFull(&line))
            {
                printf("Putting %d into queue\n",temp);
                EnQueue(temp,&line);
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if(QueueIsEmpty(&line))
                puts("Nothing to delete!");
            else
            {
                DeQueue(&temp, &line);
                printf("Removing %d from queue\n",temp);
            }
        }
        printf("%d items in queue\n",QueueItemCount(&line));
        puts("Type a to add,d to delete, q to quit:");

    }
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
    
}