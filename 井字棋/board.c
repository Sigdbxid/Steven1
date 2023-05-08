//棋盘打印
#include"game.h"
void prinboard()
{
  char (*p)[3]=board;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf(" %c ", *(*(p+i)+j));
      if(j != 2)
      {
        printf(" |");
      }
    }
    printf("\n");
    if(i != 2)
    {
      printf("---+---+---\n");
    }
  }
  printf("\n");
  
}
//玩家菜单
void menu()
{
  printf("----------------------------\n");
  printf("--------井字游戏(菜单)--------\n");
  printf("---------开始游戏(1)---------\n");
  printf("---------退出游戏(0)---------\n");
  printf("----------------------------\n");
  printf("请输入:");
}