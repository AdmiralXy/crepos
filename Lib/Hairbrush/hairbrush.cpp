#include "hairbrush.h"
#include <iostream>
using namespace std;

// hairbrush.cpp: файл, содержащий определения методов класса Hairbrush

Hairbrush::Hairbrush() // конструктор по умолчанию
{
	width = 0;
	height = 0;
	teethsNumber = 0;
	space = 0;
	heightOfHandle = 0;
}

Hairbrush::Hairbrush(const Hairbrush &h) // конструктор копирования
{
	width = h.width; // длина расчёстки
	height = h.height; // высота расчёстки
	teethsHeight = h.teethsHeight; // высота зубьев
	teethsNumber = h.teethsNumber; // количество зубьев
	space = h.space; // расстояние между зубьями
	heightOfHandle = h.heightOfHandle; // высота ручки
}

Hairbrush::~Hairbrush() // деструктор
{

}

void Hairbrush::calculate() // расчёт параметров
{
	height = teethsHeight + heightOfHandle;
	space = width / teethsNumber;
}

// инициализация параметров модели расчёстки
int Hairbrush::initialize(int w, int teethsH, int teethsN, int handleH) // параметры: ширина | высота зубьев | количество зубьев | высота ручки
{
	width = w;
	teethsHeight = teethsH;
	teethsNumber = teethsN;
	heightOfHandle = handleH;
	calculate();
	return 0;
}

void Hairbrush::resize(int w) // изменение ширины
{
	width = w;
	calculate();
}

void Hairbrush::setTeethsHeight(int n) // изменение высоты зубьев
{
	teethsHeight = n;
	calculate();
}

void Hairbrush::setTeethsNumber(int n) // изменение количества зубьев
{
	teethsNumber = n;
	calculate();
}

void Hairbrush::setHeightHandle(int n) // изменение высоты ручки
{
	heightOfHandle = n;
	calculate();
}

void Hairbrush::print() // вывод параметов на экран
{
	cout << "Width: " << width << " cm." << endl; // длина расчёстки
	cout << "Height: " << height << " cm." << endl; // высота расчёстки
	cout << "Height of Handle: " << heightOfHandle << " cm." << endl; // высота ручки
	cout << "Height of Teeths: " << teethsHeight << " cm." << endl; // высота зубьев
	cout << "Number of Teeths: " << teethsNumber << " cm." << endl; // количество зубьев
	cout << "Space between teeths: " << space << " cm." << endl; // расстояние между зубьями
}