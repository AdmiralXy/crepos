// 1_max_array_sum.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int max = 0;
	int x = 0;
	cout << "Write n = ";
	cin >> n;
	int* A = new int[n];
	cout << "Array elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (x + A[i] < 0) {
			x = 0;
		}
		else {
			x += A[i];
		}
		if (max < x)
			max = x;
	}
	cout << max << endl;
    return 0;
}
