#include <iostream>
using namespace std;

#include "../../Lib/BinarySearchTree/BinarySearchTree.h"

int main(void)
{
	Binary_tree* a = new Binary_tree();
	a->add(10);
	a->add(6);
	a->add(7);
	a->add(3);
	a->add(2);
	a->add(11);
	a->add(13);
	a->add(12);
	a->add(14);
	a->remove(13);
	a->print();
}