#include <stdio.h>
#include <ctype.h>
#include <string.h>
//根据参数，把所有字符变成大写，小写，或者原样打印。
int main(int argc, char const *argv[])
{
    int n = 1;//如果没有参数默认就是原样打印
    char a;
    if (argv[1] != NULL)//判断是否输入参数
    {
    
    //char chr[20][200];
    if(strcmp(argv[1],"-p") == 0)//原样打印
            n = 1;
    else if (strcmp(argv[1],"-u") == 0)//转换为大写
            n = 2;
    else if (strcmp(argv[1],"-l") == 0)//转换为小写
            n = 3;
    else
            n = 1;

    }
    else
        n = 1;
    while((a = getchar()) != EOF){//一边获取字符，一边进行转换操作，或者打印操作。
        //如果要用字符串，就要用二维数组来分别储存字符串，用fgets和fputs来打印，这样的话需要数组足够大，我觉得很浪费资源。但是要写也就多几行代码而已
       switch (n)
       {
        case 1:
            putchar(a);
            break;
        case 2:
            a = toupper(a);
            putchar(a);
            break;
        case 3:
            a = tolower(a);
            putchar(a);
            break;
       default:
        putchar(a);
        break;
       }
        
    }
    return 0;
}
