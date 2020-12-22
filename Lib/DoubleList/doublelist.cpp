#include <iostream>
#include "..\..\Lib\DoubleList\doublelist.h"

using namespace std;

void error_msg(bool check)
{
	if (!check)
		std::cout << "Error\n" << std::endl;
}

Double_node::Double_node()
{

}
Double_node::Double_node(int value, Double_node* n, Double_node* p)
{
	val = value;
	next = n;
	prev = p;
}

Double_list::Double_list() // ������� ������ ������
{
	tail = new Double_node;
	tail->next = tail->prev = tail;
	sz = 0;
}
Double_list::Double_list(int value) // ������� ������ � 1 ���������
{
	tail = new Double_node;
	Double_node *A = new Double_node(value, tail, tail);
	*tail = Double_node(NULL, A, A);
	sz = 1;
}
Double_list::~Double_list() // ���������� - ������� ������
{
	Double_node* t = tail->next;
	while (t != tail) {
		Double_node *A = t;
		t = t->next;
		delete A;
	}
	delete tail;
}
void Double_list::push_front(int value) // ��������� ����� � ������ ������
{
	Double_node *NewNode = new Double_node(value, tail->next, tail);
	tail->next = NewNode;
	tail->next->prev = NewNode;
	sz++;
}
void Double_list::push_back(int value) // ��������� ����� � ����� ������
{
	Double_node *NewNode = new Double_node(value, tail, tail->prev);
	tail->prev->next = NewNode;
	tail->prev = NewNode;
	sz++;
}
void Double_list::pop_front() // ������� �������� �� ������ ������
{
	Double_node *A = tail->next;
	A->next->prev = tail;
	tail->next = A->next;
	delete A;
	sz--;
}
void Double_list::pop_back() // ������� �������� �� ����� ������
{
	Double_node *A = tail->prev;
	tail->prev = A->prev;
	A->prev->next = tail;
	delete A;
	sz--;
}
int Double_list::size() // ���������� ������ ������
{
	return sz;
}
bool Double_list::empty() // ���� ������ ���� - ���������� ������
{
	return !sz;
}
void Double_list::clear() // ������ ���������� ������
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
int& Double_list::front() // ���������� ������ �� ������ �������
{
	return tail->next->val;
}
int& Double_list::back() // ���������� ������ �� ��������� �������
{
	return tail->prev->val;
}
void Double_list::print() // ������ � ������� ����� ������
{
	for (Double_node *A = tail->next; A != tail; A = A->next)
	{
		cout << A->val << " ";
	}
	cout << endl;
}