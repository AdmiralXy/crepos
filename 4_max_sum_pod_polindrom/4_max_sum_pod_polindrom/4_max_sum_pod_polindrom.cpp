// 2_max_vozr_podposled.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Пример: 14    acgtgtcaaaatcg
// Ответ : 8 (ctaaaatc || gtaaaatg)

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	cout << "Write n = ";
	cin >> n;
	char* str2 = new char[n];
	cout << "Write Elements = ";
	for (int i = 0; i < n; i++)
	{
		cin >> str2[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << str2[i];
	}
	cout << endl;
	return 0;
}