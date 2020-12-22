// naiti_pari_ravnie_t.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n;

void printarray(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void quickSort(int A[], int l, int r) {
	int i = l, j = r;
	int m = A[(l + r) / 2];

	while (i <= j) {
		while (A[i] < m)
			i++;
		while (A[j] > m)
			j--;
		if (i <= j) {
			swap(A[i], A[j]);
			i++;
			j--;
		}
	};

	if (l < j)
		quickSort(A, l, j);
	if (i < r)
		quickSort(A, i, r);

}

void pair_t(int A[], int t) {
	int l = 0;
	int r = n - 1;
	int a = 0;
	while (l < r) {
		if (A[l] + A[r] == t) {
			a++;
			l++;
			r--;
		}
		else {
			if (A[l] + A[r] < t)
				l++;
			else 
				r--;
		}
	}
	cout << "Количество: " << a << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	int i;
	int t;
	cout << "Введите t: ";
	cin >> t;
	cout << "Размер массива: ";
	cin >> n;
	cout << endl;
	int* A = new int[n];
	for (i = 0; i < n; i++) {
		cout << "A[" << i << "]: ";
		cin >> A[i];
		cout << endl;
	}
	printarray(A, n);
	quickSort(A, 0, n - 1);
	printarray(A, n);
	pair_t(A, t);
}