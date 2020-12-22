// zad3_var3.cpp: определяет точку входа для консольного приложения.
//

#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cout << "n: ";
	cin >> n;
	cout << "m: ";
	cin >> m;

	// создание динамических массивов, выделение памяти
	int** mat = new int *[n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[m];
	int* maxs = new int[m]; // массив для максимальных элементов столбцов

	// ввод
	cout << "Elements: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	// максимальные элементы столбцов
	for (int j = 0; j < m; j++) {
		maxs[j] = mat[0][j];
		for (int i = 1; i < n; i++) {
			if (mat[i][j] > maxs[j])
				maxs[j] = mat[i][j];
		}
	}

	// сортировка столбцов
	int k;
	for (int i = 0; i < m; i++) {
		k = i;
		for (int j = i + 1; j < m; j++) {
			if (maxs[j] > maxs[k])
				k = j;
		}
		if (i != k) {
			swap(maxs[i], maxs[k]);
			for (int f = 0; f < n; f++)
				swap(mat[f][i], mat[f][k]);
		}
	}

	// вывод
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	// очистка памяти
	delete[] maxs;
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
	return 0;
}
