/**
 * @file eight_queen_question.c
 * @author your name (you@domain.com)
 * @brief 八皇后问题
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*#include <stdio.h>
#define ROW 7
#define COL 8
//测试方案并打印
int queen_answer(int (*queen)[8],int count);//不指定棋盘大小，如果要指定，那就换成int y,int (*queen)[y]
int print(int *identity);

int main(void)
{
    int eight[ROW][COL] = {0}; //创建一个7×8棋盘，矩阵中用1代表皇后，0代表位置空
    int count = 0; //记录一下有几种方案
    count = queen_answer(eight,0);
    printf("一共有%d种方案",count);
    getchar();
    return 0;
}

int queen_answer(int (*queen)[8],int count)
{
    //int flag = 0;//标志位，用于标志当前点是否可以设置
    for (int i = 0; i < ROW; i++)//先测行
    {
        if(*(*queen) + i == 1)
            return 0;
    }
    for (int i = 0; i < COL; i++)//测列
    {
        if(*queen + i == 1)
            return 0;
    }
    
    
}*/

#include <stdio.h>
#define ROW 8
#define COL 8
int board[ROW][COL];

//打印解决方案
void print_board()
{
    int row;//列
    int column;//行
    static int n_solutions;
    
    n_solutions += 1;//统计打印次数，得到解决次数
    printf("Solution #%d:\n",n_solutions);

    for(row = 0; row < ROW; row++){
        for(column = 0; column < COL; column++){
            if(board[row][column])
                printf("%2c",'Q');
            else
                printf("%2c",'+');
        }
        putchar('\n');
    }
    putchar('\n');
}

//检测board[row][column]的上半部分的方向上是否有其他皇后
int conflicts(int row, int column)
{
    int i;
    for(i = 1; i < 8; i++){
        if(row - i >= 0 && board[row - i][column])//查看前面的几行是否有皇后
            return 1;
        if(column - i >= 0 && board[row][column - i])//查看前面几列是否有皇后
            return 1;
        /*if(column + i < 8 && board[row][column + i])//查看后面是否有皇后，我觉得这条可以删掉，因为检查是从前面开始，如果前面有了，后面就不用检查了，如果前面没有，后面设为皇后就行
            return 1;*/

        if(row - i >= 0 && column - i >= 0 && board[row - i][column - i])//右斜边
            return 1;
        if(row - i >= 0 && column + i < 8 && board[row - i][column + i])//左斜边
            return 1;
    }
    return 0;
}

//回溯法调用自身
void place_queen(int row)
{
    int column;
    for(column = 0; column < COL; column++){
        board[row][column] = 1;
        if(row == 0 || !conflicts(row,column))
            if(row < ROW - 1)
                place_queen(row + 1);
            else
                print_board();
        board[row][column] = 0;//重设为0，刷新整个棋盘
    }
}

int main()
{
    place_queen(0);
    getchar();
    return 0;
}