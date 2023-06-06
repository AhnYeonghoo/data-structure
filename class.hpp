#pragma once
#include <iostream>

class Class
{
private:
	int n_[10];

public:
	Class()
	{
		std::cin >> n_[0];
		for (int i = 1; i < 10; i++)
		{
			n_[i] = i * 3;
		}
	}

	int get(int index) const;
	void put(int index, int value);
	Class operator++ (int);
	Class& operator+=(const Class& c);
	Class& operator!();

	
	friend std::ostream& operator<< (std::ostream& os, const Class& c)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 9)
			{
				os << c.n_[i];
			}
			else
			{
				os << c.n_[i] << ", ";
			}
		}
		os << '\n';


		return os;
	}

	friend std::istream& operator>> (std::istream& is, Class& c)
	{
		for (int i = 0; i < 10; i++)
		{
			is >> c.n_[i];
		}
		return is;
	}
};