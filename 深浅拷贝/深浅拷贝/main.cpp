#define _CRT_SECURE_NO_WARNINGS
#include"String.h"

int main()
{
	MyString s1("changed world");
	MyString s2(s1);
	cout << s2.c_str() << endl;
	MyString s3 = s2;
	cout << s3.c_str() << endl;
	system("pause");
	return 0;
}