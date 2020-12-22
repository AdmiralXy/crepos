// zad2_var3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

// Задание:
// Дан массив из N элементов.
// Сформировать массив, отсортированный по убыванию и состоящий из элементов больших заданного числа k.

void ArrayOut(int x[], int k) {
	for (int i = 0; i < k; i++)
	{
		cout << x[i] << " ";
	}
}

void ArrayIn(int x[], int k) {
	for (int i = 0; i < k; i++)
	{
		cin >> x[i];
	}
}

void SelectionSortWithKey(int x[], int n) {
	int i, j, max, temp;
	for (i = 0; i < n - 1; i++) {
		//устанавливаем начальное значение минимального индекса
		max = i;
		//находим максимальный индекс элемента
		for (j = i + 1; j<n; j++) {
			if (x[j] > x[max])
				max = j;
			//меняем значения местами
		}
		temp = x[i];
		x[i] = x[max];
		x[max] = temp;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Razmer massiva: ";
	cin >> n;
	cout << "Elementi massiva: ";
	int* X = new int[n];
	int k;
	int count_k = 0; // кол-во элементов больших заданного числа k
	ArrayIn(X, n);
	cout << "k: ";
	cin >> k;
	for (int i = 0; i < n; i++) { // ищем кол-во чисел больших заданного числа k
		if (X[i] > k)
			count_k++;
	}
	int* Y = new int[count_k]; // новый массив, состоящий из элементов больших заданного числа k
	int j = 0; // счётчик для переноса в новый массив
	for (int i = 0; i < n; i++)
	{
		if (X[i] > k)
			Y[j++] = X[i];
	}
	SelectionSortWithKey(Y, count_k);
	ArrayOut(Y, count_k);
	delete[] X;
	delete[] Y;
    return 0;
}