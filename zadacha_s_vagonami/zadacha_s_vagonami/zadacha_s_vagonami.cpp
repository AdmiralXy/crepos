// zadacha_s_vagonami.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void task1() { // задача 1
	int n = 0;
	cout << "Введите количество вагонов N: ";
	cin >> n;
	char *command = new char[n];
	int *VHOD = new int[n];
	int *TUPICK = new int[n];
	int *VIHOD = new int[n];
	cout << "Проверить команду длиной 2N (пример. SSXX): ";
	cin >> command;
	for (int i = 0; i < n; i++)
	{
		VHOD[i] = i + 1;
		TUPICK[i] = 0;
		VIHOD[i] = 0;
	}
	for (int l = 0; l < 2*n; l++) {
		if (command[l] == 'S') {
			int k = 0;
			for (int i = 0; i < n; i++)
			{
				if (VHOD[i] != 0) {
					k = i;
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (TUPICK[i] == 0) {
					TUPICK[i] = VHOD[k];
					VHOD[k] = 0;
					i = n;
				}
			}
		}
		if (command[l] == 'X') {
			int k = 0;
			for (int i = 0; i < n; i++)
			{
				if (VIHOD[i] == 0) {
					k = i;
				}
			}
			for (int i = n - 1; i >= 0; i--)
			{
				if (TUPICK[i] != 0) {
					VIHOD[k] = TUPICK[i];
					TUPICK[i] = 0;
					i = -1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (VIHOD[i] == 0) {
			cout << "Команда не работает!" << endl;
			return;
		}
		if (i == n - 1 && VIHOD[i] != 0) {
			cout << "Команда работает!" << endl;
			return;
		}
	}
}

void task2() { // задача 2
	int n = 0;
	cout << "Введите количество вагонов N: ";
	cin >> n;
	char *command = new char[n];
	char *result = new char[2*n]; // результат
	int *VHOD = new int[n];
	int *TUPICK = new int[n];
	int *VIHOD = new int[n];
	cout << "Введите желаемый порядок на выходе [N чисел] (пример. 123): ";
	cin >> command;
	for (int i = 0; i < n; i++)
	{
		VHOD[i] = i + 1;
		TUPICK[i] = 0;
		VIHOD[i] = 0;
	}
	int k = 0;
	for (int l = 0; l < n; l++) {
		for (int p = 0; p < n; p++)
		{
			int r = 0;
			for (int i = 0; i < n; i++)
			{
				if (VHOD[i] != 0) {
					r = i;
					i = n;
				}
			}
			for (int i = 0; i < n && VHOD[n-1] != 0; i++)
			{
				if (TUPICK[i] == 0) {
					TUPICK[i] = VHOD[r];
					cout << "S";
					VHOD[r] = 0;
					i = n;
				}
			}
			for (int j = n - 1; j >= 0; j--)
			{
				if (TUPICK[j] != 0) {
					k = j;
					j = -1;
				}
			}	
			if  (TUPICK[k] == (command[l] - '0')) {
				VIHOD[l] = TUPICK[k];
				TUPICK[k] = 0;
				cout << "X";
				break;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (VIHOD[i] != (command[i] - '0')) {
			cout << "Неверный порядок!" << endl;
			return;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "");
	int number = 0;
	cout << "Список задач: " << endl;
	cout << "1) Определить является-ли команда выполнимой" << endl;
	cout << "2) Ввести желаемый порядок на выходе" << endl;
	cout << "3) Не сделал" << endl;
	cout << "Введите номер задачи: ";
	cin >> number;
	if (number == 1) {
		task1();
	}
	if (number == 2) {
		task2();
	}
	if (number == 3) {
		return 0;
	}
    return 0;
}

//Имеется ж/д тупик, на входе вагоны пронумерованы от 1 до n
//Работой тупика управляет контроллер, имеющий 2 команды
//Команда S - помещает вагон в тупик, если вагонов нет то ошибка
//Команда X - выталкивает последний вагон из тупика на выход
//
//1) Нам известна n и строка S(длиной 2n), определить является ли команда выполнимой.
//2) Нам известна n и желаемый порядок на выходе(к примеру 123), в качестве результата вывести строку состоящую из S / X, если такой команды нет то 0.
//3) На входе n, посчитать n!возможных перестановок которые дадут правильный результат.