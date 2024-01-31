#include <stdio.h>
#include <stdlib.h>
//一个菜单测试函数
typedef void (*test)(void);

void fp1(void);
void fp2(void);
void fp3(void);
void fp4(void);

int main(void){
    test menu[]={fp1,fp2,fp3,fp4};
    int ch;
    puts("**************选择食物**************");
    puts("a) 西红柿                b) 番茄炒蛋");
    puts("c) 人肉叉烧包            d) 波霸奶茶");
    printf(":");
    ch = getchar();//这里就不处理换行符了，反正题目要求就是写一写函数指针数组，如果不用typedef，可以直接void (*test)(void)[] ={}
    if(ch == 'a')
        menu[0]();
    else if(ch == 'b')
        menu[1]();
    else if(ch == 'c')
        menu[2]();
    else if(ch == 'd')
        menu[3]();
    system("pause");
    return 0;
}

void fp1(void){printf("健康的选择!\n");}
void fp2(void){printf("经典的选择!\n");}
void fp3(void){printf("恶心的选择!\n");}
void fp4(void){printf("嘿嘿嘿\n");}