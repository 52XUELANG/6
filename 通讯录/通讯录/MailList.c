#define _CRT_SECURE_NO_WARNINGS
#include"MailList.h"

void AddMember(pMailList* mail_list)
{
	assert(mail_list);
	*mail_list = (pMailList)malloc(sizeof(MailList));
	printf("姓名:");
	gets((*mail_list)->name);
	printf("\n");
	fflush(stdin);

	printf("性别:");
	gets((*mail_list)->sex);
	printf("\n");
	fflush(stdin);

	printf("年龄:");
	scanf("%d", &((*mail_list)->age));
	printf("\n");
	fflush(stdin);

	printf("电话:");
	gets((*mail_list)->tel);
	printf("\n");
	fflush(stdin);

	printf("住址:");
	gets((*mail_list)->address);
	printf("\n");
	fflush(stdin);

	printf("\n");
}
void DeleteMember(pMailList* mail_list)
{
	assert(mail_list);
	pMailList p_mail_list = *mail_list;
	printf("输入要删除的姓名:");
	char del_name[20];
	scanf("%s",del_name);
	while (1)
	{
		if (!strcmp(del_name, p_mail_list->name))
		{
			printf("姓名:%s\n", p_mail_list->name);
			printf("确认删除？\n Y or N");
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
				printf("正确输入！\n");
				continue;
			}
		}
		p_mail_list++;
	}
	
}
void FindMember(pMailList* mail_list)
{
	assert(mail_list);
	printf("输入要查找的姓名:");
	char find_name[20];
	gets(find_name);
	if (!strcmp(find_name, (*mail_list)->name))
	{
		printf("姓名:%s\n", (*mail_list)->name);
		printf("年龄:%d\n",(*mail_list)->age);
		printf("性别:%s\n", (*mail_list)->sex);
		printf("电话:%s\n", (*mail_list)->tel);
		printf("住址:%s\n", (*mail_list)->address);
		printf("\n\n");
	}
	else
	{
		printf("查无此人！\n\n");
	}
}
void ChangeMember();
void ShowAllMember();
void EmptyMember();
void SortMember();
int Menu()
{
	printf("请输入操作:\n");
	printf(" 0:添加\n 1:删除\n 2:查找\n 3:修改\n 4:显示所有人\n 5:清空\n 6:排序现有人\n 7:保存联系人到文件\n 8:加载\n 9:推出\n");
	int choice;
	scanf("%d",&choice);
	return choice;
}