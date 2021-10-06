#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
public:
	Array() : _size(0), arr(new T[0]) {}
	Array(unsigned int n) : _size(n), arr(new T[n]) {}
	Array(const Array& a) : _size(0), arr(0)
	{
		*this = a;
	}
	~Array()
	{
		delete[] arr;
	}
	Array& operator= (const Array& a)
	{
		_size = a._size;
		if (arr)
			delete[] arr;
		arr = new T[_size];
		for (size_t i = 0; i < _size; i++)
			arr[i] = a.arr[i];
		return *this;
	}
	
	T& operator[] (int idx)
	{
		if (idx < 0 || static_cast<size_t>(idx) >= _size)
			throw std::out_of_range("index out of range");
		return arr[idx];
	}
	unsigned int size() const
	{
		return _size;
	}

private:
	size_t _size;
	T* arr;
};

#endif
