#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define N 5

// Utility function to print an given array
void printArray(int A[])
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

// Iteratively sort array A[low..high] using temporary array
void mergesort(int A[], int temp[], int low, int high)
{
	// divide the array into blocks of size m
	// m = [1, 2, 4, 8, 16...]
	for (int m = 1; m <= high - low; m = 2 * m)
	{
		// for m = 1, i = 0, 2, 4, 6, 8
		// for m = 2, i = 0, 4, 8
		// for m = 4, i = 0, 8
		// ...
		for (int i = low; i - low < high - low; i += 2 * m)
		{
			int from = i;
			int mid = i + m - 1;
			int to = i + 2 * m - 1;
			cout << "From: " << A[from] << endl;
			cout << "Mid: " << A[mid] << endl;
			
			if (high - to < 0) // не вышли ли мы за границу
				to = high;
				
			cout << "To: " << A[to] << endl;
			cout << endl;

			// MERGE-------------------------------------------------------------
			int k = from, f = from, j = mid + 1;
			// цикл, пока есть элементы в левой и правой
			while (f - from <= mid - from && j - mid <= to - mid)
			{
				if (A[f] < A[j])
					temp[k++] = A[f++];
				else
					temp[k++] = A[j++];
			}

			// Copy remaining elements
			while (f - from < to - from && f - from <= mid - from)
				temp[k++] = A[f++];
				
			// Don't need to copy second half

			// copy back to the original array to reflect sorted order
			for (int i = from; i - from <= to - from; i++)
				A[i] = temp[i];
				
			// MERGE-------------------------------------------------------------
		}
	}
}



int main()
{
	int A[N], temp[N];
	srand(time(NULL));

	//for (int i = 0; i < N; i++)
	//	temp[i] = A[i] = (rand() % 10);
	temp[0] = A[0] = 3;
	temp[1] = A[1] = 5;
	temp[2] = A[2] = 1;
	temp[3] = A[3] = 7;
	temp[4] = A[4] = 10;

	printf("Original Array : ");
	printArray(A);

	mergesort(A, temp, 0, N - 1);

	printf("Modified Array : ");
	printArray(A);

	return 0;
}