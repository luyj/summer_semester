#include "Global.h"
#define STACK_INIT_SIZE 100
typedef struct S_ElemType
{
	int x;
	int y;
	Orientation z;
}SElemType;

typedef struct _SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
	int size;
}SqStack;
BOOL InitStack(SqStack *);
BOOL Push(SqStack*, SElemType);
BOOL Pop(SqStack*, SElemType*e);
BOOL StackEmpty(SqStack*s);
//�ж��Ƿ��ǿ�ջ�����ǿգ���e������ֵ
BOOL StackEmpty(SqStack*s);