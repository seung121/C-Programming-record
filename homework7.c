#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)

int Score = 0;
int width = 58;
int length = 20;
double speed = 0.5;
int count = 0;
int GetKey(void);
double GetElapsedTime(clock_t initial_clock);
void GotoXY(int x, int y);
void Erase(int x, int y);    // (x, y)로 이동하여 공백 문자 출력
void Draw(int x, int y);     // (x, y)로 이동하여 ‘*’ 문자 출력

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

typedef struct Point
{
	int x;
	int y;
} Point;

void initScreen(void);

int GetKey(void)
{
	int ch = _getch();
	if (ch == 0 || ch == 224)
		ch = 256 + _getch();
	return ch;
}

double GetElapsedTime(clock_t initial_clock)
{
	clock_t current_clock = clock();
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

void SetCursorVisible(int visible)
{
	CONSOLE_CURSOR_INFO ci = { 100, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

void DrawFood(int fx, int fy)
{
	GotoXY(fx, fy);
	printf("$");
}

void DrawTrap(int tx, int ty)
{
	GotoXY(tx, ty);
	printf("#");
}

void initScreen(void)
{


	printf("# : Trap     $ : Food\n");
	printf("┌");
	for (int i = 0; i < width; i++)
		printf("─");
	printf("┐\n");
	for (int j = 0; j < length; j++)
	{
		printf("│");
		for (int i = 0; i < (width / 2); i++)
			printf("  ");
		printf("│\n");
	}
	printf("└");
	for (int i = 0; i < 58; i++)
		printf("─");
	printf("┘\n\n");

	GotoXY(0, 25);
	printf(">>> Score : 0\n");


}

void ScoreSet()
{
	Score += 1000;
	GotoXY(0, 25);
	printf(">>> Score : %d\n", Score);
}

int main(void)
{
	system("mode con cols=70 lines=30");
	int Gamesign = 1;
	SetCursorVisible(0);
	Point food[5];
	Point trap[5];
	int sign[5] = { 0 };
	initScreen();


	int direction = DOWN;
	srand(time(NULL));
	Point snake = { rand() % (width - 2) + 3 , rand() % (length - 2) + 3 };
	for (int i = 0; i < 5; i++)
	{
		food[i].x = rand() % (width - 2) + 3;
		food[i].y = rand() % (length - 3) + 3;
		DrawFood(food[i].x, food[i].y);
	}
	for (int i = 0; i < 5; i++)
	{
		trap[i].x = rand() % (width - 2) + 3;
		trap[i].y = rand() % (length - 3) + 3;
		DrawTrap(trap[i].x, trap[i].y);
	}
	Draw(snake.x, snake.y);
	clock_t initial_clock = clock();

	while (Gamesign)
	{
		for (int i = 0; i < 5; i++)
		{
			if (snake.x == food[i].x && snake.y == food[i].y && sign[i] != 1)
			{
				ScoreSet();
				speed -= 0.1;
				count += 1;
				sign[i] = 1;
				if (Score == 5000)
				{
					GotoXY(0, 27);
					printf("Game Clear!\n\n");
					return 0;
					//Gamesign = 0;
					
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			if (snake.x == trap[i].x && snake.y == trap[i].y)
			{
				GotoXY(snake.x, snake.y);
				printf("※");
				GotoXY(0, 27);
				printf("Game Over!\n\n");
				return 0;
				//Gamesign = 0;
				
			}
		}

		if (GetElapsedTime(initial_clock) > speed)
		{   // 0.5초 경과
			Erase(snake.x, snake.y);
			if (direction == LEFT)
				snake.x--;
			else if (direction == RIGHT)
				snake.x++;
			else if (direction == UP)
				snake.y--;
			else if (direction == DOWN)
				snake.y++;
			Draw(snake.x, snake.y);
			if (snake.y == length + 2 || snake.x == width + 1 || snake.y == 1 || snake.x == 1)
			{
				GotoXY(0, 27);
				printf("Game Over!\n\n");
				return 0;
				//Gamesign = 0;


			}
			initial_clock = clock();  // 기준 시각 재설정
		}
		if (_kbhit())
		{
			int key = GetKey();
			if (key == KEY_LEFT)
				direction = LEFT;
			else if (key == KEY_RIGHT)
				direction = RIGHT;
			else if (key == KEY_UP)
				direction = UP;
			else if (key == KEY_DOWN)
				direction = DOWN;
		}


	}
}