#pragma once
#include <iostream>
#include <cstdlib>

#define SIZE 10

class Stack
{
private:
	int* arr_;
	int top_;
	int capacity_;
	
public:
	Stack(int size = SIZE);
	~Stack();
	
	void push(int);
	int pop();
	int peek();
	
	int size();
	bool isEmpty();
	bool isFull();
};

