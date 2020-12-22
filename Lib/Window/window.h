#ifndef window_H
#define window_H

#include <windows.h>

struct Point { int x; int y; Point() {}; Point(int x1, int y1) { x = x1, y = y1; } };
class Window
{
public:
	virtual void plot(int, int) = 0;
	virtual void plot(const Point&) = 0;
};

class ConsoleWindow : public Window
{
private:
	HANDLE hConsole;
	int width, height;
public:
	ConsoleWindow(int, int);
	void plot(int, int);
	void plot(const Point&);
	~ConsoleWindow();
};

class GraphicWindow : public Window
{
private:
	HINSTANCE hInst;
public:
	GraphicWindow(HINSTANCE);
	void plot(int, int);
	void plot(const Point&);
	~GraphicWindow();
};

#endif