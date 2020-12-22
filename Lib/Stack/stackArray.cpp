#include <iostream>
#include "../../Lib/Stack/stackArray.h"

Stack2::Stack2(int n) // конструктор
{
	head = 0;
	A = new int[n];
}
Stack2::~Stack2() // деструктор
{
	delete[] A;
}
bool Stack2::empty() // истина при пустом списке
{
	return head == 0;
}
int Stack2::size() // размер списка
{
	return head;
}
int& Stack2::top() // ссылка на 1 элемент
{
	return A[head - 1];
}
void Stack2::push(int value) //добавить
{
	A[head++] = value;
}
void Stack2::pop() // удалить
{
	head--;
}