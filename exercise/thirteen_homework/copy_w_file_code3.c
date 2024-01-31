#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ARSIZE 4096
//把文件中的所有字符转换为大写
int main(void){
    //static char buff[ARSIZE];
    FILE *fp;
    char name[20];
    int beys,i = 0;
    puts("Enter a file name:");
    if(fscanf(stdin,"%19s",name) == 1){
        if((fp = fopen(name,"r+")) == NULL){
            fprintf(stderr,"Can't open %s file\n",name);
            exit(EXIT_FAILURE);
        }
        //第一个笨办法
        //if(setvbuf(fp,buff,_IOFBF,ARSIZE) != 0)
        //    fputs("Can't create input buff\n",stderr);
        
       // while ((beys = getc(fp)) != EOF)
        //{
            //printf("1,%c\n",beys);
            //beys = toupper(beys);
           // buff[i] = beys;
            //i++;
            //printf("2,%c\n",beys);
           // if(putc(beys,fp) == EOF)
            //    printf("Error!\n");
       // }
        //第二个办法
        //经过我的上网查找，如果不是上网查找我还真不清楚，要被这一题给难到死
        //每次读取后要操作一下指针，也就是激活一下指针，因为这个文件指针有些特殊
        while ((beys = getc(fp)) != EOF)
        {
            //printf("%p\n",fp[i]); //我打印了一下发现fp的指针一直是不变的，神不神奇？
            //并且这个指针解引用后还有一个地址而且这个地址也没有变，也就是说文件指针是一个指向指针的指针,并且指向的这个指针也是不变的
            //我还尝试了解引用后再次解引用，编译报错了，应该是不允许。
            //我又尝试了通过数组解引用指针，发现fp的储存地址不连续，也就是说fp可能确实是一个信息流，里面含有的信息储存在不同内存中，所以有不同的指针指向目标
            //fp并没有指向文件，而是指向了一个打开文件后的信息体，或者说流。
            //所以如果没有激活指针这一步，或者说少一步，那么结果就会有些奇怪，因为它并没有直接操作文件，而是用了一个临时的载体。
            //我又查了会资料，发现FILE是结构体指针，一个指向文件的指针，但其实是指向流，要操作文件，或者说操作流，必须的用这些函数如getc，fread等
            //因为一般来说是不关心FILE里有什么的，一般就是有文件信息，权限等东西，等我在反汇编看看，能不能发现什么。
            //因为文件操作基本都是由库函数来完成的，而C的源码大多额。。有些都是汇编，看了头痛，而且效率很低。现在只有对操作系统加以理解，而不能像个机器一样完全洞悉整台电脑，不得不说是我个人的一个遗憾。
            //我又了解了一下结构体指针，发现是一个综合指针，类似于一个字典，可以在里面有着指针，数组，变量等，要获取它的值，只有获取地址然后通过.或者->来获取结构体里的内容
            //所以我在打印时才会发现FILE的地址时=是混乱，且不连续的，因为结构体内的数据可以在内存中分别储存。
            fseek(fp,-1L,SEEK_CUR);
            beys = toupper(beys);
            putc(beys,fp);
            fseek(fp,0,SEEK_CUR);
           // i++;
        }
        
       // rewind(fp);
        //fwrite(buff,sizeof(char),ARSIZE,fp);
        fclose(fp);
        printf("Conversion succeeded!\n");
    }
    else
        printf("Input error!\n");
    printf("Done!");
    return 0;
}