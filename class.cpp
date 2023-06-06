#include "class.hpp"

int Class::get(int index) const
{
	return this->n_[index];
}

void Class::put(int index, int value)
{
	this->n_[index] = value;
}

Class Class::operator++ (int)
{
	for (int i = 0; i < 10; i++)
	{
		this->n_[i] += 1;
	}
	return *this;
}

Class& Class::operator+=(const Class& c)
{
	for (int i = 0; i < 10; i++)
	{
		this->n_[i] += c.n_[i];
	}

	return (*this);
}

Class& Class::operator!()
{
	for (int i = 0; i < 10; i++)
	{
		if (this->n_[i] == 0) this->n_[i] = 1;
		else this->n_[i] = 0;
	}
	return (*this);
}

