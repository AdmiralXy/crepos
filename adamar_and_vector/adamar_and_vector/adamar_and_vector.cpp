// adamar_and_vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int number;

void hadamard_and_vector(int **a, int n) {
	int **hadamard = new int*[n];
	for (int i = 0; i < n; i++)
		hadamard[i] = new int[n];
	int l = 0; // 1 четверть
	for (int i = 0; i < n / 2; i++) {
		int r = 0;
		for (int j = 0; j < n / 2; j++) {
			hadamard[i][j] = a[l][r];
			r++;
		}
		l++;
	}
	l = 0; // 2 четверть
	for (int i = 0; i < n / 2; i++) {
		int r = 0;
		for (int j = n / 2; j < n; j++) {
			hadamard[i][j] = a[l][r];
			r++;
		}
		l++;
	}
	l = 0; // 3 четверть
	for (int i = n / 2; i < n; i++) {
		int r = 0;
		for (int j = 0; j < n / 2; j++) {
			hadamard[i][j] = a[l][r];
			r++;
		}
		l++;
	}
	l = 0; // 4 четверть
	for (int i = n / 2; i < n; i++) {
		int r = 0;
		for (int j = n / 2; j < n; j++) {
			hadamard[i][j] = a[l][r] * -1;
			r++;
		}
		l++;
	}
	if (n == number) {
		cout << "Hadamard Matrix " << n << "x" << n << endl;
		for (int i = 0; i < n; i++) { // вывод матрицы Адамара
			for (int j = 0; j < n; j++) {
				cout << hadamard[i][j] << "\t";
			}
			cout << endl;
		}
		int *vector = new int[n];
		cout << "VECTOR " << n << "x" << n << " = ";
		for (int i = 0; i < n; i++) {
			cin >> vector[i];
		}
		int *answer = new int[n];
		for (int i = 0; i < n; i++) { // умножаем матрицу на вектор
			int b = 0;
			for (int j = 0; j < n; j++) {
				b += hadamard[i][j] * vector[j];
			}
			answer[i] = b;
		}
		cout << "Answer: ";
		for (int i = 0; i < n; i++) {
			cout << answer[i] << " ";
		}
		cout << endl;
	}
	else {
		hadamard_and_vector(hadamard, n * 2);
	}
	for (int i = 0; i < n; i++)
		delete[] hadamard[i];
	delete[] hadamard;
}

int main()
{
	int n = 0;
	cout << "Write Matrix Hk, k = ";
	cin >> n;
	number = pow(2, n);
	cout << endl;
	int **pattern = new int*[1];
	pattern[0] = new int[1];
	pattern[0][0] = -1;
	hadamard_and_vector(pattern, 1);
	delete[] pattern[0];
	delete[] pattern;
    return 0;
}
