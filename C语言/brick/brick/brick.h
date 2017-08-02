#define INIT_BRICK_NUM 50//��ʼש������
#define	UP_BRICK_NUM 10//ÿ����������ש��Ŀ
#define NO_BRICK 20  //�ֲ��հ�ש��
#define UP_HIGHT 1 //ש������������
#define MAX_WIDTH 30
#define MAX_HIGHT 30
#define MAX_LEVEL 2 
#define BALL_X 20//��ʼ��С������
#define BALL_Y 28
#define MAX_LEVEL 0
#define SPEED 1
#define UP_BROADL 2//��ӳ�
#define BROAD 2
#define RATIO 1//���з�Χ
#define BRICKWIDTH 2
#define BRICKHEIGHT 1
#define BROADWIDTH 5
#define BROADHIGHT 1
#define BALLROUND 1

#define BOTTLEHIGHT 1//���

typedef enum s_Orientation//���˶������У���ײ��ש��ı߽�
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
	//ש������ֵ
	BREAK,
	ONE,
	TWO,
	THREE
}Blood;

typedef enum s_Direction
{
	//С���˶�����
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
	//ש������
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
	int life;//ש������ֵ
	BAttribute attribute;//ש������
}Brick;
typedef struct s_Ball
{
	double x;//������
	double y;
	double fx;//��һ�η���������
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




