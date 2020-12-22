#include <iostream>
#include "..\..\Lib\Queue\queue.h"

Queue::Queue()
{
	
}
bool Queue::empty()
{
	return l.empty();
}
int Queue::size()
{
	return l.size();
}
int& Queue::front() // ссылка на начало
{
	return l.front();
}
int& Queue::back() // ссылка на конец
{
	return l.back();
}
void Queue::push(int value)
{
	l.push_back(value);
}
void Queue::pop()
{
	l.pop_front();
}
Queue::~Queue()
{

}