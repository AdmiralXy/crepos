// 2_max_vozr_podposled.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

// 5 3 7 4 8 6 2 5 7 1 - 4
// 4 1 9 3 5 2 4 8 6 10 - 5
// 1 1 1 1 1 1 1 1 1 1

//printf("%d ", A[p]);


int maxArraySub(int *A, int *SubArray, int n) {
	int max = 0;
	int iterations = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			iterations++;
			if (A[i] > A[j] && SubArray[i] <= SubArray[j])
					SubArray[i]++;
			for (int p = 0; p < n; p++)
			{
				if (i == p) {
					SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << A[p] << " ";
				}
				else if (j == p) {
					SetConsoleTextAttribute(hwnd, FOREGROUND_RED);
					cout << A[p] << " ";
				}
				else {
					SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << A[p] << " ";
				}
			}
			cout << endl;
			for (int p = 0; p < n; p++)
			{
				SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << SubArray[p] << " ";
			}
			cout << endl;
		}
		if (SubArray[i] > max)
			max = SubArray[i];
	}
	cout << "Counts of interations: " << iterations << endl;
	return max;
}

int main()
{
	SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int n = 0;
	cout << "Write n = ";
	cin >> n;
	int* A = new int[n];
	int* SubArray = new int[n];
	cout << "Array elements: ";
	for (int i = 0; i < n; i++)
	{
		SubArray[i] = 1;
		cin >> A[i];
	}
	cout << endl;
	cout << maxArraySub(A, SubArray, n) << endl;
	delete[] A;
	delete[] SubArray;
	system("pause");
    return 0;
}