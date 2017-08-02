#include "Stack.h"

//��ʼ��ջ
BOOL InitStack(SqStack*s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)
	{
		return OVERFLOW;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	s->size = 0;
	return TRUE;
}

//��ջ
BOOL Pop(SqStack*s, SElemType*e)
{
	if (s->top == s->base)
	{
		return FALSE;
	}
	else
	{
		/**e = *--s->top;*/
		s->top--;
		*e = *s->top;
		return TRUE;
	}
	s->size --;

}

//��ջ
BOOL Push(SqStack*s, SElemType e)
{
	if (s->top - s->base > s->stacksize)
	{
		s->base = (SElemType*)realloc(s->base, (s->stacksize + 2 * STACK_INIT_SIZE) * sizeof(SElemType));
		if (!s->base)
		{
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += 2 * STACK_INIT_SIZE;
	}
	*s->top = e;
	s->top++;
	s->size++;
	return TRUE;
}

BOOL StackEmpty(SqStack*s)
{
	if (s->base == s->top)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}