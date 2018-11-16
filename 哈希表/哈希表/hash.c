#define _CRT_SECURE_NO_WARNINGS
#include"hash.h"
#include"common.h"

#if 0
void HashTableInit(pHashTable ht,int IsLineDetective)//初始化
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		ht->_array[i]._state = EMPTY;
	}
	ht->_size = 0;
	ht->_total = 0;
	ht->_IsLineDetective = IsLineDetective;//判断是否为线性探测
}
void HashTableInsert(pHashTable ht, DataType data)//插入
{
	assert(ht);
	//哈希函数，计算地址
	int i = 0;
	int HashIp = HashFunc(data);
	while (EMPTY != ht->_array[HashIp]._state)//插入位置不为空(表示状态为存在或者删除)
	{
		if (EXIST == ht->_array[HashIp]._state)//有数值，状态为存在
		{
			if (data == ht->_array[HashIp]._data)//是否相同
			{
				return;
			}
		}
		if (ht->_IsLineDetective)
		{
			HashIp =  Detective(HashIp);
		}
		else
		{
			HashIp = Detective2(HashIp,++i);
		}
	}

	//插入元素
	ht->_array[HashIp]._data = data;
	ht->_array[HashIp]._state = EXIST;
	ht->_size++;
	ht->_total++;
	if (MAX_SIZE == ht->_total)
	{
		return;
	}
}
void HashTableDelete(pHashTable ht,DataType data)//删除
{
	assert(ht);
	int ret = HashTableFind(ht,data);
	if (-1 == ret)
	{
		return;
	}
	else
	{
		ht->_array[ret]._state = DELETE;
		ht->_size--;
	}
}
int HashTableFind(pHashTable ht, DataType data)//查找
{
	assert(ht);
	int haship = HashFunc(data);
	int startip = haship;
	int i = 0;
	while (EMPTY != ht->_array[haship]._state)
	{
		if (EXIST == ht->_array[haship]._state)
		{
			if (data == ht->_array[haship]._data)
			{
				return haship;
			}
		}

		if (ht->_IsLineDetective)
		{
			haship = Detective(haship);
			if (startip == haship)//找完一圈
			{
				return -1;
			}
		}
		else
		{
			haship = Detective2(haship, ++i);

		}

		
	}
	return -1;


}
int HashTableSize(pHashTable ht)//大小
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(pHashTable ht)//判空
{
	assert(ht);
	return 0 == ht->_total;
}
int HashFunc(DataType data)//哈希函数:
{
	return data % MAX_SIZE;
}
int Detective(int HashIp)//线性探测
{
	HashIp++;
	HashIp %= MAX_SIZE;//越界预防
	return HashIp;
}
int Detective2(int HashIp,int i)//二次探测
{
	HashIp = HashIp + 2 * i + 1;
	HashIp %= MAX_SIZE;//越界预防
	return HashIp;
}
#endif//静态哈希表


void HashTableInit(pHashTable ht, int capacity, int IsLineDetective)//初始化
{
	capacity = GetNextPrime(capacity);//获取与原容量相近的素数容量
	ht->_array = (HashElem*)malloc(capacity*sizeof(HashElem));
	if (ht->_array == NULL)
	{
		assert(0);
		return;
	}
	for (int i = 0; i < capacity; i++)
	{
		ht->_array[i]._state = EMPTY;
	}
	ht->_size = 0;
	ht->_capacity = capacity;
	ht->_IsLineDetective = IsLineDetective;//判断是否为线性探测
}
void HashTableInsert(pHashTable ht, DataType data)//插入
{
	assert(ht);
	if (!CheckCapacity(ht))
	{
		return;
	}
	//哈希函数，计算地址
	int i = 0;
	int HashIp = HashFunc(data);
	while (EMPTY != ht->_array[HashIp]._state)//插入位置不为空(表示状态为存在或者删除)
	{
		if (EXIST == ht->_array[HashIp]._state)//有数值，状态为存在
		{
			if (data == ht->_array[HashIp]._data)//是否相同
			{
				return;
			}
		}
		if (ht->_IsLineDetective)
		{
			HashIp = Detective(HashIp, ht);
		}
		else
		{
			HashIp = Detective2(HashIp, ++i);
		}
	}

	//插入元素
	ht->_array[HashIp]._data = data;
	ht->_array[HashIp]._state = EXIST;
	ht->_size++;
	
}
void HashTableDelete(pHashTable ht, DataType data)//删除
{
	assert(ht);
	int ret = HashTableFind(ht, data);
	if (-1 == ret)
	{
		return;
	}
	else
	{
		ht->_array[ret]._state = DELETE;
		ht->_size--;
	}
}
int HashTableFind(pHashTable ht, DataType data)//查找
{
	assert(ht);
	int haship = HashFunc(data);
	int startip = haship;
	int i = 0;
	while (EMPTY != ht->_array[haship]._state)
	{
		if (EXIST == ht->_array[haship]._state)
		{
			if (data == ht->_array[haship]._data)
			{
				return haship;
			}
		}

		if (ht->_IsLineDetective)
		{
		 	haship =  Detective(haship,ht);
			if (startip == haship)//找完一圈
			{
				return -1;
			}
		}
		else
		{
			haship =  Detective2(haship, ++i);

		}


	}
	return -1;


}
int HashTableSize(pHashTable ht)//大小
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(pHashTable ht)//判空
{
	assert(ht);
	return 0 == ht->_size;
}
int HashFunc(DataType data)//哈希函数:
{
	//return data % MAX_SIZE;
	return StrToInt(data) % MAX_SIZE;
}
int Detective(int HashIp, pHashTable ht)//线性探测
{
	HashIp++;
	HashIp %= ((ht)->_capacity);//越界预防
	return HashIp;
}
int Detective2(int HashIp, int i)//二次探测
{
	HashIp = HashIp + 2 * i + 1;
	HashIp %= MAX_SIZE;//越界预防
	return HashIp;
}
int CheckCapacity(pHashTable ht)//增容
{
	assert(ht);
	//开空间
	HashTable newHt;
	if (ht->_size * 10 / ht->_capacity >= 7)
	{
		HashTableInit(&newHt, GetNextPrime(ht->_capacity), ht->_IsLineDetective);


		//拷贝元素
		for (int i = 0; i <= ht->_size; i++)
		{
			if (EXIST == ht->_array[i]._state)
				HashTableInsert(&newHt, ht->_array[i]._data);
		}
		HashTableSwap(ht, &newHt);//交换哈希表的内容(不可以用定义指向newHt的指针与ht进行交换，
		//即将执行内容进行交换，newHt属于栈上的空间，脱离该函数自动销毁，脱离该函数后无法找到)
		HashTableDestroy(&newHt);
	}


	return 1;
}

void HashTableDestroy(pHashTable newHt)//销毁
{
	assert(newHt);
	if (newHt->_array)
	{
		free(newHt->_array);
		newHt->_array = NULL;
		newHt->_capacity = 0;
		newHt->_size = 0;
	}
}

void HashTableSwap(pHashTable ht, pHashTable newHt)//交换
{
	assert(ht);
	assert(newHt);
	int temp = 0;
	temp =  ht->_capacity;
	ht->_capacity = newHt->_capacity;
	newHt->_capacity = temp;

	temp = ht->_size;
	ht->_size = newHt->_size;
	newHt->_size = temp;

	temp = ht->_IsLineDetective;
	ht->_IsLineDetective = newHt->_IsLineDetective;
	newHt->_IsLineDetective = temp;

	temp = (int)ht->_array;
	ht->_array = newHt->_array;
	newHt->_array = (HashElem*)temp;
}
