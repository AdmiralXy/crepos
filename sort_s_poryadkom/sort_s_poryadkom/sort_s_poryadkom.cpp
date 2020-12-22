// sort_s_poryadkom.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n = 0;
	int end = 0;
	cout << "Размер массива n: ";
	cin >> n;
	cout << endl;
	int* A = new int[n];
	cout << "Введите " << n << " элементов: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (A[i] % 2 == 0) {
			int b = i;
			while (b > end) {
				swap(A[b], A[b - 1]);
				b--;
			}
			end++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}

