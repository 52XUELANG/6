#define _CRT_SECURE_NO_WARNINGS
#include"MailList.h"


void ListInit(MailList* mail_list)//初始化
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
	printf("姓名:");
	gets(mail_list->MailList[mail_list->size].name);
	printf("\n");
	fflush(stdin);

	printf("性别:");
	gets(mail_list->MailList[mail_list->size].sex);
	printf("\n");
	fflush(stdin);

	printf("年龄:");
	scanf("%d", &mail_list->MailList[mail_list->size].age);
	printf("\n");
	fflush(stdin);

	printf("电话:");
	gets(mail_list->MailList[mail_list->size].tel);
	printf("\n");
	fflush(stdin);

	printf("住址:");
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
	printf("输入要删除的姓名:");
	char del_name[20];
	scanf("%s",del_name);
	int i = 0;
	while (i<mail_list->size)
	{
		if (!strcmp(del_name, mail_list_tmp->MailList[i].name))
		{
			printf("姓名:%s\n", mail_list_tmp->MailList[i].name);
			printf("确认删除？\n Y or N");
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
				printf("正确输入！\n");
				continue;
			}
		}
		i++;
	}
	printf("对不起，查无此人");
	return;
}
void FindMember(MailList mail_list)
{
	if (mail_list.size == 0)
	{
		printf("没有存储用户");
		return;
	}
	else
	{
		int i = 0;
		printf("输入要查找的姓名:");
		char find_name[20];
		gets(find_name);
		while (i < mail_list.size)
		{
			if (!strcmp(find_name, mail_list.MailList[i].name))
			{
				printf("姓名:%s\n", mail_list.MailList[i].name);
				printf("年龄:%d\n", mail_list.MailList[i].age);
				printf("性别:%s\n", mail_list.MailList[i].tel);
				printf("电话:%s\n", mail_list.MailList[i].tel);
				printf("住址:%s\n", mail_list.MailList[i].address);
				printf("\n\n");
				return;
			}
			else
			{
				i++;
			}
			printf("查无此人");
			return;
		}
	}
}
void ChangeMember(MailList* mail_list)//修改
{
	assert(mail_list);
	printf("输入要修改的人的姓名: ");
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
	printf("姓名:");
	gets(mail_list->MailList[mail_list->size].name);
	printf("\n");
	fflush(stdin);

	printf("性别:");
	gets(mail_list->MailList[mail_list->size].sex);
	printf("\n");
	fflush(stdin);

	printf("年龄:");
	scanf("%d", &mail_list->MailList[mail_list->size].age);
	printf("\n");
	fflush(stdin);

	printf("电话:");
	gets(mail_list->MailList[mail_list->size].tel);
	printf("\n");
	fflush(stdin);

	printf("住址:");
	gets(mail_list->MailList[mail_list->size].address);
	printf("\n");
	fflush(stdin);

}
void ShowAllMember(MailList mail_list)//显示所有
{
	if (mail_list.size = 0)
	{
		printf("没有存储用户");
	}
	else
	{
		int i = 0;
		while (i<mail_list.size)
		{
			printf("姓名:%s\n", mail_list.MailList[i].name);
			printf("年龄:%d\n", mail_list.MailList[i].age);
			printf("性别:%s\n", mail_list.MailList[i].sex);
			printf("电话:%s\n", mail_list.MailList[i].tel);
			printf("住址:%s\n", mail_list.MailList[i].address);
			i++;
		}
	}
}
void EmptyMember(MailList* mail_list)//清空
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

void SortMember(MailList* mail_list)//排列
{
	ListBubbleSort(mail_list);
}



int Menu()
{
	printf("请输入操作:\n");
	printf(" 0:添加\n 1:删除\n 2:查找\n 3:修改\n 4:显示所有人\n 5:清空\n 6:排序现有人\n 7:保存联系人到文件\n 8:加载\n 9:推出\n");
	int choice;
	scanf("%d",&choice);
	return choice;
}