// PolynomialClass.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

#include "../../Lib/Polynomial/polynomial.h"

int main()
{
	const int N = 9;
	const int M = 7;
	int* A = new int[N];
	int* B = new int[M];
	cout << "Polynomial a[" << N << "]:";
	for (int i = N - 1; i >= 0; i--)
		cin >> A[i];
	cout << endl;
	cout << "Polynomial b[" << M << "]:";
	for (int i = M - 1; i >= 0; i--)
		cin >> B[i];
	cout << endl;
	Polynomial a(N, A);
	Polynomial b(M, B);
	cout << a << endl;
	cout << b << endl;
	Polynomial c = a + b;
	cout << "a + b = " << c << endl;
	Polynomial f = a - b;
	cout << "a - b = " << f << endl;
	Polynomial q = a * b;
	cout << "a * b = " << q << endl;
	cout << "a == b : ";
	if (a == b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "a != b : ";
	if (a != b)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "a, b" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << "a += b" << endl;
	a += b;
	cout << "a, b" << endl;
	cout << a << endl;
	cout << b << endl;
	delete[] A;
	delete[] B;
	return 0;
}

