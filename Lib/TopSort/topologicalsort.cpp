#include <iostream>
#include "topologicalsort.h"
#include "../DoubleListTemplate/doublelist.h"

using namespace std;

struct Node
{
	struct Child
	{
		Node *to;
		Child *next;
		Child() {};
		Child(Node* t, Child* n)
		{
			to = t;
			next = n;
		}
	};
	int val;
	int N;
	Node *next;
	Child *children;
	Child *last;
	Node() {};
	Node(int value, int num, Node* n)
	{
		val = value;
		N = num;
		next = n;
		last = children;
	}
};

void topological_sort(int V[], int W[], int N) 
{
	Double_list<Node> l;
	for (int i = 0; i < N; i++) 
	{
		Double_list<Node>::Iterator V_check = 0;
		Double_list<Node>::Iterator W_check = 0;
		for (Double_list<Node>::Iterator p = l.begin(); p != l.end(); p++) {
			Node& A = *p;
			if (A.val == V[i])
				V_check = p;
			if (A.val == W[i])
				W_check = p;
		}

		if (V_check == 0) {
			l.push_back(Node(V[i], 0, 0));
			if (l.size() > 1) {
				Node& from = *(l.end() - 2);
				Node& to = *(l.end() - 1);
				from.next = &to;
			}
			V_check = l.end() - 1;
		}

		if (W_check == 0) {
			l.push_back(Node(W[i], 0, 0));
			if (l.size() > 1) {
				Node& from = *(l.end() - 2);
				Node& to = *(l.end() - 1);
				from.next = &to;
			}
			W_check = l.end() - 1;
		}
		
		Node& V_node = *V_check;
		Node& W_node = *W_check;
		W_node.N++;

		Node::Child *P = new Node::Child(&W_node, V_node.children);
		if (!V_node.last) {
			V_node.last = P;
		}
		
		V_node.children = P;
	}
	Double_list<Node> ved_elem;
	int k = 0;
	while (!l.empty())
	{
		Double_list<Node>::Iterator del = 0;
		for (Double_list<Node>::Iterator p = l.end() - 1; p != l.end(); p--) {
			Node& temp = *p;
			if (temp.N == 0) {
				Node::Child *i = temp.children;
				while (i != temp.last)
				{
					Node::Child *B = i;
					i->to->N--;
					i = i->next;
					delete B;
				}
				ved_elem.push_back(Node(temp.val, 0, 0));
				del = p;
				p = l.begin();
			}
		}
		l.erase(del);
	}
	while (!ved_elem.empty()) {
		Node& c = *(ved_elem.begin());
		cout << c.val << " ";
		ved_elem.pop_front();
	}

	cout << endl;
}