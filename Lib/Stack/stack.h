#ifndef stack_H
#define stack_H

#include "../../Lib/SingleList/singlelist.h"

void error_msg(bool check);

class Stack
{
private:
	Single_list l;
public:
	Stack();
	~Stack();
	bool empty();
	int size();
	int&top();
	void push(int value);
	void pop();
};
 
#endif