#ifndef priorityqueue_H
#define priorityqueue_H

#include "../../Lib/PriorityQueue/priorityqueue.h"

class Priority_Queue
{
private:
	int sz;
public:
	int *A;
	Priority_Queue(int); // принимает максимум 
	~Priority_Queue();
	void push(int); // около log n 
	void pop(); // выталвивается корень около log n 
	const int& top();
	int size(); // количество значений, хранящейся в очереди const 
	bool empty(); // const 
};
 
#endif