#include "Stack.h"
#include <malloc.h>

typedef Bottle ElemType;
typedef struct Node
{
	ElemType data;				//单链表中的数据域 
	struct Node *next;			//单链表的指针域 
}Node, *LinkedList;

LinkedList push_L();
LinkedList LinkedListInit(LinkedList L, ElemType x);
LinkedList LinkedListDelete(LinkedList L);
LinkedList LinkedListCreat(LinkedList L, ElemType x);

void change_Bottle();
void Init_Broad();
int get_BrickLife(int i, int j);
Color get_Color(int i, int j);
double get_Ball_Y();
double get_Ball_X();
void get_Flag(int fx, int fy);
int  GetLive();
int GetLevel();

void ball_Move();
int get_Broad_X();
int get_Broad_Y();
void change_Broad_Dir(int x, int y);
void change_Brick(int x, int y);
void dir_Change(Orientation k, Ball *b);
BOOL is_Brickhit();
BOOL is_Broadhit();
BOOL over();
int  GetLive();
int GetLevel();
int get_Broad_Length();
void Init_Ball();
void Init_Brick();
LinkedList push_L();
void Clear_L();