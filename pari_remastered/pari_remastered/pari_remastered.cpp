#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int x = 0, y = 0, f = 0, n;
	cout << "Введите натуральное число n: " << endl;
	cin >> n;
	while (x*x + y * y < n)
	{
		for (; x*x + y * y < n; y++)
		{
			f++;
		}
		y = 0;
		x++;
	}
	cout << "Количество пар (x; y): " << f << endl;
	return 0;
}