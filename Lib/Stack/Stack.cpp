#include <iostream>
#include "../../Lib/Stack/stack.h"

Stack::Stack() // конструктор
{
	
}
Stack::~Stack() // деструктор
{
	
}
bool Stack::empty() // истина при пустом списке
{
	return l.empty();
}
int Stack::size() // размер списка
{
	return l.size();
}
int& Stack::top() // ссылка на 1 элемент
{
	return l.front();
}
void Stack::push(int value) //добавить
{
	l.push_front(value);
}
void Stack::pop() // удалить
{
	l.pop_front();
}