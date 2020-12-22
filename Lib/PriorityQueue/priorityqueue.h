#ifndef priorityqueue_H
#define priorityqueue_H

#include "../../Lib/PriorityQueue/priorityqueue.h"

class Priority_Queue
{
private:
	int sz;
public:
	int *A;
	Priority_Queue(int); // ��������� �������� 
	~Priority_Queue();
	void push(int); // ����� log n 
	void pop(); // ������������� ������ ����� log n 
	const int& top();
	int size(); // ���������� ��������, ���������� � ������� const 
	bool empty(); // const 
};
 
#endif