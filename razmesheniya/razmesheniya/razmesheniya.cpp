#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int n = 0 , k = 0, num = 1;
	cout << "k = ";
	cin >> k;
	cout << "n = ";
	cin >> n;
	int* A = new int[k];
	int* B = new int[k];
	for (int i = 0; i < k; i++) {
		A[i] = 1;
		B[i] = 1;
	}
	for (int i = 0; i < k; i++)
		cout << A[i] << " ";
	cout << endl;
	// ------------------------
	for (int a = pow(n, k); num < a;)
	{
		int i = k - 1;
		while (A[i] + B[i] > n || A[i] + B[i] <= 0)
			i--;
		while (A[i] + B[i] <= n && A[i] + B[i] > 0) {
			num++;
			A[i] = A[i] + B[i];
			for (int j = 0; j < k; j++)
				cout << A[j] << " ";
			cout << endl;
			int z = i + 1;
			while (z < k) {
				B[z] = B[z] * -1;
				z++;
				i = k - 1;
			}
		}
	}
    return 0;
}

