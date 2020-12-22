// 3feb_Doublelist.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Double_node
{
	Double_node *next;
	Double_node *prev;
	int val;
	Double_node()
	{

	}
	Double_node(int value, Double_node* n, Double_node* p)
	{
		val = value;
		next = n;
		prev = p;
	}
};

class Double_list
{
private:
	Double_node * tail;
	int sz;
public:
	Double_list() // создает пустой список
	{
		tail = new Double_node;
		tail->next = tail->prev = tail;
		sz = 0;
	}
	Double_list(int value) // создает список с 1 значением
	{
		tail = new Double_node;
		Double_node *A = new Double_node(value, tail, tail);
		*tail = Double_node(NULL, A, A);
		sz = 1;
	}
	~Double_list() // Деструктор - очистка полная
	{
		Double_node* t = tail->next;
		while (t != tail) {
			Double_node *A = t;
			t = t->next;
			delete A;
		}
		delete tail;
	}
	void push_front(int value) // добавляет число в начало списка
	{
		Double_node *NewNode = new Double_node(value, tail->next, tail);
		tail->next->prev = tail->next = NewNode;
		sz++;
	}
	void push_back(int value) // добавляет число в конец списка
	{
		Double_node *NewNode = new Double_node(value, tail, tail->prev);
		tail->prev->next = tail->prev = NewNode;
		sz++;
	}
	void pop_front() // удаляет значение из начала списка
	{
		Double_node *A = tail->next;
		tail->next = A->next;
		A->next->prev = tail;
		delete A;
		sz--;
	}
	void pop_back() // удаляет значение из конца списка
	{
		Double_node *A = tail->prev;
		tail->prev = A->prev;
		A->prev->next = tail;
		delete A;
		sz--;
	}
	int size() // возвращает размер списка
	{
		return sz;
	}
	bool empty() // если список пуст - возвращаем истину
	{
		return !sz;
	}
	void clear() // список становится пустым
	{
		Double_node* t = tail->next;
		while (t != tail)
		{
			Double_node *A = t;
			t = t->next;
			delete A;
		}
		tail->next = tail->prev = tail;
		sz = 0;
	}
	int &front() // возвращает ссылку на первый элемент
	{
		return tail->next->val;
	}
	int &back() // возвращает ссылку на последний элемент
	{
		return tail->prev->val;
	}
	void print() // печать в строчку через пробел
	{
		for (Double_node *A = tail->next; A != tail; A = A->next)
		{
			cout << A->val << " ";
		}
		cout << endl;
	}
};

int main()
{
	Double_list l;
	for (int i = 0; i < 5; i++)
	{
		l.push_back(i);
		l.print();
	}
	l.clear();
	l.push_back(7);
	//	l.push_front(5);
	l.print();
	return 0;
}