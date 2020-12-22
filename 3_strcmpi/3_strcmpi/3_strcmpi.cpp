// 3_strcmpi.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

// abc abf

using namespace std;

char toLowReg(char *str) {
	int number = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] >= 'A' && str[i] <= 'Z') {
			number = str[i] - 'A';
			str[i] = 'a' + number;
			number = 0;
		}
	return *str;
}

int strcmpi(char* a, char* b)
{
	toLowReg(a);
	toLowReg(b);
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	if (*a > *b)
		return 1;
	if (*a < *b)
		return -1;
	return 0;
}

int main() {
	cout << "1 char: ";
	char string1[100];
	cin >> string1;
	cout << "2 char: ";
	char string2[100];
	cin >> string2;
	cout << strcmpi(string1, string2) << endl;
	return(0);
}

