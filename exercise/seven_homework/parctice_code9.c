/*#include <stdio.h>

int main(void){
    int num;
    printf("这个程序只接受正整数输入，其他数字会发生错误\n");
    printf("Enter a positive integer:");
    scanf("%d",&num);
    for (int i = 1; i <= num; i += 2)
    {
        printf("%d ",i);
    }
    fflush(stdin);
    getchar();
    return 0;
}*/
/*因为我一下子把素数理解成奇数了，所以原来的代码就不对了，我还在想着这么简单？
然后上网查了一下，但是既然读了别人的代码，已经知道怎么写了，自己在抄一遍也没意思。
所以走直接copy下来了。*/
#include<stdio.h>
#include<math.h>
int main()
{
int i;
int m;
printf("please input the upper number:");
scanf("%d", &m);
if(m == 0)
printf("0不是素数!\n");
if(m==1)
printf("1不是素数!\n");
while(m > 1)
{
for(i=2; i <= sqrt(m); i++)//有等号
{
if( m%i ==0)
break;
}
if(i > sqrt(m))
printf("%d\n", m);//是素数
m--;
}
fflush(stdin);
getchar();
return 0;
}