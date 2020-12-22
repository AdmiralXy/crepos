#include <iostream>
using namespace std;

#include "../../Lib/DoubleListTemplate/doublelist.h"

template<class Value, class ForwardIterator>
void merge(ForwardIterator begin, ForwardIterator middle, ForwardIterator end, Value* res)
{
	ForwardIterator a = begin, b = middle;
	Value *r = res;

	while (a != middle && b != end)
		if (*a < *b) {
			*r++ = *a;
			a++;
		}
		else {
			*r++ = *b;
			b++;
		}

	while (a != middle)  {
		*r++ = *a;
		a++;
	}
		
	while (b != end) {
		*r++ = *b;
		b++;
	}

	while (begin != end) {
		*begin = *res;
		begin++;
		res++;
	}
		
}

template<class Value, class ForwardIterator>
void mergesort(ForwardIterator begin, ForwardIterator end)
{
	int s = end - begin;
	Value *res = new Value[end - begin];

	if (s > 1)
	{
		ForwardIterator middle = begin + s / 2;
		mergesort<Value, ForwardIterator>(begin, middle);
		mergesort<Value, ForwardIterator>(middle, end);
		merge<Value, ForwardIterator>(begin, middle, end, res);
	}
}

int main()
{
	//int A[5];
	//A[0] = 7;
	//A[1] = 5;
	//A[2] = 8;
	//A[3] = 1;
	//A[4] = 2;

	//mergesort<int>(A, A + 5);

	//for (int i = 0; i < 5; i++)
	//	cout << A[i] << " ";
	//cout << endl;

	Double_list<int> l;
	l.push_back(7);
	l.push_back(45);
	l.push_back(8);
	l.push_back(24);
	l.push_back(2);
	l.push_back(5);
	l.push_back(6);
	l.push_back(2);
	l.push_back(0);
	l.push_back(22);
	l.print();
	mergesort<int>(l.begin(), l.end());
	l.print();
	return 0;
}