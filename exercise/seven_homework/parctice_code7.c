#include <stdio.h>
#include <windows.h>

#define BASIC 1000
#define F_TAX 0.15//前300
#define S_TAX 0.20//后150
#define E_TAX 0.25//其余
#define WORK_OVER 1.5 //加班后算1.5倍时间
#define WORK_OTIME 40 //40小时候算加班

int main(void){
    float hours;
    float job_dollar,tax_dollar;//工资和税金
    printf("Enter your working hours:");
    scanf("%f",&hours);
    if( hours > WORK_OTIME)
        hours = (hours-WORK_OTIME) * WORK_OVER + WORK_OTIME;
    job_dollar =  hours * BASIC;
    if(job_dollar <= 300)
        tax_dollar = job_dollar * F_TAX;
    else if (job_dollar <= 452)
        tax_dollar = job_dollar * S_TAX;
    else
        tax_dollar = job_dollar * E_TAX;
    printf("Total wages = %.1f$, Taxes = %.1f$,Net income = %.1f$.\n",job_dollar,tax_dollar,job_dollar - tax_dollar);
    system("pause");
    return 0;
}