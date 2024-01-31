#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
/*这个程序是7的改写，加了一个工资选择表，效果都是计算工资额度和税金，以及净收入*/
#define F_TAX 0.15//前300
#define S_TAX 0.20//后150
#define E_TAX 0.25//其余
#define WORK_OVER 1.5 //加班后算1.5倍时间
#define WORK_OTIME 40 //40小时候算加班

int main(void){
    float hours,basic;
    float job_dollar,tax_dollar;//工资和税金
    int num = 6;
    bool is = true;
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                          2) $9.33/hr\n");
    printf("3) $10.00/hr                         4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
    printf("Select the number as above:");
    while(num > 5){
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            basic = 8.75;
            break;
        case 2:
            basic = 9.33;
            break;
        case 3:
            basic = 10.00;
            break;
        case 4:
            basic = 11.20;
            break;
        case 5:
            is = false;
            break;
        default:
            printf("Plaese re-enter:\n");
            continue;
        }
    }
    if(is){
    printf("Enter your working hours:");
    scanf("%f",&hours);
    if( hours > WORK_OTIME)
        hours = (hours-WORK_OTIME) * WORK_OVER + WORK_OTIME;
    job_dollar =  hours * basic;
    if(job_dollar <= 300)
        tax_dollar = job_dollar * F_TAX;
    else if (job_dollar <= 452)
        tax_dollar = job_dollar * S_TAX;
    else
        tax_dollar = job_dollar * E_TAX;
    printf("Total wages = %.1f$, Taxes = %.1f$,Net income = %.1f$.\n",job_dollar,tax_dollar,job_dollar - tax_dollar);
    }
    system("pause");
    return 0;
}