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
	//char* pos = _str + _size;//µ½_strµÄ\0´¦
	//while (*pos++ = *ch++);
	strcpy(_str + _size, ch);

}

void MyString::Expand(size_t n)
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