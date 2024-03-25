#pragma once

#include <iostream>

class Vector
{
public:
	Vector();
	Vector(const Vector& rhs);
	Vector(int elements, int value = 0);
	Vector(const std::initializer_list<int>& list);

	~Vector();

	void Push_back(int value);
	void Pop_back();

	bool Empty() const;
	int Size() const;
	int Capacity() const;

	bool operator==(const Vector& rhs) const;
	bool operator!=(const Vector& rhs) const;

	friend std::ostream& operator<<(std::ostream& ostr, const Vector& rhs);

	Vector& operator=(const Vector& rhs);
	int& operator[](int index);
	int& At(int index);
	int& Front();
	int& Back();

	void Insert(int index, int value);
	void Erase(int index);
	void Clear();

private:
	int size;
	int capacity;
	int* my_array;
};