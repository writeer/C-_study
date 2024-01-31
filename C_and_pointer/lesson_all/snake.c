#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

bool gameOver;
int score;
int x, y;  // 蛇头的坐标
int fruitX, fruitY;  // 食物的坐标
int tailX[100], tailY[100];  // 蛇身的坐标
int tailLength;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

void Setup()
{
    gameOver = false;
    score = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    dir = STOP;
}

void Draw()
{
    system("cls");  // 清屏

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else
            {
                bool printTail = false;
                for (int k = 0; k < tailLength; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        printTail = true;
                        break;
                    }
                }
                if (!printTail)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < tailLength; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
for (int i = 0; i < tailLength; i++)
{
    if (tailX[i] == x && tailY[i] == y)
    {
        gameOver = true;
        break;
    }
}

if (x == fruitX && y == fruitY)
{
    score++;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    tailLength++;
}
}

int main()
{
Setup();

while (!gameOver)
{
    Draw();
    Input();
    Logic();
    Sleep(10);  // 控制游戏速度，单位为毫秒
}

printf("Game Over!\n");
return 0;
}