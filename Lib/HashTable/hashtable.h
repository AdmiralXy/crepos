#ifndef ht_H
#define ht_H

struct Cell
{
	const char *data; // ������
	int key; // ����
	Cell *next; // ��������� �� ���������
	Cell(const char* d, int k, Cell* n);
};

class Hash_table {
private:
	Cell **table; // ������ �� ����������
	int table_size;
	const char *not_found;// ��� ������ ��� �� ��������� ��������
	int hash(int key);
public:
	Hash_table(int size, const char* notFound);
	~Hash_table();
	bool add(const char* data, int key);
	void remove(int key);
	const char *find(int key);
	void print();
};

#endif