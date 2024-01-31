#include <stdio.h>
#include <string.h>

int base(const char *);

int main(void){
    char * pbin = "01001001";
    int n;
    n = base(pbin);
    printf("dec: %d.\n",n);
    printf("oct: %o.\n",n);
    printf("hex: %x.\n",n);
    printf("bin: %s.\n",pbin);
    getchar();
    return 0;
}

int base(const char * ch){
    int re = 0;
    int j,n = 0,sum = 0;
    for (int i = strlen(ch) - 1; i >= 0 ; i--)
    {
        sum = ch[i] - '0';
        //printf("%c : %d\n",ch[i],sum);
        for ( j = 0; j < n; j++)
            sum = sum * 2;
        re += sum;
        n++;
        //printf("%d :",re);
    }
    return re;
}