#define _CRT_SECURE_NO_WARNINGS

/*
����������Ϸ
֧��˫�˺ͷ������˻���ս
*/

#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Menu(int check[3][3]);//��ʼ�˵�

int SelectionMenu();//ѡ��˵�

void Initialization(int check[3][3]);//��ʼ������

void PrintingCheckerboard(int check[3][3]);//��ӡ����

int JudgeWinAndLose(int check[3][3]);//�ж���Ӯ

void Player1(int check[3][3]);//һ��

void Player2(int check[3][3]);//����

void Computer(int check[3][3]);//�������

int Full(int check[3][3]);//������Ա

void Game(int check[3][3]);//��Ϸ����

#endif