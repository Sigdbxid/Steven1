#include <stdio.h>
#include<time.h>
#include<stdbool.h>
#define SIDE 3
int a;
struct player;
bool twins=false;
bool start=true;
char board[3][3];
char c='*';
char d='#';
int win =1;
int lose=0;
int win_lose=2;
char verify(char ch_ww);
void menu();
void prinboard();
void initizanation();
void player(struct player *pl);
void initiozation();
void again();
