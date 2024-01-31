/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * convert(int num, int base,char * strnum) {
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char result[100];
    int quotient = num;
    int i = 0;

    // 转换为目标进制
    while (quotient != 0) {
        result[i++] = digits[quotient % base];
        quotient /= base;
    }
    result[i] = '\0';
    // 反转字符串，得到最终结果
    int len = strlen(result);
    for (int j = len - 1,l = 0; j >= 0; j--,l++) {
        sprintf((strnum + l),"%c", result[j]);
    }
}

*/

/*
int main(int argc, char *argv[]) {
    // 检查命令行参数是否合法
    /*if (argc != 2) {
        printf("Usage: %s age\n", argv[0]);
        return 1;
    }*//*
char strnum[25];
int age = atoi(argv[1]); // 将命令行参数转换为整数
int base = 0;            // 初始化最小基数为0
int min = 0;
// 从2到36依次检查每个基数，找到最小的那个
for (int i = 2; i <= 36; i++)
{
    // j < ZZ的十进制大小
    /*if(min >= age)
        break;*/
   /* for (int j = 1; j <= (i * 10 + i); j++) // 2进制最高22,9进制最高99
    {

        convert(j, i, strnum); // 把当前数字转化为字符数组
        min = strtol(strnum, NULL, i);
        // fprintf(stdout,"%d\n",min);
        if (strlen(strnum) < 3 && min <= age)
        {
            base = i;
        }
        else
        {
            break;
        }
    }
}

printf("The minimum base for age %d is %d\n", age, base);
return 0;
}
*/

//说实话，我看不懂题意，所以算了。
#include <stdio.h>
#include <stdlib.h>
    int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        perror("argc");
        exit(1);
    }
    int i;
    long num = strtol(argv[1], NULL, 10);
    //这个函数不能算小于29的数字，并且是吧29的各种进制转十进制值与输入的数字比较，
    for(i = 2; i < 37 && strtol("29", NULL, i) <= num; i++);
    printf("这个最小基数为%d\n", i - 1);
    return 0;
}
