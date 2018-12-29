#define _CRT_SECURE_NO_WARNINGS

//浅拷贝:进行简单的值拷贝，对于简单数据可以，但是如果是对于指针一类的数据，进行
//浅拷贝，会导致共享一份空间，当一个对象对共享空间进行销毁，会导致访问违规
//深拷贝:单独开出一份空间，拷贝空间内容，杜绝空间共享
//现代写法--复用
#ifndef __STRING_H__
#define __STRING_H__
#include<assert.h>
#include<iostream>
using namespace std;

class MyString//字符串的增删查改
{
public:
	//MyString()//构造
	//	:_str(new char[1])
	//{
	//	_str[0] = '\0';
	//}
	MyString(const char* str = "")//带值得构造
		:_str(new char[strlen(str)+1])
	{
		_size = _capacity = strlen(str);
		strcpy(_str, str);
	}

	//s1 = s2
	//MyString& operator = (const MyString& s)
	//{
	//	if (this != &s)//防止s1 = s1
	//	{
	//		char *pStr = new char[strlen(s._str) + 1];
	//		strcpy(pStr, s._str);
	//		delete[] this->_str;//举例:释放s1的原本指向空间，重新分配一个可指向空间
	//		_str = pStr;
	//	}
	//	return *this;
	//}
	MyString& operator = (const MyString& s);

	//MyString(const MyString& s)//拷贝构造:深拷贝,传统写法
	//	:_str(new char[strlen(s._str)+1])
	//{
	//	strcpy(_str, s._str);
	//}

	MyString(const MyString& s)//拷贝构造:利用构造函数完成拷贝构造，现代写法
		:_str(NULL)
		, _size(0)
		, _capacity(0)
	{
		MyString str_tmp(s._str);
		this->Swap(str_tmp);
	}

	~MyString()//析构函数
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
			_size = _capacity = 0;
		}
	}

	const char* c_str()
	{
		return _str;
	}
	void PushBack(char ch);
	void PushBack(const char* ch);
	void Swap(MyString& s);
	MyString& operator+(char ch);
	MyString& operator+=(char ch);
	MyString& operator+(const char* ch);
	MyString& operator+=(const char* ch);
	void PushFront(char ch);
	void PushFront(const char* str);
	void PopBack(size_t size);
	void PopFront(size_t size);

	bool operator>(const MyString& s);
	bool operator>=(const MyString& s);
	bool operator<(const MyString& s);
	bool operator<=(const MyString& s);
	bool operator==(const MyString& s);
	bool operator!=(const MyString& s);
	void Insert(size_t pos, char ch);//增加字符
	void Insert(size_t pos, const char* str);
	void Erase(size_t pos, size_t n = 1);
	void Replace(const char* str1, const char* str2);
	size_t Find(char ch);
	size_t Find(const char* str);
private:
	void Expand(size_t n);

private:
	char* _str;
	size_t _size;
	size_t _capacity;

};

#endif