#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;

void ParallelCalc(int **a, int* vect, int* res, int n, int m) {
	int i, j;
		#pragma omp parallel for private (j)
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				res[i] += a[i][j] * vect[j];
		}
}

void DefaultCalc(int **a, int* vect, int* res, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			res[i] += a[i][j] * vect[j];
	}
}

int main() {
	//srand(time(NULL));
	setlocale(LC_CTYPE, "");
	int n, m;
	clock_t start, end;
	printf("Введите количество строк: ");
	cin >> n;
	printf("\n");
	printf("Введите количество столбцов: ");
	cin >> m;
	printf("\n");
	int **A, *B, *result1, *result2;
	A = new int *[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];

	B = new int[m];
	result1 = new int[m];
	result2 = new int[m];


	//printf("Ваша матрица: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand() % 9 + 1;
			//printf("%d ", A[i][j]);
		}
		//printf("\n");
	}
	printf("\n");

	//printf("Ваш вектор: \n");
	for (int i = 0; i < m; i++) {
		B[i] = rand() % 9 + 1;
		result1[i] = 0;
		result2[i] = 0;
		//printf("%d ", B[i]);
	}
	printf("\n");

	start = clock();
	DefaultCalc(A, B, result1, n, m);
	end = clock();

	double defaultTimer = ((double)end - start) / ((double)CLOCKS_PER_SEC);

	start = clock();
	ParallelCalc(A, B, result2, n, m);
	end = clock();

	double parallelTimer = ((double)end - start) / ((double)CLOCKS_PER_SEC);

	for (int i = 0; i < m; i++)
	{
		if (result1[i] != result2[i]) {
			printf("Результаты вычислений не совпадают! Ошибка.\n");
			return 2;
		}
	}
	printf("Результаты вычислений совпадают!\n\n");

	/*printf("Результат обычного вычисления: \n");
	for (int i = 0; i < m; i++) {
		printf("%d ", result1[i]);
	}
	printf("\n");

	printf("Результат параллельного вычисления: \n");
	for (int i = 0; i < m; i++) {
		printf("%d ", result2[i]);
	}
	printf("\n");*/

	if (defaultTimer < parallelTimer)
		printf("Быстрее сработал последовательный алгоритм, последовательный = %.4f сек., параллельный = %.4f сек.\n", defaultTimer, parallelTimer);
	else
		printf("Быстрее сработал параллельный алгоритм, параллельный = %.4f сек., последовательный = %.4f сек.\n", parallelTimer, defaultTimer);

		

	for (int i = 0; i < n; i++)
		delete[] A[i];
		
	delete[] A;
	delete[] B;
	delete[] result1;
	delete[] result2;
}