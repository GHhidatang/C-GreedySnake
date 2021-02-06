#include <stdio.h>
#include <graphics.h>
#include <mmsystem.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib")

#include "struct.h"

Snake snake;
Food food;

void gameinit()
{
	mciSendString(L"open E:\\C\\vsProject\\C_GreedySnake\\aaa.mp3", NULL, 0, NULL);
	mciSendString(L"play E:\\C\\vsProject\\C_GreedySnake\\aaa.mp3", NULL, 0, NULL);

	snake.n = 3;
	snake.dir = right;
	snake.szb[0].x = 20;
	snake.szb[0].y = 0;
	snake.szb[1].x = 10;
	snake.szb[1].y = 0;
	snake.szb[2].x = 0;
	snake.szb[2].y = 0;

	food.flag = 1;
}

void gamedraw()
{
	BeginBatchDraw();
	cleardevice();

	for (int i = 0; i < snake.n; i++)
	{
		rectangle(snake.szb[i].x, snake.szb[i].y, snake.szb[i].x + 10, snake.szb[i].y + 10);

	}

	if (food.flag == 0)
	{
		rectangle(food.x, food.y, food.x + 10, food.y + 10);
	}

	EndBatchDraw();
}

void gamelogic()
{
	for (int i = snake.n - 1; i > 0; i--)
	{
		snake.szb[i].x = snake.szb[i - 1].x;
		snake.szb[i].y = snake.szb[i - 1].y;

	}

	switch (snake.dir)
	{
	case up:
		snake.szb[0].y -= 10;
		break;
	case down:
		snake.szb[0].y += 10;
		break;
	case left:
		snake.szb[0].x -= 10;
		break;
	case right:
		snake.szb[0].x += 10;
		break;
	}

	if (snake.szb[0].x == -10)
	{
		snake.szb[0].x = 630;
	}
	else if (snake.szb[0].x == 640)
	{
		snake.szb[0].x = 0;
	}

	if (snake.szb[0].y == -10)
	{
		snake.szb[0].y = 470;
	}
	else if (snake.szb[0].y == 480)
	{
		snake.szb[0].y = 0;
	}
}

void cretaefood()
{
	if (food.flag == 1)
	{
		food.x = rand() % 64 * 10;
		food.y = rand() % 48 * 10;
		food.flag = 0;
	}
}

void gamecontrol()
{
	char key;
	key = _getch();
	switch (key)
	{
	case up:
		if (snake.dir != down);
		snake.dir = up;
		break;
	case down:
		if (snake.dir != up);
		snake.dir = down;
		break;
	case left:
		if (snake.dir != right);
		snake.dir = left;
		break;
	case right:
		if (snake.dir != left);
		snake.dir = right;
		break;
	}
}

void eatfood()
{
	if (snake.szb[0].x == food.x && snake.szb[0].y == food.y)
	{
		food.flag = 1;
		snake.n++;
	}
}

int main()
{
	initgraph(640, 480);

	gameinit();

	while (1)
	{
		gamelogic();
		gamedraw();
		cretaefood();
		eatfood();

		if (_kbhit())
			gamecontrol();

		Sleep(200);
	}

	system("pause");
	return  0;
}
