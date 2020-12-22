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

Single_list::Single_list() // создает пустой список
{
	head = tail = new Single_node;
}
Single_list::Single_list(int value) // создает список с 1 значением
{
	tail = new Single_node;
	head = new Single_node(value, tail);
}
Single_list::~Single_list() // деструктор - очистка полная
{
	clear();
	delete tail;
}
void Single_list::push_front(int value) // добавляет число в начало списка
{
	head = new Single_node(value, head);
}
void Single_list::pop_front() // удаляет значение из начала списка
{
	Single_node *A = head;
	head = A->next;
	delete A;
}
bool Single_list::empty() // если список пуст - возвращаем истину
{
	return head == tail;
}
void Single_list::clear() // список становится пустым
{
	while (head != tail)
	{
		Single_node *A = head;
		head = A->next;
		delete A;
	}
}
int Single_list::size() // возвращает количество элементов
{
	int count = 0;
	for (Single_node *A = head; A != tail; A = A->next)
		count++;
	return count;
}
int& Single_list::front() // возвращает ссылку на первый элемент
{
	return head->val;
}

void Single_list::print() // печатает в строчку через пробел
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

Single_list::Single_list(const Single_list& l) // Конструктор копирования
{
	head = tail = new Single_node;
	copy(l);
}

Single_list& Single_list::operator=(const Single_list& l) // Перегруженный оператор присваивания
{
	if (this != &l) {
		clear();
		copy(l);
	}
	return *this;
}