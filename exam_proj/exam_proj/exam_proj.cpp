// 3feb_Doublelist.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct Matrix
{
	int** A;
	int n;
	int m;
	Matrix(int na, int ma)
	{
		n = na;
		m = ma;
		A = new int*[n];
		for (int i = 0; i < m; i++)
			A[i] = new int[m];
	}
	Matrix(const Matrix& old_obj)
	{
		std::cout << "Конструктор копирования" << std::endl;
		n = old_obj.n;
		m = old_obj.m;
		A = new int*[n];
		for (int i = 0; i < m; i++)
			A[i] = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = old_obj.A[i][j];
	}
	Matrix& operator=(const Matrix & klass)
	{
		delete[] A;
		n = klass.n;
		m = klass.m;
		A = new int*[n];
		for (int i = 0; i < m; i++)
			A[i] = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = klass.A[i][j];
	}
	~Matrix()
	{
		delete[] A;
	}
	friend istream& operator>>(istream& in, Matrix& f);
	friend ostream& operator<<(ostream& out, const Matrix& f);
	friend Matrix operator+(const Matrix& A, const Matrix& B);
};

istream& operator>>(istream& is, Matrix& A)
{
	for (int i = 0; i < A.n; ++i)
	{
		for (int j = 0; j < A.m; ++j)
		{
			is >> A.A[i][j];
		}
	}
	return is;
}

ostream& operator<<(ostream& is, const Matrix& A)
{
	for (int i(0); i < A.n; ++i)
	{
		for (int j(0); j < A.m; ++j)
		{
			is << A.A[i][j] << " ";
		}
		cout << endl;
	}
	return is;
}

Matrix operator+(const Matrix& A, const Matrix& B)
{
	Matrix C(A.n, A.m);
	for (int i = 0; i < A.n; i++)
	{
		for (int j = 0; j < A.m; j++)
		{
			C.A[i][j] = A.A[i][j] + B.A[i][j];
		}
	}
	return C;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix A(2, 2);
	Matrix B(2, 2);
	cin >> A;
	cin >> B;
	cout << A + B;
	return 0;
}