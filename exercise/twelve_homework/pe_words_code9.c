#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

void words_handle();

int main(void)
{
    words_handle();
    system("pause");
    return 0;
}

void words_handle(){
    int words = 0;
    char temp[SIZE] = {0};
    char **ptr;
    char *pr;
    int nu;
    printf("How many words do you wish to enter?");
    scanf("%d",&words);
    ptr = (char **)malloc(words * sizeof(char *));//我发现的代码出错的原因是这个sizeof获取的大小不够，因为我用的sizeof(char)只有一个字节不够存指针，所以溢出了，然后数据就会变得奇怪。
    if (ptr == NULL)
	{

		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
    printf("Enter %d words now:\n",words);
    //如果有一个临时数组，而不是先得到字符然后获取单词，或者说一个数组来储存单词，就有两种方法。
    //一个是用fget获取一行，然后分割单词，在分别获取每个单词的长度，创建相应的数组
    //另外一个方法是，依次获取单词，然后创建相应的数组，储存，或者copy过去，可以一个字符一个字符的，也可以用strcpy函数
    for (int i = 0; i < words; i++)
    {
        scanf("%s",temp);
        nu = strlen(temp) + 1;
        pr = (char *)malloc(nu * sizeof(char));
        if (pr == NULL)
	{

		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
        strcpy(pr,temp);
        ptr[i] = pr;
    }
    
    puts("How are you words:");
    for (int i = 0; i < words; i++)
    {
        puts(ptr[i]);
        free(ptr[i]);
        ptr[i] = NULL;
    }
    free(ptr);
    ptr = NULL;
    return ;
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 100

int main(void)
{
	char **pt;
	char temp[LEN];
	int i, n, length;

	printf("How many words do you wish to enter? ");
	scanf("%d", &n);

	pt = (char**)malloc(n * sizeof(char *));
	//指向指针的指针


	if (pt == NULL)
	{

		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter %d words now:", n);


	//每循环一次，对temp中的数据进行一次拷贝
	for (i = 0; i < n; i++)
	{
		scanf("%99s", temp);
		length = strlen(temp) + 1;
		//↑+1便于保存空字符'\0';

		pt[i] = (char *)malloc(length * sizeof(char));
		//数组当中包含的元素都是指向 char类型 的指针，pt 是 指向指针的指针
		//↑使用malloc分配足够的存储空间来存储单词;
		if (pt[i] == NULL)
		{
			printf("Memory allocation failed!\n");
			exit(EXIT_FAILURE);
		}
		else
			strcpy(pt[i], temp);
		//这里空间够用，上诉为 pt[i] 创建的堆区空间大小即为 temp 数组对应大小的空间
	}

	printf("Here are your words:\n");
	for (i = 0; i < n; i++)
	{
		puts(pt[i]);
		free(pt[i]);
		pt[i] = NULL;
	}

	free(pt);
	pt = NULL;
	//↑指针仍然指向malloc分配的存储空间;
   //↑因此令指针指向NULL后防止内存滥用;
   system("pause");
	return 0;
}
*/