// may2_PriorityQueue.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "../../Lib/PriorityQueue/priorityqueue.h"

using namespace std;

void error_msg(bool check)
{
	if (!check)
		std::cout << "Error\n" << std::endl;
}

void print(int *A, int n)
{
	cout << "Array[" << n << "] = {";
	for (int i = 0; i < n - 1; i++)
	{
		cout << A[i] << ", ";
	}
	cout << A[n - 1] << "}" << endl;
}

int main()
{
	Priority_Queue Q(10);
	Q.push(1);
	Q.push(4);
	Q.push(2);
	Q.push(8);
	error_msg(Q.size() == 4);
	error_msg(Q.top() == 1);
	print(Q.A, Q.size());
	Q.pop();
	print(Q.A, Q.size());
	error_msg(Q.top() == 2);
	Q.pop();
	error_msg(Q.top() == 4);
	Q.pop();
	error_msg(Q.top() == 8);
	Q.pop();
	error_msg(Q.empty());
}
