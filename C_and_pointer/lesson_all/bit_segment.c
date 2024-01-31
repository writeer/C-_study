/**
 * @file bit_segment.c
 * @author your name (you@domain.com)
 * @brief 编写位段声明，第十章第三题
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

struct misc//其余指令
{
    unsigned int opcode : 16;
};

struct branch//转移指令
{
    unsigned int offset : 8;
    unsigned int opcode : 8;
};

struct sql_op //单操作数指令
{
    unsigned int dst_reg : 3;
    unsigned int dst_mode: 3;
    unsigned int opcode  : 10;
};

struct reg_src//原寄存器指令
{
    unsigned int dst_reg : 3;
    unsigned int dst_mode: 3;
    unsigned int src_reg : 3;
    unsigned int opcode  : 7;
};

struct dbl_op //双操作数指令
{
    unsigned int dst_reg : 3;
    unsigned int dst_mode: 3;
    unsigned int src_reg : 3;
    unsigned int src_mode: 3;
    unsigned int opcode  : 4;
};

typedef struct 
{
    union 
    {
        //unsigned int addr : 16;
        struct misc misc;
        struct branch branch;
        struct sql_op sql_op;
        struct reg_src reg_src;
        struct dbl_op dbl_op;
    } ;
    
} machine_inst;





int main()
{
    machine_inst x;
    printf("%d \n",sizeof(x));
    /*int a = x.addr;
    a  = x.misc.opcode;
    x.branch.opcode;
    x.sql_op.dst_mode;
    x.reg_src.src_reg;
    x.dbl_op.opcode;*/
    getchar();
    return 0;
}