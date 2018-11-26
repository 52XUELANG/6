#define _CRT_SECURE_NO_WARNINGS
#ifndef __MAILLIST_H__
#define __MAILLIST_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct MailList
{
	char name[20];
	char sex[5];
	short age;
	char tel[11];
	char address[50];
}MailList, *pMailList;

int Menu();
void AddMember(pMailList* mail_list);
void DeleteMember(mail_list);
void FindMember(pMailList* mail_list);
void ChangeMember();
void ShowAllMember();
void EmptyMember();
void SortMember();

#endif