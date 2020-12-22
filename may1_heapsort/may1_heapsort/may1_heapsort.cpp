// may1_heapsort.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "../../Lib/HeapSort/heapsort.h"

using namespace std;

void print(int *A, int n)
{
	cout << "Array[" << n << "] = {";
	for (int i = 0; i < n - 1; i++)
	{
		cout << A[i] << ", ";
	}
	cout << A[n - 1] << "}" << endl;
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "Количество элементов: ";
	cin >> n; 
	cout << endl;
	int *A = new int[n];
	cout << "A: ";
	for (int i = 0; i < n; i++)
	cin >> A[i];
	cout << endl;

	heap_sort(A, n);
	print(A, n);

	delete[] A;
    return 0;
}

