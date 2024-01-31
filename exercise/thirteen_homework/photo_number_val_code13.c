# include <stdio.h>
# include <stdlib.h>
 //这个是网上的代码，简单来说就是把原来的程序模块化，然后在形参里用上变长数组。
 //我原本读题的意思，以为是要用户来决定字符或者说数字长度，但想了想，题目要求是用上变长数组重写。
 //就算要换用户输入决定长度，这个代码把预处理改成变量，然后用户输入后再创建变长数组就可以了。
 //所以我想了想，看过他的代码，我再写，应该也会用他的轮子，所以就不浪费这个时间了，直接去做下一题
# define ROWS 20
# define COLS 30
# define FNAME "photo.txt"
# define FARGS "photo_jpg"
# define STR " .':~*=&%#"
 
void initialize_ar(FILE * fp ,int n , int m , int ar[n][m]);
void set_st(int n , int m , char st[n][m + 1] , int ar[n][m]);
 
int main(void)
{
	FILE * fp , * ft;
	int ar[ROWS][COLS] ;
	char st[ROWS][COLS + 1] ;
 
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
 
	initialize_ar(fp , ROWS , COLS , ar) ;
	set_st(ROWS , COLS , st , ar) ;
 
	for (int i = 0 ; i < ROWS ; i++)
		fprintf(ft ,"%s\n" ,st[i] );
	
	if (fclose(fp) || fclose(ft))	
	{
		fprintf(stderr , "Clossing error .\n");
		exit(EXIT_FAILURE);
	}
	
	return 0 ;
}
 
void initialize_ar(FILE * fp ,int n , int m , int ar[n][m])
{
	// 读取文件中的内容到整型数组
	for (int i = 0 ; i < n ; i++)	
		for (int j = 0 ; j < m ; j++)
			//这样做是为了确保fscanf()正确读到1个数,而不受空格和其他字符影响
			while (fscanf(fp ,"%d" , &ar[i][j]) != 1)
				fscanf(fp ,"%*c");
}
 
void set_st(int n , int m , char st[n][m + 1] , int ar[n][m])
{
	int i , j ;
 
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < m ; j++)
		{
			st[i][j] = *(STR + ar[i][j]) ;
		}
		st[i][j] = '\0' ;
	}
}
