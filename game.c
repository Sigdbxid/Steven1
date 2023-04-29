#include <stdio.h>
#include<time.h>
#include<stdbool.h>
int a;
bool twins=false;
bool start=true;
char board[3][3];
int win =1;
int lose=0;
int win_lose=2;
void menu();
void prinboard();
void initizanation();
void player1();
void player2();
//主函数
int main() 
{
  menu();
  scanf("%d",&a);
  do 
    {
      
      switch(a)
        {
          case 0:
          printf("退出游戏\n");
          return 1;
          case 1:
          
          if(start==true)
          {
            printf ("开始游戏\n");
            start=false;
          }
          prinboard();
          if(twins==false)
          {
          player1();
          }
          else
          {
            player2();
          }
          break;
          default:
          printf("输入错误\n");
          break;
        }
    }while(a);
  return 0;
}
//棋盘打印
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
        printf("|");
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
//玩家下棋
void player1()
{
  char (*p)[3]=(char(*)[3])board;
  char c='*';
  int x,y;
  printf("玩家*的回合:\n");
  do
  {
    printf("请输入坐标(x)\n");
    scanf("%d",&x);
    printf("请输入坐标(y)\n");
    scanf("%d",&y);
    printf("\n");
    
    if(x<=0||x>3||y>3||y<=0)
    {
      printf("输入超过了有效范围, 请重新输入:\n");
      continue;
    }
    if(board[x-1][y-1]!='\0')
    {
      printf("该坐标已经有主了, 亲!\n");
      continue;
    }
    *(*(board+x)+y) = c;
  }while(x<=0||x>3||y>3||y<=0);
  twins=true;
}
//player2
void player2()
{
  char c='#';
  int x,y;
  printf("玩家#的回合:\n");
  do
  {
    printf("请输入坐标(x)\n");
    scanf("%d",&x);
    printf("请输入坐标(y)\n");
    scanf("%d",&y);
    printf("\n");
    
    if(x<=0||x>3||y>3||y<=0)
    {
      printf("输入超过了有效范围, 请重新输入:\n");
      continue;
    }
    if(board[y-1][x-1]!='\0')
    {
      printf("该坐标已经有主了, 亲!\n");
      continue;
    }
    board[y-1][x-1] = c;
  }while(x<=0||x>3||y>3||y<=0);
  twins=false;
}
//人机下棋
void computer()
{
  
}
//胜负判定
int verify(char a)
{
  int i;
  char ch_ww=' ';
  //检测行
  for(i=0;i<3;i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
    {
      ch_ww=board[i][0];
    }
  }
  //检测列
  for(i=0;i<3;i++)
  {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
      ch_ww=board[0][i];
    }
  }

  return ch_ww;
}
//再来一局？
//评语
