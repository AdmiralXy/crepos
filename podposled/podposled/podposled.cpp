// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	// ввод массива A[n]
	int n;
	cout << "Введите кол-во элементов массива A[n]: ";
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}
	cout << endl;
	bool b = true;
	while (b) {
		int k = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				k++;
			}
		}
		if (k == 0)
			b = false;
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}