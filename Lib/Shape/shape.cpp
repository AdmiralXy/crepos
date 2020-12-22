#include <iostream>
#include "shape.h"

Dot::Dot(Point t)
{
	coords.x = t.x;
	coords.y = t.y;
}

void Dot::draw(Window* l)
{
	l->plot(coords);
}

Line::Line(Point s, Point e)
{
	start = s;
	end = e;
}

void Line::draw(Window* l)
{
	int kx = 1, ky = 1;
	int a = end.x - start.x, b = end.y - start.y;
		
	//std::cout << a << "  " << b << std::endl;

	if (a < 0) {
		a = -a;
		kx = -kx;
	}

	if (b < 0) {
		b = -b;
		ky = -ky;
	}

	bool oct = false;
	if (a < b) {
		oct = true;
		std::swap(a, b);
		if (end.x - start.x < 0 && -(end.y - start.y) < 0) {
			std::swap(start.x, start.y);
			kx = -kx;
			ky = -ky;
		}
		else if (end.x - start.x < 0 && -(end.y - start.y) > 0) {
			std::swap(start.x, start.y);
		}
	}

	int e = 2 * b - a;
	int eS = 2 * b;
	int eD = 2 * b - 2 * a;
	int x = 0; int y = 0;
	while (x <= a) {
		int dotx = start.x + (x * kx), doty = start.y + (y * ky);
		l->plot(oct ? doty : dotx, oct ? dotx : doty);
		if (e > 0) {
			y++;
			e += eD;
		}
		else {
			e += eS;
		}
		x++;
	}
}

Rectangle_shape::Rectangle_shape(Point tl, Point br)
{
	top_left = tl;
	bottom_right = br;
}

void Rectangle_shape::draw(Window* l)
{
	for (int i = top_left.x; i < bottom_right.x; i++)
	{
		l->plot(i, top_left.y);
		l->plot(i, bottom_right.y);
	}
	for (int i = top_left.y; i <= bottom_right.y; i++)
	{
		l->plot(top_left.x, i);
		l->plot(bottom_right.x, i);
	}
}

Ellipse_shape::Ellipse_shape(Point tl, Point br)
{
	top_left = tl;
	bottom_right = br;
}

void Ellipse_shape::draw(Window* l)
{
	int x = (bottom_right.x + top_left.x) / 2; // центр по x
	int y = (bottom_right.y + top_left.y) / 2; // центр по y
	int a = bottom_right.x - x; // бол
	int b = bottom_right.y - y; // центр по y

	int _x = 0; // Компонента x
	int _y = b; // Компонента y
	int a_sqr = a * a; // 1 полуось
	int b_sqr = b * b; // 2 полуось
					   // Функция координат точки (x+1, y-1/2)
	int delta = 4 * b_sqr * ((_x + 1) * (_x + 1)) + a_sqr * ((2 * _y - 1) * (2 * _y - 1)) - 4 * a_sqr * b_sqr;
	// grad(x, y) = (af/ax, af/ay) = (2b^2*x, 2a^2*y)
	// тангенс угла наклона вектора нормали : t = a2y / b2x
	// b2x = a2y
	// критерий того, что мы переходим ко второй области a^2(2y - 1) <= 2b^2(x + 1)
	while (a_sqr * (2 * _y - 1) > 2 * b_sqr * (_x + 1)) // Первая часть дуги
	{
		l->plot(x + _x, y + _y);
		l->plot(x + _x, y - _y);
		l->plot(x - _x, y - _y);
		l->plot(x - _x, y + _y);
		if (delta < 0) // Переход по горизонтали
		{
			_x++;
			delta += 4 * b_sqr * (2 * _x + 3); // delta(x, y) + 4b^2(2x+3)
		}
		else // Переход по диагонали
		{
			_x++;
			delta = delta - 8 * a_sqr * (_y - 1) + 4 * b_sqr * (2 * _x + 3); // delta(x, y) + 4b^2(2x+3)-8a^2(y-1)
			_y--;
		}
	}

	// Функция координат точки (x+1/2, y-1)
	delta = b_sqr * ((2 * _x + 1) * (2 * _x + 1)) + 4 * a_sqr * ((_y + 1) * (_y + 1)) - 4 * a_sqr * b_sqr;

	while (_y + 1 != 0)
	{
		l->plot(x + _x, y + _y);
		l->plot(x + _x, y - _y);
		l->plot(x - _x, y - _y);
		l->plot(x - _x, y + _y);
		if (delta < 0) // Переход по вертикали
		{
			_y--;
			delta += 4 * a_sqr * (2 * _y + 3);
		}
		else // Переход по диагонали
		{
			_y--;
			delta = delta - 8 * b_sqr * (_x + 1) + 4 * a_sqr * (2 * _y + 3);
			_x++;
		}
	}
}

Triangle::Triangle(Point a, Point b, Point c)
{
	A = a;
	B = b;
	C = c;
}

void Triangle::draw(Window* l)
{
	Line a(A, B);
	Line b(A, C);
	Line c(B, C);
	a.draw(l);
	b.draw(l);
	c.draw(l);
}