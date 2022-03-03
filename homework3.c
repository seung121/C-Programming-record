#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define KEY_LEFT (256+75)
#define KEY_UP (256+72)
#define KEY_RIGHT (256+77)
#define KEY_DOWN (256+80)
#define KEY_ESC 27


int GetKey(void);
double GetElapsedTime(clock_t initial_clock, clock_t current_clock);
void GotoXY(int x, int y);
void Erase(int x, int y);    // (x, y)로 이동하여 공백 문자 출력
void Draw(int x, int y);     // (x, y)로 이동하여 ‘*’ 문자 출력

int main(void)
{
	system("mode con cols=70 lines=20");
	srand(time(NULL));

	int x = rand() % 61 + 10;
	int y = rand() % 16 + 5;
	int Direction = 1; // 1 = RIGHT, 2 = LEFT, 3 = UP, 4 = DOWN 
	Draw(x, y);

	clock_t initial_clock = clock();

	while (1)
	{
		clock_t current_clock = clock();
		if (x == 0)
			Direction = 1;
		if (x == 69)
			Direction = 2;
		if (y == 0)
			Direction = 4;
		if (y == 19)
			Direction = 3;

		if (GetElapsedTime(initial_clock, current_clock) > 0.05)
		{   // 0.5초 경과

			switch (Direction)
			{
			case 1:
				Erase(x, y);
				x++;
				Draw(x, y);
				break;

			case 2:
				Erase(x, y);
				x--;
				Draw(x, y);
				break;

			case 3:
				Erase(x, y);
				y--;
				Draw(x, y);
				break;

			case 4:
				Erase(x, y);
				y++;
				Draw(x, y);
				break;
			}
			initial_clock = current_clock;  // 기준 시각 재설정
		}
		if (_kbhit())
		{
			int key = GetKey();

			if (key == KEY_RIGHT)
			{
				Direction = 1;
			}
			else if (key == KEY_LEFT)
			{
				Direction = 2;
			}
			else if (key == KEY_UP)
			{
				Direction = 3;
			}
			else if (key == KEY_DOWN)
			{
				Direction = 4;
			}
			else if (key == KEY_ESC)
				break;
		}
	}
}
int GetKey(void)
{
	int ch = _getch();

	if (ch == 0 || ch == 224)
		// 방향키의 경우 0 또는 224의 값이 먼저 입력됨
		ch = 256 + _getch();
	// 그 다음에 해당 방향키에 따라 72(Up), 
	// 80(Down), 75(Left), 77(Right) 값이 입력됨
	return ch;
}

double GetElapsedTime(clock_t initial_clock, clock_t current_clock)
{
	return (double)(current_clock - initial_clock) / CLOCKS_PER_SEC;
}

void GotoXY(int x, int y)
{
	// COORD 구조체 변수를 통해 이동할 위치 설정
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Erase(int x, int y)
{
	GotoXY(x, y);
	printf(" ");
}

void Draw(int x, int y)
{
	GotoXY(x, y);
	printf("*");
}