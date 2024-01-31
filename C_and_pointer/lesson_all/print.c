/**
 * @file print.c
 * @author your name (you@domain.com)
 * @brief 实现简单的printf
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdarg.h>

int print(char *format,...);
void print_float(float num);//打印浮点数,默认十进制
void print_integer(int num);//打印整数

int main()
{
    int d = 18;
    float f = 35.758;
    print("int : %d \nfloat: %f \nstring : %s \nchar : %c",d,f,"grow on tree",'A');
    getchar();
    return 0;
}

int print(char *format,...)
{
    va_list num;
    char *str = NULL;
    va_start(num,format);
    while (*format != '\0')
    {
        if(*format != '%'){
            putchar(*format++);
            continue;
        }
        switch (*++format)
        {
        case 'd':
            print_integer(va_arg(num,int));
            format++;
            break;
        case 'f':
            print_float(va_arg(num,double));//因为float会自动转换为double，所以这里必须用double，否则会出错
            format++;
            break;
        case 'c':
            //putchar(*(char *)num);//因为va_arg在访问参数后，指针自动后移了，所以可以直接转化为char类型指针，然后解引用出变量
            putchar(va_arg(num,int));//这里也要用int类型，用char类型会出错
            format++;
            break;
        case 's':
            str = va_arg(num,char *);//与上面相似，这里也可以用(char *)*num来传递字符串的指针。
            while(*str != '\0')
                putchar(*str++);
            format++;
            break;
        default:
            putchar('\a');
            return 0;
            break;
        }
    }
    va_end(num);
    return 0;
}

void print_integer(int num)//有两个方法，递归函数，或者字符数组存储然后逆序输出，我上网看了一下，觉得递归比较好理解
{
    if (num != 0)
    {
        print_integer(num/10);
        putchar("0123456789"[num%10]);
    }
}

void print_float(float num)
{
    int temp = (int)num;//打印整数部分
    print_integer(temp);
    putchar('.');
    num -= temp;
    if(num == 0)
        putchar('0');
    else{
        num *= 1000000;//六位精度
        print_integer(num);
    }
    
}