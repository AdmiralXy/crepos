#ifndef queue_H
#define queue_H

void error_msg(bool check);

class Queue2
{
private:
	int *A;
	int sz;
	int start;
	int n;
public:
	Queue2(int maxSize);
	bool empty();
	int size();
	int&front();
	int &back();
	void push(int value);
	void pop();
	~Queue2();
};

#endif