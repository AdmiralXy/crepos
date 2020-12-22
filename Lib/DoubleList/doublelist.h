#ifndef dl_H
#define dl_H

void error_msg(bool check);

struct Double_node
{
	Double_node *next;
	Double_node *prev;
	int val;
	Double_node();
	Double_node(int value, Double_node* n, Double_node* p);
};

class Double_list
{
private:
	Double_node * tail;
	int sz;
public:
	Double_list();
	Double_list(int value);
	~Double_list();
	void push_front(int value);
	void push_back(int value);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	void clear();
	int &front();
	int &back();
	void print();
};

#endif