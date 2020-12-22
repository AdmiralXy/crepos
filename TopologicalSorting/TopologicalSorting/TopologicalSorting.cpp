// TopologicalSorting.cpp: определяет точку входа для консольного приложения.
//

#include "../../Lib/TopologicalSort/topologicalsort.h"


int main()
{
	const int N = 13;
	int V[N]{ 1, 2, 4, 2, 4, 6, 3, 5, 7, 7, 9, 9, 1 };
	int W[N]{ 2, 4, 6, 10, 8, 3, 5, 8, 9, 5, 10, 4, 3 };
	topological_sort(V, W, N);
    return 0;
}

