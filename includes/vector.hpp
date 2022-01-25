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
		vector &operator=(vector &other);
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

		// MODIFIERS --------------------------------------- fix insert overload
		void clear(void);
		iterator insert(iterator pos, const T &value);
		void insert(iterator pos, size_type count, const T &value);
		// template <class InputIt>
		// void insert(iterator pos, InputIt first, InputIt last); //issue with the prev type
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const value_type &input);
		void pop_back(void);
		void resize(size_type count);
		void resize(size_type count, value_type val);
		void swap(vector &other);

		// Non-member functions ------------------------------------------------

		// TMP -----------------------------------------------------------------
		void print();
	};
}

/*******************************DEFINITIONS************************************/

// MEMBER FUNCTIONS ============================================================
template <typename T, typename A>
ft::vector<T, A>::vector(void)
{
	allocator_type alloc;

	_arr = alloc.allocate(1); // initial capacity of 1 element
	_capacity = 1;
	_current = 0;
}

template <typename T, typename A>
ft::vector<T, A>::~vector(void)
{
	allocator_type alloc;

	alloc.deallocate(_arr, _capacity);
}

template <typename T, typename A>
ft::vector<T, A> &ft::vector<T, A>::operator=(vector &other)
{
	allocator_type alloc;
	iterator thisIt;
	iterator otherIt;

	if (_arr != 0)
		alloc.deallocate(_arr, _capacity);
	_arr = alloc.allocate(1);
	_capacity = 1;
	_current = 0;
	thisIt = this->begin();
	otherIt = other.begin();
	while (otherIt != other.end())
	{
		thisIt = insert(thisIt, *otherIt) + 1;
		otherIt++;
	}
	return (*this);
}

// CAPACITY ====================================================================
template <typename T, typename A>
bool ft::vector<T, A>::empty(void) { return (!_current); }

template <typename T, typename A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::size(void) { return (_current); }

template <typename T, typename A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::max_size(void)
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

template <typename T, typename A>
void ft::vector<T, A>::reserve(size_type new_cap)
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

template <typename T, typename A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::capacity(void) { return (_capacity); }

// MODIFIERS ===================================================================
template <typename T, typename A>
void ft::vector<T, A>::clear(void)
{
	while (--_current > 0)
		_arr[_current] = 0;
	_arr[_current] = 0;
}

template <typename T, typename A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::insert(iterator pos, const_reference value)
{
	iterator it;
	size_type i;

	i = 0;
	for (it = begin(); it < pos && i <= _current; it++)
		i++;
	if (i > _current) // allow insert at the last index
		return (NULL);
	if (_current + 1 > _capacity)
		reserve(_current + 1);
	for (size_type j = _current; j > i; j--)
		_arr[j] = _arr[j - 1];
	_arr[i] = value;
	_current++;
	return (&_arr[i]);
}

template <typename T, typename A>
void ft::vector<T, A>::insert(iterator pos, size_type count, const_reference value)
{
	if (pos > end())
		return;
	while (count > 0)
	{
		pos = insert(pos, value);
		count--;
	}
}

// template <typename T, typename A>
// template <class InputIt>
// void ft::vector<T, A>::insert(iterator pos, InputIt first, InputIt last)
// {
// 	if (pos > end())
// 		return;
// 	while (first != last)
// 	{
// 		pos = insert(pos, *first) + 1;
// 		first++;
// 	}
// }

template <typename T, typename A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase(iterator pos)
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

template <typename T, typename A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		erase(first);
		last--;
	}
	return (first);
}

template <typename T, typename A>
void ft::vector<T, A>::push_back(const_reference input)
{
	allocator_type alloc;
	pointer tmp;

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

template <typename T, typename A>
void ft::vector<T, A>::pop_back(void)
{
	if (_current > 0)
		_arr[_current--] = 0; //test
}

template <typename T, typename A>
void ft::vector<T, A>::resize(size_type count)
{
	while (count < _current)
		pop_back();
	while (count > _current)
		push_back(0);
}

template <typename T, typename A>
void ft::vector<T, A>::resize(size_type count, value_type value)
{
	while (count < _current)
		pop_back();
	while (count > _current)
		push_back(value);
}

template <typename T, typename A>
void ft::vector<T, A>::swap(vector &other)
{
	ft::vector<T> tmp;

	tmp = *this;
	*this = other;
	other = tmp;
}

// ITERATORS ===================================================================
template <class T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::begin(void)
{
	return (&_arr[0]);
}

template <class T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::end(void)
{
	return (&_arr[this->_current]);
}

// TMP =========================================================================
template <typename T, typename A>
void ft::vector<T, A>::print(void)
{
	for (size_type i = 0; i < _current; i++)
		std::cout << _arr[i] << ' ';
	std::cout << std::endl;
}

#endif
