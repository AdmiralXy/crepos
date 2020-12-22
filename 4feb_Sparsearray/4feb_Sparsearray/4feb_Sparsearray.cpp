// 4feb_Sparsearray.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Cell {
	int col;
	int data;
	Cell *right;
};

class Sparse_Array {
private:
	Cell * head;
	int default_value;
public:
	Sparse_Array() // конструктор
	{
		default_value = -1;
		head = new Cell;
		head->col = default_value;
		head->data = NULL;
		head->right = NULL;
	}
	~Sparse_Array() // деструктор
	{

	}
	int& operator[ ](int index) // переопределение операции обращения по индексу
	{
		Cell *NewCell = new Cell;
		Cell *A = head;
		Cell *Prev = head;
		while (A->col < index)
		{
			if (A->right == NULL) {
				NewCell->col = index;
				NewCell->data = default_value;
				NewCell->right = NULL;
				A->right = NewCell;
				return NewCell->data;
			}
			Prev = A;
			A = A->right;
			if (A->col == index)
				return A->data;
		} 
		NewCell->col = index;
		NewCell->data = default_value;
		NewCell->right = A;
		Prev->right = NewCell;
		A->right = NULL;
		return NewCell->data;
	}
	void print() // вывод по возрастанию индексов
	{
		cout << "Try Printing..." << endl;
		Cell *A = head;
		int i = 0;
		// i < 2
		while (A->right != NULL)
		{
			A = A->right;
			i++;
			cout << "[" << A->col << "," << A->data << "]";
		}
	}
};

int main()
{
	Sparse_Array A;
	A[10] = 10;
	A[8] = 8;
	A[2] = 2;
	A[3] = 3;
	A[7] = 7;
	A.print();
    return 0;
}