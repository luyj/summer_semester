#define INIT_BRICK_NUM 50//初始砖块数量
#define	UP_BRICK_NUM 10//每次升级增加砖数目
#define NO_BRICK 20  //局部空白砖块
#define UP_HIGHT 1 //砖块纵向增加数
#define MAX_WIDTH 30
#define MAX_HIGHT 30
#define MAX_LEVEL 2 
#define BALL_X 20//初始化小球坐标
#define BALL_Y 28
#define MAX_LEVEL 0
#define SPEED 1
#define UP_BROADL 2//板加长
#define BROAD 2
#define RATIO 1//击中范围
#define BRICKWIDTH 2
#define BRICKHEIGHT 1
#define BROADWIDTH 5
#define BROADHIGHT 1
#define BALLROUND 1

#define BOTTLEHIGHT 1//球高

typedef enum s_Orientation//球运动过程中，碰撞到砖块的边界
{
	HN,
	Above,
	Below,
	Right,
	Left,
	angle1,
	angle2,
	angle3,
	angle4
}Orientation;
typedef enum s_Blood
{
	//砖块生命值
	BREAK,
	ONE,
	TWO,
	THREE
}Blood;

typedef enum s_Direction
{
	//小球运动方向
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
}Direction;
typedef enum s_Color
{
	None,
	Purple,
	Brown,
	Green,
	Blue,
}Color;


typedef enum s_Attribute
{
	//砖块性能
	No,
	UpBlood,
	DownBlood,
	UpBoard,
}Attribute;

typedef struct s_Bottle
{
	double x;
	double y;
	Attribute z;
}Bottle;
typedef struct s_BAttribute
{
	Color color;
	Attribute at;
}BAttribute;

typedef struct s_Brick
{
	int life;//砖块生命值
	BAttribute attribute;//砖块性能
}Brick;
typedef struct s_Ball
{
	double x;//球坐标
	double y;
	double fx;//上一次反射球坐标
	double fy;
	double judge;
	BOOL flag;
	Direction dir;
}Ball, *SBall;


typedef struct s_Broad
{
	int x;
	int y;
	int length;
}Broad;




