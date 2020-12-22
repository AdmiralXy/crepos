#ifndef stack2_H
#define stack2_H

class Stack2
{
private:
	int *A;
	int head;
public:
	Stack2(int n);
	~Stack2();
	bool empty();
	int size();
	int& top();
	void push(int value);
	void pop();
};
 
#endif