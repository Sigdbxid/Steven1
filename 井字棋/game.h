#include <stdio.h>
#include<time.h>
#include<stdbool.h>
#define SIDE 3
#define PRINT(fmt, ...)   \
        printf("[FILE:%s][FUNC: %s][LINE:%d]\n"fmt,\
        __FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
int a;
struct player;
bool twins=false;
bool start=true;
char board[3][3];
char c='*';
char d='#';
short verify(char ch_ww);
void menu();
void p_board();
void initialization();
void player(struct player *pl);
void initialization();
short again();