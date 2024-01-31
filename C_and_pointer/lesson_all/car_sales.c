/**
 * @file edit.c
 * @author your name (you@domain.com)
 * @brief 模拟汽车销售,为它编写一个声明
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>


struct customer//顾客信息
{
    char customer_name[20];
    char customer_address[40];
    char model[20];
};

struct full_sales//全额销售
{
    struct customer customers;
    float manufacturer;
    float actual;
    float sales_tax;
    float licensing;
};

struct lease_sales//租赁销售
{
    struct customer customers;
    float manufacturer;
    float actual;
    float down_payment;
    float security_deposit;
    float monthly_payment;
    int lease_term;
};


struct loan_sales//贷款销售
{
    struct customer customers;
    struct full_sales loan;
    float doun_payment;
    int loan_duration;
    float interest_rate;
    float monthly_payment;
    char name_of_bank[20];
};




int main()
{
    
    return 0;
}