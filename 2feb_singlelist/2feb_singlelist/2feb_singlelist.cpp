// 2feb_singlelist.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <..\..\..\..\..\..\Users\Danil\Desktop\Lib\SingleList\singlelist.h>

using namespace std;

int main()
{
	Single_list l;
	for (int i = 0; i < 5; i++)
	{
		l.push_front(i);
		l.print();
	}
	l.clear();
	l.print();
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.front() = 101;
	l.print();
	return 0;
}

