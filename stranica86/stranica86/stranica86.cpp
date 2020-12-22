// zadacha9_variant1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <iomanip>
#include <windows.h>

#include "ConvOem.h"

using namespace std;

int main()
{
	CConvOem szBuff(100);
	if (szBuff.isInvalid()) return -1;

	// Ввод данных
	int size = 256;
	char* str = new char[size]; // текст с заданным размером size
	cout << szBuff.toOemA("Введите текст (макс. размер 256): "); // пример: "Abc37 ksqm354 i4nc2hls35222 1111kk", ответ: 35222;
	cin.getline(str, size);

	int res = 0; // индекс начала наибольшего числа
	int max_size = 0; // максимальное кол-во цифр подряд
	int start_index = -1; // индекс начала для проверки числа
	for (int i = 0; i < 256 && (str[i - 1] && str[i]) != '\0'; i++) // перебираем строку, пока не закончится текст
	{
		if (isdigit(str[i])) { // isdigit - проверяет является ли параметр десятичной цифрой
			if (start_index == -1) start_index = i; // запомнили начало если мы имеем дело с новым числом
			if (!isdigit(str[i + 1])) { // если следующий символ это не цифра, то это конец числа
				if (i - start_index > max_size) { // текущий индекс минус начальный индекс = размер текущего числа, если оно больше максимально найденого
					res = start_index; // то назначаем новый индекс начала для максимального числа
					max_size = i - start_index; // и обновляем размер максимально найденного число
				}
			}
		}
		else start_index = -1; // сбрасываем до стандартного значения -1, для поиска нового числа
	}


	// Вывод результата
	cout << fixed;
	cout << szBuff.toOemA("\nРезультат: ");
	for (int i = 0; i < max_size + 1; i++) 
		cout << setprecision(3) << str[i + res];
	cout << ".\n\n";
	delete[] str;
	return 0;
}

