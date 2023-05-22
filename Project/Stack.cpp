#include "Stack.h"

Stack::Stack(int size)
{
	arr_ = new int[size];
	capacity_ = size;
	top_ = -1;
}

Stack::~Stack()
{
	delete[] arr_;
}

void Stack::push(int x)
{
	if (isFull())
	{
		std::cout << "Overflow\nProgram Terminated\n";
		std::exit(EXIT_FAILURE);
	}
	
	std::cout << "Inserting " << x << std::endl;
	arr_[++top_] = x;
}

int Stack::pop()
{
	if (isEmpty())
	{
		std::cout << "Underflow\nProgram Terminated\n";
		std::exit(EXIT_FAILURE);
	}
	
	std::cout << "Removing " << peek() << std::endl;
	return arr_[top_--];
}

int Stack::peek()
{
	if (!isEmpty())
		return arr_[top_];
	else
		std::exit(EXIT_FAILURE);
}

int Stack::size()
{
	return top_ + 1;
}

bool Stack::isEmpty()
{
	return top_ == -1;
}

bool Stack::isFull()
{
	return top_ == capacity_ - 1;
}

