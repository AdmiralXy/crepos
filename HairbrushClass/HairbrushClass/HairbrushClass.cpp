// HairbrushClass.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

#include "../../Lib/Hairbrush/hairbrush.h"

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

