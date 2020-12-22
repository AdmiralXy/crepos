#include <iostream>
#include "..\..\Lib\Queue\queueArray.h"

Queue2::Queue2(int maxSize)
{
	n = maxSize;
	A = new int[n];
	sz = 0;
	start = 0;
}
bool Queue2::empty() // ����� == 1
{
	return !sz;
}
int Queue2::size() // ������
{
	return sz;
}
int& Queue2::front() // ������ �� ������
{
	return A[start];
}
int& Queue2::back() // ������ �� �����
{
	return A[start + (sz - 1)];
}
void Queue2::push(int value) // ��������
{
	A[(start + sz) % n] = value;
	sz++;
}
void Queue2::pop() // �������
{
	start = (start + 1) % n;
	sz--;
}
Queue2::~Queue2()
{
	delete[] A;
}