#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MIN 1

void print(void);
int analyzed(int , int);

int main(void){
    int num;
    print();
    num = analyzed(MAX,MIN);
    if (num == 4)
    {
        /*直接退出*/
    }
    
    system("pause");
    return 0;
}

void print(void){
    printf("Please choose one of the following:\n" 
    "1)copy files         2)move files\n"
    "3)remove files       4)quit\n");
    printf("Enter the number of your choice:");
    return;
}

int analyzed(int num,int munb){
    int number;
    
    while (scanf("%d",&number) == 1)
    {
        if (number < 1 || number > 4)
        {
            print();
        }
        /*如果是1~4中间，的话在后面执行*/
    }
    return 4;
    
}