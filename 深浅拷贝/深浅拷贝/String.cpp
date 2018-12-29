#define _CRT_SECURE_NO_WARNINGS
#include"String.h"
void MyString::Swap(MyString& s)
{
	swap(this->_str, s._str);
	swap(this->_size, s._size);
	swap(this->_capacity, s._capacity);
}

void MyString::PushBack(char ch)
{
	if (_size>= _capacity)
	{
		Expand(_capacity * 2);
	}
	_str[_size++] = ch;
	_str[_size] = '\0';
}
void MyString::PushBack(const char* ch)
{
	size_t size = strlen(ch);
	if (_size + size > _capacity)
	{
		Expand(_size + size);
	}
	char* pos = _str + _size;//µ½_strµÄ\0´¦
	while (*pos++ = *ch++);
	//strcpy(_str + _size, ch);
	_size += size;
}

void MyString::Expand(size_t n)//À©ÈÝ
{
	if (n > _capacity)
	{
		char* new_str = new char[n + 1];
		strcpy(new_str, _str);
		delete[] _str;
		_str = new_str;
		_capacity = n;
	}
}

MyString& MyString::operator=(const MyString& s)

{
	if (this != &s)
	{
		MyString tmp(s._str);
		this->Swap(tmp);
	}
	return *this;
}
MyString& MyString::operator+(char ch)
{
	MyString tmp(*this);
	tmp.PushBack(ch);
	return tmp;
}
MyString& MyString::operator+=(char ch)
{
	PushBack(ch);
	return *this;
}
MyString& MyString::operator+(const char* ch)
{
	MyString tmp(*this);
	tmp.PushBack(ch);
	return tmp;
}
MyString& MyString::operator+=(const char* ch)
{
	PushBack(ch);
	return *this;
}
void MyString::PushFront(char ch)
{
	if (_size >= _capacity)
	{
		Expand(_capacity * 2);
	}
	for (int i = _size; i >= 0; i--)
	{
		_str[i+1] = _str[i];
	}
	_str[0] = ch;
	_size++;
}
void MyString::PushFront(const char* str)//Í·²å
{
	size_t size = strlen(str);
	if (_size + size > _capacity)
	{
		Expand(_size + size);
	}
	for (int i = _size; i >= 0; i--)
	{
		_str[i + size] = _str[i];
	}
	//char *p = _str;
	//while (*str != '\0')
	//{
	//	*p++ = *str++;
	//}
	memmove(_str, str,size);
	_size += size;
}

void MyString::PopBack(size_t size)//Î²É¾
{
	if (_size < size)
	{
		cout << "³¬³ö¿ÉÉ¾³ý·¶Î§" << endl;
		return;
	}
	_size -= size;
	_str[_size] = '\0';
}

void MyString::PopFront(size_t size)//Í·É¾
{
	if (_size < size)
	{
		cout << "³¬³ö¿ÉÉ¾³ý·¶Î§" << endl;
		return;
	}
	_size -= size;
	char* p = _str + size;
	char* q = _str;
	while (*q++ = *p++);
}
void MyString::Insert(size_t pos, char ch)
{

}

void MyString::Insert(size_t pos, const char* str)
{

}
void MyString::Erase(size_t pos,size_t n = 1)
{

}
//bool MyString::operator>(const MyString& s)
//{
//
//}
//bool MyString::operator>=(const MyString& s)
//{
//
//}bool MyString::operator<(const MyString& s)
//{
//
//}bool MyString::operator<=(const MyString& s)
//{
//
//}bool MyString::operator==(const MyString& s)
//{
//
//}bool MyString::operator!=(const MyString& s)
//{
//
//}