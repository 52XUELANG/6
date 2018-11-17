#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void * MyMemmove(void * str1, const void * str2, int size)
{
	assert(str1);
	assert(str2);
	if (str1 <= str2 )
	{
		while (size--)
		{
			*(char*)str1 = *(char*)str2;
			str1 = (char*)str1 + 1;
			str2 = (char*)str2 + 1;
		}
	}
	else
	{
		str1 = (char*)str1 + size - 1;
		str2 = (char*)str2 + size - 1;
		while (size--)
		{
			*(char*)str1 = *(char*)str2;
			str1 = (char*)str1 - 1;
			str2 = (char*)str2 -1;
		}
	}
}

int main()
{
	char str[] = "memmove can be very useful";
	MyMemmove(str + 6, str + 2, 3);
	puts(str);
	system("pause");
	return 0;
}

//void* MyMemcpy(void * arr2, const void * arr1, int size)
//{
//	assert(arr1);
//	assert(arr2);
//	char* ret = (char*)arr2;
//	while (size--)
//	{
//		*(char*)arr2 = *(char*)arr1;
//		arr1 = (char*)arr1 + 1;
//		arr2 = (char*)arr2 + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "qwer";
//	int size = strlen(arr1);
//	char *arr2 = (char*)malloc((size+1)*sizeof(char));
//	arr2 = MyMemcpy(arr2,arr1,sizeof(arr1)/sizeof(arr1[0]));
//	printf("%s",arr2);
//	free(arr2);
//	system("pause");
//	return 0;
//}


//void* MyMemcpy(void * arr2, const void * arr1, int size)
//{
//	assert(arr1);
//	assert(arr2);
//	char* ret = (char*)arr2;
//	while (size--)
//	{
//		*(char*)arr2 = *(char*)arr1;
//		arr1 = (char*)arr1 + 1;
//		arr2 = (char*)arr2 + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "qwer";
//	int size = strlen(arr1);
//	char *arr2 = (char*)malloc((size+1)*sizeof(char));
//	arr2 = MyMemcpy(arr2,arr1,sizeof(arr1)/sizeof(arr1[0]));
//	printf("%s",arr2);
//	free(arr2);
//	system("pause");
//	return 0;
//}


//int MyStrcmp(const char * arr1, const char* arr2)
//{
//	assert(arr1);
//	assert(arr2);
//	while (*arr1||*arr2)
//	{
//		if ((*arr1 - *arr2) == 0)
//		{
//			arr1++;
//			arr2++;
//		}
//		else if ((*arr1 - *arr2) > 0)
//		{
//			return 1;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "\0";
//	char arr2[] = "\0";
//	printf("%d\n", MyStrcmp(arr1, arr2));
//	system("pause");
//	return 0;
//}

//char* MyStrchr(const char* str1,const char c )
//{
//	assert(str1);
//	char* temp1 = (char*)str1;
//	if (c == '\0')
//	{
//		return NULL;
//	}
//	while (*temp1++)
//	{
//		if (*temp1 == c)
//		{
//			return temp1;
//		}
//	}
//	return NULL;
//}
//
//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch = MyStrchr(str,'s');
//	printf("%s",pch);
//	system("pause");
//	return 0;
//}

//char* MyStrstr(const char* str1,const char* str2 )
//{
//	assert(str1);
//	assert(str2);
//	char* temp1 = (char*)str1;
//	char* temp2 = (char*)str2;
//	if (*str2 == '\0')
//	{
//		return NULL;
//	}
//
//	char* pch = temp1;
//
//	while (*pch)
//	{
//		temp1 = pch;
//		temp2 = (char*)str2;
//		while (*temp1 && *temp2 && (*temp1 == *temp2))
//		{
//			temp1++;
//			temp2++;
//		}
//		if (*temp2 == '\0')
//		{
//			return pch;
//		}
//		pch++;
//	}
//}
//
//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch = MyStrstr(str,"simple");
//	printf("%s",pch);
//	system("pause");
//	return 0;
//}


//char* MyStrcat(char* arr2, const char* arr1)
//{
//	assert(arr1);
//	assert(arr2);
//	char* ret = arr2;
//	while (*ret)
//	{
//		ret++;
//	}
//	while (*ret++ = *arr1++)
//	{
//		;
//	}
//		return ret;
//}
//int main()
//{
//	char arr1[] = "qwer";
//	char arr2[80] = "asdf";
//	int size = strlen(arr1);
//	arr2[10] = MyStrcat(arr2,arr1);
//	printf("%s",arr2);
//	system("pause");
//	return 0;
//}


//char* MyStrcpy(char * arr2, const char* arr1)
//{
//	assert(arr1);
//	assert(arr2);
//	char* ret = arr2;
//	while (*arr2++ = *arr1++)
//	{
//
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "qwer";
//	int size = strlen(arr1);
//	char *arr2 = (char*)malloc((size+1)*sizeof(char));
//	arr2 = MyStrcpy(arr2,arr1);
//	printf("%s",arr2);
//	free(arr2);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int money = 20;
//	int total = money;
//	int empty = 20;
//	while (empty>=2)
//	{
//		total = total + empty/2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d",total);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int num1 = 0, num2 = 0;
//	int sum = arr[0];
//	for (int i = 1; i < size; i++)
//	{
//		sum ^= arr[i];
//	}
//	int sum0 = sum;
//	int count = 0;
//	while (!(sum&1))
//	{
//		sum >>= 1;
//		count++;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		int temp = arr[i]>>count;
//		if ((temp & 1) == 0)
//		{
//			int x = 0;
//			if (x == 0)
//			{
//				num1 = arr[i];
//			}
//			else
//			{
//				num1 ^= arr[i];
//			}
//			x++;
//		}
//	}
//	num2 = sum0^num1;
//	printf("%d %d",num1,num2);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,0};
//	int count = 0;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < size ; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (i!=j && (arr[i] ^ arr[j]) == 0)
//			{
//				break;
//			}
//			if (j == size-1)
//			{
//				printf("%d ",arr[i]);
//				count++;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//int reverse_bit(int value)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		count = (count << 1) + (value & 1);
//		value = value >> 1;
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	printf("%u", reverse_bit(num));
//	system("pause");
//	return 0;
//}



//1
//11
//121
//1331
//14641
//int main()
//{
//	int n = 0;
//	int arr[20][20] = { 0 };
//	printf("输入小于20的数");
//	scanf("%d",&n);
//	for (int i = 0; i <= n; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//				printf("%d ",arr[i][j]);
//			}
//			else if (i == j)
//			{
//				arr[i][j] = 1;
//				printf("%d ",arr[i][j]);
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//				printf("%d ", arr[i][j]);
//			}
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for ( a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <=5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b==2)^(a==3))&&((b==2)^(e==4))&&((c==1)^(d==2))&&((c==5)^(d==3))&&((e==4)^(a==1)))
//						{
//							printf("%d %d %d %d %d\n",a,b,c,d,e);
//						}
//					}
//				}
//			}
//		}
//
//	}
//	system("pause");
//	return 0;
//}


//int main()//犯人
//{
//	int k = 0;
//	for (k = 'a'; k <= 'd'; k++)
//	{
//		if ((k != 'a') + (k == 'c') + (k == 'd') + (k != 'd') == 3)
//			printf("%c\n",k);
//	}
//	system("pause");
//	return 0;
//}



//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//
//	systrm("pause");
//	return 0;
//}


//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	for (int i = 31; i >=0; i--)
//	{
//		printf("%d",(num>>i)&1);
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	scanf("%d",&i);
//	int num = 0;
//	num = i;
//	printf("奇数位：");
//	for (int j = 31; j >0; j=j-2)
//	{
//		printf("%d",(i>>j)&1);
//	}
//	printf("\n");
//	i = num;
//	printf("偶数位：");
//	for (int j = 30; j >=0; j = j - 2)
//	{
//		printf("%d", (i >> j) & 1);
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int count = 0;
//	scanf("%d%d", &num1, &num2);
//	int dif = num1^num2;
//	while (dif)
//	{
//		dif = dif&(dif - 1);
//		count++;
//	}
//	printf("%d",count);
//	system("pause");
//	return 0;
//}


//int count_one_bits(int num)
//{
//	int count = 0;
//	while (num)
//	{
//		num = num&(num - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	printf("%d\n", count_one_bits(num));
//	system("pause");
//	return 0;
//}