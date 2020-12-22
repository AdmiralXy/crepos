// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../../Lib/DoubleListTemplate/doublelist.h"
#include "../../Lib/MergesortTemplate/MergesortTemplate.h"

int main()
{
	Double_list<int> l;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		l.push_back(rand() % 20);

	l.print();
	Merge_sort<int>(l.begin(), l.end());
	l.print();
}
