#ifndef sm_H
#define sm_H

struct Cell {
	int row, col;
	Cell *right, *down;
	int data;
	Cell();
	Cell(int n_row, int n_col);
};

class Sparse_Matrix {
private:
	int n_rows;
	int n_cols;
	int def_value; 
	Cell *head;
public:
	Sparse_Matrix(int rows, int cols, int def);
	int r_access(int row, int col) const;
	int &w_access(int row, int col);
	void print();
	~Sparse_Matrix();
};
 
#endif