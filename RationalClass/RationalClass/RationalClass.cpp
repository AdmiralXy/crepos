// RationalClass.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "..\..\Lib\Rational\rational.h"

using namespace std;

int main()
{
	Rational a = Rational(5, 6);
	Rational b = 3;
	Rational c = a + 2;
	Rational d = 2 + b;
	Rational e = -b - c;
	Rational f = c * 2 * c;
	cout << c << endl << d << endl << e << endl << f << endl;
	Rational k(4, 6);
	k += a;
	cout << k << endl;
	return 0;
}
