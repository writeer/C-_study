#include <stdio.h>
#include "pe12-2a.h"

static int index = 0;//模式
static double range = 0;//距离
static double fuel = 0;//燃料

void set_mode(int bo){
    if (bo < 2)
    {
        index = bo;
    }
    
    if (bo > 1)
    {
        printf("Invalid mode specified. Mode %d(us)used.\n",index);
    }
}

void get_info(){
    if(index == 0){
    printf("Enter distance traveled in kilomenters:");
    scanf("%lf",&range);
    printf("Enter fuel consumed in liters:");
    scanf("%lf",&fuel);
    }//写两个if代码更加清晰。
    if (index == 1)
    {
        printf("Enter distance travled miles:");
        scanf("%lf",&range);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf",&fuel);
    }
    
}

void show_info(){
    if (index == 0)//两个if，这样如果是错误输入，程序什么也不会做。
    {
        printf("Fuel consumptions is %.2lf liters per 100 km.\n",fuel * 100 / range);
    }
    if (index == 1)
    {
        printf("Fuel consumptions is %.1lf miles per gallon.\n",range / fuel);
    }
    
    
}