// vse_vozrast.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0, k = 0;
	const int j = 100;
	int A[j];
	int B[j];
	cout << "Введите число n [1,2 ... n]" << endl;
	cin >> n;
	cout << "Введите число k [длина]" << endl;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		A[i] = 1;
	}
	for (int i = 0; i < n - k + s; i++)
	{
		B[i] = n;
	}
    return 0;
}

