#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int unique = 0;
	int a = 0, b = 0;
	// ввод массива A[n]
	int n;
	cout << "Введите кол-во элементов массива A[n]: ";
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}
	cout << endl;
	// ввод массива B[m]
	int m;
	cout << "Введите кол-во элементов массива B[m]: ";
	cin >> m;
	int* B = new int[m];
	for (int i = 0; i < m; i++)
	{
		cout << "B[" << i << "]: ";
		cin >> B[i];
	}
	cout << endl;
	system("cls");
	cout << "Ваш массив A[" << n << "] = ";
	//Вывод содержимого массивов
	for (int i = 0; i < n; i++)
		cout << "[" << A[i] << "] ";
	cout << endl;
	cout << "Ваш массив B[" << m << "] = ";
	for (int i = 0; i < m; i++)
		cout << "[" << B[i] << "] ";
	// ------------------------------------------
	cout << endl;
	for (int i = 0; i < n; i++) 
	{
		for (int k = 0; k < m; k++)
		{
			if (A[i] == B[k])
			{
				a = 0;
				break;
			}
			else
			{
				a++;
			}
			if (a == m)
			{
				cout << "Уникальное число - " << A[i] << endl;
				unique++;
				a = 0;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (B[i] == A[k])
			{
				b = 0;
				break;
			}
			else
			{
				b++;
			}
			if (b == n)
			{
				cout << "Уникальное число - " << B[i] << endl;
				unique++;
				b = 0;
			}
		}
	}
	cout << endl;
	cout << "Уникальных чисел: " << unique << endl;
    return 0;
}

