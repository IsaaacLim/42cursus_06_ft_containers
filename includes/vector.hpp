#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
	// template <typename T, typename A = std::allocator<T> >
	template <typename T>
	class vector
	{
	private:
		T *_arr;	   // pointer to the address of the vector
		int _capacity; // capacity of the vector
		int _current;  // num of elements currently in the vector
	public:
		vector(/* args */);
		~vector();

		// ITERATORS -----------------------------------------------------------
		class iterator;
		iterator begin();
		const iterator begin() const;

		// CAPACITY ------------------------------------------------------------
		bool empty(void);
		int size(void);
		// int max_size();
		// void reserve();
		int capacity(void);

		// MODIFIERS -----------------------------------------------------------
		void push_back(const T &input);
		void push_back(const T &input, int index);
		void pop_back(void);

		// TMP -----------------------------------------------------------------
		void print();
	};
}

// ITERATORS ===================================================================
template <class T>
class ft::vector<T>::iterator
{
private:
	T *_it;

public:
	iterator(T *p) : _it(p) {}
};

template <typename T>
ft::vector<T>::vector(/* args */)
{
	std::allocator<T> alloc;
	_arr = alloc.allocate(1); // initial capacity of 1 element
	_capacity = 1;
	_current = 0;
}

template <typename T>
ft::vector<T>::~vector()
{
	std::allocator<T> alloc;

	alloc.deallocate(_arr, _capacity);
}

// CAPACITY ====================================================================
template <typename T>
bool ft::vector<T>::empty(void) { return (!_current); }

template <typename T>
int ft::vector<T>::size(void) { return (_current); }

template <typename T>
int ft::vector<T>::capacity(void) { return (_capacity); }

// MODIFIERS ===================================================================
template <typename T>
void ft::vector<T>::push_back(const T &input)
{
	std::allocator<T> alloc;
	T *tmp;

	if (_current == _capacity)
	{
		tmp = alloc.allocate(2 * _capacity); // double capacity
		for (int i = 0; i < _capacity; i++)	 // copy data to new array
			tmp[i] = _arr[i];
		alloc.deallocate(_arr, _capacity); // delete prev array
		_capacity *= 2;
		_arr = tmp;
	}
	_arr[_current] = input;
	_current++;
}

template <typename T>
void ft::vector<T>::push_back(const T &input, int index)
{
	if (index > _capacity)
		std::cout << "TOO MUCH\n";
	if (index == _capacity)
		push_back(input);
	else
		_arr[index] = input;
}

// ITERATORS ===================================================================
template <class T>
inline typename ft::vector<T>::iterator ft::vector<T>::begin()
{
	return ft::vector<T>::iterator(&_arr[0]);
}

template <class T>
inline typename ft::vector<T>::iterator const ft::vector<T>::begin() const
{
	return ft::vector<T>::iterator(&_arr[0]);
}

// TMP =========================================================================
template <typename T>
void ft::vector<T>::print(void)
{
	for (int i = 0; i < _current; i++)
		std::cout << _arr[i] << ' ';
	std::cout << std::endl;
}

#endif
