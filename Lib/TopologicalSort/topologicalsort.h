#ifndef default_H
#define default_H

struct Single_node
{
	struct Child
	{
		Single_node *to;
		Child *next;
		Child() {};
		Child(Single_node* t, Child* n)
		{
			to = t;
			next = n;
		}
	};
	int val;
	int N;
	Single_node *next;
	Child *children;
	Child *last;
	Single_node();
	Single_node(int value, int N, Single_node* n);
};

class Single_list {
private:
	Single_node* head;
	Single_node* tail;
public:
	Single_list();
	Single_list(int value);
	~Single_list();
	void push_front(int value);
	void push_back(int value);
	void push_back_with_child(int, int);
	void pop_front();
	int pop_without_pred();
	bool empty();
	void clear();
	int size();
	int& front();
	void print();
};

void topological_sort(int V[], int W[], int N);
 
#endif