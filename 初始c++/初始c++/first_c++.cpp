//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//#include<iomanip>
//using namespace std;
//#define max 100
////using std::cout;
////using std::endl;
////void TestFunc(int a = 10,int b = 20,int c = 30)//全缺省
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////
////}
//
////void TestFunc(int a = max, int b = 20, int c = 30)//半缺省(半缺省参数必须从右向左给出,缺省参数不能在函数定义和声明同时给出)
////{
////	std::cout << "a = " << a << std::endl;
////	std::cout << "b = " << b << std::endl;
////	std::cout << "c = " << c << std::endl;
////}
//
////void TestFunc(int a = max, int b = 20, int c = 30)//半缺省(半缺省参数必须从右向左给出,缺省参数不能在函数定义和声明同时给出)
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	//double a = 22.0 / 7.0;
//	//cout <<setprecision(2)<< a << endl;
//	const int& b = Add(1,2);
//	Add(3, 4);
//	cout << b << endl;
//	//int& b = 10;//报错
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//class Stu//声明
//{
//public:
//	void Show();
//public:
//	char* _name;
//	int _age;
//	int _num;
//};
//class Teacher//声明
//{
//public:
//	void Show()
//	{
//		cout << _name << endl;
//	}
//private:
//	char* _name = "dsadas";
//	int _age;
//};
//void Stu::Show()
//{
//	cout << _age << endl;
//};
//
//int main()
//{
//	Stu stu1;//实例化
//	stu1._age = 18;
//	stu1._name = "zhangsan";
//	stu1._num = 15;
//	//stu1.Show();
//	//Teacher tea;
//	//tea.Show();
//	printf("%d\n",sizeof(stu1));
//	//tea._age = 16;//除公有之外的其他限定访问不能在类外直接访问
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
//enum Sex
//{
//	man,
//	woman
//}sex;
//class Body
//{
//private:
//	int mima = 111111;
//public:
//	int num;
//	char* name;
//	int sex;
//	char* home;
//	char* change(char* name);
//};
//char* Body::change(char* name)
//{
//	name = "dsa";
//	return name;
//}
//int main()
//{
//	Body body1;
//	body1.name = "zhangsan";
//	body1.num = 1716;
//	body1.sex = man;
//	body1.home = "dsadsada";
//	body1.name =  body1.change(body1.name);
//	//cout << body1.name << endl;
//	cout << sizeof(Body) << endl;
//	system("pause");
//	return 0;
//}

class Body
{
public:
	int s;
	int a;
};
int main()
{
	Body body1;
	body1.a = 16;
	body1.s = 16;
	cout << sizeof(Body) << endl;
	cout << sizeof(body1) << endl;
	printf("%p\n", &body1.s);
	printf("%p\n", &body1.a);

	system("pause");
	return 0;
}