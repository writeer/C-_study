#include <stdio.h>

char * s_gets(char * st,int n);

int main(void){
    char temp[40];
    int n = 0;
    while(n<4 &&s_gets(temp,40)){
        printf("%s\n",temp);
        n++;
        }
    
    return 0;
}

char * s_gets(char * st,int n){
    int i = 0;
    char * ret_val;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
    
}