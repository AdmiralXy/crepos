// april3_hashtable.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "..\..\Lib\HashTable\hashtable.h"


using namespace std;

int main()
{
	Hash_table hash(5, " ");
	hash.add("abc", 99);
	hash.add("abc", 100);
	hash.add("def", 100);
	hash.add("ghi", 101);
	hash.print();
	cout << hash.find(99) << endl;
	cout << hash.find(100) << endl;
	cout << hash.find(101) << endl;
	cout << hash.find(66) << endl;
	hash.remove(99);
	hash.remove(100);
	hash.remove(101);
	hash.remove(5);
	for (int i = 0; i < 25; i++)
		hash.add("xyz", i);
	hash.print();
    return 0;
}

