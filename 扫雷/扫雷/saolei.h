#define _CRT_SECURE_NO_WARNINGS

/*ɨ����Ϸ*/

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
void Menu();//�˵�
void Game();//��Ϸ��ʼ
void Init(char arr[ROWS][COLS], int row, int col, char s);//��ʼ��
void DisPlay(char mine[ROWS][COLS],int row,int col);//��ӡ
void SetMine(char mine[ROWS][ROWS], int row,int col);//����
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//����
int GetMine(char arr[ROWS][COLS],int row,int col);//ͳ������
void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//չ��



#endif