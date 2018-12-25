#define _CRT_SECURE_NO_WARNINGS
#ifndef __MailList_H__
#define __MailList_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct MailMember
{
	char name[20];
	char sex[5];
	short age;
	char tel[11];
	char address[50];
	int size;
}MailMember, *pMailMember;

typedef struct MailList
{
	MailMember* MailList;
	int size;
	int capacity;
}MailList;


void ListInit(MailList* mail_list);
int Menu();
void AddMember(MailList* mail_list);
void DeleteMember(MailList* mail_list);
void FindMember(MailList mail_list);
void ChangeMember(MailList* mail_list);
void ShowAllMember(MailList mail_list);
void EmptyMember(MailList* mail_list);
void SortMember(MailList* mail_list);

#endif