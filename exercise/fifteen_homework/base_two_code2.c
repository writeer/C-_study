#include <stdio.h>
#include <string.h>

int base(const char *);
char * show_bit(int n, char *);

int main(int argc,char *argv[])
{
    char st[sizeof(int) * 8];
    int cmp = 0,b = 0,sum = 0;
    cmp = base(argv[1]);
    b = base(argv[2]);
    sum = cmp ^ b;printf("a ^ b:\n");
    show_bit(sum,st);
    sum = ~cmp;puts("~a:");
    show_bit(sum,st);
    sum = ~b;puts("~b:");
    show_bit(sum,st);
    sum = cmp & b;puts("cmp & b:");
    show_bit(sum,st);
    sum = cmp | b;puts("cmp | b:");
    show_bit(sum,st);
    return 0;
}

char * show_bit(int n,char * st){
    int size = 32;//最多显示32位
    int i;
    for(i = size -2;i >= 0;i--,n >>= 1)
        st[i] = (n & 01) + '0';
    st[size -1] = '\0';
    printf("%s \n",st);
    return st;
}

int base(const char * ch){
    int re = 0;
    int j,n = 0,sum = 0;
    for (int i = strlen(ch) - 1; i >= 0 ; i--)
    {
        sum = ch[i] - '0';
        for ( j = 0; j < n; j++)
            sum = sum * 2;
        re += sum;
        n++;
    }
    return re;
}

