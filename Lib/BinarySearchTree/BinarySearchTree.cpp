#include <iostream>
#include "..\..\Lib\BinarySearchTree\BinarySearchTree.h"

using namespace std;

Tree_node::Tree_node(int value)
{
	val = value;
	left_child = 0;
	right_child = 0;
}
Tree_node::Tree_node(int value, Tree_node *l, Tree_node *r)
{
	val = value;
	left_child = l;
	right_child = r;
}
int heightOfTree(Tree_node *A)
{
	if (A == 0) 
		return 0;
	else {
		int a = heightOfTree(A->left_child);
		int b = heightOfTree(A->right_child);
		return a > b ? a + 1 : b + 1;
	}
}
int sizeOfTree(Tree_node *A)
{
	return A ? sizeOfTree(A->left_child) + 1 + sizeOfTree(A->right_child) : 0;
}
void default_print(Tree_node *A, int space)
{
	if (A)
	{
		default_print(A->right_child, space + 1);
		for (int i = 0; i < space; i++) cout << "  ";
		cout << A->val << endl;
		default_print(A->left_child, space + 1);
	}
	else {
		for (int i = 0; i < space; i++) cout << "  ";
		cout << "@" << endl;
	}
}
void inorder(Tree_node *A)
{
	if (A) {
		inorder(A->left_child);
		cout << A->val << " ";
		inorder(A->right_child);
	}
}
void preorder(Tree_node *A)
{
	if (A) {
		cout << A->val << " ";
		preorder(A->left_child);
		preorder(A->right_child);
	}
}
void postorder(Tree_node *A)
{
	if (A) {
		postorder(A->left_child);
		postorder(A->right_child);
		cout << A->val << " ";
	}
}
void Clear(Tree_node *A)
{
	if (A) {
		Clear(A->right_child);
		Clear(A->left_child);
		delete A;
	}
}

Binary_tree::Binary_tree()  // создает пустое дерево 
{
	root = 0;
}
Binary_tree::Binary_tree(int value) // создает корень
{
	root = new Tree_node(value);
}
Binary_tree::~Binary_tree() // использу€ один из рекурсивных обходов и еще одну функцию
{
	Clear(root);
}
bool Binary_tree::add(int value) // возвращает ложь, если есть в дереве такое значение. »наче - истину
{
	if (root == 0)
		root = new Tree_node(value);
	else 
	{
		Tree_node* A = root;
		Tree_node* B = A;
		while (A != 0)
		{
			if (A->val == value) return false;
			B = A;
			if (value < A->val)
				A = A->left_child;
			else
				A = A->right_child;
		}
		if (value < B->val)
			B->left_child = new Tree_node(value);
		else
			B->right_child = new Tree_node(value);
	}
	return true;
}
bool Binary_tree::find(int value) // поиск по значению
{
	if (root == 0) 
		return false;
	else 
	{
		Tree_node* A = root;
		while (A != 0)
		{
			if (A->val == value) 
				return true;
			else if (value < A->val)
				A = A->left_child;
			else
				A = A->right_child;
		}
	}
	return false;
}
void Binary_tree::remove(int value)
{
	if (root != 0) {
		Tree_node* A = root;
		Tree_node* B = A;

		while (A->val != value) // поиск элемента
		{
			B = A;
			if (value < A->val)
				A = A->left_child;
			else
				A = A->right_child;
		}

		if (A->left_child == 0 && A->right_child == 0) // первый случай - нет потомков, A - удал€емый узел, B - его родитель
		{
			if (A == root)
				root = 0;
			else if (B->left_child == A)
				B->left_child = 0;
			else
				B->right_child = 0;
			delete A;
		}

		else if (A->left_child && A->right_child) // третий случай - 2 потомка, B - удал€емый узел, B_parent - его родитель
		{
			Tree_node* B_parent = B;
			for (Tree_node* tempSearch = A->right_child; tempSearch != 0; )
			{
				B_parent = B;
				B = tempSearch;
				tempSearch = tempSearch->left_child;
			}
			A->val = B->val;
			if (B->right_child == 0)
				if (B_parent->left_child == B)
					B_parent->left_child = 0;
				else
					B_parent->right_child = 0;
			else
				if (B_parent->left_child == B)
					B_parent->left_child = B->right_child;
				else
					B_parent->right_child = B->right_child;
			delete B;
		}

		else // второй случай - 1 потомок, A - удал€емый узел, B - его родитель
		{
			if (A == B)
				if (A->left_child == 0)
					root = A->right_child;
				else 
					root = A->left_child;
			else if (A->left_child == 0)
				if (B->left_child == A)
					B->left_child = A->right_child;
				else
					B->right_child = A->right_child;
			else
				if (B->left_child == A)
					B->left_child = A->left_child;
				else
					B->right_child = A->left_child;
			delete A;
		}
	}
}
int Binary_tree::height() // высота дерева
{
	return heightOfTree(root);
}
int Binary_tree::size() // количество элементов
{
	return sizeOfTree(root);
}
void Binary_tree::print()
{
	default_print(root, 0);
	cout << endl;
}
void Binary_tree::print_pre_order() // вершина, лево, право
{
	preorder(root);
	cout << endl;
}
void Binary_tree::print_in_order() // обход слева
{
	inorder(root);
	cout << endl;
}
void Binary_tree::print_post_order()  // лево, право, вершина
{
	postorder(root);
	cout << endl;
}