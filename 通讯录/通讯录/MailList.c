#define _CRT_SECURE_NO_WARNINGS
#include"MailList.h"


void ListInit(MailList* mail_list)//��ʼ��
{
	assert(mail_list);
	mail_list->size = 0;
	mail_list->capacity = 10;
	mail_list = (MailList*)malloc(sizeof(MailMember)*mail_list->capacity);
}

void CheckCapacity(MailList* mail_list)
{
	mail_list->capacity *= 2;
	MailList* new_mail_list = NULL;
	new_mail_list = (MailList*)malloc(sizeof(MailMember)*mail_list->capacity);
	assert(new_mail_list);
	for (int i = 0; i < mail_list->size; i++)
	{
		new_mail_list->MailList[i] = mail_list->MailList[i];
	}
	free(mail_list);
	mail_list = new_mail_list;
}

void AddMember(MailList* mail_list)
{
	assert(mail_list);
	if (mail_list->size == mail_list->capacity)
	{
		CheckCapacity(mail_list);
	}
	mail_list->MailList = (pMailMember)malloc(sizeof(MailMember));
	printf("����:");
	gets(mail_list->MailList[mail_list->size].name);
	printf("\n");
	fflush(stdin);

	printf("�Ա�:");
	gets(mail_list->MailList[mail_list->size].sex);
	printf("\n");
	fflush(stdin);

	printf("����:");
	scanf("%d", &mail_list->MailList[mail_list->size].age);
	printf("\n");
	fflush(stdin);

	printf("�绰:");
	gets(mail_list->MailList[mail_list->size].tel);
	printf("\n");
	fflush(stdin);

	printf("סַ:");
	gets(mail_list->MailList[mail_list->size].address);
	printf("\n");
	fflush(stdin);
	mail_list->size++;
	printf("\n");
}
void DeleteMember(MailList* mail_list)
{
	assert(mail_list);
	MailList* mail_list_tmp = mail_list;
	printf("����Ҫɾ��������:");
	char del_name[20];
	scanf("%s",del_name);
	int i = 0;
	while (i<mail_list->size)
	{
		if (!strcmp(del_name, mail_list_tmp->MailList[i].name))
		{
			printf("����:%s\n", mail_list_tmp->MailList[i].name);
			printf("ȷ��ɾ����\n Y or N");
			char c = '\0';
			scanf("%c", &c);
			if (c == 'Y')
			{
				mail_list->MailList[i] = mail_list->MailList[mail_list->size - 1];
				mail_list->size--;
				return;
			}
			else if (c == 'N')
			{
				return;
			}
			else
			{
				printf("��ȷ���룡\n");
				continue;
			}
		}
		i++;
	}
	printf("�Բ��𣬲��޴���");
	return;
}
void FindMember(MailList mail_list)
{
	if (mail_list.size == 0)
	{
		printf("û�д洢�û�");
		return;
	}
	else
	{
		int i = 0;
		printf("����Ҫ���ҵ�����:");
		char find_name[20];
		gets(find_name);
		while (i < mail_list.size)
		{
			if (!strcmp(find_name, mail_list.MailList[i].name))
			{
				printf("����:%s\n", mail_list.MailList[i].name);
				printf("����:%d\n", mail_list.MailList[i].age);
				printf("�Ա�:%s\n", mail_list.MailList[i].tel);
				printf("�绰:%s\n", mail_list.MailList[i].tel);
				printf("סַ:%s\n", mail_list.MailList[i].address);
				printf("\n\n");
				return;
			}
			else
			{
				i++;
			}
			printf("���޴���");
			return;
		}
	}
}
void ChangeMember(MailList* mail_list)//�޸�
{
	assert(mail_list);
	printf("����Ҫ�޸ĵ��˵�����: ");
	char find_name[20];
	gets(find_name);
	int i = 0;
	while (i<mail_list->size)
	{
		if (!strcmp(find_name, mail_list->MailList[i].name))
		{
			break;
		}
		else
		{
			i++;
		}
	}
	printf("����:");
	gets(mail_list->MailList[mail_list->size].name);
	printf("\n");
	fflush(stdin);

	printf("�Ա�:");
	gets(mail_list->MailList[mail_list->size].sex);
	printf("\n");
	fflush(stdin);

	printf("����:");
	scanf("%d", &mail_list->MailList[mail_list->size].age);
	printf("\n");
	fflush(stdin);

	printf("�绰:");
	gets(mail_list->MailList[mail_list->size].tel);
	printf("\n");
	fflush(stdin);

	printf("סַ:");
	gets(mail_list->MailList[mail_list->size].address);
	printf("\n");
	fflush(stdin);

}
void ShowAllMember(MailList mail_list)//��ʾ����
{
	if (mail_list.size = 0)
	{
		printf("û�д洢�û�");
	}
	else
	{
		int i = 0;
		while (i<mail_list.size)
		{
			printf("����:%s\n", mail_list.MailList[i].name);
			printf("����:%d\n", mail_list.MailList[i].age);
			printf("�Ա�:%s\n", mail_list.MailList[i].sex);
			printf("�绰:%s\n", mail_list.MailList[i].tel);
			printf("סַ:%s\n", mail_list.MailList[i].address);
			i++;
		}
	}
}
void EmptyMember(MailList* mail_list)//���
{
	mail_list->size = 0;
}

static void ListBubbleSort(MailList* mail_list)
{
	int i = mail_list->size;
	for (i; i > 0; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (0 >= strcmp(mail_list->MailList[j].name, mail_list->MailList[j + 1].name))
			{
				j++;
			}
			else if (0 < strcmp(mail_list->MailList[j].name, mail_list->MailList[j + 1].name))
			{
				MailMember mail_mem_tmp = mail_list->MailList[j];
				mail_list->MailList[j] = mail_list->MailList[j + 1];
				mail_list->MailList[j + 1] = mail_mem_tmp;
			}
		}
	}
}

void SortMember(MailList* mail_list)//����
{
	ListBubbleSort(mail_list);
}



int Menu()
{
	printf("���������:\n");
	printf(" 0:���\n 1:ɾ��\n 2:����\n 3:�޸�\n 4:��ʾ������\n 5:���\n 6:����������\n 7:������ϵ�˵��ļ�\n 8:����\n 9:�Ƴ�\n");
	int choice;
	scanf("%d",&choice);
	return choice;
}