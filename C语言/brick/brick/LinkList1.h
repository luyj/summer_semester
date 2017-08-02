#include "Stack.h"

typedef struct s_ElemType
{
	int x;
	int y;
	Color z;
}ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
	struct LNode *front;
}LNode,*LinkList;

BOOL CreateList(LinkList L);
BOOL CreateNode(LinkList L, int i, int j, Color c);
LNode TraverseList(LinkList L, int bx, int by);