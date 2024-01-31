#include <stdio.h>
#include <string.h>
#define SIZE 17
int shift_four(short n,int s);//用short比较好看出来，s表示左移s位
//我在网上还看到一个写法，但是也是要用到字节对齐，比如int就需要SIZE里有4 * 8的数量
//然后用SIZE减掉要位移的数量，然后右移对应的数，保存起来，最后左移原数，然后两个数相加
//它的问题在于不好控制边界，也就是很依赖字符对齐。
//而我这个函数，可用比较值来设定边界，在返回函数时通过边界值比如两个字节就可以设置0xFFFF & n，然后在返回，就可以保证数字的精确
//还可以手动设置边界之类交互性，那样有些麻烦，可以先整体左移，然后每移动一个字节添加一个字节FF，来达到动态边界的可操控。

char * show_bit(int n,char * st);

int main(){
    short number = 22783;
    char st[SIZE];
    printf("src: ");
    show_bit(number,st);
    number = shift_four(number,4);
    printf("dest: ");
    show_bit(number,st);
    getchar();
    return 0;
}

int shift_four(short n,int s){
    short temp = 0;
    for (int i = 0; i < s; i++)
    {
        temp = 0;
        if ((0x8000 & n))
            temp = 1;
        n <<= 1;
        n += temp;
    }
    return n;
}


char * show_bit(int n,char * st){
    int size = SIZE;
    int i;
    for(i = size -2;i >= 0;i--,n >>= 1)
        st[i] = (n & 01) + '0';
    st[size -1] = '\0';
    printf("%s \n",st);
    return st;
}