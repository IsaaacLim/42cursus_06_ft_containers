#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include "VectorIterator.hpp"

namespace ft
{
	// template <typename T, typename Allocator = std::allocator<T> >
	template <typename T>
	class vector
	{
	public:
		// MEMBER TYPES ------------------------------------------------not done
		typedef T value_type;
		// typedef Allocator allocator_type;
		typedef size_t size_type;
		// typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef T *pointer;
		// typedef const T *const_pointer;
		typedef ft::VectorIterator<value_type> iterator;
		typedef ft::VectorIterator<value_type const> const_iterator;
		// typedef ft::reverse_VectorIterator<T> reverse_iterator;
		// typedef const ft::reverse_VectorIterator<T> const_reverse_iterator;

	private:
		pointer _arr;		 // pointer to the address of the vector
		size_type _capacity; // capacity of the vector
		size_type _current;	 // num of elements currently in the vector

	public:
		// MEMBER FUNCTIONS --------------------------------------------not done
		vector(void);
		// vector(size_type n, const_reference val);
		// vector(with iterator);
		~vector(void);
		// assign
		// operator=
		// get_allocator

		// ELEMENT ACCESS ----------------------------------------------not done
		// at
		// operator[]
		// front
		// back
		// data

		// ITERATORS -----------------------------------------------------------
		iterator begin(void);
		iterator end(void);
		// iterator rbegin(void);
		// iterator rend(void);

		// CAPACITY ------------------------------------------------------- done
		bool empty(void);
		size_type size(void);
		size_type max_size();
		void reserve(size_type new_cap);
		size_type capacity(void);

		// MODIFIERS -----------------------------------------------------------
		// clear
		// insert
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const value_type &input);
		void pop_back(void); // not done
		// void resize(size_type n, value_type val);
		// swap

		// Non-member functions ------------------------------------------------

		// TMP -----------------------------------------------------------------
		void print();
	};
}

/*******************************DEFINITIONS************************************/

template <typename T>
// template <typename T, typename A = std::allocator<T> >
// template <class T, class Alloc>
ft::vector<T>::vector(void)
{
	std::allocator<T> alloc;
	_arr = alloc.allocate(1); // initial capacity of 1 element
	_capacity = 1;
	_current = 0;
}

template <typename T>
ft::vector<T>::~vector(void)
{
	std::allocator<T> alloc;

	alloc.deallocate(_arr, _capacity);
}

// CAPACITY ====================================================================
template <typename T>
bool ft::vector<T>::empty(void) { return (!_current); }

template <typename T>
typename ft::vector<T>::size_type ft::vector<T>::size(void) { return (_current); }

template <typename T>
typename ft::vector<T>::size_type ft::vector<T>::max_size(void)
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

template <typename T>
void ft::vector<T>::reserve(size_type new_cap)
{
	std::allocator<T> alloc;
	pointer tmp;
	size_type i;

	if (new_cap > _capacity)
	{
		tmp = alloc.allocate(new_cap);
		i = -1;
		while (++i < _current)
			tmp[i] = _arr[i];
		alloc.deallocate(_arr, _capacity);
		_arr = tmp;
		_capacity = new_cap;
	}
}

template <typename T>
typename ft::vector<T>::size_type ft::vector<T>::capacity(void) { return (_capacity); }

// MODIFIERS ===================================================================
template <typename T>
typename ft::vector<T>::iterator ft::vector<T>::erase(iterator pos)
{
	iterator tmp;

	tmp = pos;
	while (tmp != end())
	{
		*tmp = *(tmp + 1);
		tmp++;
	}
	_current--;
	return (pos);
}

template <typename T>
typename ft::vector<T>::iterator ft::vector<T>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		erase(first);
		last--;
	}
	return (first);
}

template <typename T>
void ft::vector<T>::push_back(const value_type &input)
{
	std::allocator<T> alloc;
	value_type *tmp;

	if (_current == _capacity)
	{
		tmp = alloc.allocate(2 * _capacity);	  // double capacity
		for (size_type i = 0; i < _capacity; i++) // copy data to new array
			tmp[i] = _arr[i];
		alloc.deallocate(_arr, _capacity); // delete prev array
		_capacity *= 2;
		_arr = tmp;
	}
	_arr[_current] = input;
	_current++;
}

// ITERATORS ===================================================================
template <class T>
typename ft::vector<T>::iterator ft::vector<T>::begin(void)
{
	return (&_arr[0]);
}

template <class T>
typename ft::vector<T>::iterator ft::vector<T>::end(void)
{
	return (&_arr[this->_current - 1]);
}

// template <class T>
// typename ft::vector<T>::iterator const ft::vector<T>::begin() const
// {
// 	std::cout << "const vec iterator\n";
// 	return (&_arr[0]);
// }

// TMP =========================================================================
template <typename T>
void ft::vector<T>::print(void)
{
	for (size_type i = 0; i < _current; i++)
		std::cout << _arr[i] << ' ';
	std::cout << std::endl;
}

#endif
