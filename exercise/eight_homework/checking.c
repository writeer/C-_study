#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//验证输入是一个整数
long get_long(void);
//验证范围上下限是否有效
bool bad_limits(long begin,long end,long low,long high);
//计算a-b之间的整数平方和
double sum_squares(long a,long b);

int main(void){
    const int MIN = -10000000;//下限
    const int MAX = +10000000;//上限
    long start;//用户指定范围的最大值
    long stop;//用户...最小值
    double answer;
    printf("This program computes the sum of the sqares of" 
    "integers in a range.\nThe lower bound shoult not be less"
    "than -10000000 and\nthe upper bound should not be more"
    "that +10000000.\nEnter the limits(enter 0 for both limits to quit):\n"
    "lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (stop != 0 || start != 0)//上限或者下限不为零
    {
        if(bad_limits(start,stop,MIN,MAX))
            printf("Please try again.\n");
        else{
            answer = sum_squares(stop,start);
            printf("The sum of the squares of the integers ");
            printf("from %ld to %ld is %g\n",start,stop,answer);
        }
        printf("Enter the limits(enter 0 for both limits to quit):\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }
    printf("Done!\n");
    system("pause");
    return 0;
}

long get_long(void){
    long input;
    char ch;
    while (scanf("%ld",&input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer.\nPlease enter an");
        printf("integer value,such as 25,-178 or 3:");
    }
    return input;
}

double sum_squares(long a,long b){//计算a-b之间所有数字的平方和
    double total = 0;
    long i;
    for(i = a;i < b; i++)
        total = (double)i * (double)i;
    return total;
}

bool bad_limits(long begin,long end,long low,long high){
    bool not_good = false;
    if (begin > end)
    {
        printf("%ld isn't smaller than %ld\n",begin,end);
        not_good = true;
    }
    if(begin < low || end < low)
    {
        printf("Values mast be %ld or greater.\n",low);
        not_good = true;
    }
    if(begin > high || end > high)
    {
        printf("Values mast be %ld or less.\n",high);
        not_good = true;
    }
    return not_good;
}