#include "Queue.h"

Queue::Queue(int size)
{
	arr_ = new int[size];
	capacity_ = size;
	front_ = 0;
	rear_ = -1;
	count_ = 0;
}

Queue::~Queue()
{
	delete[] arr_;
}

int Queue::dequeue()
{
	if (isEmpty())
	{
		std::cout << "Underflow\nProgram Terminated\n";
		std::exit(EXIT_FAILURE);
	}

	int x = arr_[front_];
	std::cout << "Removing " << x << std::endl;

	front_ = (front_ + 1) % capacity_;
	count_--;
	return x;
}

void Queue::enqueue(int x)
{
	if (isFull())
	{
		std::cout << "Overflow\nProgram Terminated\n";
		std::exit(EXIT_FAILURE);
	}
	
	std::cout << "Inserting " << x << std::endl;
	
	rear_ = (rear_ + 1) % capacity_;
	arr_[rear_] = x;
	count_++;
}

int Queue::size()
{
	return count_;
}

bool Queue::isEmpty()
{
	return (size() == 0);
}

bool Queue::isFull()
{
	return (size() == capacity_);
}