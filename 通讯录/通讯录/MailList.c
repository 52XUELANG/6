#define _CRT_SECURE_NO_WARNINGS
#include"MailList.h"

void AddMember(pMailList* mail_list)
{
	assert(mail_list);
	*mail_list = (pMailList)malloc(sizeof(MailList));
	printf("����:");
	gets((*mail_list)->name);
	printf("\n");
	fflush(stdin);

	printf("�Ա�:");
	gets((*mail_list)->sex);
	printf("\n");
	fflush(stdin);

	printf("����:");
	scanf("%d", &((*mail_list)->age));
	printf("\n");
	fflush(stdin);

	printf("�绰:");
	gets((*mail_list)->tel);
	printf("\n");
	fflush(stdin);

	printf("סַ:");
	gets((*mail_list)->address);
	printf("\n");
	fflush(stdin);

	printf("\n");
}
void DeleteMember(pMailList* mail_list)
{
	assert(mail_list);
	pMailList p_mail_list = *mail_list;
	printf("����Ҫɾ��������:");
	char del_name[20];
	scanf("%s",del_name);
	while (1)
	{
		if (!strcmp(del_name, p_mail_list->name))
		{
			printf("����:%s\n", p_mail_list->name);
			printf("ȷ��ɾ����\n Y or N");
			char c = '\0';
			scanf("%c", &c);
			if (c == 'Y')
			{
				free(p_mail_list);
				break;
			}
			else if (c == 'N')
			{
				break;
			}
			else
			{
				printf("��ȷ���룡\n");
				continue;
			}
		}
		p_mail_list++;
	}
	
}
void FindMember(pMailList* mail_list)
{
	assert(mail_list);
	printf("����Ҫ���ҵ�����:");
	char find_name[20];
	gets(find_name);
	if (!strcmp(find_name, (*mail_list)->name))
	{
		printf("����:%s\n", (*mail_list)->name);
		printf("����:%d\n",(*mail_list)->age);
		printf("�Ա�:%s\n", (*mail_list)->sex);
		printf("�绰:%s\n", (*mail_list)->tel);
		printf("סַ:%s\n", (*mail_list)->address);
		printf("\n\n");
	}
	else
	{
		printf("���޴��ˣ�\n\n");
	}
}
void ChangeMember();
void ShowAllMember();
void EmptyMember();
void SortMember();
int Menu()
{
	printf("���������:\n");
	printf(" 0:���\n 1:ɾ��\n 2:����\n 3:�޸�\n 4:��ʾ������\n 5:���\n 6:����������\n 7:������ϵ�˵��ļ�\n 8:����\n 9:�Ƴ�\n");
	int choice;
	scanf("%d",&choice);
	return choice;
}