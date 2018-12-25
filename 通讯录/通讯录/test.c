#define _CRT_SECURE_NO_WARNINGS
#include"MailList.h"
int main()
{
	MailList mail_list;
	ListInit(&mail_list);
	while (1)
	{
		int choice = Menu();
		fflush(stdin);
		switch (choice)
		{
		case 0:
			AddMember(&mail_list);
			break;
		case 1:
			DeleteMember(&mail_list);
			break;
		case 2:
			FindMember(mail_list);
			break;
		case 3:
			ChangeMember(&mail_list);
			break;
		case 4:
			ShowAllMember(mail_list);
			break;
		case 5:
			EmptyMember(&mail_list);
			break;
		case 6:
			SortMember(&mail_list);
				break;
		case 9:
			break;
		default:
			break;
		}
		if (9 == choice)
		{
			break;
		}
	}
	system("pause");
	return 0;
}