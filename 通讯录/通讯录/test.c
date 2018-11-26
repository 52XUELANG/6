#define _CRT_SECURE_NO_WARNINGS
#include"MailList.h"
int main()
{
	MailList* mail_list[1000];
	pMailList* p_mail_list = mail_list;
	while (1)
	{
		int choice = Menu();
		fflush(stdin);
		switch (choice)
		{
		case 0:
			AddMember(p_mail_list);
			break;
		case 1:
			DeleteMember(mail_list);
			break;
		case 2:
			FindMember(mail_list);
			break;
			//case 3:
			//	ChangeMember();
			//	break;
			//case 4:
			//	ShowAllMember();
			//	break;
			//case 5:
			//	EmptyMember();
			//	break;
			//case 6:
			//	SortMember();
			//	break;
		case 9:
			break;
		default:
			break;
		}
		if (9 == choice)
		{
			break;
		}
		p_mail_list++;
	}
	system("pause");
	return 0;
}