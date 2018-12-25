#define _CRT_SECURE_NO_WARNINGS
#ifndef __DATA_H__
#define __DATA_H__

#include<iostream>
using namespace std;
#include<assert.h>

class Data
{

public:
	Data(int year = 1970, int month = 1, int day = 1)//���캯��
		:_year(year)
		, _month(month)
		, _day(day)//��ʼ���б�
	{
		if (_month<1
			|| _month>12
			|| day<1
			|| day>GetMonthDay(year, month))
		{
			assert(false);
		}
	}
	~Data()//��������
	{
		_year = 1970;
		_month = 1;
		_day = 1;
	}
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	};

	bool operator ==(const Data& d)
	{
		return _year == d._year && _month == d._month &&_day == d._day;
	}//�ж����
	bool operator !=(const Data& d)
	{
		return !(*this == d);
	}//�жϲ���
	bool operator >=(const Data& d)
	{
		return !(*this < d);
	}
	bool operator <=(const Data& d)
	{
		return *this<d || *this == d;
	}
	bool operator >(const Data& d)
	{
		return !(*this <= d);
	}
	bool operator <(const Data& d)
	{
		if ((_year < d._year) || (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}//�ж����ڴ�С

	Data& operator =(const Data& d)//��ֵ���������
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Data operator +(int day)
	{
		if (day<0)
		{
			return *this - (-day);
		}
		Data ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}
	Data operator -(int day)
	{
		if (day < 0)
		{
			return *this + (-day);
		}
		Data ret(*this);
		ret._day -= day;
		while (ret._day <= 0)
		{
			ret._month--;
			if (ret, _month == 0)
			{
				ret._year--;
				ret._month = 12;
			}
			ret._day += GetMonthDay(ret._year, ret._month);
		}
		return ret;
	}
	Data& operator +=(int day)
	{
		*this = *this + day;
		return *this;
	}
	Data& operator -=(int day)
	{
		*this = *this - day;
		return *this;
	}
	Data& operator ++()//ǰ��++,����������֮��*this�����ڣ�����������
	{
		*this += 1;
		return *this;
	}
	Data operator ++(int)//����++,������������Ч����û��̫��ʵ������
	{
		Data tmp(*this);
		*this += 1;
		return tmp;
	}//����������֮��tmp�����ڣ�����ʹ������


	Data& operator --()//ǰ��--
	{
		*this -= 1;
		return *this;
	}
	Data operator --(int)//����--
	{
		Data tmp(*this);
		*this -= 1;
		return tmp;
	}
	int operator -(const Data& d)//����-����
	{
		int flag = 1;
		int day = 0;
		Data max = *this;
		Data min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (min<max)
		{
			++min;
			++day;
		}
		return day*flag;

	}

	void Show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	bool IsLeapYear(int year)//�����ж�
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetMonthDay(int year, int month)//������
	{
		assert(month > 0 && month < 13);
		int month_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			return month_days[month] + 1;
		}
		else
		{
			return month_days[month];
		}
	}
};

#endif