#include <stdio.h>
#include <windows.h>

int main(void){
    int n_num;
    int o_num,e_num;//奇数和偶数计数
    int odd_num,even_num;
    odd_num = even_num = o_num = e_num = 0;
    printf("这个程序会统计你输入数字的奇数个数和偶数个数，并且打印它们的平均值\n");
    printf("Enter '0' to quit\n");
    while (true)
    {
        scanf("%d",&n_num);
        if (n_num == 0)
        {
            break;
        }
        else if (n_num % 2 == 0){
            e_num++;
            even_num += n_num;
        }
        else{
            o_num++;
            odd_num += n_num;
        }       
    }
    printf("偶数有 %d个,average value = %d\n",e_num,even_num / e_num);
    printf("奇数有 %d个,average value = %d\n",o_num,odd_num / o_num);
    system("pause");
    return 0;
}