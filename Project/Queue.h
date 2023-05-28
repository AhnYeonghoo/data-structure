#pragma once
#include <iostream>
#include <cstdlib>

#define SIZE 1000

class Queue
{
private:
	int* arr_;
	int capacity_;
	int front_;
	int rear_;
	int count_;
	
public:
	Queue(int size = SIZE);
	~Queue();
	
	int dequeue();
	void enqueue(int x);
	int size();
	bool isEmpty();
	bool isFull();
};