//包含头文件
#include"game.h"
//定义一个结构体用于储存玩家的基本信息
struct player 
{
  char simbolo;
  short num_win;
  short num_lose;
}pa,pb;
//主函数
int main() 
{
  menu();
  struct player *pl_1=&pa;
  struct player *pl_2=&pb;
  pl_1->simbolo='*';
  pl_2->simbolo='#';
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
            player(&pa);
            short re=verify(pl_1->simbolo);
            switch(re)
            {
              case 1:
                prinboard();
                printf("恭喜玩家%c本局获胜\n",pl_1->simbolo);
                pa.num_win++;
                pb.num_lose++;
                printf("现在比分%d : %d\n",pa.num_win,pb.num_win);
                if(!again())
                {
                  return 1;
                }
                printf("新的一局了\n");
                initiozation();
                break;
              case 2:
                prinboard();
                printf("平局!\n");
                printf("现在比分%d : %d\n",pa.num_win,pb.num_win);
                printf("新的一局了...\n");
                initiozation();
                break;
            }
          }
          else
          {
            player(&pb);
            short re=verify(pl_1->simbolo);
            switch(re)
            {
              case 1:
                prinboard();
                printf("恭喜玩家%c本局获胜\n",pl_2->simbolo);
                pa.num_win++;
                pb.num_lose++;
                printf("现在比分%d : %d\n",pa.num_win,pb.num_win);
                if(!again())
                {
                  return 1;
                }
                printf("新的一局了\n");
                initiozation();
                break;
              case 2:
                prinboard();
                printf("平局!\n");
                printf("现在比分%d : %d\n",pa.num_win,pb.num_win);
                printf("新的一局了...\n");
                initiozation();
                break;
            }
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
//玩家下棋
void player(struct player *pl)
{
  while(getchar()!='\n');
  int x,y;
  printf("玩家%c的回合:\n",pl->simbolo);
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
    board[y-1][x-1] = pl->simbolo;
    break;
  }while(1);//本来写了一大段表达式了，但是感觉太臃肿了，用break直接退出循环更简单。
  if(twins)
  {
    twins=false;
  }
  else
  {
    twins=true;
  }
}
//胜负判定
short verify(char ch_ww)
{
  int i;
  bool draw=true;
  //检测行
  for(i=0;i<SIDE;i++)
  {
    if (board[i][0]==ch_ww&&board[i][0] == board[i][1] && board[i][1] == board[i][2])
    {
      //PRINT("i=%d",i);
      return 1;
    }
  }
  //检测列
  for(i=0;i<3;i++)
  {
    if (board[0][i]==ch_ww&&board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
      //PRINT("i=%d",i);
      return 1;
    }
  }
  //检查对角线
  if((board[0][0]==ch_ww&&board[1][1]==ch_ww&&board[2][2]==ch_ww)||
  (board[2][0]==ch_ww&&board[1][1]==ch_ww&&board[1][1]==board[2][0]))
  {
    //PRINT("i=%d",i);
    return 1;
  }
  for(int i=0;i<SIDE;i++)
  {
    for(int j=0;j<SIDE;j++)
    {
      if(board[i][j]=='\0')
      {
        draw = false;
      }
    }
  }
  if(draw)
  {
    return 2;
  }
  return 0;
}
//再来一局？
short again()
{
  printf("本次对局结束了, 再来一盘吗?");
  printf("如果继续, 扣1");
  printf("如果不想玩了, 扣0");
  short ag;
  scanf("%hd",&ag);
  while(ag!=0&&ag!=1)
  {
    printf("输入错误, try again");
    scanf("%hd",&ag);
  }
  if(ag)
  {
    return 1;
  }
  else{
    return 0;
  }
}