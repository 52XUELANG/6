#define _CRT_SECURE_NO_WARNINGS

#ifndef __COMMON_H__
#define __COMMON_H__
#include<stdio.h>
#include<stdlib.h>

#define  PRIME_SIZE 8

size_t UnStrToInt(int data);//Ԫ��Ĭ�����������ݣ�ֱ�ӷ���
size_t StrToInt(const char* str);//ʵ���ַ���ת���ͣ����ڴ洢
size_t GetNextPrime(int capacity);//��ȡ�ȸ��������ϴ���������������
size_t StrToInt1(const char* str);
size_t StrToInt2(const char* str);
size_t StrToInt3(const char* str);
size_t StrToInt4(const char* str);
size_t StrToInt5(const char* str);//5�ֹ�ϣ���������԰ٶ�



#endif