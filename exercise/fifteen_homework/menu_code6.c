#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

struct typeface
{
    unsigned int id   :  8;
    unsigned int size :  7;
    unsigned int      :  1;
    unsigned int alignment : 2;// 0 ,1,2分别表示左，中，右对齐方式
    bool bold         :  1;
    bool italic       :  1;
    bool underline     :  1;
};

void change_fount(struct typeface * sptr);
void change_size(struct typeface * sptr);
void change_alignment(struct typeface *sptr);
void show_menu(struct typeface *sptr);

int main(void){
    char ch;
    struct typeface style = {1,12,0,0,0,0};
    show_menu(&style);
    while ((ch = getchar()) != 'q')
    {
        ch = tolower(ch);
        while(getchar() != '\n');
        switch (ch)
        {
        case 'f':
            change_fount(&style);
            break;
        case 's':
            change_size(&style);
            break;
        case 'a':
            change_alignment(&style);
            break;
        case 'b'://我发现bool值取反后，总是为true，我估计因为bool是逻辑运算的关系，只会储存假和非假，所以用条件判断来重新赋值不用~
            style.bold = !style.bold;//总的来说bool是一个特殊类型，不能把它看成只有一字节的int类型
           // printf("\n%d\n",style.bold + '0');
            break;
        case 'i':
            style.italic = !style.italic;
            break;
        case 'u':
            style.underline = !style.underline;
            break;
        default:printf("input error.\n");
            break;
        }


        fflush(stdin);
        show_menu(&style);
    }
    return 0;
}

void show_menu(struct typeface *sptr){
    char * ch;//这题还有一个方法就是，用一个字符串数组，或者指针数组，然后新建一个变量i，直接让i = sptr->alignment就行了
    if(sptr->alignment == 0)
        ch = "left";
    else if (sptr->alignment == 1)
        ch = "center";
    else
        ch = "right";
    printf("ID  SIZE  ALIGNMENT    B    I    U   \n");
    printf("%d   %d      %s      %s   %s   %s \n",sptr->id,sptr->size,
    ch,sptr->bold ? "on":"off",sptr->italic?"on":"off",sptr->underline?"on":"off");
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit.");
    printf(":");
}

void change_fount(struct typeface * sptr){
    printf("Font ID(0 - 255):");
    unsigned int id= 0;//我发现不能直接用sanf来赋值给位字段，因为对齐方式不一样，容易出错，要转化一下
    while(scanf("%d",&id) != 1)
        printf("input error.Please re-enter:");
    //while(getchar() != '\n');
    sptr->id = id & 255;
}

void change_size(struct typeface * sptr){
     printf("Font size(0 - 127):");
     unsigned int size = 0;
    while(scanf("%d",&size) != 1)
        printf("input error.Please re-enter:");
    //while(getchar() != '\n');
    sptr->size = size & 127;
}

void change_alignment(struct typeface *sptr){
    char ch;
    puts("l)left c)center r)right");
    printf(": ");
    while((ch = getchar()) != 'l' && ch != 'c' && ch != 'r'){
        printf("input error.Please re-enter:");
    //while(getchar() != '\n');
    fflush(stdin);
    }
    switch (ch)
    {
    case 'l':sptr->alignment = 0; break;
    case 'c':sptr->alignment = 1; break;
    case 'r':sptr->alignment = 2; break;
    default:
        break;
    }
}