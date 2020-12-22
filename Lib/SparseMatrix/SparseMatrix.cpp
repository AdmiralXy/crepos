#include <iostream>
#include "../../Lib/SparseMatrix/SparseMatrix.h"

using namespace std;

Cell::Cell() {};
Cell::Cell(int n_row, int n_col)
{
	row = n_row; col = n_col;
}

Sparse_Matrix::Sparse_Matrix(int rows, int cols, int def) // создает все заголовки
{
	def_value = def;
	n_rows = rows;
	n_cols = cols;
	Cell *A = new Cell(-1, -1);
	head = A;
	for (int i = 0; i<rows; i++)
	{
		Cell *NewCell = new Cell(i, -1);
		A->down = NewCell;
		NewCell->right = NULL;
		NewCell->down = NULL;
		A = NewCell;
	}
	A = head;
	for (int i = 0; i<cols; i++)
	{
		Cell *NewCell = new Cell(-1, i);
		A->right = NewCell;
		NewCell->right = NULL;
		NewCell->down = NULL;
		A = NewCell;
	}
	A = head;
}
int Sparse_Matrix::r_access(int row, int col) const // чтение элемента (если его нет, мы НЕ создаем новый Cell)
{
	Cell *A = head;
	while (A != NULL && A->row < row)s
		A = A->down;
	while (A != NULL && A->col < col)
		A = A->right;
	return A == NULL ? def_value : A->data;
}
int& Sparse_Matrix::w_access(int row, int col)
{
	Cell *A = head;
	while (A != NULL && A->row < row)
		A = A->down;
	while (A->right != NULL && A->right->col < row)
		A = A->right;
	Cell *A1 = head;
	while (A1 != NULL && A1->col < col)
		A1 = A1->right;
	while (A1->down != NULL && A1->down->row < col)
		A1 = A1->down;
	if (A->right != A1->down || A->right == NULL)
	{
		Cell *NewCell = new Cell;
		NewCell->row = row;
		NewCell->col = col;
		NewCell->data = def_value;
		NewCell->right = A->right;
		A->right = NewCell;
		NewCell->down = A1->down;
		A1->down = NewCell;
		return NewCell->data;
	}
	else
		return A->right->data;
}
void Sparse_Matrix::print()
{
	Cell *A = head->down;
	while (A != NULL && A->row < n_rows)
	{
		Cell *NewCell = A;
		if (A->right != NULL)
		{
			NewCell = A->right;
			cout << NewCell->row << ":";
			while (NewCell != NULL)
			{
				cout << "[(" << NewCell->row << "," << NewCell->col << ")" << NewCell->data << "]";
				NewCell = NewCell->right;
			}
			cout << endl;
		}
		A = A->down;
	}
}
Sparse_Matrix::~Sparse_Matrix()
{
	Cell *A = head;
	while (head != NULL)
	{
		Cell *NewCell = head->right;
		while (NewCell != NULL)
		{
			Cell *NewCell1 = NewCell->right;
			delete NewCell;
			NewCell = NewCell1;
		}
		A = head->down;
		delete head;
		head = A;
	}
}