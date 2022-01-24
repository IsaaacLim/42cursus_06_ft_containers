#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include "VectorIterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T>>
	// template <typename T>
	// template < template < typename, typename > class Container, typename T>
	class vector
	{
	public:
		// MEMBER TYPES ------------------------------------------------not done
		typedef T value_type;
		typedef Allocator allocator_type;
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
		void clear(void);
		iterator insert(iterator pos, const T &value);
		void insert(iterator pos, size_type count, const T &value);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const value_type &input);
		void pop_back(void);
		void resize(size_type count);
		void resize(size_type count, value_type val);
		// swap

		// Non-member functions ------------------------------------------------

		// TMP -----------------------------------------------------------------
		void print();
	};
}

/*******************************DEFINITIONS************************************/

// template <typename T>
template <typename T, typename Allocator>
// template <class T>
ft::vector<T, Allocator>::vector(void)
{
	allocator_type alloc;

	_arr = alloc.allocate(1); // initial capacity of 1 element
	_capacity = 1;
	_current = 0;
}

// template <typename T>
template <typename T, typename Allocator>
ft::vector<T, Allocator>::~vector(void)
{
	allocator_type alloc;

	alloc.deallocate(_arr, _capacity);
}

// CAPACITY ====================================================================
template <typename T, typename Allocator>
bool ft::vector<T, Allocator>::empty(void) { return (!_current); }

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::size(void) { return (_current); }

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::max_size(void)
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::reserve(size_type new_cap)
{
	allocator_type alloc;
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

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::capacity(void) { return (_capacity); }

// MODIFIERS ===================================================================
template <typename T, typename Allocator>
void ft::vector<T, Allocator>::clear(void)
{
	while (_current > 0)
		_arr[_current--] = 0;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::insert(iterator pos, const_reference value)
{
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase(iterator pos)
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

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		erase(first);
		last--;
	}
	return (first);
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::push_back(const_reference input)
{
	allocator_type alloc;
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

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::pop_back(void)
{
	if (_current > 0)
		_arr[_current--] = 0;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::resize(size_type count)
{
	while (count < _current)
		pop_back();
	while (count > _current)
		push_back(0);
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::resize(size_type count, value_type value)
{
	while (count < _current)
		pop_back();
	while (count > _current)
		push_back(value);
}

// ITERATORS ===================================================================
template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::begin(void)
{
	return (&_arr[0]);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::end(void)
{
	return (&_arr[this->_current - 1]);
}

// template <class T>
// typename ft::vector<T, Allocator>::iterator const ft::vector<T, Allocator>::begin() const
// {
// 	std::cout << "const vec iterator\n";
// 	return (&_arr[0]);
// }

// TMP =========================================================================
template <typename T, typename Allocator>
void ft::vector<T, Allocator>::print(void)
{
	for (size_type i = 0; i < _current; i++)
		std::cout << _arr[i] << ' ';
	std::cout << std::endl;
}

#endif
