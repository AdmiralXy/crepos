#include <iostream>
#include "../../Lib/Stack/stackArray.h"

Stack2::Stack2(int n) // �����������
{
	head = 0;
	A = new int[n];
}
Stack2::~Stack2() // ����������
{
	delete[] A;
}
bool Stack2::empty() // ������ ��� ������ ������
{
	return head == 0;
}
int Stack2::size() // ������ ������
{
	return head;
}
int& Stack2::top() // ������ �� 1 �������
{
	return A[head - 1];
}
void Stack2::push(int value) //��������
{
	A[head++] = value;
}
void Stack2::pop() // �������
{
	head--;
}