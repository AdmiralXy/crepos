#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	const int k = 2;
	const int n = 3;
	bool b = true;
	int A[n][k];
	int B[n][k];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			A[i][j] = 0;
			B[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			A[0][j] = 1;
			B[i][j] = 1;
		}
	}
	for (int j = 0; j < k; j++) {
		cout << A[0][j];
	}
	cout << endl;
	while (b) {
		for (int i = 0; i < n - 1; i++) {
			if (A[i + 1][k - 1] += B[i][k - 1] <= n) {
				A[i + 1][k - 1] += B[i][k - 1];
			}
			cout << A[i + 1][k - 1];
			b = false;
		}
		return 0;
	}
}