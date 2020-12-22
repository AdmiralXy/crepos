#ifndef HAIRBRUSH_H
#define HAIRBRUSH_H


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

#endif