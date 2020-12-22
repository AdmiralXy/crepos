#ifndef mstemplate_H
#define mstemplate_H

template<class Value, class ForwardIterator>
void merge(ForwardIterator begin, ForwardIterator middle, ForwardIterator end, Value* res)
{
	ForwardIterator a = begin, b = middle;
	Value *r = res;

	while (a != middle && b != end)
		if (*a < *b)
			*r++ = *a++;
		else
			*r++ = *b++;

		while (a != middle)
			*r++ = *a++;

		while (b != end)
			*r++ = *b++;

		while (begin != end)
			*begin++ = *res++;
}

template<class Value, class ForwardIterator>
void Merge_sort(ForwardIterator begin, ForwardIterator end)
{
	int s = end - begin;

	if (s > 1)
	{
		Value *res = new Value[end - begin];
		ForwardIterator middle = begin + s / 2;
		Merge_sort<Value, ForwardIterator>(begin, middle);
		Merge_sort<Value, ForwardIterator>(middle, end);
		merge<Value, ForwardIterator>(begin, middle, end, res);
		delete res;
	}
}

#endif