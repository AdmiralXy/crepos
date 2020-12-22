#include "hairbrush.h"
#include <iostream>
using namespace std;

// hairbrush.cpp: ����, ���������� ����������� ������� ������ Hairbrush

Hairbrush::Hairbrush() // ����������� �� ���������
{
	width = 0;
	height = 0;
	teethsNumber = 0;
	space = 0;
	heightOfHandle = 0;
}

Hairbrush::Hairbrush(const Hairbrush &h) // ����������� �����������
{
	width = h.width; // ����� ���������
	height = h.height; // ������ ���������
	teethsHeight = h.teethsHeight; // ������ ������
	teethsNumber = h.teethsNumber; // ���������� ������
	space = h.space; // ���������� ����� �������
	heightOfHandle = h.heightOfHandle; // ������ �����
}

Hairbrush::~Hairbrush() // ����������
{

}

void Hairbrush::calculate() // ������ ����������
{
	height = teethsHeight + heightOfHandle;
	space = width / teethsNumber;
}

// ������������� ���������� ������ ���������
int Hairbrush::initialize(int w, int teethsH, int teethsN, int handleH) // ���������: ������ | ������ ������ | ���������� ������ | ������ �����
{
	width = w;
	teethsHeight = teethsH;
	teethsNumber = teethsN;
	heightOfHandle = handleH;
	calculate();
	return 0;
}

void Hairbrush::resize(int w) // ��������� ������
{
	width = w;
	calculate();
}

void Hairbrush::setTeethsHeight(int n) // ��������� ������ ������
{
	teethsHeight = n;
	calculate();
}

void Hairbrush::setTeethsNumber(int n) // ��������� ���������� ������
{
	teethsNumber = n;
	calculate();
}

void Hairbrush::setHeightHandle(int n) // ��������� ������ �����
{
	heightOfHandle = n;
	calculate();
}

void Hairbrush::print() // ����� ��������� �� �����
{
	cout << "Width: " << width << " cm." << endl; // ����� ���������
	cout << "Height: " << height << " cm." << endl; // ������ ���������
	cout << "Height of Handle: " << heightOfHandle << " cm." << endl; // ������ �����
	cout << "Height of Teeths: " << teethsHeight << " cm." << endl; // ������ ������
	cout << "Number of Teeths: " << teethsNumber << " cm." << endl; // ���������� ������
	cout << "Space between teeths: " << space << " cm." << endl; // ���������� ����� �������
}