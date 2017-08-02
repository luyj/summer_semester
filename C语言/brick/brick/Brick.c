#include "Global.h"
Brick brick[MAX_WIDTH][MAX_HIGHT];
Ball ball;
Broad broad;


void Init_Ball()
{
	//初始化小球
	ball.flag = FALSE;
	ball.x = BALL_X;
	ball.y = BALL_Y;
	ball.fx = BALL_X;
	ball.fy = BALL_Y;
	ball.judge = 1;
	ball.dir = UP_LEFT;
}
void Init_Brick()
{
	//初始化砖块，砖块在固定的区域随机分布，种类随机生成
	int num = 0;
	int i, j;
	int k = 0;
	srand(time(0));
	int x, y;
	int m = 0, n = 0;
	int power = 1;
	while (num < INIT_BRICK_NUM)
	{
		if (level == 2)
		{
			power = 1.5;
		}
		for (j = 10* power; j <MAX_HIGHT && num < INIT_BRICK_NUM*power; j += BRICKHEIGHT)
		{
			for (i = 4; i < MAX_WIDTH - BRICKWIDTH&&num < INIT_BRICK_NUM*power; i += BRICKWIDTH)
			{
				//在一定范围内初始化小球，小球数目一定，第一关砖块数目值全为一
				Attribute a;
				Color c;
				if (n < 20)
				{
					a = rand() % 4;
					
					if (a == No)
					{
						n++;
					}
					
				}
				else if (n >= 20)
				{
					a = rand() % 3 + 1;
				}
				if (a == UpBlood)
				{
					m++;
				}
				if (n == 30 && m < 10)
				{
					a = UpBlood;
				}
				brick[i][j].attribute.at = a;
				
				if (num > 20)
				{
					c = rand() % 4 + 1;
				}
				else
				{
					c = rand() % 5;
				}
				brick[i][j].attribute.color = c;
				if (level == 1)
				{
					brick[i][j].life = level;
				}
				else if (level == 2)
				{
					brick[i][j].life = rand() % 2 + 1;
				}
				if (c != None)
				{
					num++;
				}
			}
		}
	}
}
void Init_Broad()
{
	broad.x = BALL_X-3;
	broad.y = BALL_Y + 1;
	broad.length = BROADWIDTH;
}

int get_Broad_Length()
{
	return broad.length;
}

