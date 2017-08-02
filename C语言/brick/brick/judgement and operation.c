#include "LinkList.h"
LinkedList L;

DWORD level = 1;
DWORD plLife = 2;
HWND hwndBrick;
int eggLife = 0;
int redBottle = 10;

BOOL is_Broadhit()
{
	//判断板是否与小球接触
	if (ball.x >= broad.x&&
		ball.x <= broad.x + broad.length&&
		ball.y + 1 == broad.y)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int get_BrickLife(int i, int j)
{
	return brick[i][j].life;
	
}

Color get_Color(int i, int j)
{
	return brick[i][j].attribute.color;
}
void get_Flag(int fx, int fy)
{
	ball.flag = fabs((fx - ball.x)*0.1 / (fy - ball.y));
}
void change_Brick(int x, int y)
{
	//改变板的生命值
	brick[x][y].life--;
	if (brick[x][y].life == 0)
	{
		if (brick[x][y].attribute.at != No)
		{
			Bottle p;
			p.x = x;
			p.y = y + 1;
			p.z = brick[x][y].attribute.at;
			if (L == NULL)
			{
				L = LinkedListInit(L, p);
			}
			else
			{

				L = LinkedListCreat(L, p);
			}
		}
		brick[x][y].attribute.color = None;
		bricknum++;
	}
	
}

void change_Bottle() 
{
	LinkedList P = L;
	L = LinkedListDelete(P);
}
LinkedList push_L()
{
	LinkedList P = L;
	return P;
}

void ball_Move()
{
	//小球有四种移动方向，每种移动方向
	//由不同坐标变化表示
	if (ball.dir == UP_RIGHT)
	{
		ball.x = ball.x + 0.25;
		ball.y = ball.y - 0.25;
	}
	if (ball.dir == UP_LEFT)
	{
		ball.x = ball.x - 0.25;
		ball.y = ball.y - 0.25;
	}
	if (ball.dir == DOWN_RIGHT)
	{
		ball.x = ball.x + 0.25;
		ball.y = ball.y + 0.25;
	}
	if (ball.dir == DOWN_LEFT)
	{
		ball.x = ball.x - 0.25;
		ball.y = ball.y + 0.25;
	}
	if (over() == TRUE)
	{
		ball.x = broad.x;
		ball.y = broad.y-1;
		ball.flag = FALSE;
	}
}
int get_Broad_X()
{
	return broad.x;
}
int get_Broad_Y()
{
	return broad.y;
}

void change_Broad_Dir(int x, int y)
{
	if (broad.x + BROADWIDTH != MAX_WIDTH)
	{
		broad.x = x + BROADWIDTH;
	}
	broad.x = x + BROADWIDTH;
}

void dir_Change(Orientation k,Ball *b)
{
	//变化与砖块撞击后，小球移动方向
	if (k == Above)
	{
		if (b->dir == DOWN_RIGHT)
		{
			b->dir = UP_RIGHT;
		}
		else
		{
			b->dir = UP_LEFT;
		}
	}
	else if (k == Below)
	{
		if (b->dir == UP_RIGHT)
		{
			b->dir = DOWN_RIGHT;
		}
		else
		{
			b->dir = DOWN_LEFT;
		}
	}
	else if (k == Right)
	{
		if (b->dir = DOWN_LEFT)
		{
			b->dir = DOWN_RIGHT;
		}
		else
		{
			b->dir = UP_RIGHT;
		}
	}
	else if (k == Left)
	{
		if (b->dir = DOWN_RIGHT)
		{
			b->dir = DOWN_LEFT;
		}
		else
		{
			b->dir = UP_LEFT;
		}
	}
	else
	{
		if (ball.dir == DOWN_LEFT)
		{
			ball.dir = UP_RIGHT;
		}
		else if (ball.dir == DOWN_RIGHT)
		{
			ball.dir = UP_LEFT;
		}
		else if (ball.dir == UP_LEFT)
		{
			ball.dir = DOWN_RIGHT;
		}
		else if (ball.dir = UP_RIGHT)
		{
			ball.dir = DOWN_LEFT;
		}
	}
} 


 BOOL is_Brickhit()
{
	int i, j;
	int num = 0;
	SElemType e;
	SqStack s;
	SElemType e1, e2;
	InitStack(&s);
	BOOL h = FALSE;
	for (j = 10; j < MAX_WIDTH&&num<INIT_BRICK_NUM; j += BRICKHEIGHT)
	{
 		for (i = 0; i < MAX_HIGHT&&num<INIT_BRICK_NUM; i += BRICKWIDTH)
		{
			if (brick[i][j].attribute.color != None)
			{
				if (ball.x >= i-BALLROUND/2.0&&ball.x < i + BRICKWIDTH&&ball.y == j + BALLROUND)
				{
					e.x = i;
					e.y = j;
					e.z = Below;
					Push(&s, e);
				}
				else if (ball.x >= i - BALLROUND / 2.0&&ball.x < i + BRICKWIDTH&&ball.y == j - BALLROUND)
				{
					e.x = i;
					e.y = j;
					e.z = Above;
					Push(&s, e);
				}
				else if (ball.y >= j - BALLROUND / 2.0&&ball.y < j + BRICKHEIGHT&&ball.x == i + BRICKWIDTH)
				{
					e.x = i;
					e.y = j;
					e.z = Right;
					Push(&s, e);
				}
				else if (ball.y >= j-BALLROUND/2.0&&ball.y <j + BRICKHEIGHT&&ball.x  == i-BALLROUND)
				{

					e.x = i;
					e.y = j;
					e.z = Left;
					Push(&s, e);
				}
				else if (ball.x == i + BRICKWIDTH - 0.25&&ball.y -0.75== j )
				{
					e.x = i;
					e.y = j;
					e.z = angle2;
					Push(&s, e);
				}
				else if (ball.x - 1.75 == i && ball.y + 0.75 == j)
				{
					e.x = i;
					e.y = j;
					e.z = angle1;
					Push(&s, e);
				}
				else if (ball.x + 0.75 == i && ball.y + 0.75 == j)
				{
					e.x = i;
					e.y = j;
					e.z = angle3;
					Push(&s, e);
				}
				else if (ball.x +0.75==i && ball.y == j + 0.75)
				{
					e.x = i;
					e.y = j;
					e.z = angle4;
					Push(&s, e);

				}
				num++;
				
			}

		}
	}
   if (s.size == 1)
	{
		Pop(&s, &e1);
		change_Brick(e1.x, e1.y);
		dir_Change(e1.z, &ball);
		h = TRUE;
	}
 	else if (s.size == 2||(ball.x==0&&ball.y==0)||
		(ball.x==MAX_WIDTH-1&&ball.y==0))
	{
		if (s.size == 2)
		{
			Pop(&s, &e1);
			Pop(&s, &e2);
			change_Brick(e1.x, e1.y);
			change_Brick(e2.x, e2.y);
			
		}
		if (ball.dir == DOWN_LEFT)
		{
			ball.dir = UP_RIGHT;
		}
		else if (ball.dir == DOWN_RIGHT)
		{
			ball.dir = UP_LEFT;
		}
		else if (ball.dir == UP_LEFT)
		{
			ball.dir = DOWN_RIGHT;
		}
		else if (ball.dir = UP_RIGHT)
		{
			ball.dir = DOWN_LEFT;
		}
		h = TRUE;
	}
    if (ball.dir == UP_LEFT&&
		ball.x == 0 && ball.y > 0 &&
		ball.y < MAX_HIGHT)
	{
		ball.dir = UP_RIGHT;
		h = TRUE;
	}
	else if (ball.dir == DOWN_LEFT&&
		ball.x == 0 && ball.y > 0 &&
		ball.y < MAX_HIGHT)
	{
		ball.dir = DOWN_RIGHT;
		h = TRUE;
	}
	else if (ball.dir == UP_RIGHT&&
		ball.y == 0 && ball.x > 0
		&& ball.x < MAX_WIDTH)
	{
		ball.dir = DOWN_RIGHT;
		h = TRUE;
	}
	else if (ball.dir == UP_LEFT&&
		ball.y == 0 && ball.x > 0
		&& ball.x < MAX_WIDTH)
	{
		ball.dir = DOWN_LEFT;
		h = TRUE;
	}
	else if (ball.dir == UP_LEFT&&
		ball.y == 0 && ball.x > 0
		&& ball.x < MAX_WIDTH)
	{
		ball.dir = DOWN_LEFT;
		h = TRUE;
	}
	else if (ball.dir == DOWN_RIGHT&&
		ball.x == MAX_WIDTH - 1 && ball.y > 0 &&
		ball.y < MAX_HIGHT)
	{
		ball.dir = DOWN_LEFT;
		h = TRUE;
	}
	else if (ball.dir == UP_RIGHT&&
		ball.x == MAX_WIDTH - 1 && ball.y > 0 &&
		ball.y < MAX_HIGHT)
	{
		ball.dir = UP_LEFT;
		h = TRUE;
	}
	if (is_Broadhit() == TRUE)
	{
		if (ball.x == 0)
		{
			ball.dir = UP_RIGHT;
		}
		else if (ball.x + 1 == MAX_WIDTH)
		{
			ball.dir = UP_LEFT;
		}
		if (ball.dir == DOWN_RIGHT)
		{
			ball.dir = UP_RIGHT;
		}
		if (ball.dir == DOWN_LEFT)
		{
			ball.dir = UP_LEFT;
		}
	}
	return h;
}

BOOL over()
{
	if (ball.y == MAX_HIGHT - 1)
	{
		if (plLife > 0)
		{
			
			plLife--;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}

double get_Ball_X()
{
	return ball.x;
}
double get_Ball_Y()
{
	return ball.y;
}
int  GetLive()
{
	return plLife;
}
int GetLevel()
{
	return level;
}


void Clear_L()
{
	L = NULL;
}