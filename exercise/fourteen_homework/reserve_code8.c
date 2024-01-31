#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//明天再写，想玩游戏。
#define PMAX 12
enum book{unsubribed, subscribed};//座位是否预定

struct name{
    char name[10];
    char surname[10]; //姓氏
};

struct plane //飞机座位
{
    char s_number[5]; //座位编号
    struct name names; //姓名
    enum book bol; //判断是否已被预定
};

void show_menu();//显示菜单
void re_seats(struct plane * st);//预订座位
void de_seats(struct plane * st);//删除预订
char * s_gets(char * st,int n);
int main(void){
    struct plane planes[PMAX] = {
        {"A1","\0","\0",unsubribed},{"A2","\0","\0",unsubribed},{"A3","\0","\0",unsubribed},
        {"B1","\0","\0",unsubribed},{"B2","\0","\0",unsubribed},{"B3","\0","\0",unsubribed},
        {"C1","\0","\0",unsubribed},{"C2","\0","\0",unsubribed},{"C3","\0","\0",unsubribed},
        {"D1","\0","\0",unsubribed},{"D2","\0","\0",unsubribed},{"D3","\0","\0",unsubribed},
    };
    char ch;
    int count;
    
    show_menu();
    while ((ch = getchar()) != 'f')
    {
        while(getchar() != '\n')//如果用户输入多个字符，清理剩下的字符
            continue;
        if (islower(ch) == 0)//如果第一个字符获取的是大写字符，改为小写
            ch = tolower(ch);
        if (ch == 'f') //  如果输入的是大写F直接退出循环
            break;
        switch (ch)
        {
        case 'a':
            count = 0;
            for (int i = 0; i < PMAX; i++)
            {    
                if(!planes[i].bol)
                    count++;
            }
            printf("emptr seats is %d.\n",count);
            break;
        case 'b':
            for (int i = 0; i < PMAX; i++)
            {
                if(!planes[i].bol){
                    printf("%s ",planes[i].s_number);
                }
            }
            printf("is empty\n");
            break;
        case 'c'://因为初始化了一下数组，一开始就是按照字母排序的，所以不用排序
            for (int i = 0; i < PMAX; i++)
                printf("%s by %s %s\n",planes[i].s_number,planes[i].names.name,planes[i].names.surname);
            
            break;
        case 'd':
            re_seats(planes);
            break;
        case 'e':
            de_seats(planes);
            break;
        default:
            printf("Please re-enter:\n");
            break;
        }
        show_menu();
    }
    
}


void show_menu(){
    puts("To choose a function, enter its letter lable:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}

void re_seats(struct plane * st){
    char ch[5];
    int bol = 0;//用于判断是否成功输入，如果输入座位号不存在，则提示重新错误
    printf("Enter the seat number you want to reserve:");
    s_gets(ch,5);
    for (int i = 0; i < PMAX; i++)
    {
        if(strcmp(st[i].s_number,ch) == 0){
            if(!st[i].bol){
            printf("Enter your name:");
            s_gets(st[i].names.name,PMAX);
            printf("Enter your last name:");
            s_gets(st[i].names.surname,PMAX);
            st[i].bol = subscribed;
            bol = 1;
            }
            else
                printf("The seat you selected has been reserved.\n");
        }  
    }
    if(!bol)
        printf("Enter the seat number in the list.\n");
}

void de_seats(struct plane * st){
    char ch[5];
    int bol = 0;
    printf("Enter the seat number you want to delete:");
    s_gets(ch,5);
    for (int i = 0; i < PMAX; i++)
    {
        if (strcmp(st[i].s_number,ch) == 0)
        {
            if (!st[i].bol)
                printf("Nobady reserved this seat.\n");
            else{
                st[i].bol = unsubribed;
                for(int j = 0;j < 10;j++){
                st[i].names.name[j] = '\0';
                st[i].names.surname[j] = '\0';
                bol = 1;
                }
            }
        }
    }
    if(!bol)
        puts("Enter the seat number in the list.");
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