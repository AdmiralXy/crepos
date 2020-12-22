// april1_BinaryTree.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "..\..\Lib\BinarySearchTree\BinarySearchTree.h"

using namespace std;

int main()
{
	Binary_tree B; // 5 3 9 1 4 7 12 2 6 8
	B.add(5);
	B.add(3);
	B.add(9);
	B.add(1);
	B.add(4);
	B.add(7);
	B.add(12);
	B.add(2);
	B.add(6);
	B.add(8);
	B.remove(5);
	B.print();
	B.print_pre_order(); // 5 3 1 2 4 9 7 6 8 12
	B.print_in_order(); // 1 2 3 4 5 6 7 8 9 12
	B.print_post_order(); // 2 1 4 3 6 8 7 12 7 5
	cout << B.find(6) << endl;
	cout << B.find(11) << endl;
	cout << B.height() << endl;
	cout << B.size() << endl;
    return 0;
}

