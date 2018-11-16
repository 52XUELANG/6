#define _CRT_SECURE_NO_WARNINGS
#include"hash.h"
#include"common.h"

#if 0
void HashTableInit(pHashTable ht,int IsLineDetective)//��ʼ��
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		ht->_array[i]._state = EMPTY;
	}
	ht->_size = 0;
	ht->_total = 0;
	ht->_IsLineDetective = IsLineDetective;//�ж��Ƿ�Ϊ����̽��
}
void HashTableInsert(pHashTable ht, DataType data)//����
{
	assert(ht);
	//��ϣ�����������ַ
	int i = 0;
	int HashIp = HashFunc(data);
	while (EMPTY != ht->_array[HashIp]._state)//����λ�ò�Ϊ��(��ʾ״̬Ϊ���ڻ���ɾ��)
	{
		if (EXIST == ht->_array[HashIp]._state)//����ֵ��״̬Ϊ����
		{
			if (data == ht->_array[HashIp]._data)//�Ƿ���ͬ
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

	//����Ԫ��
	ht->_array[HashIp]._data = data;
	ht->_array[HashIp]._state = EXIST;
	ht->_size++;
	ht->_total++;
	if (MAX_SIZE == ht->_total)
	{
		return;
	}
}
void HashTableDelete(pHashTable ht,DataType data)//ɾ��
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
int HashTableFind(pHashTable ht, DataType data)//����
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
			if (startip == haship)//����һȦ
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
int HashTableSize(pHashTable ht)//��С
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(pHashTable ht)//�п�
{
	assert(ht);
	return 0 == ht->_total;
}
int HashFunc(DataType data)//��ϣ����:
{
	return data % MAX_SIZE;
}
int Detective(int HashIp)//����̽��
{
	HashIp++;
	HashIp %= MAX_SIZE;//Խ��Ԥ��
	return HashIp;
}
int Detective2(int HashIp,int i)//����̽��
{
	HashIp = HashIp + 2 * i + 1;
	HashIp %= MAX_SIZE;//Խ��Ԥ��
	return HashIp;
}
#endif//��̬��ϣ��


void HashTableInit(pHashTable ht, int capacity, int IsLineDetective)//��ʼ��
{
	capacity = GetNextPrime(capacity);//��ȡ��ԭ�����������������
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
	ht->_IsLineDetective = IsLineDetective;//�ж��Ƿ�Ϊ����̽��
}
void HashTableInsert(pHashTable ht, DataType data)//����
{
	assert(ht);
	if (!CheckCapacity(ht))
	{
		return;
	}
	//��ϣ�����������ַ
	int i = 0;
	int HashIp = HashFunc(data);
	while (EMPTY != ht->_array[HashIp]._state)//����λ�ò�Ϊ��(��ʾ״̬Ϊ���ڻ���ɾ��)
	{
		if (EXIST == ht->_array[HashIp]._state)//����ֵ��״̬Ϊ����
		{
			if (data == ht->_array[HashIp]._data)//�Ƿ���ͬ
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

	//����Ԫ��
	ht->_array[HashIp]._data = data;
	ht->_array[HashIp]._state = EXIST;
	ht->_size++;
	
}
void HashTableDelete(pHashTable ht, DataType data)//ɾ��
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
int HashTableFind(pHashTable ht, DataType data)//����
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
			if (startip == haship)//����һȦ
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
int HashTableSize(pHashTable ht)//��С
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(pHashTable ht)//�п�
{
	assert(ht);
	return 0 == ht->_size;
}
int HashFunc(DataType data)//��ϣ����:
{
	//return data % MAX_SIZE;
	return StrToInt(data) % MAX_SIZE;
}
int Detective(int HashIp, pHashTable ht)//����̽��
{
	HashIp++;
	HashIp %= ((ht)->_capacity);//Խ��Ԥ��
	return HashIp;
}
int Detective2(int HashIp, int i)//����̽��
{
	HashIp = HashIp + 2 * i + 1;
	HashIp %= MAX_SIZE;//Խ��Ԥ��
	return HashIp;
}
int CheckCapacity(pHashTable ht)//����
{
	assert(ht);
	//���ռ�
	HashTable newHt;
	if (ht->_size * 10 / ht->_capacity >= 7)
	{
		HashTableInit(&newHt, GetNextPrime(ht->_capacity), ht->_IsLineDetective);


		//����Ԫ��
		for (int i = 0; i <= ht->_size; i++)
		{
			if (EXIST == ht->_array[i]._state)
				HashTableInsert(&newHt, ht->_array[i]._data);
		}
		HashTableSwap(ht, &newHt);//������ϣ�������(�������ö���ָ��newHt��ָ����ht���н�����
		//����ִ�����ݽ��н�����newHt����ջ�ϵĿռ䣬����ú����Զ����٣�����ú������޷��ҵ�)
		HashTableDestroy(&newHt);
	}


	return 1;
}

void HashTableDestroy(pHashTable newHt)//����
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

void HashTableSwap(pHashTable ht, pHashTable newHt)//����
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
