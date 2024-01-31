/**
 * @file array.c
 * @author your name (you@domain.com)
 * @brief 访问伪数组
 * 因为我看不太懂算式，不过后面还是看懂了，但是我先找了其他的。
 * 我从CSDN上复制的代码，原本还有另外一个，但是我发现他写的不对，就用了这个。
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdarg.h>
#define MAX_DIM 10
int array_offset(int arrayinfo[],...);
//int array_offset_2(int arrayinfo[],...);//第七题只用修改下面的计算函数的公式就行了
int compute_offset( int dim, int *arrayinfo, int *arg, unsigned int *weight );

int main( void )
{
    int i;
    int offset;
    int arrayinfo[21] = { 3, 4, 6, 1, 5, -3, 3 };
 
    printf( "arrayinfo[]:" );
    for( i = 0; i < arrayinfo[0] * 2 + 1; ++i )
    {
        printf( "%d, ", arrayinfo[i] );
    }
    printf( "\n" );
 
    offset = array_offset( arrayinfo, 4, 1, -3 );
    printf( "下标为: 4, 1, -3时, 偏移量为:%-4d\n", offset );
 
    offset = array_offset( arrayinfo, 4, 1, -2 );
    printf( "下标为: 4, 1, -2时, 偏移量为:%-4d\n", offset );
 
    offset = array_offset( arrayinfo, 4, 1, 3 );
    printf( "下标为: 4, 1,  3时, 偏移量为:%-4d\n", offset );
 
    offset = array_offset( arrayinfo, 4, 2, -3 );
    printf( "下标为: 4, 2, -3时, 偏移量为:%-4d\n", offset );
 
    offset = array_offset( arrayinfo, 5, 1, -3 );
    printf( "下标为: 5, 1, -3时, 偏移量为:%-4d\n", offset );
 
    offset = array_offset( arrayinfo, 6, 3, 1 );
    printf( "下标为: 6, 3,  1时, 偏移量为:%-4d\n", offset );
    getchar();
    return 0;
}

int array_offset( int *arrayinfo, ... )
{
    //检查arrayinfo 的数据是否自相矛盾
    if( arrayinfo[0] < 1 || arrayinfo[0] > 10 )
    {
        return -1;    //维数不在[1, 10]范围, 返回-1
    }
 
    int i;
    va_list ap;    //参数指针
    int arg[MAX_DIM];    //存储可变部分参数, 最多MAX_DIM 维, 超过就忽略
     
    va_start( ap, arrayinfo );    //将参数指针ap指向可变部分的第一个参数, 也就是表示数组第一维信息的参数
    for( i = 0; i < arrayinfo[0]; ++i )
    {
        if( arrayinfo[2 + i * 2] <= arrayinfo[1 + i * 2] )
        {
            return -1;    //上限小于或等于下限, 返回-1
        }
 
        arg[i] = va_arg( ap, int );    //读取参数信息, 并将ap 移到下一个参数
    }
    va_end( ap );
 
    //计算偏移量offset
    unsigned int weight;    //weight: 权, 维度较低时的偏移量乘以权(weight)等于实际偏移量 
    return compute_offset( 1, arrayinfo, arg , &weight );    //第一个参数1 表示从最低维度(第一维)开始, weight(权)通过地址传递, 使后续递归函数可以改变weight值
}
 
int compute_offset( int dim, int *arrayinfo, int *arg, unsigned int *weight )
{
    if( dim == arrayinfo[0] )    //当达到最高维
    {
        if( arg[dim - 1] >= arrayinfo[dim * 2 - 1] && arg[dim - 1] <= arrayinfo[dim * 2] )    //如果可变部分参数中表示最高维的那个参数值符合arrayinfo[0]中的规定
        {
            *weight = arrayinfo[dim * 2] - arrayinfo[dim * 2 - 1] + 1;    //初始化weight(权), weight值是最高维的最大偏移量
            return arg[dim - 1] - arrayinfo[dim * 2 - 1];    //返回最高纬实际偏移量
        }
 
        return -1;    //如果可变部分表示最高维的参数值不满足arrayinfo[0]中的限制, 返回-1
    }
    printf("%u\n",*weight);
    int offset;
    offset = compute_offset( dim + 1, arrayinfo, arg, weight );    //如果没有达到最高维, 维度+1, 调用自身
 
    if( offset == -1 )    //如果递归到高维, 开始出栈, 判断返回值, 如果返回了-1, 说明参数有误, compute_offset全部出栈后返回值仍是-1
    {
        return -1;
    }
     
    if( arg[dim - 1] >= arrayinfo[dim * 2 - 1] && arg[dim - 1] <= arrayinfo[dim * 2] )    //如果前一个出栈的函数返回值不是-1, 说明从之前返回的偏移量是有意义的. 判断当前维度的参数是否符合限制条件
    {
        offset += *weight * ( arg[dim - 1] - arrayinfo[dim * 2 - 1] );    //新的偏移量 = 之前累计偏移量 + 现在维度的权 * 现在维度偏移量
        *weight *= arrayinfo[dim * 2] - arrayinfo[dim * 2 - 1] + 1;    //更新下一维度权值
        return offset;    //返回更新后的总偏移量
    }
}

