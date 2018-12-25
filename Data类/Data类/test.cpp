#define _CRT_SECURE_NO_WARNINGS
#include"Data.h"
int main()
{
	Data d1(2018, 3, 28);
	Data d2(2018, 3, 29);

	cout << d1 - d2 << endl;
	system("pause");
	return 0;
}