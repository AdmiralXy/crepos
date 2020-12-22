#include <iostream>
using namespace std;

class Hairbrush // определение класса расчёстки, все числа в сантиметрах
{
private:
	double width; // длина расчёстки
	double height; // высота расчёстки
	int teethsHeight; // высота зубьев
	int teethsNumber; // количество зубьев
	double space; // расстояние между зубьями
	int heightOfHandle; // высота ручки
	void calculate(); // расчёт параметров
public:
	Hairbrush(); // конструктор по умолчанию
	Hairbrush(const Hairbrush &); // конструктор копирования
	~Hairbrush(); // деструктор
	int initialize(int, int, int, int); // инициализация параметров модели расчёстки
	void resize(int w); // изменение ширины
	void setTeethsHeight(int n); // изменение высоты зубьев
	void setTeethsNumber(int n); // изменение количества зубьев
	void setHeightHandle(int n); // изменение высоты ручки
	void print();
};

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

int main()
{
	Hairbrush h;
	h.initialize(50, 20, 6, 10);
	h.print(); cout << endl;
	h.resize(60);
	h.print(); cout << endl;
	h.setTeethsHeight(60);
	h.print(); cout << endl;
	h.setTeethsNumber(12);
	h.print(); cout << endl;
	h.setHeightHandle(10);
	h.print(); cout << endl;
	Hairbrush p(h);
	p.print(); cout << endl;
	return 0;
}