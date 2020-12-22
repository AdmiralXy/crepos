#include <iostream>
#include "../../Lib/SingleList/singlelist.h"

using namespace std;

Single_node::Single_node()
{
	
}

Single_node::Single_node(int value, Single_node* n)
{
	val = value;
	next = n;
}

Single_list::Single_list() // ������� ������ ������
{
	head = tail = new Single_node;
}
Single_list::Single_list(int value) // ������� ������ � 1 ���������
{
	tail = new Single_node;
	head = new Single_node(value, tail);
}
Single_list::~Single_list() // ���������� - ������� ������
{
	clear();
	delete tail;
}
void Single_list::push_front(int value) // ��������� ����� � ������ ������
{
	head = new Single_node(value, head);
}
void Single_list::pop_front() // ������� �������� �� ������ ������
{
	Single_node *A = head;
	head = A->next;
	delete A;
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
}

void Single_list::copy(const Single_list& l)
{
	/*
	int count = 0;
	for (Single_node *A = l.head; A != l.tail; A = A->next)
		count++;
	for (int i = 1; count != 0; count--) {
		Single_node *A = l.head;
		for (; i != count; i++) {
			A = A->next;
		}
		head = new Single_node(A->val, head);
		i = 1;
	}
	*/
	for (Single_node *A = l.head; A != l.tail; A = A->next) {
		head->val = A->val;
		head->next = new Single_node;
		head = head->next;
	}
	swap(head, tail);
}

Single_list::Single_list(const Single_list& l) // ����������� �����������
{
	head = tail = new Single_node;
	copy(l);
}

Single_list& Single_list::operator=(const Single_list& l) // ������������� �������� ������������
{
	if (this != &l) {
		clear();
		copy(l);
	}
	return *this;
}