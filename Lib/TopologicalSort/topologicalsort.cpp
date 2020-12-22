#include <iostream>
#include "../../Lib/TopologicalSort/topologicalsort.h"

using namespace std;

Single_node::Single_node()
{
	last = children;
}

Single_node::Single_node(int value, int num, Single_node* n)
{
	val = value;
	N = num;
	next = n;
	last = children;
}

Single_list::Single_list() // ������� ������ ������
{
	head = tail = new Single_node;
}
Single_list::Single_list(int value) // ������� ������ � 1 ���������
{
	tail = new Single_node;
	head = new Single_node(value, 0, tail);
}
Single_list::~Single_list() // ���������� - ������� ������
{
	clear();
	delete tail;
}
void Single_list::push_front(int value) // ��������� ����� � ������ ������
{
	head = new Single_node(value, 0, head);
}
void Single_list::push_back(int value) // ��������� ����� � ����� ������
{
	tail->val = value;
	tail->N = 0;
	tail->next = new Single_node();
	tail = tail->next;
}
void Single_list::push_back_with_child(int value, int p) // ��������� ����� � ����� ������
{
	Single_node *V = 0;
	Single_node *W = 0;
	for (Single_node *A = head; A != tail; A = A->next) {
		if (A->val == value)
			V = A;
		if (A->val == p)
			W = A;
	}

	if (!V) {
		V = tail;
		push_back(value);
	}

	if (!W) {
		W = tail;
		push_back(p);
	}

	W->N++;

	Single_node::Child *P = new Single_node::Child(W, V->children);
	if (V->last == NULL) {
		V->last = P;
	}
		
	V->children = P;
		
}
void Single_list::pop_front() // ������� �������� �� ������ ������
{
	Single_node *A = head;
	head = A->next;
	delete A;
}
int Single_list::pop_without_pred() // �������� ���� ��� ����������������
{
	Single_node *A = head;
	Single_node *F = head;
	int k = A->val;
	while (A != tail) 
	{
		if (A->N == 0) {
			k = A->val;
			F = A;
		}
		A = A->next;
	}

	Single_node::Child *i = F->children;
	while (i != F->last)
	{
		Single_node::Child *B = i;
		i->to->N--;
		i = i->next;
		delete B;
	}

	Single_node *del = head;
	Single_node *pre = head;
	while (del != F)
	{
		pre = del;
		del = del->next;
	}
	if (del == head)
		head = head->next;
	else
		pre->next = del->next;
	delete del;

	return k;
}
bool Single_list::empty() // ���� ������ ���� - ���������� ������
{
	return head == tail;
}
void Single_list::clear() // ������ ���������� ������
{
	while (head != tail)
	{
		Single_node *A = head;
		head = A->next;
		delete A;
	}
}
int Single_list::size() // ���������� ���������� ���������
{
	int count = 0;
	for (Single_node *A = head; A != tail; A = A->next)
		count++;
	return count;
}
int& Single_list::front() // ���������� ������ �� ������ �������
{
	return head->val;
}

void Single_list::print() // �������� � ������� ����� ������
{
	for (Single_node *A = head; A != tail; A = A->next)
		cout << A->val << " ";
	cout << endl;
	for (Single_node *A = head; A != tail; A = A->next)
		cout << A->N << " ";
	cout << endl;
}

void topological_sort(int V[], int W[], int N) 
{
	Single_list l;
	for (int i = 0; i < N; i++)
		l.push_back_with_child(V[i], W[i]);
	l.print();
	Single_list ved_elem;
	while (!l.empty())
		ved_elem.push_back(l.pop_without_pred());
	ved_elem.print();
}