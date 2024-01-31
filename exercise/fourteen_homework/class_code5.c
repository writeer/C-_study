#include <stdio.h>
#include <string.h>
#define CSIZE 4
struct name
{
    char name[10];
    char surname[10];
};

struct student
{
    struct name names;
    double grade[3];
    double avg;
};

void avg(struct student * st,int n);
void show(const struct student * st,int n);
void class_avg(struct student * st,int n);
char * s_gets(char * st,int n);

int main(void){
    int count = 0; //班级人数
    struct student students[CSIZE]; //人数上限4
    puts("输入学生的名字：");
    while (s_gets(students[count].names.name,9) != NULL && students[count].names.name[0] != '\0' && count < CSIZE)
    {
        int i;
        puts("输入学生的姓氏:");
        s_gets(students[count].names.surname,9);
        puts("输入学生三个成绩:");
        for (i = 0; i < 3; i++)
        {
            scanf("%lf",&students[count].grade[i]);
        }
        while(getchar() != '\n')
            continue;
        avg(&students[count],i);
        count++;
        if (count < CSIZE)
            puts("输入下一个名字(empty to quit)");
        
    }
    show(students,count);
    class_avg(students,count);
    getchar();
    return 0;
}

void class_avg(struct student * st,int n){
    double sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += st[i].grade[j];
        }
        
    }
    printf("class avg: %.2lf .\n",sum / (i*3));
}

void show(const struct student * st,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%s is %s by: ",st[i].names.name,st[i].names.surname);
        for (int j = 0; j < 3; j++)
        {
            printf(" %.2lf ",st[i].grade[j]);
        }
        printf(".\n");
        printf("avg: %.2lf.\n",st[i].avg);
    }
    
}

void avg(struct student * st,int n){
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        //printf("grade: %.3lf\n",st ->grade[i]);
        sum += st ->grade[i];
    }
    //printf("sum : %.2lf\n",sum);
    st ->avg = sum / n;
    return;
}

char * s_gets(char * st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;;
        
    }
    return ret_val;
}