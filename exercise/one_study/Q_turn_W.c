#include <stdio.h>

int main(void){
    long double quart = 3.0E-23;
    float num;
    int g = 950;
    printf("This is a quart converted water molecule\n");
    printf("input quart:");
    scanf("%f",&num);
    num = num * g / quart;
    printf("water molecule = %e",num);//只有用科学计数法才能显示出来，数字太大超过了上限。
    getchar();
    getchar();
    return 0;
}

/*
#include <stdio.h>
 
#define MOL_MASS  3.0e-23
#define QT_MASS 950
 
int main(int argc, const char *argv[])
{
	float water,quarts,molecules;
	printf("MOL_MASS = %e\n", MOL_MASS);
	printf("Please enter number of the quart of water: ");
	scanf("%f",&quarts);
	
	water = quarts * QT_MASS;    //计算水的质量
	molecules = quarts * QT_MASS / MOL_MASS;   //计算水分子的数量
	
	printf("quarts = %f quart\n",quarts);
	printf("water = %f g\n",water);
	printf("molecules = %e(%f)\n",molecules,molecules);
	putchar('\n');
	getchar();
    getchar();
	return 0;
}*/