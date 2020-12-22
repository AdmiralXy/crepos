#include <iostream>
#include "..\..\Lib\HashTable\hashtable.h"

using namespace std;


Cell::Cell(const char* d, int k, Cell* n)
{
	data = d;
	key = k;
	next = n;
}

int Hash_table::hash(int key)
{ 
	return key % table_size; 
}
Hash_table::Hash_table(int size, const char* notFound)
{
	table = new Cell*[size];
	for (int i = 0; i < size; i++)
		table[i] = new Cell(0, 0, 0);
	table_size = size;
	not_found = notFound;
}
Hash_table::~Hash_table()
{
	Cell *A, *temp;
	for (int i = 0; i < table_size; i++)
		for (A = table[i]; A != 0; delete temp) {
			temp = A;
			A = A->next;
		}
	delete[] table;
}
bool Hash_table::add(const char* data, int key) // добавляем в начало
{
	Cell* A;
	for (A = table[hash(key)]->next; A != 0; A = A->next)
		if (A->key == key)
			return false;
	A = new Cell(data, key, table[hash(key)]->next);
	table[hash(key)]->next = A;
	return true;
}
void Hash_table::remove(int key)
{
	int val = hash(key);
	Cell* PreA = table[val];
	for (Cell* A = table[hash(key)]->next; A != 0; A = A->next)
	{
		if (A->key == key) {
			PreA->next = A->next;
			delete A;
			return;
		}
		PreA = A;
	}
}
const char* Hash_table::find(int key) // поиск по ключу
{
	Cell* A;
	for (A = table[hash(key)]; A != 0; A = A->next)
		if (A->key == key)
			return A->data;
	return not_found;
}
void Hash_table::print() // номер_строки: [значение, ключ]
{
	for (int i = 0; i < table_size; i++)
	{
		if (table[i]->next) {
			cout << i << ": ";
			for (Cell* A = table[i]->next; A != 0; A = A->next)
			{
				cout << "[" << A->data << ", " << A->key << "] ";
			}
			cout << endl;
		}
	}
}