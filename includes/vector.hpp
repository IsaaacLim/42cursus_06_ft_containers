#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include "VectorIterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T>>
	class vector
	{
	public:
		// MEMBER TYPES ----------------------------------------------------- OK
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef ft::VectorIterator<value_type> iterator;
		typedef ft::VectorIterator<value_type const> const_iterator;
		typedef ft::ReverseVectorIterator<T> reverse_iterator;
		typedef const ft::ReverseVectorIterator<T> const_reverse_iterator;

	private:
		pointer _arr;		   // pointer to the address of the vector
		size_type _capacity;   // capacity of the vector
		size_type _current;	   // num of elements currently in the vector
		allocator_type _alloc; // stores the given allocator type during instantiation

	public:
		// MEMBER FUNCTIONS ----------------------------------------------- done
		vector(void);																		  // (1)
		explicit vector(const Allocator &alloc);											  // (2)
		explicit vector(T count, const T &value = T(), const Allocator &alloc = Allocator()); // (3) & (4)
		template <class InputIt>															  //
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator());			  // (5)
		vector(const vector &other);														  // (6)
		~vector(void);
		vector &operator=(const vector &other);
		void assign(size_type count, const T &value);
		template <class InputIt>
		void assign(InputIt first, InputIt last);
		allocator_type get_allocator() const;

		// ELEMENT ACCESS ------------------------------------------------- done
		reference at(size_type pos);
		const_reference at(size_type pos) const;
		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;
		reference front(void);
		const_reference front(void) const;
		reference back(void);
		const_reference back(void) const;
		T *data(void);
		const T *data(void) const;

		// ITERATORS -----------------------------------------------------------
		iterator begin(void);
		iterator end(void);
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_iterator begin(void) const;
		const_iterator end(void) const;

		// CAPACITY ------------------------------------------------------- done
		bool empty(void) const;
		size_type size(void) const;
		size_type max_size(void);
		void reserve(size_type new_cap);
		size_type capacity(void);

		// MODIFIERS ------------------------------------------------------ done
		void clear(void);
		iterator insert(iterator pos, const T &value);
		void insert(iterator pos, T count, const T &value);
		template <typename InputIt>
		void insert(iterator pos, InputIt first, InputIt last);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const value_type &input);
		void pop_back(void);
		void resize(size_type count);
		void resize(size_type count, value_type val);
		void swap(vector &other);
	};

	/**************************NON-MEMBER FUNCTIONS****************************/
	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		size_t i;

		i = 0;
		while (i < lhs.size() && i < rhs.size())
		{
			if (lhs[i] != rhs[i])
				break;
			i++;
		}
		if (i != lhs.size() || i != rhs.size())
			return (false);
		else
			return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		size_t i;

		i = 0;
		while (i < lhs.size() && i < rhs.size())
		{
			if (lhs[i] != rhs[i])
				return (lhs[i] < rhs[i]);
			i++;
		}
		if (i == lhs.size() && i == rhs.size())
			return (false);
		else if (i == lhs.size())
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		size_t i;

		i = 0;
		while (i < lhs.size() && i < rhs.size())
		{
			if (lhs[i] != rhs[i])
				return (lhs[i] < rhs[i]);
			i++;
		}
		if (i == lhs.size())
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs) && lhs != rhs);
	}

	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
	{
		ft::vector<T> tmp;

		tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}
}

/************************MEMBER FUNCTION DECLARATIONS**************************/

// MEMBER FUNCTIONS ============================================================
template <typename T, typename A>
ft::vector<T, A>::vector(void)
{
	_arr = _alloc.allocate(1); // initial capacity of 1 element
	_capacity = 1;
	_current = 0;
}

template <typename T, typename A>
ft::vector<T, A>::vector(const allocator_type &alloc) : _alloc(alloc)
{
	_arr = _alloc.allocate(1);
	_capacity = 1;
	_current = 0;
}

// test with std::string (directly use push_back)
template <typename T, typename A>
ft::vector<T, A>::vector(T count, const_reference value, const allocator_type &alloc) : _current(0), _alloc(alloc)
{
	_arr = _alloc.allocate(count);
	while (_current < (size_type)count)
		_arr[_current++] = value;
	_capacity = count;
}

template <typename T, typename A>
template <typename InputIt>
ft::vector<T, A>::vector(InputIt first, InputIt last, const allocator_type &alloc) : _capacity(0), _current(0), _alloc(alloc)
{
	_arr = _alloc.allocate(0);
	assign(first, last);
}

template <typename T, typename A>
ft::vector<T, A>::vector(const vector &other) : _capacity(0) { *this = other; }

template <typename T, typename A>
ft::vector<T, A>::~vector(void)
{
	clear();
	_alloc.deallocate(_arr, _capacity);
}

template <typename T, typename A>
ft::vector<T, A> &ft::vector<T, A>::operator=(const vector &other)
{
	iterator thisIt;
	const_iterator otherIt;

	if (_capacity != 0)
		_alloc.deallocate(_arr, _capacity);
	_arr = _alloc.allocate(1);
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

template <typename T, typename A>
void ft::vector<T, A>::assign(size_type count, const_reference value)
{
	clear();
	resize(count, value);
}

template <typename T, typename A>
template <typename InputIt>
void ft::vector<T, A>::assign(InputIt first, InputIt last)
{
	clear();
	insert(begin(), first, last);
}

template <typename T, typename A>
typename ft::vector<T, A>::allocator_type ft::vector<T, A>::get_allocator() const
{
	return _alloc;
}

// ELEMENT ACCESS ==============================================================
template <typename T, typename A>
typename ft::vector<T, A>::reference ft::vector<T, A>::at(size_type pos)
{
	if (pos >= _current)
		throw std::runtime_error("this index is out of range");
	return (_arr[pos]);
}

template <typename T, typename A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::at(size_type pos) const
{
	if (pos >= _current)
		throw std::runtime_error("this index is out of range");
	return (_arr[pos]);
}

template <typename T, typename A>
typename ft::vector<T, A>::reference ft::vector<T, A>::operator[](size_type pos) { return (_arr[pos]); }

template <typename T, typename A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::operator[](size_type pos) const { return (_arr[pos]); }

template <typename T, typename A>
typename ft::vector<T, A>::reference ft::vector<T, A>::front(void) { return (_arr[0]); }

template <typename T, typename A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::front(void) const { return (_arr[0]); }

template <typename T, typename A>
T &ft::vector<T, A>::back(void) { return (_arr[_current - 1]); }

template <typename T, typename A>
const T &ft::vector<T, A>::back(void) const { return (_arr[_current - 1]); }

template <typename T, typename A>
T *ft::vector<T, A>::data(void) { return _arr; }

template <typename T, typename A>
const T *ft::vector<T, A>::data(void) const { return _arr; }

// CAPACITY ====================================================================
template <typename T, typename A>
bool ft::vector<T, A>::empty(void) const { return (!_current); }

template <typename T, typename A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::size(void) const { return (_current); }

template <typename T, typename A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::max_size(void)
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type) / 2);
}

template <typename T, typename A>
void ft::vector<T, A>::reserve(size_type new_cap)
{
	pointer tmp;
	size_type i;

	if (new_cap <= _capacity)
		return;
	tmp = _alloc.allocate(new_cap * sizeof(value_type));
	for (i = 0; i < _current; i++)
	{
		new (tmp + i) value_type; // placement new
		tmp[i] = _arr[i];
	}
	clear();
	_alloc.deallocate(_arr, _capacity);
	_arr = tmp;
	_current = i;
	_capacity = new_cap;
}

template <typename T, typename A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::capacity(void) { return (_capacity); }

// MODIFIERS ===================================================================
template <typename T, typename A>
void ft::vector<T, A>::clear(void)
{
	if (_current <= 0)
		return;
	for (size_type i = 0; i < _current; i++)
		(_arr + i)->~value_type();
	_current = 0;
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
void ft::vector<T, A>::insert(iterator pos, T count, const_reference value)
{
	if (pos > end())
		return;
	while (count > 0)
	{
		pos = insert(pos, value);
		count--;
	}
}

template <typename T, typename A>
template <typename InputIt>
void ft::vector<T, A>::insert(iterator pos, InputIt first, InputIt last)
{
	if (pos > end())
		return;
	while (first != last)
	{
		pos = insert(pos, *first) + 1;
		first++;
	}
}

template <typename T, typename A> // WORKING HERE
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase(iterator pos)
{
	iterator tmp;

	tmp = pos;
	while (tmp != end())
	{
		// tmp->~value_type();
		// new (tmp) value_type;
		*tmp = *(tmp + 1);
		tmp++;
	}
	_current--;
	// pop_back(); // testing
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
	if (_current == _capacity)
		reserve(2 * _capacity);
	new (_arr + _current) value_type;
	_arr[_current++] = input;
}

template <typename T, typename A>
void ft::vector<T, A>::pop_back(void)
{
	if (_current > 0)
		(_arr + --_current)->~value_type();
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
typename ft::vector<T, A>::iterator ft::vector<T, A>::begin(void) { return (&_arr[0]); }

template <class T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::end(void) { return (&_arr[_current]); }

template <class T, class A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::rbegin(void)
{
	return (&_arr[_current - 1]);
}

template <class T, class A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::rend(void)
{
	return (&_arr[-1]);
}

template <class T, class A>
typename ft::vector<T, A>::const_iterator ft::vector<T, A>::begin(void) const { return (&_arr[0]); }

template <class T, class A>
typename ft::vector<T, A>::const_iterator ft::vector<T, A>::end(void) const { return (&_arr[_current]); }

#endif
