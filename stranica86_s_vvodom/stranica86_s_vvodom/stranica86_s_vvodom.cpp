// zadacha9_variant1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	// Ввод данных
	int size = 256;
	char* str = new char[size]; // текст с заданным размером size
	// Работа с файлом
	cout << "Введите название файла: ";
	string path = "test.txt";
	cin >> path;
	fstream fs;
	fs.open(path, fstream::in || fstream::out || fstream::app);
	if (!fs.is_open())
	{
		cout << "Ошибка чтения файла!";
		return 0;
	}
	else 
		cout << "Файл открыт!";
	fs.getline(str, size);
	int res = 0; // индекс начала наибольшего числа
	int max_size = 0; // максимальное кол-во цифр подряд
	int start_index = -1; // индекс начала для проверки числа
	for (int i = 0; i < 256 && str[i] != '\0'; i++) // перебираем строку, пока не закончится текст или не встретим последнюю строку
	{
		if (isdigit(str[i])) { // isdigit - проверяет является ли символ десятичной цифрой
			if (start_index == -1) start_index = i; // запомнили индекс начала если мы имеем дело с новым числом
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
	cout << "\nВывести результат в файл (введите название): ";
	cin >> path;
	ofstream fout;
	fout.open(path, ios_base::trunc); // ios_base::trunc - если файл существует, то удаляем содержимое
	if (!fout.is_open())
		cout << "Ошибка создания файла!" << endl;
	else
		cout << "Файл успешно сохранён!" << endl;
	for (int i = 0; i < max_size + 1; i++)
		fout << str[i + res];
	cout << "\n";
	fs.close(); // закрываем файл ввода
	fout.close(); // закрываем файл вывода
	delete[] str;
	return 0;
}

