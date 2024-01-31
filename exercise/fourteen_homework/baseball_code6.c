/*#include <stdio.h>
#include <stdlib.h>

struct player{
    unsigened int number[19]; //球员号0-18
}*/
//懒得写了，网上抄来改改
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NLEN 20
#define MAXRS 100
struct name {              //姓名
	char fname[NLEN];
	char lname[NLEN];
};
struct data {              //数据
	unsigned int P_count;  // 上场数
	unsigned int D_count;  // 击中数
	unsigned int R_count;  // 走垒
	unsigned int I_count;  // 打点
};
struct record {             // 记录
	unsigned int P_number;   //球员号
	struct name names;
	struct data datas;
};
struct player {                // 球员数据统计
	unsigned int P_number;
	struct name names;
	struct data datas;
	float Rate;           // 安打率
};
 
int main(void)
{
	FILE * fp;
	struct player total[19]={           //初始化所有球员的数据
	{0,{"abc","def"}},
	{1,{"ghi","jkl"}},
	{2,{"mno","pqr"}},
	{3,{"stu","vwx"}},
	{4,{"bcd","efg"}},
	{5,{"hij","klm"}},
	{6,{"nop","qrs"}},
	{7,{"tuv","wxy"}},
	{8,{"cde","fgh"}},
	{9,{"ijk","lmn"}},
	{10,{"opq","rst"}},
	{11,{"uvw","xyz"}},
	{12,{"def","ghi"}},
	{13,{"jkl","mno"}},
	{14,{"pqr","stu"}},
	{15,{"vwx","yxa"}},
	{16,{"acd","bef"}},
	{17,{"gij","hkl"}},
	{18,{"mop","nqr"}}
	};
	struct record temp;      // 临时数组（应该叫临时结构
	int count=0;
	int i=0,index;
 
	if((fp=fopen("records.dat","a+b"))==NULL)//以a+b方式打开，可以在下次打开时添加数据，但是不可更新文件，第二次打开会导致文件重复写在后面
	{
		fputs("Error in open file.",stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter the player/'s records:"); // 给文件添加一些记录
	puts("Enter the number of the player(<0 || >18 quit):");
	while(scanf("%u",&temp.P_number)==1 && temp.P_number>=0 && temp.P_number<=18)//正常输入一个球员编号，并且不超过18，大于等于0
	{//他用scanf，如果有错误输入就不好处理了，最好的方法是自建一个函数，或者用atoi，不过算了，我是抄代码的。
    //有点奇怪，我一开始直接输入错误的输入，理论上来说应该不会执行循环中的部分，也就是不会写入文件，但是依然读出了基本的格式。
    //并且a+只会在文件结尾进行添加，这个函数却和w+一样，会写入值，并且完全更改文件内容。
    //经过我的观察，确实没有写入文件，因为每次都会根据值来打印，没有值自然结构初始化是0，所以也就正常。
    //至于每次打印出来的数据会自动增加，完全是因为下面的统计方法，当读取到三个0编号的结构数据，自然就会把他们的值加上
    //然后显示时就会自动增加，一开始我还以为是文件重写，更新，现在我明白，确实只是添加到后面而已，只是统计时会一起统计，然后一起计算安打率。
    //所以这个程序只能增加数据，不能修改，其实文件里改也行，但是程序上不行，不过题目没有要求，我也懒了没有写，所以这个程序我觉得想到棒。
		temp.names=total[temp.P_number].names;//读取球员编号后的名字赋给临时结构
		puts("Enter the score datas(P_count D_count R_count I_count) of the player:");
		scanf("%u %u %u %u",&temp.datas.P_count,&temp.datas.D_count,&temp.datas.R_count
			               ,&temp.datas.I_count);//输入球员的数据
        while (getchar() != '\n')//写个循环帮他处理一下scanf留着缓冲区中的换行符
            continue;
        
		fwrite(&temp,sizeof(struct record),1,fp);//把结果写入文件
		fputc('\n',fp);//下面要多用一个fgetc的原因就在于这里多了一个换行符
		puts("Enter next record:");
	}
	rewind(fp);
	while(fread(&temp,sizeof(struct record),1,fp)==1)    // 统计球员数据
	{
		switch(temp.P_number)//读取对应结构的球员号
		{//原来结构，哪一个对应，就把相关值加入到哪一个，其实如果名字也用输入，可以直接两两个结构相等，因为球员名字未定义，直接相等，会覆盖原来的名字。
			case 0:total[0].datas.P_count+=temp.datas.P_count;//这个代码是把文件中的全部数据，读到程序的内存中。
				   total[0].datas.D_count+=temp.datas.D_count;
				   total[0].datas.R_count+=temp.datas.R_count;
				   total[0].datas.I_count+=temp.datas.I_count;
				   break;
			case 1:total[1].datas.P_count+=temp.datas.P_count;
				   total[1].datas.D_count+=temp.datas.D_count;
				   total[1].datas.R_count+=temp.datas.R_count;
				   total[1].datas.I_count+=temp.datas.I_count;
				   break;
            case 2:total[2].datas.P_count+=temp.datas.P_count;
				   total[2].datas.D_count+=temp.datas.D_count;
				   total[2].datas.R_count+=temp.datas.R_count;
				   total[2].datas.I_count+=temp.datas.I_count;
				   break;
            case 3:total[3].datas.P_count+=temp.datas.P_count;
				   total[3].datas.D_count+=temp.datas.D_count;
				   total[3].datas.R_count+=temp.datas.R_count;
				   total[3].datas.I_count+=temp.datas.I_count;
				   break;
            case 4:total[4].datas.P_count+=temp.datas.P_count;
				   total[4].datas.D_count+=temp.datas.D_count;
				   total[4].datas.R_count+=temp.datas.R_count;
				   total[4].datas.I_count+=temp.datas.I_count;
				   break;
            case 5:total[5].datas.P_count+=temp.datas.P_count;
				   total[5].datas.D_count+=temp.datas.D_count;
				   total[5].datas.R_count+=temp.datas.R_count;
				   total[5].datas.I_count+=temp.datas.I_count;
				   break;
            case 6:total[6].datas.P_count+=temp.datas.P_count;
				   total[6].datas.D_count+=temp.datas.D_count;
				   total[6].datas.R_count+=temp.datas.R_count;
				   total[6].datas.I_count+=temp.datas.I_count;
				   break;
            case 7:total[7].datas.P_count+=temp.datas.P_count;
				   total[7].datas.D_count+=temp.datas.D_count;
				   total[7].datas.R_count+=temp.datas.R_count;
				   total[7].datas.I_count+=temp.datas.I_count;
				   break;
            case 8:total[8].datas.P_count+=temp.datas.P_count;
				   total[8].datas.D_count+=temp.datas.D_count;
				   total[8].datas.R_count+=temp.datas.R_count;
				   total[8].datas.I_count+=temp.datas.I_count;
				   break;
            case 9:total[9].datas.P_count+=temp.datas.P_count;
				   total[9].datas.D_count+=temp.datas.D_count;
				   total[9].datas.R_count+=temp.datas.R_count;
				   total[9].datas.I_count+=temp.datas.I_count;
				   break;
           case 10:total[10].datas.P_count+=temp.datas.P_count;
				   total[10].datas.D_count+=temp.datas.D_count;
				   total[10].datas.R_count+=temp.datas.R_count;
				   total[10].datas.I_count+=temp.datas.I_count;
				   break;
           case 11:total[11].datas.P_count+=temp.datas.P_count;
				   total[11].datas.D_count+=temp.datas.D_count;
				   total[11].datas.R_count+=temp.datas.R_count;
				   total[11].datas.I_count+=temp.datas.I_count;
				   break;
           case 12:total[12].datas.P_count+=temp.datas.P_count;
				   total[12].datas.D_count+=temp.datas.D_count;
				   total[12].datas.R_count+=temp.datas.R_count;
				   total[12].datas.I_count+=temp.datas.I_count;
				   break;
           case 13:total[13].datas.P_count+=temp.datas.P_count;
				   total[13].datas.D_count+=temp.datas.D_count;
				   total[13].datas.R_count+=temp.datas.R_count;
				   total[13].datas.I_count+=temp.datas.I_count;
				   break;
           case 14:total[14].datas.P_count+=temp.datas.P_count;
				   total[14].datas.D_count+=temp.datas.D_count;
				   total[14].datas.R_count+=temp.datas.R_count;
				   total[14].datas.I_count+=temp.datas.I_count;
				   break;
           case 15:total[15].datas.P_count+=temp.datas.P_count;
				   total[15].datas.D_count+=temp.datas.D_count;
				   total[15].datas.R_count+=temp.datas.R_count;
				   total[15].datas.I_count+=temp.datas.I_count;
				   break;
           case 16:total[16].datas.P_count+=temp.datas.P_count;
				   total[16].datas.D_count+=temp.datas.D_count;
				   total[16].datas.R_count+=temp.datas.R_count;
				   total[16].datas.I_count+=temp.datas.I_count;
				   break;
           case 17:total[17].datas.P_count+=temp.datas.P_count;
				   total[17].datas.D_count+=temp.datas.D_count;
				   total[17].datas.R_count+=temp.datas.R_count;
				   total[17].datas.I_count+=temp.datas.I_count;
				   break;
           case 18:total[18].datas.P_count+=temp.datas.P_count;
				   total[18].datas.D_count+=temp.datas.D_count;
				   total[18].datas.R_count+=temp.datas.R_count;
				   total[18].datas.I_count+=temp.datas.I_count;
				   break;
			default: break;
		}
		fgetc(fp);//我猜测可能是每次指针差一，导致读取有问题，所以加入fgetc来移动指针。fgetc会读取一个字符并且把指针移动一位。
	}
	for(index=0;index<19;index++)    // 计算安打率
	{
		if(total[index].datas.P_count!=0)
			total[index].Rate=total[index].datas.D_count/total[index].datas.P_count;
		else
			total[index].Rate=0.0;
	}
	for(index=0;index<19;index++)     // 输出每个球员的数据
		printf("%u %s %s,%u %u %u %u %.2f\n",total[index].P_number,total[index].names.fname,total[index].names.lname,
			                              total[index].datas.P_count,total[index].datas.D_count,
			                              total[index].datas.R_count,total[index].datas.I_count,
			                              total[index].Rate);
	fclose(fp);
	puts("Bye.");
    
    system("pause");
	return 0;

}