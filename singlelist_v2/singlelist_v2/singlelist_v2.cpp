// Singlelist.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "../../Lib/SingleList/singlelist.h"

using namespace std;


int main()
{
	Single_list l(7);
	l.push_front(5);
	l.push_front(3);
	l.push_front(1);
	Single_list f = l;
	f = l;
	f.print();
    return 0;
}

