// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	int count = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2) {
			count++;
		}
	}
    return 0;
}

