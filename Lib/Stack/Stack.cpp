#include <iostream>
#include "../../Lib/Stack/stack.h"

Stack::Stack() // �����������
{
	
}
Stack::~Stack() // ����������
{
	
}
bool Stack::empty() // ������ ��� ������ ������
{
	return l.empty();
}
int Stack::size() // ������ ������
{
	return l.size();
}
int& Stack::top() // ������ �� 1 �������
{
	return l.front();
}
void Stack::push(int value) //��������
{
	l.push_front(value);
}
void Stack::pop() // �������
{
	l.pop_front();
}