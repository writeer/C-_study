/**
 * @file def.c
 * @author your name (you@domain.com)
 * @brief 简单的宏
 * @version 0.1
 * @date 2023-03-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

void print_ledger(int num);
void print_ledger_long(int num);
void print_ledger_detailed(int num)
void print_ledger_default(int num);

void print_ledger(int num)
{
    #ifdef OPTION_LONG 
    #define DE 1
        print_ledger_long(num);
    #endif
    #ifdef OPTION_DETAILED
    #define DE 1
        print_ledger_detailed(num);
    #endif
    #ifndef DE
        print_ledger_default(num);
    #endif
}