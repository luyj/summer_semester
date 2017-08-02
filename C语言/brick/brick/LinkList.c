#include "LinkList.h"

//////////////////////////////////////////// 
//定义结点类型 

//////////////////////////////////////////// 
//单链表的初始化
LinkedList LinkedListInit(LinkedList L, ElemType x)
{
	L = (Node*)malloc(sizeof(Node));
	L->data.x = x.x;
	L->data.y = x.y;
	L->data.z = x.z;
	L->next = NULL;
	return L;
}
//////////////////////////////////////////// 
//单链表的建立1，头插法建立单链表
LinkedList LinkedListCreat(LinkedList L, ElemType x)
{
	LinkedList q = L;
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	while (q->next != NULL)
	{
		q = q->next;
	}
	p->data.x = x.x;
	p->data.y = x.y;
	p->data.z = x.z;
	p->next = NULL;
	q->next = p;
	q = q->next;
	return L;
 }
 LinkedList LinkedListDelete(LinkedList q)
{
	LinkedList p = q;
 	Node*current = NULL;
	Node*previous = NULL;
	if (q == NULL)
	{
		return (NULL);
	}
	current = q;
	while (current != NULL)
	{
		while (current->data.y < broad.y - 1)
			{
				current->data.y += 0.1;
				previous = current;
				current = current->next;
				if (current == NULL)
				{
					break;
				}
			}
			if (current != NULL&&
				broad.y - 1 - current->data.y < 0.00001 &&
				broad.y + 1 - current->data.y>0.00001 &&
				((current->data.x) + 1 >= broad.x&&
					current->data.x < broad.x + broad.length))
			{
				if (current->data.z == UpBlood)
				{
					eggLife++;

				}
				if (current->data.z == DownBlood)
				{
					plLife--;
				}
				if (current->data.z == UpBoard)
				{
					if (broad.length == 8)
					{
						broad.length = 8;
					}
					else
					{
						broad.length++;
					}
				}
				if (current == q)
				{
					p = q = current->next;
				}
				else
				{
					previous->next = current->next;
				}
				Node *k = current;
				current = current->next;
				free(k);
			}
			else if (current != NULL)
			{
				while (current->data.y < MAX_HIGHT - 1)
				{
					current->data.y += 0.1;
					previous = current;
					current = current->next;
					if (current == NULL)
					{
						break;
					}
				}
				if (current != NULL&&MAX_HIGHT - 1 - current->data.y < 0.00001)
				{
					if (current == q)
					{
						p = q = current->next;
					}
					else
					{
						previous->next = current->next;
					}
					Node *k = current;
					current = current->next;
					free(k);
				}

			}

		}
	return p;

}
