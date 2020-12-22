#ifndef dl_H
#define dl_H

struct Tree_node
{
	int val;
	Tree_node *left_child; // левый потомок
	Tree_node *right_child; // правый потомок
	Tree_node(int value);
	Tree_node(int value, Tree_node *l, Tree_node *r);
};

class Binary_tree {
private:
	Tree_node * root; // корень дерева
public:
	Binary_tree();
	Binary_tree(int value);
	~Binary_tree();
	bool add(int value);
	bool find(int value);
	void remove(int value);
	int height();
	int size();
	void print();
	void print_pre_order();
	void print_in_order();
	void print_post_order();
};

#endif