#include "Vector.h"

Vector::Vector() : 
	size(0), 
	capacity(5), 
	my_array(new int [capacity]) {}

Vector::Vector(const Vector& rhs) : 
	size(rhs.size), 
	capacity(rhs.capacity), 
	my_array(new int[capacity])
{
	for (int i = 0; i < rhs.Size(); ++i)
	{
		my_array[i] = rhs.my_array[i];
	}
}

Vector::Vector(int elements, int value) : 
	size(elements), 
	capacity(elements + 5), 
	my_array(new int[capacity]) 
{
	for (int i = 0; i < size; ++i)
	{
		my_array[i] = value;
	}
}

Vector::Vector(const std::initializer_list<int>& list) : 
	size(0), 
	capacity(list.size() + 5), 
	my_array(new int[capacity])
{
	for (int i : list)
	{
		Push_back(i);
	}
}

Vector::~Vector()
{
	delete[] my_array;
}

void Vector::Push_back(int value)
{
	if (size < capacity)
	{
		my_array[size] = value;
		size++;
	}
	else
	{
		capacity *= 2;
		int* new_array = new int[capacity];
		for (int i = 0; i < size; ++i)
		{
			new_array[i] = my_array[i];
		}
		new_array[size] = value;
		++size;
		delete[] my_array;
		my_array = new_array;
	}

}

void Vector::Pop_back()
{
	if (size == 0)
	{
		throw std::exception("Pop back on empty vector!");
	}
	--size;
}

bool Vector::Empty() const
{
	return size == 0;
}

int Vector::Size() const
{
	return size;
}

int Vector::Capacity() const
{
	return capacity;
}

bool Vector::operator==(const Vector& rhs) const
{
	if (Size() != rhs.Size())
	{
		return false;
	}

	for (int i = 0; i < rhs.Size(); ++i)
	{
		if (my_array[i] != rhs.my_array[i])
		{
			return false;
		}
	}

	return true;
}

bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (rhs.size > size)
	{
		delete[] my_array;
		capacity = rhs.size + 5;
		my_array = new int[rhs.size + 5];
	}

	for (int i = 0; i < rhs.Size(); ++i)
	{
		my_array[i] = rhs.my_array[i];
	}

	size = rhs.size;

	return *this;
}

int& Vector::operator[](int index)
{
	return my_array[index];
}

int& Vector::At(int index)
{
	if ((index < 0) || (index >= size))
	{
		throw std::exception("Index out of range!");
	}
	return my_array[index];
}

int& Vector::Front()
{
	return my_array[0];
}

int& Vector::Back()
{
	return my_array[size - 1];
}

void Vector::Insert(int index, int value)
{
	if ((index < 0) || (index >= size))
	{
		throw std::exception("Insert - index out of range!");
	}

	if (size != capacity)
	{
		for (int i = size - 1; i >= index; --i)
		{
			my_array[i + 1] = my_array[i];
		}

		my_array[index] = value;
		++size;
	}
	else
	{
		capacity *= 2;
		int* new_array = new int[capacity];
		for (int i = 0; i < size; ++i)
		{
			new_array[i] = my_array[i];
		}

		delete[] my_array;
		my_array = new_array;
		Insert(index, value);
	}
}

void Vector::Erase(int index)
{
	if ((index < 0) || (index >= size))
	{
		throw std::exception("Erase - index out of range!");
	}

	for (int i = index; i < size - 1; ++i)
	{
		my_array[i] = my_array[i + 1];
	}
	--size;
}

void Vector::Clear()
{
	size = 0;
}

std::ostream& operator<<(std::ostream& ostr, const Vector& rhs)
{
	for (int i = 0; i < rhs.size; ++i)
	{
		ostr << rhs.my_array[i] << " ";
	}

	ostr << " || ";

	for (int i = rhs.size; i < rhs.capacity; ++i)
	{
		ostr << rhs.my_array[i] << " ";
	}

	ostr << std::endl;

	return ostr;
}