#define _CRT_SECURE_NO_WARNINGS

/*
简单三子棋游戏
支持双人和非智能人机对战
*/

#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Menu(int check[3][3]);//开始菜单

int SelectionMenu();//选择菜单

void Initialization(int check[3][3]);//初始化棋盘

void PrintingCheckerboard(int check[3][3]);//打印棋盘

int JudgeWinAndLose(int check[3][3]);//判断输赢

void Player1(int check[3][3]);//一号

void Player2(int check[3][3]);//二号

void Computer(int check[3][3]);//电脑玩家

int Full(int check[3][3]);//棋盘满员

void Game(int check[3][3]);//游戏过程

#endif