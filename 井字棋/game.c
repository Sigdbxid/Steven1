//包含头文件
#include"game.h"
//定义一个结构体用于储存玩家的基本信息
struct player 
{
  char simbolo;
  short num_win;
  short num_lose;
}pl_1,pl_2;


//主函数
int main() 
{
  menu();
  do
  {
    scanf("%d",&a);
    
  }while(a<0||a>=3);
  do
  {
    switch(a)//分辨玩家是想开始游戏还是退出游戏
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
//棋盘初始化并且也可以在一盘结束后刷新棋盘
void initiozation()
{
  for(int i=0;i<SIDE;i++)
  {
    for(int j=0;j<SIDE;j++)
    {
      board[i][j]='\0';
    }
  }
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
//打印玩家菜单
void menu()
{
  printf("----------------------------\n");
  printf("--------井字游戏(菜单)--------\n");
  printf("---------开始游戏(1)---------\n");
  printf("---------退出游戏(0)---------\n");
  printf("----------------------------\n");
  printf("请输入:");
}
//玩家1下棋
void player1()
{
  while(getchar()!='\n');
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
    if(board[y-1][x-1]!='\0')
    {
      printf("该坐标已经有主了, 亲!\n");
      continue;
    }
    *(*(board+y-1)+x-1) = c;
    break;
  }while(1);
  twins=true;
  if(verify(c)=='w')
  {
    printf("恭喜玩家%c你在本局获胜",c);
    initiozation();
  }
}
//玩家2下棋
void player2()
{
  while(getchar()!='\n');
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
    board[y-1][x-1] = d;
    break;
  }while(1);//本来写了一大段表达式了，但是感觉太臃肿了，用break直接退出循环更简单。
  twins=false;
  if(verify(c)=='w')
  {
    printf("恭喜玩家%c你在本局获胜",c);
    initiozation();//刷新棋盘
  }
}
//人机下棋
void computer()
{
  
}
//胜负判定
char verify(char ch_ww)
{
  int i;

  //检测行
  for(i=0;i<3;i++)
  {
    if (board[i][0]==ch_ww&&board[i][0] == board[i][1] && board[i][1] == board[i][2])
    {
      ch_ww='w';
      return ch_ww;
    }
  }
  //检测列
  for(i=0;i<3;i++)
  {
    if (board[0][i]==ch_ww&&board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
      ch_ww='w';
      return ch_ww;
    }
  }
  //检查对角线
  if((board[0][0]==ch_ww&&board[0][0]==board[1][1]&&board[2][2]==board[1][1])||
  (board[0][0]==ch_ww&&board[0][2]==board[1][1]&&board[1][1]==board[2][0]))
  {
    ch_ww='w';
    return ch_ww;
  }
}