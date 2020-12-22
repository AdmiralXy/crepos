#include <iostream>
#include "window.h"

ConsoleWindow::ConsoleWindow(int w, int h)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	width = w;
	height = h;
}

void ConsoleWindow::plot(int x, int y)
{
	if (x > width || x < 0 || y > height || y < 0)
		return;
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(hConsole, Pos);
	WriteConsoleA(hConsole, "*", 1, 0, 0);
}

void ConsoleWindow::plot(const Point& t)
{
	if (t.x > width || t.x < 0 || t.y > height || t.y < 0)
		return;
	COORD Pos;
	Pos.X = t.x;
	Pos.Y = t.y;
	SetConsoleCursorPosition(hConsole, Pos);
	WriteConsoleA(hConsole, "*", 1, 0, 0);
}

ConsoleWindow::~ConsoleWindow()
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = height;
	SetConsoleCursorPosition(hConsole, Pos);
	CloseHandle(hConsole);
}

GraphicWindow::GraphicWindow(HINSTANCE hInst)
{

}

void GraphicWindow::plot(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;

}

void GraphicWindow::plot(const Point& t)
{
	COORD Pos;
	Pos.X = t.x;
	Pos.Y = t.y;

}

GraphicWindow::~GraphicWindow()
{
	
}