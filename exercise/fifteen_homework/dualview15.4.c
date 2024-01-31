/**
 * @file fields.15.3.c
 * @author your name (you@domain.com)
 * @brief 位字段和按位运算符
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
//线的样式
#define SOLID 0
#define DOTTED 1
#define DASHED 2
//三原色
#define BLUE 4
#define GREEN 2
#define RED 1
//混合色
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN |BLUE)
//按位方法中用到的符号常量
#define OPAQUE     0x1
#define FILL_BLUE  0x8
#define FILL_GREEN 0x4
#define FILL_RED   0x2
#define FILL_MASK  0xE
#define BORDER     0x100
#define BORDER_BLUE 0x800
#define BORDER_GREEN 0x400
#define BORDER_RED   0x200
#define BORDER_MASK  0xE00
#define B_SOLID      0
#define B_DOTTED     0x1000
#define B_DASHED     0x2000
#define STYLE_MASK   0x3000

const char * colors[8] = {"black","red","green","yellow","blue","magenta","cyan","white"};

struct box_props {//这里占了十六个字节而不是两个字节，也就是十六位，我真服了,让我调试半天，原来是因为用unsigned short用的是后八字节，两边互不影响
//但是union理论上来说应该会读取一样的值，毕竟内存是一样的，没道理说struct用前面的，short用其他的
//我的推测是，首先我的机器，或者编译器解释struct的时候，是这样存的0xNNN00000000后面用0填充，然后short获取到的是后面的值
//所以我在修改short的值时修改的是0xNNN0000000SS，用S表示后修改的值，于是在我打印时所使用的是32位，而我有十六字节，所以一次只能打印八个字节。
//所以我就无法看出差别
//奇怪了。我的代码和书上是一样的,为了验证我的猜测。
//经过调试，我发现，在union里，当我修改us_view的值时，st_view的值没有变化，更验证了我的猜测。
//下面是我从网上找的的说法，逆向过程中由于我的水平问题，我没找到初始化变量的所在。
//但是这个说法证明了，为什么我的结果和书上不一样，并且修改后面的数据，前面的数据依然正常的原因。
//应该少用union这种方法，它既浪费内存，储存方式又不是用新值来覆盖旧值，只有在旧编译器或者系统中，把unsigned short看成2字节
//并且把box_porps成16位，或者两个看成一样大小的内存，才能进行相同的读取方式，否则就会出现我这种情况。
//结构的储存在前面，看成数字又从0开始，结果就是无法触碰到前面的储存区，达不到想要的效果。
//逆向搞不出来，我写了一个test_union测试，验证了这点

/*它可以存储两者的方式是"纯粹的运气".我将假设您的计算机体系结构使用IEEE 754浮点数并尝试解释您所看到的内容.
你的工会确实只用八个字节,但15.5看起来像这样十六进制:402F000000000000.如您所见,
较低的四个字节完全为零.现在让我们将最低的四个字节设置为整数200,看看8字节值会发生什么.
这给了我们402F0000000000C8.现在假设您现在读取所有八个字节为双,在IEEE754中,您将获得15.500000000000355当打印时将四舍五入到15.5,
使得看起来联合可以存储double和int.
所有这一切都表示访问联盟的两个成员是至少在C++ 11中的未定义行为(即使它在我所知道的所有平台上以逻辑方式运行),
所以这只是一种可能的解释对于你观察到的行为.在C中,它看起来完全合法.*/
    bool opaque : 1; //或者unsigned int
    unsigned int fill_color : 3;
    unsigned int : 4;
    bool show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int  : 2;
};
union Views //我不知道为什么，当我初始化结构后，再用short的方式查看里面的数据，结果却不一样，只剩下01了
{
    struct box_props st_view;
    unsigned short _Alignas(16) us_view;
    //这题我的解决办法是新建一个十六字节的结构，然后用这个结构来填充前一个的数据，或者用一个一样的union，里面能存十六字节
    //然后把这个有十六字节的union在里面操作，然后在赋值回这个union，就能达到直接覆盖，且数据不错误了。
    //由此可得知union很不靠谱，尽量少用，不然如果你不像我这样去钻研他的原理，你肯定要吃大亏，而且头皮都得挠秃。
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short );
char * itobs(int n,char * ps);

int main(void)
{
    //初始化box_props结构
    union Views box = { { true, YELLOW, true, GREEN, DASHED } };
    //union Views * pr = &box;
    printf("%zd\n",_Alignof(box.us_view));
    char bin_str[8 * sizeof(unsigned int) + 1];
    //printf("%d",sizeof(union Views));
    printf("Original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n",itobs(box.us_view,bin_str));
    box.us_view &= ~FILL_MASK;
    box.us_view |= (FILL_BLUE | FILL_GREEN);
    box.us_view ^= OPAQUE;
    box.us_view |= BORDER_RED;
    box.us_view &= ~STYLE_MASK;
    box.us_view |= B_DOTTED;
    printf("\nModified box settings:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n",itobs(box.us_view,bin_str));
    show_settings(&box.st_view); //我添加这个函数测试，发现值没有变化，也就说这个函数结构储存的值是4字节，并且分开储存的，不像是储存在两个字节中。
    /*for (int i = 0; i <= 128; i++)
    {
        printf("%c",pr->st_view+i);
    }
    */
    getchar();
    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Box is %s.\n",pb->opaque == true ? "opaque" : "transparent");
    printf("The fill color is %s.\n",colors[pb->fill_color]);
    printf("Border %s.\n",pb->border_color == true ? "shown" : "not shown");
    printf("The border color is %s.\n",colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style)
    {
    case SOLID:printf("solid.\n");break;
    case DOTTED:printf("dotted.\n"); break;
    case DASHED:printf("dashed.\n"); break;
    default: printf("unknown type.\n");
        break;
    }
}

void show_settings1(unsigned short us)
{
    printf("box is %s.\n",(us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
    printf("The fill color is %s.\n",colors[(us >> 1) & 07]);
    printf("Border %s.\n",(us & BORDER) == BORDER ? "shown" : "not shown");
    printf("The border style is ");
    switch (us & STYLE_MASK)
    {
    case B_SOLID:printf("solid.\n"); break;
    case B_DOTTED:printf("dotted.\n"); break;
    case B_DASHED:printf("dashed.\n"); break;
    default:printf("unknown type.\n");
        break;
    }
    printf("The border color is %s.\n",colors[(us >> 9) & 07]);

}

char * itobs(int n,char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for(i = size -1; i >= 0; i--,n >>=1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';
    
    return ps;
}