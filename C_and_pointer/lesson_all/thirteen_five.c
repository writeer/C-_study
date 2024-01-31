/**
 * @file thirteen_five.c
 * @author your name (you@domain.com)
 * @brief C和指针 第13章第五题
 * 我从网上抄的代码，用chatGPT写的注释和测试用例，这题并不难，问题在于题目翻译的太绕，我理解起来不太容易，直接看代码好多了。
 * @version 0.1
 * @date 2023-03-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 定义枚举类型NONE、FLAG和ARG
enum {NONE, FLAG, ARG};

// 根据字符ch和参数控制字符串control判断参数类型
int argtype(register int ch, register int *control)
{
    while(*control != '\0')
        if(ch == *control++)
            // 判断下一个字符是不是+
            return *control == '+' ? ARG : FLAG;
    return NONE;
}

// 处理命令行参数
char **do_args(int argc, char **argv, char *control,
               void (*do_arg)(int ch, char *value),
               void (*illegal_arg)(int ch))
{

    register char *argp;
    register int ch;
    register int skip_arg;

    while((argp = *++argv) != NULL && *argp == '-'){
        skip_arg = 0;
        while(!skip_arg && (ch = *++argp) != '\0'){
            switch(argtype(ch, control)){
            case FLAG:
                // 处理FLAG类型的参数
                (*do_arg) (ch, NULL);
                break;
            case ARG:
                // 处理ARG类型的参数
                if(*++argp != '\0' || (argp = *++argv) != NULL){
                    (*do_arg)(ch, argp);
                    skip_arg = 1;
                    break;
                }
                // 参数不合法
                (*illegal_arg)(ch);
                return argv;
            case NONE:
                // 参数不合法
                (*illegal_arg)(ch);
                break;
            }
        }
    }
    return argv;
}


void print_flag(int ch, char *value){
    printf("Flag %c is set\n", ch);
}

void print_arg(int ch, char *value){
    printf("Argument for flag %c is %s\n", ch, value);
}

void illegal_arg(int ch){
    printf("Illegal argument %c\n", ch);
}

int main(int argc, char **argv){
    char control[] = "x";
    argv = do_args(argc, argv, control, print_arg, illegal_arg);
    printf("return : %s \n",*argv);
    return 0;
}