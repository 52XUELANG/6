#define _CRT_SECURE_NO_WARNINGS

//ǳ����:���м򵥵�ֵ���������ڼ����ݿ��ԣ���������Ƕ���ָ��һ������ݣ�����
//ǳ�������ᵼ�¹���һ�ݿռ䣬��һ������Թ���ռ�������٣��ᵼ�·���Υ��
//���:��������һ�ݿռ䣬�����ռ����ݣ��ž��ռ乲��
//�ִ�д��--����
#ifndef __STRING_H__
#define __STRING_H__
#include<assert.h>
#include<iostream>
using namespace std;

class MyString//�ַ�������ɾ���
{
public:
	//MyString()//����
	//	:_str(new char[1])
	//{
	//	_str[0] = '\0';
	//}
	MyString(const char* str = "")//��ֵ�ù���
		:_str(new char[strlen(str)+1])
	{
		_size = _capacity = strlen(str);
		strcpy(_str, str);
	}

	//s1 = s2
	//MyString& operator = (const MyString& s)
	//{
	//	if (this != &s)//��ֹs1 = s1
	//	{
	//		char *pStr = new char[strlen(s._str) + 1];
	//		strcpy(pStr, s._str);
	//		delete[] this->_str;//����:�ͷ�s1��ԭ��ָ��ռ䣬���·���һ����ָ��ռ�
	//		_str = pStr;
	//	}
	//	return *this;
	//}
	MyString& operator = (const MyString& s);

	//MyString(const MyString& s)//��������:���,��ͳд��
	//	:_str(new char[strlen(s._str)+1])
	//{
	//	strcpy(_str, s._str);
	//}

	MyString(const MyString& s)//��������:���ù��캯����ɿ������죬�ִ�д��
		:_str(NULL)
		, _size(0)
		, _capacity(0)
	{
		MyString str_tmp(s._str);
		this->Swap(str_tmp);
	}

	~MyString()//��������
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
	void Insert(size_t pos, char ch);//�����ַ�
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