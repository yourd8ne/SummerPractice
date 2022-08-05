#include <iostream>
#include <windows.h>
#include <conio.h> // kbhit
using namespace std;

bool gameover;
const int heigh = 20;
const int width = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100], ntail;// координаты хвоста, количество хвостов
enum eDirection { stop = 0, UP, LEFT, DOWN, RIGHT};
eDirection dir;

void set()
{
	gameover = false;
	dir = stop;
	x = width / 2 - 1;
	y = heigh / 2 - 1;
	fruitX = rand() % (width - 2);
	fruitY = rand() % (heigh - 2);
	score = 0;
}

void draw()
{
	
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;

		for (int i = 0; i < heigh - 2; i++)
		{
		for (int j = 0; j < width - 1; j++)
		{
			if (j == 0 || j == width - 2)
				cout << "#";
			
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}


	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
}

void input()
{
	if (_kbhit())// возвращает 1 если произошло нажати клавиши
	{
		switch (_getch()) // getch на какую именно клавишу
		{
		case 'w':
			if(dir!= DOWN)
				dir = UP;
			break;
		case 'a':
			if(dir!= RIGHT)
				dir = LEFT;
			break;
		case 's':
			if(dir!= UP)
				dir = DOWN;
			break;
		case 'd':
			if(dir!=LEFT)
				dir = RIGHT;
			break;
		case 'x':
			gameover = true;
		}
	}
}

void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	
	case UP:
		y--;
		break;
	case LEFT:
		x--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	
	}
	/*if (x > width || x < 0 || y >= heigh || y < -1)
		gameover = true;*/
	if (x >= width - 2)
		x = 0;
	else if (x < 0)
		x = width - 3;
	if (y >= heigh)
		y = 0;
	else if (y < 0)
		y = heigh - 1;
	for (int i = 0; i < ntail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % (width - 2);
		fruitY = rand() % (heigh - 2);
		ntail++;
	}
}

int main()
{
	set();
	while (!gameover)
	{	
		system("cls");
		draw();
		input();
		logic();
		Sleep(100);
	}
}
