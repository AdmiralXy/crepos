// SWDR_n3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;
#include "../../Lib/Shape/shape.h"

int main()
{
	ConsoleWindow S(100, 20);

	//Point i(3, 5);
	//Point j(1, 2);

	//Line G(i, j);
	//G.draw(&S);

	Point a(2, 2);
	Point b(6, 6);

	Triangle Triangle1(Point(5, 1), Point(3, 5), Point(7, 5));
	Triangle1.draw(&S);

	Triangle Triangle2(Point(5, 7), Point(10, 10), Point(1, 10));
	Triangle2.draw(&S);

	//Triangle Triangle3(Point(5, 8), Point(3, 3), Point(7, 3));
	//Triangle3.draw(&S);


	/*Circle B(center, 3);
	B.draw(&S);*/
	/*Square R(10, j);
	R.draw(&S);*/
	
	//Ellipse_shape O(a, b);
	//O.draw(&S);
    return 0;
}

