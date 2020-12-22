#include <iostream>
#include "../../Lib/HeapSort/heapsort.h"

using namespace std;

void ArrayToHeap(int *A, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		int j = i;
		bool b = true;
		while (j < n && b)
		{
			int max;
			int left_child = 2 * j + 1;
			int right_child = left_child + 1;
			if (left_child < n && A[left_child] > A[j])
				max = left_child;
			else
				max = j;
			if (right_child < n && A[right_child] > A[max])
				max = right_child;
			if (max != j)
			{
				swap(A[j], A[max]);
				j = max;
			}
			else
				b = false;
		}
	}
}

void heap_sort(int *A, int n)
{
	ArrayToHeap(A, n);

	for (int heap_size = n - 1; heap_size > 0; heap_size--)
	{ 
		swap(A[0], A[heap_size]);
		int root = 0;
		for (int max = 2 * root + 1; max < heap_size; root = max)
		{
			max = (2 * root + 1);
			if (A[max] < A[max + 1] && max + 1 < heap_size)
				max++;
			if (A[root] < A[max] && max < heap_size)
				swap(A[root], A[max]);
		}
	}
}