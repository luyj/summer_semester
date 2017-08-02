#include "LinkList.h"
#pragma comment(lib,"winmm.lib")

DWORD dwTimerElapse;
HINSTANCE hinst;
POINT ptFighter;
HBITMAP hbmpBegin;
HBITMAP hbmpFighterA;
HBITMAP hbmpFighterB;
HBITMAP hbmpFighterC;
HBITMAP hbmpEgg[8];
HBITMAP hbmpThreeEgg[8];
RECT rectBoundary;

int s = 2;
int r = 0;
int r1 = 0;
int r2 = 0;
int Init = -1;
int s1 = 0;
int bricknum = 0;
void CreateGame(HWND hwnd, DWORD dwInitTimerElapse, int boundary_x, int boundary_y)
{
	Init_Ball();
	Init_Brick();
	Init_Broad();
	dwTimerElapse = dwInitTimerElapse;
	SetTimer(hwnd, TIMER_ID, dwTimerElapse, NULL);
	hbmpBegin = (HBITMAP)LoadImage(NULL, "begin.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpBegin == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[0] = (HBITMAP)LoadImage(NULL, "01.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[0] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[1] = (HBITMAP)LoadImage(NULL, "02.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[1] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[2] = (HBITMAP)LoadImage(NULL, "03.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[2] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[3] = (HBITMAP)LoadImage(NULL, "04.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[3] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[4] = (HBITMAP)LoadImage(NULL, "05.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[4] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[5] = (HBITMAP)LoadImage(NULL, "06.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[5] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[6] = (HBITMAP)LoadImage(NULL, "07.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[6] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpThreeEgg[7] = (HBITMAP)LoadImage(NULL, "08.bmp",
		IMAGE_BITMAP, 410, 220, LR_LOADFROMFILE);
	if (hbmpThreeEgg[7] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[0] = (HBITMAP)LoadImage(NULL, "0.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[0] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[1] = (HBITMAP)LoadImage(NULL, "0.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[1] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[2] = (HBITMAP)LoadImage(NULL, "2.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[2] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[3] = (HBITMAP)LoadImage(NULL, "3.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[3] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[4] = (HBITMAP)LoadImage(NULL, "4.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[4] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[5] = (HBITMAP)LoadImage(NULL, "5.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[5] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[6] = (HBITMAP)LoadImage(NULL, "6.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[6] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpEgg[7] = (HBITMAP)LoadImage(NULL, "7.bmp",
		IMAGE_BITMAP, 109, 115, LR_LOADFROMFILE);
	if (hbmpEgg[7] == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	hbmpFighterB = (HBITMAP)LoadImage(NULL, "green2.bmp",
		IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);

	if (hbmpFighterB == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpFighterA = (HBITMAP)LoadImage(NULL, "red3.bmp",
		IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);

	if (hbmpFighterA == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	hbmpFighterC = (HBITMAP)LoadImage(NULL, "blue.bmp",
		IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);

	if (hbmpFighterC == NULL)
	{
		MessageBox(hwnd, "bmp file not find", "ERROR!",
			MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
}
void ReSizeGameWnd(HWND hwnd)
{
	POINT ptLeftTop;		// ���Ͻ�
	POINT ptRightBottom;	// ���½�
	RECT rectWindow;

	// ������Ϸ�߽�
	rectBoundary.left = 10;
	rectBoundary.top = 10;
	rectBoundary.right = 10 + CELL_PIXEL*GAME_WIDTH;
	rectBoundary.bottom = 10 + CELL_PIXEL*GAME_HEIGHT;

	// �����������ҽǵ�λ��
	ptLeftTop.x = rectBoundary.left;
	ptLeftTop.y = rectBoundary.top;
	ptRightBottom.x = rectBoundary.right;
	ptRightBottom.y = rectBoundary.bottom;
	ClientToScreen(hwnd, &ptLeftTop);
	ClientToScreen(hwnd, &ptRightBottom);

	GetWindowRect(hwnd, &rectWindow);
	// ������ˣ����ô��ڴ�С��
	MoveWindow(hwnd,
		rectWindow.left,
		rectWindow.top,
		ptLeftTop.x - rectWindow.left + ptRightBottom.x - rectWindow.left, // ����߽���������߱߿���ȡ�
		rectBoundary.bottom + 120, //��������Ϣ������ʾ�ռ䡣
		TRUE);
}

void GamePaint(HWND hwnd)
{
	int r;
	HPEN hpen;
	HDC hdc, hdcmem, hdcmem1;
	HPEN hPenBoundary;
	HPEN hOldPen;
	BITMAP bmp;
	HBRUSH hBrush1;
	HBRUSH hBrushball;
	HBRUSH hBrushb;
	HBRUSH hBrushBroad;
	HBRUSH hBrushBackground;
	HBRUSH hBrushA1, hBrushA2, hBrushA3;
	HBRUSH hBrushB1, hBrushB2, hBrushB3;
	HBRUSH hBrushC1, hBrushC2, hBrushC3;
	HBRUSH hBrushD1, hBrushD2, hBrushD3;
	HBRUSH hOldBrush;
	HBITMAP hBitmap, hBitmap1;
	HFONT hFont, hOldFont;

	RECT rect;

	int i;





	GetClientRect(hwnd, &rect);
	hdc = GetDC(hwnd);
	hdcmem = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc, // ������hdcMem��������ɺڰ�2ɫλͼ
		rect.right - rect.left, rect.bottom - rect.top);
	hdcmem1 = CreateCompatibleDC(hdcmem);
	hBitmap1 = CreateCompatibleBitmap(hdc, // ������hdcMem��������ɺڰ�2ɫλͼ
		rect.right - rect.left, rect.bottom - rect.top);

	SelectObject(hdcmem, hBitmap);
	SelectObject(hdcmem1, hBitmap1);


	hBrush1 = CreateSolidBrush(COLOR_BRICKW);
	hBrushBroad = CreateSolidBrush(COLOR_BROAD);
	hBrushA1 = CreateSolidBrush(COLOR_BRICKA1);
	hBrushA2 = CreateSolidBrush(COLOR_BRICKA2);
	hBrushA3 = CreateSolidBrush(COLOR_BRICKA3);
	hBrushB1 = CreateSolidBrush(COLOR_BRICKB1);
	hBrushB2 = CreateSolidBrush(COLOR_BRICKB2);
	hBrushB3 = CreateSolidBrush(COLOR_BRICKB3);
	hBrushC1 = CreateSolidBrush(COLOR_BRICKC1);
	hBrushC2 = CreateSolidBrush(COLOR_BRICKC1);
	hBrushC3 = CreateSolidBrush(COLOR_BRICKC3);
	hBrushD1 = CreateSolidBrush(COLOR_BRICKD1);
	hBrushD2 = CreateSolidBrush(COLOR_BRICKD2);
	hBrushD3 = CreateSolidBrush(COLOR_BRICKD3);
	hBrushball = CreateSolidBrush(COLOR_BALL);
	hBrushb = CreateSolidBrush(COLOR_BACKGROUND);
	hpen = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	hPenBoundary = CreatePen(0, 3, COLOR_BOUNDARY);
	hBrushBackground = CreateSolidBrush(RGB(255, 255, 255));
	if (Init==-1)
	{
		FillRect(hdcmem1, &rect, hBrushBackground);
		SelectObject(hdcmem, hbmpBegin);
		GetObject(hbmpBegin, sizeof(BITMAP), &bmp);
		StretchBlt(hdcmem1,
			0,0,
			690, 690,
			hdcmem,
			0, 0, bmp.bmWidth, bmp.bmHeight,
			SRCCOPY);
	}


	else if (Init == 1)
	{
		SetLayeredWindowAttributes(hdc, RGB(255, 255, 255), 0, LWA_COLORKEY | LWA_ALPHA);
		FillRect(hdcmem1, &rect, hBrushBackground);
		SelectObject(hdcmem, hbmpThreeEgg[s1]);
		GetObject(hbmpThreeEgg[s1], sizeof(BITMAP), &bmp);
		BitBlt(hdcmem1,
			2 * CELL_PIXEL * 2, 12 * CELL_PIXEL, 3000, 3000,
			hdcmem, 0, 0, SRCCOPY);
	}




	else
	{
		FillRect(hdcmem1, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
		SelectObject(hdcmem, hbmpEgg[s]);
		GetObject(hbmpEgg[s], sizeof(BITMAP), &bmp);
		BitBlt(hdcmem1,
			12 * CELL_PIXEL, 1 * CELL_PIXEL, 120, 120,
			hdcmem, 0, 0, SRCCOPY);

		/*******************************************************************************
		* #############  ����ƿ  ################
		*
		//*******************************************************************************/
		LinkedList P = push_L();
		while (P != NULL)
		{
			if (P->data.z != None)
			{

				SelectObject(hdcmem, hbmpFighterA);
				GetObject(hbmpFighterA, sizeof(BITMAP), &bmp);
				BitBlt(hdcmem1,
					P->data.x*CELL_PIXEL, P->data.y*CELL_PIXEL, 50, 50,
					hdcmem, 0, 0, SRCCOPY);
			}
			if (P->data.z == DownBlood)
			{
				SelectObject(hdcmem, hbmpFighterB);
				GetObject(hbmpFighterB, sizeof(BITMAP), &bmp);
				BitBlt(hdcmem1,
					P->data.x*CELL_PIXEL, P->data.y*CELL_PIXEL, 50, 50,
					hdcmem, 0, 0, SRCCOPY);
			}
			if (P->data.z == UpBoard)
			{

				SelectObject(hdcmem, hbmpFighterC);
				GetObject(hbmpFighterC, sizeof(BITMAP), &bmp);
				BitBlt(hdcmem1,
					P->data.x*CELL_PIXEL, P->data.y*CELL_PIXEL, 50, 50,
					hdcmem, 0, 0, SRCCOPY);
			}
			P = P->next;
		}

		double a, b;
		int life;
		int blife;
		/*******************************************************************************
		* #############  ��ש��  ################
		*
		//*******************************************************************************/
		for (a = 0; a < MAX_WIDTH; a += 2)
		{
			for (b = 0; b < MAX_HIGHT; b += 1)
			{
				life = get_BrickLife(a, b);
				switch (get_Color(a, b))
				{
				case Purple:
				{
					if (life == 3)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushA1);
					}
					if (life == 2)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushA2);
					}
					if (life == 1)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushA3);
					}
					hOldPen = (HPEN)SelectObject(hdcmem1, hpen);
					Rectangle(hdcmem1,
						a * CELL_PIXEL + rectBoundary.left,
						b * CELL_PIXEL + rectBoundary.top,
						(a + BRICKWIDTH)*CELL_PIXEL + rectBoundary.left,
						(b + BRICKHEIGHT)*CELL_PIXEL + +rectBoundary.top);
					break;

				}
				case Brown:
				{
					if (life == 3)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushB1);
					}
					if (life == 2)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushB2);
					}
					if (life == 1)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushB3);
					}
					hOldPen = (HPEN)SelectObject(hdcmem1, hpen);
					Rectangle(hdcmem1,
						a * CELL_PIXEL + rectBoundary.left,
						b * CELL_PIXEL + rectBoundary.top,
						(a + BRICKWIDTH)*CELL_PIXEL + rectBoundary.left,
						(b + BRICKHEIGHT)*CELL_PIXEL + +rectBoundary.top);
					break;
				}
				case Green:
				{
					if (life == 3)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushC1);
					}
					if (life == 2)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushC2);
					}
					if (life == 1)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushC3);
					}
					hOldPen = (HPEN)SelectObject(hdcmem1, hpen);
					Rectangle(hdcmem1,
						a * CELL_PIXEL + rectBoundary.left,
						b * CELL_PIXEL + rectBoundary.top,
						(a + BRICKWIDTH)*CELL_PIXEL + rectBoundary.left,
						(b + BRICKHEIGHT)*CELL_PIXEL + +rectBoundary.top);
					break;
				}
				case Blue:
				{
					if (life == 3)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushD1);
					}
					if (life == 2)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushD2);
					}
					if (life == 1)
					{
						hOldBrush = (HBRUSH)SelectObject
						(hdcmem1, hBrushD3);
					}
					hOldPen = (HPEN)SelectObject(hdcmem1, hpen);
					Rectangle(hdcmem1,
						a * CELL_PIXEL + rectBoundary.left,
						b * CELL_PIXEL + rectBoundary.top,
						(a + BRICKWIDTH)*CELL_PIXEL + rectBoundary.left,
						(b + BRICKHEIGHT)*CELL_PIXEL + +rectBoundary.top);
					break;
				}
				default:
				{
					break;
				}
				}
			}
		}

		/*******************************************************************************
		* #############  ��С��  ################
		*
		*******************************************************************************/

		hOldBrush = (HBRUSH)SelectObject(hdcmem1, hBrushball);
		hOldPen = (HPEN)SelectObject(hdcmem1, hpen);
		Ellipse(hdcmem1,
			get_Ball_X()*CELL_PIXEL + rectBoundary.left,
			get_Ball_Y()*CELL_PIXEL + rectBoundary.top,
			(get_Ball_X() + BALLROUND)*CELL_PIXEL + rectBoundary.left,
			(get_Ball_Y() + BALLROUND)*CELL_PIXEL + rectBoundary.top);

		/*******************************************************************************
		* #############  �������  ################
		*
		*******************************************************************************/
		hOldBrush = (HBRUSH)SelectObject(hdcmem1, hBrushBroad);


		hOldPen = (HPEN)SelectObject(hdcmem1, hpen);
		Rectangle(hdcmem1,
			get_Broad_X() * CELL_PIXEL + rectBoundary.left,
			get_Broad_Y()* CELL_PIXEL + rectBoundary.top,
			(get_Broad_X() + get_Broad_Length())*CELL_PIXEL + rectBoundary.left,
			(get_Broad_Y() + BROADHIGHT)*CELL_PIXEL + +rectBoundary.top);
		/*******************************************************************************
		* #############  ��ǽ  ################
		*
		*******************************************************************************/

		SelectObject(hdcmem1, hPenBoundary);

		// ��PEN�ƶ�����Ҫ���Ƶķ�������Ͻ�
		MoveToEx(hdcmem1, rectBoundary.left, rectBoundary.top, NULL);
		// ����һ��������ʾLineTo����
		LineTo(hdcmem1, rectBoundary.left, rectBoundary.bottom);
		LineTo(hdcmem1, rectBoundary.right, rectBoundary.bottom);
		LineTo(hdcmem1, rectBoundary.right, rectBoundary.top);
		LineTo(hdcmem1, rectBoundary.left, rectBoundary.top);



		/*******************************************************************************
		* #############  дһ����  ################
		*
		*******************************************************************************/

		// ������һ���������
		hFont = CreateFont(48, 0, 0, 0, FW_DONTCARE, 0, 1, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Consolas"));

		// �����FONT�������DC��
		if (hOldFont = (HFONT)SelectObject(hdcmem1, hFont))
		{
			CHAR szSourceInfo[1024];
			wsprintf(szSourceInfo, "Live %d level %d egglife %d", GetLive(), GetLevel(), eggLife);
			// ���������ɫ
			SetTextColor(hdcmem1, COLOR_TEXT);
			// ����ַ�����
			TextOut(hdcmem1, rectBoundary.left + 3, rectBoundary.bottom + 3,
				szSourceInfo, lstrlen(szSourceInfo));
			// �����ɣ���ԭ�����������Ż�DC��
			SelectObject(hdcmem1, hOldFont);
		}
		DeleteObject(hFont);
	}



	BitBlt(hdc,
		0, 0, rect.right - rect.left, rect.bottom - rect.top,
		hdcmem1, 0, 0, SRCCOPY);

	DeleteObject(hBrush1);
	DeleteObject(hBrushball);
	DeleteObject(hBrushA1);
	DeleteObject(hBrushA2);
	DeleteObject(hBrushA3);
	DeleteObject(hBrushB1);
	DeleteObject(hBrushB2);
	DeleteObject(hBrushB3);
	DeleteObject(hBrushC1);
	DeleteObject(hBrushC2);
	DeleteObject(hBrushC3);
	DeleteObject(hBrushD1);
	DeleteObject(hBrushD2);
	DeleteObject(hBrushD3);
	DeleteObject(hpen);
	DeleteObject(hPenBoundary);
	DeleteObject(hBrushBackground);

	DeleteObject(hBrushBroad);
	DeleteObject(hBrushb);
	DeleteObject(hdcmem1);
	DeleteObject(hdcmem);
	DeleteObject(hBitmap1);
	DeleteObject(hBitmap);
	/*******************************************************************************
	* #############  ReleaseDC ����  ################
	* �ͷ�ռ�õ�DC��ϵͳ��Դ��
	*******************************************************************************/
	ReleaseDC(hwnd, hdc);

}
//LONG BrickTimer(HWND hwnd);
void OnKeyDown(DWORD vk)
{
	switch (vk)
	{

	case VK_LEFT:
		if (ball.flag == TRUE)
		{
			broad.x--;
			if (broad.x < 0)
			{
				broad.x = 0;
			}
		}
		break;
	case VK_RIGHT:
		if (ball.flag == TRUE)
		{
			broad.x++;
			if (broad.x + broad.length > MAX_WIDTH)
			{
				broad.x = MAX_WIDTH - broad.length;
			}
		}
		break;
	case VK_UP:
	{
		if (ball.flag == TRUE)
		{
			broad.y--;
			if (broad.y <= 15)
			{
				broad.y = 15;
			}
		}
		break;
	}
	case VK_DOWN:
	{
		if (ball.flag == TRUE)
		{
			broad.y++;
			if (broad.y >= MAX_HIGHT - 1)
			{
				broad.y = MAX_HIGHT - 1;
			}
		}
		break;
	}
	case VK_SPACE:
		if (ball.flag == FALSE)
		{
			ball.flag = TRUE;
			ball_Move();
		}
		break;
	}
}
void OnTimer(HWND hwnd)
{
	
	if (eggLife < EGG_MAX_LIFE)
	{

		if (ball.flag == TRUE)
		{
			ball_Move();
			if (is_Brickhit() == TRUE || is_Broadhit() == TRUE)
			{

				PlaySound("E:\\17games\\17games\\touch.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		change_Bottle();
		if (s != 4)
		{
			r1++;
			if (r1 == 10)
			{
				s++;
				r1 = 0;
			}

		}
		else
		{
			s = 2;
		}
	}
	else
	{
		if (s != 7)
		{
			s++;
		}
		else
		{
			s = 0;
		}

	}

	if (eggLife >= EGG_MAX_LIFE)
	{

		GamePaint(hwnd);
		r++;
		if (r > 50)
		{
			Init = 1;
		}

		if (Init == 1 && r2 < 100)
		{
			if (level == 2 && eggLife == EGG_MAX_LIFE)
			{
				KillTimer(hwnd, TIMER_ID);
				// Ȼ��֪ͨ��ң�Game Over�ˣ��˳����̡�
				MessageBox(0, "You are win", "Game Over", 0);
				ExitProcess(0);
			}
			r2++;
			if (s1 < 7)
			{
				s1++;
			}
			else
			{
				s1 = 0;
			}

			GamePaint(hwnd);
		}
		if (r2 == 100)
		{

			r2 = 0;
			level++;
			Init = 0;
			eggLife = 0;
			plLife = 3;
			s = 2;
			Init_Ball();
			Init_Brick();
			Init_Broad();
			r = 0;
			r1 = 0;
			Clear_L();
			GamePaint(hwnd);

		}


	}
	else if (plLife == 0 || bricknum == 50)
	{
		GamePaint(hwnd);
		KillTimer(hwnd, TIMER_ID);
		// Ȼ��֪ͨ��ң�Game Over�ˣ��˳����̡�
		MessageBox(0, "Game Over", "Game Over", 0);
		ExitProcess(0);
	}
	return;
}
LONG CALLBACK MainWndProc(
	HWND hwnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{
	RECT rectNew;
	int x, y;
	switch (msg)
	{

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (x > 228 &&
			x < 460 && 
			y>381 &&
			y < 445)
		{
			Init = 0;
		}
		else if (x > 225 && 
			x < 455 &&
			y>487 && 
			y < 566)
		{
			exit(0);
		}
		break;
	case WM_CREATE:
		if (Init == -1)
			CreateGame(hwnd,
				INIT_TIMER_ELAPSE,
				MAX_WIDTH,
				MAX_HIGHT);
		ReSizeGameWnd(hwnd);
		break;
	case WM_PAINT:
		GamePaint(hwnd);
		break;
	case WM_KEYDOWN:
		OnKeyDown(wParam);
		GamePaint(hwnd);
		break;
	case WM_TIMER:
		OnTimer(hwnd);
		GamePaint(hwnd);
		break;

	case WM_DESTROY:
		ExitProcess(0);
		break;

	default:
		break;
	}
	return DefWindowProc(hwnd,
		msg,
		wParam,
		lParam);
}


int WINAPI WinMain(
	HINSTANCE hinstance, // ����ʵ��������ڳ������У����̴������ɲ���ϵͳ��Ӧ�ó�����
	HINSTANCE hPrevInstance, // �����̵ĳ���ʵ�����
	LPSTR lpCmdLine,  // �����в�������λ����������C����main��������argc��argv,����û�а��ո�����з�
	int nCmdShow)   // ����ָ�������Ƿ���Ҫ��ʾ�Ĳ�����
{

	WNDCLASS wc;
	// ���ھ����hwnd�����������ڵľ�������������ֻ�õ���һ�����ڡ�
	HWND hwnd;

	MSG msg;
	int fGotMessage;

	hinst = hinstance;

	// Fill in the window class structure with parameters 
	// that describe the main window. 

	// ���������ʽ���������õ���ʽ��ʾ�����ڴ�С�仯����Ҫ�ػ�
	wc.style = CS_HREDRAW | CS_VREDRAW;
	// һ������ָ�룬�������������������Ϣ�� ��� MainWndProc������ע�͡�
	wc.lpfnWndProc = MainWndProc;
	// no extra class memory 
	wc.cbClsExtra = 0;
	// no extra window memory
	wc.cbWndExtra = 0;
	// handle to instance 
	wc.hInstance = hinstance;
	// hIcon��Ա����ָ�����ڵ�ͼ��
	// ����ֱ��ʹ��LoadIcon����������һ��ϵͳԤ�����ͼ�꣬������Ա��Ҳ�����Լ�����ͼ�ꡣ
	wc.hIcon = LoadIcon(NULL,
		IDI_APPLICATION);
	// Cursor������꣬�������趨����������ʽ��
	// ֱ��ʹ��LoadCursor API����������һ��ϵͳԤ����Ĺ����ʽ������IDC_CROSS,IDC_HAND����ʽ 
	wc.hCursor = LoadCursor(NULL,
		IDC_CROSS);
	// GetStockObject�Ĺ����Ǽ���һ��ϵͳԤ���壨��ջ�У���GDI����
	// ������ص���һ����ɫ�Ļ�ˢ���йػ�ˢ��GDI�������GDI˵����
	wc.hbrBackground = (HBRUSH)GetStockObject(
		WHITE_BRUSH);
	// ���ڵĲ˵�����Դ����
	wc.lpszMenuName = "MainMenu";
	// ����������һ�����֣��ڴ�������ʱ��Ҫ������֡�
	wc.lpszClassName = "MainWClass";

	// Register the window class. 

	if (!RegisterClass(&wc))
	{
		// ����ע��ʧ�ܣ���Ϣ����ʾ�����˳���
		MessageBox(NULL, "��������classʧ��", "����", MB_ICONERROR | MB_OK);
		return -1;
	}
	hwnd = CreateWindow(
		"MainWClass",			// �����������������Ѿ�ע���˵Ĵ�����
		"Snake Game!!",		// title-bar string 
		WS_OVERLAPPEDWINDOW,	// ���ڵ�style�������ʾΪtop-level window 
		CW_USEDEFAULT,			// ����ˮƽλ��default horizontal POINT 
		CW_USEDEFAULT,			// ���ڴ�ֱλ��default vertical POINT 
		CW_USEDEFAULT,			// ���ڿ�� default width 
		CW_USEDEFAULT,			// ���ڸ߶� default height 
		(HWND)NULL,				// �����ھ�� no owner window 
		(HMENU)NULL,			// ���ڲ˵��ľ�� use class menu 
		hinstance,				// Ӧ�ó���ʵ����� handle to application instance 
		(LPVOID)NULL);			// ָ�򸽼����ݵ�ָ�� no window-creation data 

	if (!hwnd)
	{
		// ���ڴ���ʧ�ܣ���Ϣ����ʾ�����˳���
		MessageBox(NULL, "��������ʧ��", "����", MB_ICONERROR | MB_OK);
		return -1;
	}

	// ���ڴ����ɹ����������С�

	// ��ʾ���ڣ�WinMain������nCmdShow���������﷢�����ã�һ�㶼����ΪSW_SHOW
	ShowWindow(hwnd, nCmdShow);

	// ˢ�´��ڣ��򴰿ڷ���һ��WM_PAINT��Ϣ��ʹ�ô��ڽ����ػ档
	UpdateWindow(hwnd);
	while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0
		&& fGotMessage != -1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
