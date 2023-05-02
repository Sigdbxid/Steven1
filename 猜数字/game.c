#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct player 
{
    char simbolo;
    short num_win;
    short num_lose;
}pl_1,pl_2;

int main()
{
    char c;
    scanf("%c",&c);
    switch(c)
    {
        case 1:

    }
    return 0;
}

void menu()
{
    printf("猜数字游戏");
    printf("\t\t1;开始游戏");
    printf("\t\t2:退出游戏");
    printf("请输入1或2:");
}
