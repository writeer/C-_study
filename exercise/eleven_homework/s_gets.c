char * s_gets(char * st,int n);

char * s_gets(char * st,int n){
    char * ret_val;
    int i = 0;
    //根据复习题第九题，用数组表示法可以减少变量i。
    ret_val = fgets(st,n,stdin);
    if(ret_val){
        //这里改成*st != '\n' && *st != '\0'
        while (st[i] != '\n' && st[i] != '\0')//根据复习题第11题，可以用strchar(*st,'\n') != null && strchar(*st,'\0') != null
            i++;/// *st++
        if(st[i] == '\n')// *st
            st[i] = '\0'; // *st
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val; 
}