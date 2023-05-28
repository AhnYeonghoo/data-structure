#pragma once
#include <iostream>

class Node
{
public:
	int data_;
	Node* next_;
};

void printList(Node* head)
{
	Node* cursor = new Node();
	if (head == NULL)
		std::cout << "The head is NULL";
	else
	{
		cursor = head->next_;
		while (cursor != NULL)
		{
			std::cout << cursor->next_ << " ";
			cursor = cursor->next_;
		}
	}
}

Node* insert(Node* head, int new_data)
{
	if (head == NULL)
	{
		std::cout << "The head is NULL";
		return head;
	}
	
	Node* new_node = new Node();
	new_node->data_ = new_data;
	new_node->next_ = head->next_;
	head->next_ = new_node;
	return head;
}

Node* deleteNode(Node* head, int key)
{
	if (head == NULL)
	{
		std::cout << "The head is NULL";
		return head;
	}
	
	Node* cursor = new Node();
	cursor = head;
	while (cursor->next_->data_ != key)
	{
		cursor = cursor->next_;
	}
	
	Node* temp = new Node();
	temp = cursor->next_;
	cursor->next_ = cursor->next_->next_;
	delete temp;
	return head;
}