//网上找的，因为我很懒得写，但是又觉得有参考价值。
//第七题很简单，就是把一组数据的每个位置，做预期的判断，然后去掉不需要的值就行了。
#include <stdio.h>
#include <limits.h>
#define FONT_ID 0XFF000000
#define FONT_SIZE 0XFE0000
#define ALIGNMENT 0XC000
#define LEFT 0X0000
#define CENTER 0X4000
#define RIGHT 0X8000
#define BOLD 0X800
#define ITATIC 0X400
#define UNDERLINE 0X200
void print_menu(void);
void show_settings(unsigned long);
char * itobs(int n,char * ps);
char get_choice(void);
int main(void)
{
	unsigned long font_style=0;
	char ch;
 
	print_menu();
	while((ch=get_choice())!='q')
	{
		switch(ch)
	    {
			case 'f': font_style&=~FONT_ID;    // 重置字体
				      printf("Enter font ID(0~255): ");
				      unsigned int font_ID;
				      scanf("%u",&font_ID);
				      while(getchar()!='\n')
					      continue;
				      font_ID&=255;
				      font_ID<<=24;
				      font_style|=font_ID;
				      break;
			case 's': font_style&=~FONT_SIZE;    // 重置字体大小
				      printf("Enter font size(0~127): ");
				      unsigned int font_size;
				      scanf("%u",&font_size);
				      while(getchar()!='\n')
					      continue;
				      font_size&=127;
				      font_size<<=17;
				      font_style|=font_size;
				      break;
			case 'a': printf("Select alignment:\n");
				      printf("l)left    c)center   r)right\n");
				      font_style&=~ALIGNMENT;    // 重置对齐方式
				      char align;
				      scanf("%c",&align);
				      while(getchar()!='\n')
					      continue;
				      switch(align)
					  {
					      case 'l': font_style|=LEFT;  break;   // 左对齐
					      case 'c': font_style|=CENTER; break;  // 居中对齐
					      case 'r': font_style|=RIGHT; break;   // 右对齐
				      }
			          break;
			case 'b': font_style^=BOLD;   // 切换加粗
				      break;
			case 'i': font_style^=ITATIC;   // 切换斜体
					  break;
			case 'u': font_style^=UNDERLINE;  // 切换下划线
				      break;
			default: break;
		}
		show_settings(font_style);
		print_menu();
	}
	printf("Bye.\n");
 
	return 0;
}
 
void print_menu(void)
{
	printf("f)change font   s)change size   a)change alignment\n");
	printf("b)toggle bold   i)toggle static u)toggle underline\n");
	printf("q)quit\n");
}
 
void show_settings(unsigned long font_style)
{
	printf("ID  SIZE ALIGNMENT   B   I   U\n");
	printf("%-3u %4u",font_style>>24,(font_style&(~FONT_ID))>>17);
	switch(font_style&ALIGNMENT)
	{
		case LEFT: printf(" %7s","left");  break;
		case CENTER: printf(" %7s","center"); break;
		case RIGHT:  printf(" %7s","right"); break;
	}
	printf("    %3s",(font_style&BOLD)?"on":"off");
	printf(" %3s",(font_style&ITATIC)?"on":"off");
	printf(" %3s",(font_style&UNDERLINE)?"on":"off");
	printf("\n");
}
 
char * itobs(int n,char * ps)
{
	int i;
	const static int size=CHAR_BIT*sizeof(unsigned long);
	for(i=size-1;i>=0;i--,n>>=1)
		ps[i]=(01&n)+'0';
	ps[size]='\0';
 
	return ps;
}
 
char get_choice(void)
{
	char ch;
 
	scanf("%c",&ch);
	while(getchar()!='\n')
		continue;
 
	return ch;
}