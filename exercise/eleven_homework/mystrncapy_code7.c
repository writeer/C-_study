#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <assert.h>
/*char* mystrncpy (char* dest , const char* src, size_t count){

char* start=dest;

assert(dest && src) ;

while( count && (*dest++=*src++) ) // 遇到’ \0'或count=0时停止

{

count-- ;

}

while( count )

{

*dest++=' \0' ;

count-- ;

}

return start;

}*/
//上面是网络上的代码，然后我发现，如果不向目标字符填充\0，那么目标数组不会有问题，但是返回的指针会显示一些奇怪的内容。
//返回的指针是一摸一样的，但是打印目标数组正常，打印返回指针内容，前后会出现奇怪的现实。
//额。。。我发现是因为我在for循环中加入了&& chr[i] != '\0'，导致小于n的原数组情况下，少拷贝的\0，于是打印的时候就会一直打印直到\0
//所以才出现莫名其妙的东西，这也算是代码没问题的逻辑错误严重，搞出的莫名其妙的bug，也算吃了亏，浪费许多调试时间。
char * mystrncpy(char *cr,const char * chr,int n);

int main(void){
    char s1[80];
    char s2[80];
    char * cr;
    int n = 1;
    char acter;
    while (acter != EOF)
    {
    puts("输入一个字符串：");
    fgets(s2,80,stdin);
    puts("输入正整数n，控制字符的截断.");
    scanf("%d",&n);
    cr = mystrncpy(s1,s2,n);
    fputs(s2,stdout);
    fputs(s1,stdout);
    //printf("%p .,. %p",s1,cr);
    fputs(cr,stdout);
    puts("按回车继续，输入ctrl-z结束。");
    fflush(stdin);
    acter = getchar();
    }
    system("pause");
    return 0;

}
//经过我的仔细了解，我发现strncpy在元字符串大于目标字符时，不会以空字符结尾，也就是不会追加空字符。
//换句话说如果n大于了源字符串就会导致目标不是一个字符串，就会一直打印直到遇到字符\0，这个函数其实很鸡肋。
char * mystrncpy(char * cr,const char * chr,int n){
    int i;
    for (i = 0; i < n; i++)
    {
       cr[i] = chr[i];
       if(chr[i] == '\0')
            break;
    }
    //cr[i] = '\0';
    return cr;
}