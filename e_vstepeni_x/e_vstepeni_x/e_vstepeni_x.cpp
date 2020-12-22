#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	long double e, x, sigma = 0.0, x_stepeni_i = 1.0;
	long long i_factorial = 1, i = 2;
	int y, z = 0;
	cout << "Введите число X для нахождения e^x: " << endl;
	cin >> y;
	if (y < 0) {
		z = y;
		y *= -1;
		x = y;
	}
	else
		x = y;
	sigma = +x;
	do
	{
		i_factorial = 1;
		x_stepeni_i = 1.0;
		for (int xstep = 0; xstep < i; xstep++)
		{
			x_stepeni_i *= x;
		}
		for (long factorial_number = 2; factorial_number <= i; factorial_number++)
		{
			i_factorial *= factorial_number;
		}
		i++;
		sigma += (x_stepeni_i / i_factorial);
	} while (x_stepeni_i / i_factorial > 0);
	e = 1 + sigma;
	if (z < 0)
		e = 1 / e;
	cout << "Значение e^" << x << " ~ " << e << endl;
}