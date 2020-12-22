#ifndef queue_H
#define queue_H

#include "..\..\Lib\DoubleList\doublelist.h"

void error_msg(bool check);

class Queue {
private:
	Double_list l;
	int sz;
public:
	Queue();
	bool empty();
	int size();
	int&front();
	int &back();
	void push(int value);
	void pop();
	~Queue();
};

#endif