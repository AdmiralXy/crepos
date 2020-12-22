#ifndef shape_H
#define shape_H

#include "../Window/window.h"

class Shape
{
public:
	virtual void draw(Window*) = 0;
};

class Dot : public Shape
{
private:
	Point coords;
public:
	Dot(Point);
	void draw(Window*);
};

class Line : public Shape
{
private:
	Point start;
	Point end;
public:
	Line(Point, Point);
	void draw(Window*);
};

class Rectangle_shape : public Shape
{
private:
	Point top_left;
	Point bottom_right;
public:
	Rectangle_shape(Point, Point);
	void draw(Window*);
};

class Ellipse_shape : public Shape
{
private:
	Point top_left;
	Point bottom_right;
public:
	Ellipse_shape(Point, Point);
	void draw(Window*);
};

class Square : public Rectangle_shape
{
public:
	Square(Point start, int width) : Rectangle_shape(start, Point(start.x + width, start.y + width)) {};
};

class Triangle : public Shape
{
private:
	Point A;
	Point B;
	Point C;
public:
	Triangle(Point, Point, Point);
	void draw(Window*);
};

class Circle : public Ellipse_shape
{
public:
	Circle(Point c, int r) : Ellipse_shape(Point(c.x - r, c.y - r), Point(c.x + r, c.y + r)) {};
};

#endif