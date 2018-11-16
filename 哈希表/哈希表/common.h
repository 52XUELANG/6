#define _CRT_SECURE_NO_WARNINGS

#ifndef __COMMON_H__
#define __COMMON_H__
#include<stdio.h>
#include<stdlib.h>

#define  PRIME_SIZE 8

size_t UnStrToInt(int data);//元素默认是整型数据，直接返回
size_t StrToInt(const char* str);//实现字符假转整型，利于存储
size_t GetNextPrime(int capacity);//获取比给定容量较大的相近的素数容量
size_t StrToInt1(const char* str);
size_t StrToInt2(const char* str);
size_t StrToInt3(const char* str);
size_t StrToInt4(const char* str);
size_t StrToInt5(const char* str);//5种哈希函数，可以百度



#endif