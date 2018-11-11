#define _CRT_SECURE_NO_WARNINGS

/*扫雷游戏*/

#ifndef __SAOLEI_H__
#define __SAOLEI_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_NUM ((ROW*COL)/9)
void Menu();//菜单
void Game();//游戏开始
void Init(char arr[ROWS][COLS], int row, int col, char s);//初始化
void DisPlay(char mine[ROWS][COLS],int row,int col);//打印
void SetMine(char mine[ROWS][ROWS], int row,int col);//布雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//排雷
int GetMine(char arr[ROWS][COLS],int row,int col);//统计雷数
void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//展开



#endif