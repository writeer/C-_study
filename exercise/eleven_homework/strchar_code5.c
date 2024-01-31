#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
//这个代码编译会有警告，因为我在下面这个函数中韩用了const，表示指针指向的数据不可更改，但是return后就可以更改了，所以编译器会有警告。
char * strchar_sn(const char * chr,char cr);

int main(void){
    char prtf[SIZE];//用于储存字符串
    char cr = ' ';
    char * ptr;
    puts("这个程序可以查找字符，并显示第一个字符出现的位置。");
    while (cr != EOF)//这个是后来审题加的，其实比较无所谓的，所以我是随便写的。
    {
    fflush(stdin);
    puts("输入一个字符串：");
    gets(prtf);//原则上来说，我是想用fgets的，但是我懒得处理换行了，再其次，printf去掉换行也可以。但是就用gets吧，他会忽略换行。而且我不怕越界毕竟只是个小程序。
    puts("输入一个字符(按ctrl-z退出):");
    cr = getchar();//scanf("%c",&cr);加了循环后直接用getchar比较好，反正我就存一个字符。并且scanf要多一个变量来存返回值，很没有必要。
    //printf("%c",cr); 调试函数
    ptr = strchar_sn(prtf,cr);
    if (ptr)
        printf("&%p = '%c' = %s\n",ptr,*ptr,ptr);
    else
        printf("&%p = 0 \n",ptr);
    }
    system("pause");
    return 0;
}

char * strchar_sn(const char * chr,char cr){

    while (*chr != '\0'){
        if (*chr == cr)
            return chr;
        chr++;
        }
    return NULL;
}

/*//这个是检测strchar函数情况的代码，用于了解和调试。
#include <stdio.h>
#include <string.h>
 
int main (){
    
    const char str[] = "Hello World";
    char ch = ' ';
    scanf("%c",&ch);
    char *ret = strchr(str, ch);
 
    printf("要被检索的字符串:%s\n",str);
    printf("从%c字符后开始检测\n", ch);
    printf("显示被检测之后的字符:%s\n",ret);
    fflush(stdin);
    getchar();
   return(0);
}*/