#include <stdio.h>
#include <time.h>
#include <stdlib.h> //提供srand和rand
#define SIZE 25

void rand_show(const int * st,int n,int select);

int main(void)
{
    int number[SIZE];
    int n;
    for(int i = 0;i < 25;i++)
        number[i] = i + 1;
    printf("输入你想要随机显示的次数(0 - 25):");
    scanf("%d",&n);
    rand_show(number,SIZE,n);//可以设置为交互式，改变第三函数的选取值
    return 0;
}

void rand_show(const int * st,int n,int select)
{
    srand(select);//这样每次输入的值不一样，随机就不一样，或者改成根据时间用time(NULL)每次有一个伪随机数
    int record[select]; //用变长数组来记录每一次的值，保证不会重复输出
    int random;
    for (int i = 0; i < select; i++)
    {
        random = rand() % n;
        for(int j = 0;j < i;j++)
            if(random == record[j])
            {
                random = rand() % n;
                j = 0;
            }
        printf("random : %d \n",st[random]);
        record[i] = random;
    }
    
}