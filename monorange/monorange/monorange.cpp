#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	bool b;
	int k = 0, f = 0;
	int ybvaet = 1;
	int vozras = 1;
	int A[11] = { 7, 3, 8, 15, 6, 1, 5, 4, 3, 1, 9 };
	for (int i = 0; i < 10; i++)
	{
		if (A[i] < A[i + 1]) {
			b = true;
			ybvaet = 1;
		}
		else if (A[i] > A[i + 1]) {
			b = false;
			vozras = 1;
		}
		if (b) {
			vozras++;
			if (k < vozras)
				k = vozras;
		}
		else {
			ybvaet++;
			if (f < ybvaet)
				f = ybvaet;
		}
	}
	if (k > f)
		cout << "Максимальная длина непрерывного монотонного участка: " << k << endl;
	else
		cout << "Максимальная длина непрерывного монотонного участка: " << f << endl;
	return 0;
}