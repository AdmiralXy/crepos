#include <iostream>
#include "..\..\Lib\Queue\queueArray.h"

Queue2::Queue2(int maxSize)
{
	n = maxSize;
	A = new int[n];
	sz = 0;
	start = 0;
}
bool Queue2::empty() // пусто == 1
{
	return !sz;
}
int Queue2::size() // размер
{
	return sz;
}
int& Queue2::front() // ссылка на начало
{
	return A[start];
}
int& Queue2::back() // ссылка на конец
{
	return A[start + (sz - 1)];
}
void Queue2::push(int value) // добавить
{
	A[(start + sz) % n] = value;
	sz++;
}
void Queue2::pop() // удалить
{
	start = (start + 1) % n;
	sz--;
}
Queue2::~Queue2()
{
	delete[] A;
}