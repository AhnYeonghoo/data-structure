#pragma once
#include <iostream>

class Array
{
private:
	int* arr_;
	int arr_size_;
	
public:
	Array(int size)
	{
		arr_size_ = size;
		arr_ = new int[arr_size_];
		for (int i = 0; i < size; i++)
			arr_[i] = 0;
	}
	
	int at(int idx)
	{
		return arr_[idx];
	}

	void add(int idx, int value)
	{
		if (idx > arr_size_ - 1)
			std::cout << -1 << std::endl;
		else
		{
			for (int i = arr_size_ - 2; i >= idx; i--)
				arr_[i + 1] = arr_[i];
		}
		arr_[idx] = value;
	}

	void remove(int idx)
	{
		for (int i = idx; i < arr_size_ - 1; i++)
		{
			arr_[i] = arr_[i + 1];
		}
		arr_[arr_size_ - 1] = 0;
	}

	void set(int idx, int value)
	{
		arr_[idx] = value;
	}

	void print()
	{
		for (int i = 0; i < arr_size_; i++)
		{
			std::cout << arr_[i] << " ";
		}
		std::cout << std::endl;
	}

};