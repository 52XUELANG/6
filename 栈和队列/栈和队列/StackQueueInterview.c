#define _CRT_SECURE_NO_WARNINGS
#include"StackQueueInterview.h"
#if 0
void MStackInit(MinStack* s)//³õÊ¼»¯
{
	assert(s);
	StackInit(&(s->_s));
}
void MStackPush(MinStack* s, MSDataTtpe data)//Ñ¹Õ»
{
	SElem elem;
	elem._data = elem._min_data = data;
	if (!StackEmpty(&(s->_s)))
	{
		MSDataTtpe min_data = MStakeMinData(s);
		if (min_data < data)
			elem._min_data = min_data;
	}
	PushBack(&(s->_s), elem);
}
int MSEmpty(MinStack* s)
{
	assert(s);
	return StackEmpty(&(s->_s));
}
void MStackPop(MinStack* s)//³öÕ»
{
	assert(s);
	assert(!MSEmpty(s));
	PopBack(&(s->_s));
}
MSDataTtpe MStackTop(MinStack* s)
{
	return  TakeOut(&(s->_s));
}
MSDataTtpe MStakeMinData(MinStack* s)
{
	return TakeOut(&(s->_s));
}
#endif

void QueueBy2StackInit(QueueBy2Stack* q)
{
	assert(q);
	StackInit(&q->_s1);
	StackInit(&q->_s2);
}
void QueueBy2StackPush(QueueBy2Stack* q, QDataType data)
{
	assert(q);
	PushBack(&q->_s1,data);
}
void QueueBy2StackPop(QueueBy2Stack* q)
{
	if (QueueBy2StackEmpty(q))
		return;
	if (StackEmpty(q->_s2))
	{
		while (!StackEmpty(q->_s1))
		{
			PushBack(&q->_s2,TakeOut(&q->_s1));
			PopBack(&q->_s1);
		}
	}
	PopBack(&q->_s2);
}
QDataType QueueBy2StackFront(QueueBy2Stack* q)
{
	if (StackEmpty(q->_s2))
	{
		while (!StackEmpty(q->_s1))
		{
			PushBack(&q->_s2, TakeOut(&q->_s1));
			PopBack(&q->_s1);
		}
	}
	return TakeOut(&q->_s2);
}
QDataType QueueBy2StackBack(QueueBy2Stack* q)
{
	if (StackEmpty(q->_s1))
	{
		while (!StackEmpty(q->_s2))
		{
			PushBack(&q->_s1, TakeOut(&q->_s2));
			PopBack(&q->_s2);
		}
	}
	return TakeOut(&q->_s1);
}
int QueueBy2StackEmpty(QueueBy2Stack* q)
{
	return StackEmpty(q->_s1) && StackEmpty(q->_s2);
}