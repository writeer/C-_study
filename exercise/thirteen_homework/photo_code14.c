# include <stdio.h>
# include <stdlib.h>
# define ROWS 20
# define COLS 30
# define FNAME "photo.txt"
# define FARGS "photo_jpg.txt"
# define STR " .':~*=&%#"
 
void initialize_ar(FILE * fp ,int n , int m , int ar[n][m]);
void set_st(int n , int m , char st[n][m + 1] , int ar[n][m]);
void repair(int n, int m, int ar[n][m]);
 
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
    repair(ROWS,COLS,ar);
	set_st(ROWS , COLS , st , ar) ;
 
	for (int i = 0 ; i < ROWS ; i++)
		fprintf(ft ,"%s\n" ,st[i] );
	
	if (fclose(fp) || fclose(ft))	
	{
		fprintf(stderr , "Clossing error .\n");
		exit(EXIT_FAILURE);
	}
	printf("Done!\n");
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
//因为最后三题很像，这里我也借鉴了网上的写法，但是我发现他没有对最上，最边缘，最下等地方做处理，而是忽略了，于是我加入了处理方法
//如果是自己慢慢磨，也能写，但是代码就要长不少，我还是很感谢他的通过指针来选择字符储存的方法，让我学到不少。
void repair(int n, int m, int ar[n][m]){
    int count;
    int sum;
    int l,r,u,d; //左右前后
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            l = r = u = d = 1;
            sum = count = 0;
            if (j == 0)
            {
                l = 1;
                r = (ar[i][j] - ar[i][j + 1]) >1 ? 1 : 0;
                sum += ar[i][j + 1];
                count++;
            }
            else if (j > 0)
            {
                l = (ar[i][j] - ar[i][j - 1]) >1 ? 1 : 0;
                sum += ar[i][j - 1];
                count++;
            }
            if (j == 0 && j < m-1)
            {
                ;
            }
            else if(j == m -1)
            {
                r = 1;
            }
            else if(j < m - 1)
            {
                r = (ar[i][j] - ar[i][j + 1]) >1 ? 1 : 0;
                sum += ar[i][j + 1];
                count++;
            }
            if (i == 0)
            {
                u = 1;
                d = (ar[i][j] - ar[i + 1][j]) >1 ? 1 : 0;
                sum += ar[i + 1][j];
                count++;
            }
            else if (i > 0)
            {
                u = (ar[i][j] - ar[i - 1][j]) >1 ? 1 : 0;
                sum += ar[i-1][j];
                count++;
            }
            
            if (i == 0)
            {
                ;
            }
            else if(i == n - 1)
            {
                u = 1;
            }
            else if (i < n - 1)
            {
                d = (ar[i][j] - ar[i + 1][j]) >1 ? 1 : 0;
                sum += ar[i + 1][j];
                count++;
            }
            if (l && r && u && d)
            {
                ar[i][j] = sum /count;
            }
            
        }
        
    }
    
}