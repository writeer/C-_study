/*#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp,*fa;//源文件和输出文件
    int number[20][30]; //储存原数字图像
    char ch[20][32];//用来储存转换后的字符
    int temp;
    if ((fp = fopen("photo.txt","r")) == NULL)//文件名可以写成可选的，但是因为只是练习，而且这种方法又不常用
    {
        fprintf(stderr,"Can't open photo file.\n");
        exit(EXIT_FAILURE);
    }
    //识别数字，并且转换字符，然后储存在数组中。用swich来转换，两组循环。我先去跑步，回来再写。
     if ((fa = fopen("photo_jpg","w")) == NULL)//文件名可以写成可选的，但是因为只是练习，而且这种方法又不常用
    {
        fprintf(stderr,"Can't create photo_jpg file.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if ((temp = getc(fp)) != EOF)
            {
                number[i][j] = temp - '0';
            }
            
        }
        
    }
    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            switch (number[i][j])
            {
            case 0:
                ch[i][j] = number[i][j] + 32;
                break;
            case 1:
                ch[i][j] = number[i][j] + 45;
                break;
            case 2:
                ch[i][j] = number[i][j] + 38;
                break;
            case 3:
                ch[i][j] = number[i][j] + 55;
                break;
            case 4:
                ch[i][j] = number[i][j] + 122;
                break;
            case 5:
                ch[i][j] = number[i][j] + 37;
                break;
            case 6:
                ch[i][j] = number[i][j] + 65;
                break;
            case 7:
                ch[i][j] = number[i][j] + 36;
                break;
            case 8:
                ch[i][j] = number[i][j] + 29;
                break;
            case 9:
                ch[i][j] = number[i][j] + 26;
                break;    
            default:
                break;
            }
        }
        ch[i][30] = '\n';
        ch[i][31] = '\0';
    }
    for (int i = 0; i < 20; i++)
    {
            fputs(ch[i],fa);
    }
    if (fclose(fp) != 0 || fclose(fa) != 0)
        fprintf(stderr,"file close failed\n");
    
    printf("Done!");
    return 0;
}*/
//下面是我在网上找到的代码，比我精简多了，而且更加易读，写的也更好
# include <stdio.h>
# include <stdlib.h>
 
# define FNAME "photo.txt"
# define FARGS "photo_jpg"
# define STR " .':~*=&%#"
 
int main(void)
{
	FILE * fp , * ft;
	int ar[20][30] ;
	char st[20][31] ;
 
	if (!(fp = fopen(FNAME, "r")))
	{
		fprintf(stderr , "Can't open file %s.\n" ,FNAME) ; 
		exit(EXIT_FAILURE);
	}
 
	if (!(ft = fopen(FARGS , "w")))
	{
		fprintf(stderr , "Can't open file %s.\n" ,FARGS);
		exit(EXIT_FAILURE);
	}
 
	// 读取文件中的内容到整型数组
	for (int i = 0 ; i < 20 ; i++)	
		for (int j = 0 ; j < 30 ; j++)
			//这样做是为了确保fscanf()正确读到1个数,而不受空格和其他字符影响
			while (fscanf(fp ,"%d" , &ar[i][j]) != 1)
				fscanf(fp ,"%*c");//他这样写之后，如果数字之间没有空格就会出问题，我的方法是做减法，数字中间没有空格，不过各有优缺点，而且他运用指针来描述，比我算ascll码好多了，在输出这个我很比不上。
 
	// 初始化字符串数组
	for (int j ,i = 0 ; i < 20 ; i++)
	{
		for ( j = 0 ; j < 30 ; j++)
			st[i][j] = *(STR + ar[i][j]);
		st[i][j] = '\0' ;
		fprintf(ft ,"%s\n" ,st[i] );
	}
	
	if (fclose(fp) || fclose(ft))	
	{
		fprintf(stderr , "Clossing error .\n");
		exit(EXIT_FAILURE);
	}
	printf("Done!\n");
	return 0 ;
}
