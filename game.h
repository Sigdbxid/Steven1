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