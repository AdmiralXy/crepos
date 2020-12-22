#ifndef default_H
#define default_H

struct Single_node
{
	int val;
	Single_node *next;
	Single_node();
	Single_node(int value, Single_node* n);
};

class Single_list {
private:
	Single_node* head;
	Single_node* tail;
	void copy(const Single_list&);
public:
	Single_list();
	Single_list(int value);
	~Single_list();
	void push_front(int value);
	void pop_front();
	bool empty();
	void clear();
	int size();
	int& front();
	void print();
	Single_list(const Single_list& l);
	Single_list & operator=(const Single_list& l);
};
 
#endif