#define _CRT_SECURE_NO_WARNINGS
#include"StackQueueInterview.h"
#if 0
void MStackInit(MinStack* s)//初始化
{
	assert(s);
	StackInit(&(s->_s));
}
void MStackPush(MinStack* s, MSDataTtpe data)//压栈
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
void MStackPop(MinStack* s)//出栈
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
#endif//最小值

#if 0
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
#endif//双栈实现队列

#if 0
void StackBy2QueueInit(StackBy2Queue* s)
{
	assert(s);
	QueueInit(&s->_q1);
	QueueInit(&s->_q2);
}
void StackBy2QueuePush(StackBy2Queue* s, QDataType data)
{
	QueuePush(&s->_q1, data);
}
void StackBy2QueuePop(StackBy2Queue* s)
{
	if (StackBy2QueueEmpty(s))
	{
		return;
	}
	if (QueueEmpty(&s->_q1))
	{
		while (QueueSize(&s->_q1)>1)
		{
			QueuePush(&s->_q2, QueueFront(&s->_q1));
			QueuePop(&s->_q1);
		}
		QueuePop(&s->_q1);
	}
	if (QueueEmpty(&s->_q2))
	{
		while (QueueSize(&s->_q2)>1)
		{
			QueuePush(&s->_q1, QueueFront(&s->_q2));
			QueuePop(&s->_q2);
		}
		QueuePop(&s->_q2);
	}
}

QDataType StackBy2QueueTop(StackBy2Queue* s)
{
	assert(s);
	if (!QueueEmpty(&s->_q1))
	{
		return QueueBack(&s->_q1);
	}
	else
	{
		return QueueBack(&s->_q2);
	}
}
int StackBy2QueueSize(StackBy2Queue* s)
{
	return QueueSize(&s->_q1) && QueueSize(&s->_q2);
}
int StackBy2QueueEmpty(StackBy2Queue* s)
{
	return QueueEmpty(&s->_q1) && QueueEmpty(&s->_q2);
}
#endif//双队列实现栈

#if 0
int IsValidStack(int *In, int InSize, int* Out, int OutSize)//出栈匹配
{
	if (InSize != OutSize)
	{
		return 0;
	}
	int InIdx = 0;
	int OutIdx = 0;
	pStack s;
	StackInit(&s);
	while (OutIdx<OutSize)
	{
		while (StackEmpty(s) || TakeOut(&s) != Out[OutIdx])
		{
			if (InIdx < InSize)
			{
				PushBack(&s, In[InIdx++]);
			}
			else
			{
				return 0;
			}
		}
		PopBack(&s);
		OutIdx++;
	}
	return 1;
}
#endif//出栈匹配

void SharedStackInit(SharedStack* s)//初始化
{
	s->_top1 = 0;
	s->_top2 = 100 - 1;
}
void SharedStackPushBack(SharedStack* s, int num, int which)//入栈
{
	if ((s->_top1)>(s->_top2))
	{
		return;
	}
	if (which == 1)
	{
		s->_array[s->_top1++] = num;
	}
	else
	{
		s->_array[s->_top2++] = num;
	}
}
void SharedStackPopBack(SharedStack* s, int which)//出栈
{
	if (SharedStackEmpty(s, which))
	{
		return;
	}
	if (1 == which)
	{
		s->_top1--;
	}
	else
	{
		s->_top2++;
	}
}
int SharedStackTop(SharedStack* s, int which)//取出元素
{
	assert(!SharedStackEmpty(s, which));
	if (1 == which)
	{
		return s->_array[s->_top1 - 1];
	}
	else
	{
		return s->_array[s->_top2 + 1];
	}
}
int SharedStackSize(SharedStack* s, int which)//大小
{
	if (which == 1)
	{
		return s->_top1;
	}
	else
	{
		return 100 - s->_top2 - 1;
	}
}
int SharedStackEmpty(SharedStack* s, int which)//判空
{
	if (which == 1)
	{
		return 0==s->_top1;
	}
	else
	{
		return 100 -1 == s->_top2;
	}
}