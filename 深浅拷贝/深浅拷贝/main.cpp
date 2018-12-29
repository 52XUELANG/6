#define _CRT_SECURE_NO_WARNINGS
#include"String.h"
//#include<string>

int main()
{
	//string s("66");
	//cout << s << endl;
	//s += "77";
	//cout << s.c_str() << endl;
	//MyString s1("changed world");
	//MyString s2(s1);
	//cout << s2.c_str() << endl;
	//MyString s3 = s2;
	//cout << s3.c_str() << endl;
	//s3 += "!";
	//cout << s3.c_str() << endl;
	//s3 += "www";
	//cout << s3.c_str() << endl;
	//s3 += s2.c_str();
	//cout << s3.c_str() << endl;
	MyString s1("666");
	s1.PushFront("777");
	cout << s1.c_str() << endl;
	//s1.PopBack(6);
	//cout << s1.c_str() << endl;
	s1.PopFront(3);
	cout << s1.c_str() << endl;
	system("pause");
	return 0;
}