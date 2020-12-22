#ifndef dltemplate_H
#define dltemplate_H

#include <iostream>

using namespace std;

template <class T>
class Double_list
{
private:
	struct Double_node
	{
		Double_node *next;
		Double_node *prev;
		T val;
		Double_node();
		Double_node(const T&, Double_node* n, Double_node* p);
	};
	Double_node * tail;
	int sz;
	void copy(const Double_list<T>&);
public:
	class Iterator {
		friend class Double_list;
	private:
		Double_node *index;
	public:
		Iterator() 
		{
			index = 0;
		}
		Iterator(Double_node * temp)
		{
			index = temp;
		}
		Iterator& operator++()
		{
			index = index->next;
			return *this;
		}
		Iterator operator ++(int) {
			Iterator temp = *this;
			++*this;
			return temp;
		}
		Iterator& operator--()
		{
			index = index->prev;
			return *this;
		}
		Iterator operator --(int) {
			Iterator temp = *this;
			--*this;
			return temp;
		}
		T& operator*() {
			return index->val;
		}
		Iterator operator +(int t) {
			Iterator temp = *this;
			for (int i = 0; i < t; i++)
				temp++;
			return temp;
		}
		Iterator operator -(int t) {
			Iterator temp = *this;
			for (int i = 0; i < t; i++)
				temp--;
			return temp;
		}
		bool operator == (const Iterator &t) const
		{
			return index == t.index;
		}
		bool operator!=(const Iterator& t) const 
		{
			return t.index != index;
		}
		int operator -(Iterator q)
		{
			int temp = 0;
			while (index != q.index) {
				q++;
				temp++;
			}
			return temp;
		}
	};
	class Reverse_Iterator {
		friend class Double_list;
	private:
		Double_node * index;
	public:
		Reverse_Iterator()
		{
			index = 0;
		}
		Reverse_Iterator(Double_node * temp)
		{
			index = temp;
		}
		Reverse_Iterator& operator++()
		{
			index = index->prev;
			return *this;
		}
		Reverse_Iterator operator ++(int) {
			Reverse_Iterator temp = *this;
			++*this;
			return temp;
		}
		Reverse_Iterator& operator--()
		{
			index = index->next;
			return *this;
		}
		Reverse_Iterator operator --(int) {
			Reverse_Iterator temp = *this;
			--*this;
			return temp;
		}
		T& operator*() {
			return index->val;
		}
		Reverse_Iterator operator +(int t) {
			Reverse_Iterator temp = *this;
			for (int i = 0; i < t; i++)
				temp++;
			return temp;
		}
		Reverse_Iterator operator -(int t) {
			Reverse_Iterator temp = *this;
			for (int i = 0; i < t; i++)
				temp--;
			return temp;
		}
		bool operator == (const Reverse_Iterator &t) const
		{
			return index == t.index;
		}
		bool operator!=(const Reverse_Iterator& t) const
		{
			return t.index != index;
		}
		int operator -(Reverse_Iterator q)
		{
			int temp = 0;
			while (index != q.index) {
				q++;
				temp++;
			}
			return temp;
		}
	};
	Iterator begin();
	Iterator end();
	Iterator insert(Iterator, const T&);
	Iterator erase(Iterator);
	Reverse_Iterator rbegin();
	Reverse_Iterator rend();
	Double_list();
	Double_list(T value);
	~Double_list();
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	void clear();
	T &front();
	int &back();
	void print();
	Double_list(const Double_list<T>& l);
	Double_list & operator=(const Double_list<T>& l);
};

template<class T>
typename Double_list<T>::Iterator Double_list<T>::begin()
{
	return Iterator(tail->next);
}

template<class T>
typename Double_list<T>::Iterator Double_list<T>::end()
{
	return Iterator(tail);
}

template<class T>
typename Double_list<T>::Iterator Double_list<T>::insert(Iterator pos, const T& value)
{
	Double_node* InsertPosition = pos.index;
	Double_node *NewNode = new Double_node(value, InsertPosition, InsertPosition->prev);
	InsertPosition->prev->next = NewNode;
	InsertPosition->prev = NewNode;
	sz++;
	return Iterator(NewNode);
}

template<class T>
typename Double_list<T>::Iterator Double_list<T>::erase(Iterator pos)
{
	Double_node* it = pos.index->next;
	Double_node* DeletePosition = pos.index;
	DeletePosition->next->prev = DeletePosition->prev;
	DeletePosition->prev->next = DeletePosition->next;
	delete DeletePosition;
	sz--;
	return Iterator(it);
}

template<class T>
typename Double_list<T>::Reverse_Iterator Double_list<T>::rbegin()
{
	return Reverse_Iterator(tail->prev);
}

template<class T>
typename Double_list<T>::Reverse_Iterator Double_list<T>::rend()
{
	return Reverse_Iterator(tail);
}

template <class T>
Double_list<T>::Double_node::Double_node()
{

}

template <class T>
Double_list<T>::Double_node::Double_node(const T& value, Double_node* n, Double_node* p)
{
	val = value;
	next = n;
	prev = p;
}

template <class T>
Double_list<T>::Double_list() // создает пустой список
{
	tail = new Double_node;
	tail->next = tail->prev = tail;
	sz = 0;
}

template <class T>
Double_list<T>::Double_list(T value) // создает список с 1 значением
{
	tail = new Double_node;
	Double_node *A = new Double_node(value, tail, tail);
	*tail = Double_node(NULL, A, A);
	sz = 1;
}

template <class T>
Double_list<T>::~Double_list() // Деструктор - очистка полная
{
	Double_node* t = tail->next;
	while (t != tail) {
		Double_node *A = t;
		t = t->next;
		delete A;
	}
	delete tail;
}

template <class T>
void Double_list<T>::push_front(const T& value) // добавляет число в начало списка
{
	Double_node *NewNode = new Double_node(value, tail->next, tail);
	tail->next->prev = NewNode;
	tail->next = NewNode;
	sz++;
}

template <class T>
void Double_list<T>::push_back(const T& value) // добавляет число в конец списка
{
	Double_node *NewNode = new Double_node(value, tail, tail->prev);
	tail->prev->next = NewNode;
	tail->prev = NewNode;
	sz++;
}

template <class T>
void Double_list<T>::pop_front() // удаляет значение из начала списка
{
	Double_node *A = tail->next;
	A->next->prev = tail;
	tail->next = A->next;
	delete A;
	sz--;
}

template <class T>
void Double_list<T>::pop_back() // удаляет значение из конца списка
{
	Double_node *A = tail->prev;
	tail->prev = A->prev;
	A->prev->next = tail;
	delete A;
	sz--;
}

template <class T>
int Double_list<T>::size() // возвращает размер списка
{
	return sz;
}

template <class T>
bool Double_list<T>::empty() // если список пуст - возвращаем истину
{
	return !sz;
}

template <class T>
void Double_list<T>::clear() // список становится пустым
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

template <class T>
T& Double_list<T>::front() // возвращает ссылку на первый элемент
{
	return tail->next->val;
}

template <class T>
int& Double_list<T>::back() // возвращает ссылку на последний элемент
{
	return tail->prev->val;
}

template <class T>
void Double_list<T>::print() // печать в строчку через пробел
{
	for (Double_node *A = tail->next; A != tail; A = A->next)
	{
		cout << A->val << " ";
	}
	cout << endl;
}

template<class T>
void Double_list<T>::copy(const Double_list<T>& l)
{
	for (Double_node *A = l.tail->next; A != l.tail; A = A->next)
		push_back(A->val);
}

template<class T>
Double_list<T>::Double_list(const Double_list<T>& l) // Конструктор копирования
{
	tail = new Double_node;
	tail->next = tail->prev = tail;
	sz = 0;
	copy(l);
}

template<class T>
typename Double_list<T>::Double_list& Double_list<T>::operator=(const Double_list<T>& l) // Перегруженный оператор присваивания
{
	if (this != &l) {
		clear();
		copy(l);
	}
	return *this;
}

#endif
