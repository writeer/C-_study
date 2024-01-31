#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*选择你想要的运算，然后输入两个数字。
这个代码有些问题，比如scanf的截断问题，在数字上，输入88hh8，它会读入88，然后把剩下的hh留在循环中。
如果可以控制scanf的读入，让它用换行结尾就好了。
否则的话，就需要先保存用户输入，然后进行判断是否是数字，判断完后再执行。
但是这样对于输入流的运用就不是很好，而且要多一些代码。
限制用户输入也是一个好方法，但是命令行比较难限制，我又不想保存用户输入，这样要改好些代码。
对于我这屎一样的代码，我提不起兴趣来改。
总之，我认为的解决方案就是两个，一个是想办法控制scanf的读取数据，让它读取直到遇到换行，这样它的返回值就会清晰的告诉我数字正确性、
第二个方法，就是用数组存储下用户输入的所有字符，挨个进行判断，如果有除了换行以外的字母，就让用户重新输入。
如果全部都是数字，就直接返回计算。
*/
float analyzed(float num);//测试输入字符是否是数字

int main(void){
    char ch = ' ';
    float num,num_two;
    while (ch != 'q')
    {
        num = num_two = 0;
        printf("Enter the operation of your choice.\n"
        "a.add                  s.subtrack\n"
        "m.multiply             d.divide\n"
        "q.quit\n:");
        fflush(stdin);
        scanf("%c",&ch);
        if (isalpha(ch) != 0)//检测输入是否是字母
        {
            switch (ch)
            {
            case 'a':
            printf("Enter first number:");
            num = analyzed(num);
            printf("Enter second number:");
            num_two = analyzed(num_two);//检测输入是否是数字
            printf("%g + %g = %g\n",num,num_two,num + num_two);
                break;
            case 's':
            printf("Enter first number:");
            num = analyzed(num);
            printf("Enter second number:");
            num_two = analyzed(num_two);
            printf("%g - %g = %g\n",num,num_two,num - num_two);
                break;
            case 'm':
            printf("Enter first number:");
            num = analyzed(num);
            printf("Enter second number:");
            num_two = analyzed(num_two);
            printf("%g * %g = %g\n",num,num_two,num * num_two);
                break;
            case 'd':
            printf("Enter first number:");
            num = analyzed(num);
            printf("Enter second number:");
            num_two = analyzed(num_two);
            while (num_two == 0)
            {
             printf("Enter the number other than 0:");
             num_two = analyzed(num_two);
            }
            printf("%g / %g = %g\n",num,num_two,num / num_two);
                break;
            case 'q':
                break;
            default:
                printf("Please reselect!\n");
                break;
            }
        }
        else{
            printf("Please reselect!\n");
        }
        
    }
    printf("Bye!");
    return 0;
}

float analyzed(float num){
    char ch;
    int is;
    is = scanf("%f",&num);
    while(true){
    if (is)
    {
        return num;
    }
    else{
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number,such as 2.5,-1.78E8,or 3:");
        is = scanf("%f",&num);
    }
    }
}