

#define TIMER_ID 12340
#define TIMER_ID1 12341
#define INIT_TIMER_ELAPSE	40

#define BRICK_PIXEL 60
#define COLOR_BRICKW RGB(141,182,205)
#define COLOR_BACKGROUND RGB(250,128,134)
#define  COLOR_BOUNDARY RGB(139,134,130)
#define COLOR_TEXT			RGB(173,216,230)
#define COLOR_BROAD RGB(121,205,205)
#define COLOR_BALL RGB(238,99,99)
//hBrushA组渐变色purple
#define COLOR_BRICKA1 RGB(153,50,204)
#define COLOR_BRICKA2 RGB(218,112,214)
#define COLOR_BRICKA3 RGB(221,160,221)
//hBrushB组渐变色brown
#define COLOR_BRICKB1 RGB(139,126,102)
#define COLOR_BRICKB2 RGB(205,186,150)
#define COLOR_BRICKB3 RGB(238,216,174)
//hBrushC组渐变色green
#define COLOR_BRICKC1 RGB(34,139,34)
#define COLOR_BRICKC2 RGB(50,205,50)
#define COLOR_BRICKC3 RGB(154,205,50)
//hBrushD组渐变色blue
#define COLOR_BRICKD1 RGB(0 ,206 ,209)
#define COLOR_BRICKD2 RGB(64,224,208)
#define COLOR_BRICKD3 RGB(175,238,238)
#define EGG_MAX_LIFE 2

#define CELL_PIXEL			20
#define BROAD_MOVE_STEP 5//控制键控制下
#define GAME_HEIGHT 30
#define GAME_WIDTH 30


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
void CreateGame(HWND hwnd, DWORD dwInitTimerElapse, int boundary_x, int boundary_y);
void ReSizeGameWnd(HWND hwnd);
void GamePaint(HWND hwnd);
void OnKeyDown(DWORD vk);
void OnTimer(HWND hwnd);