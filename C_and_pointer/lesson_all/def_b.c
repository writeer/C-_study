/**
 * @file def_b.c
 * @author your name (you@domain.com)
 * @brief 简单宏
 * @version 0.1
 * @date 2023-03-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "cpu_type.h"

 int cpu_type()
 {
    #ifdef VAX
        return CPU_VAX;
    #elif M68000
        return CPU_68000;
    #elif M68020
        return CPU_68020;
    #elif I80386
        return CPU_80386;
    #elif X6809
        return CPU_6809;
    #elif X6502
        return CPU_3B2;
    #else
        return CPU_UNKNOWN;
    #endif
 }
