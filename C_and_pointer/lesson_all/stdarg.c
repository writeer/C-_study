#include <stdio.h>
/**
 * @brief 其中，_INTSIZEOF用于计算每个参数在栈上占用的字节数，
 * va_start将ap指向第一个可变参数的地址，va_arg用于逐个取出可变参数
 * ，并将指针后移至下一个参数，va_end用于清空ap。
 * 需要注意的是，该实现方式只支持参数类型大小为int及其倍数的可变参数函数。
 * 只支持一个同一个类型的可变参数组
 * 原因和很简单，因为写的va_arg宏，先位移指针，然后再读取类型，这样的话，当有一个类型不同
 * 比如，浮点数，整数，浮点数,函数会先移动第一个参数，也就是最后一个固定参数的大小，然后按照浮点数，也就是double读取第一个参数
 * 然后在移动一个整型变量，这就出错了，因为double变量的下一个参数，距离它一个double变量，所以需要移动一个double变量，然后用整型读取
 * 所以当变量不同时就会出错，如果是在第一次读取后，接下来每次读取，都先移动指针，移动的大小是上一次读取的大小，然后在读取
 * 这次想要读取的数值，就可以解决这个问题。
 * 所以，可以在每次读取后移动指针，下一次直接读取，然后再移动
 */
typedef char* va_list;
int flag = 0;

#define va_start(ap, v) (ap = (va_list)&v)

#define va_arg(ap, t) flag ? (*(t*)(ap += sizeof(t))): (*(t*)(ap += sizeof(int))), flag = 1

//大概思路就是下面这条，这条语法不合理，但是程序运行思路大概就是这样的
//#define va_arg(ap, t) flag ? ((*(t*)(ap)),(ap += sizeof(t))) : ((*(t*)(ap += sizeof(int))), flag = 1,(ap += sizeof(t)))

#define va_end(ap) (ap = (va_list)0)
/**
 * @brief 这个函数也能实现一部分的效果，但是问题在于，对于第一次读取值，之后返回的字符要强制转换。
 * 所以第一次的类型必须和第二次的类型相同，并且还要检测每次读取函数的类型，然后转换成对应的关键字
 * 比如用if检测获取到的关键字，然后分别执行不同的类型转换。
 * 但是太麻烦，而且不是很好的宏定义，也不够精简，所以我就不写了。
 * 
 */
/*#define va_arg(ap, t) _va_arg(ap,sizeof(t))
void* _va_arg(va_list **ap,size_t t)
{
    if (flag)
    {
        void * buf = *ap;
        *ap += t;
        return buf;
    }
    else
    {
        *ap += sizeof(int);
        void *buf = *ap;
        *ap += t;
        flag = 1;
        return buf;
    }
}
*/
float sum(int count, ...)
{
    va_list args;
    float result = 0;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);//因为可变参数用浮点值，会自动转换为double，所以用float获取值会出错。
    }
    va_end(args);
    return result;
}


int main()
{
    printf("sum(1, 2, 3) = %.2f\n", sum(3, 1.2, 2.5, 3));
    printf("sum(10, 20, 30, 40) = %f\n", sum(4, 10., 20.0, 30., 40.));
    getchar();
    return 0;
}