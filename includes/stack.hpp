#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <iostream>

namespace ft
{
	template <class T, class Container = ft::vector<T>>
	class stack
	{
	public:
		// MEMBER TYPES --------------------------------------------------------
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	protected:
		// MEMBER OBJECTS ------------------------------------------------------
		container_type c;

	public:
		// MEMBER FUNCTIONS ----------------------------------------------------
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
		stack(const stack &other) { *this = other; }
		~stack(void) {}
		stack &operator=(const stack &other)
		{
			c = other.c;
			return (*this);
		}

		// ELEMENT ACCESS ------------------------------------------------------
		reference top(void) { return (c.back()); }
		const_reference top(void) const { return (c.back()); }

		// CAPACITY ------------------------------------------------------------
		bool empty(void) const { return (c.empty()); }
		size_type size(void) const { return (c.size()); }

		// MODIFIERS -----------------------------------------------------------
		void push(const value_type &value) { c.push_back(value); }
		void pop(void) { c.pop_back(); }

	private:
		// NON-MEMBER FUNCTIONS ------------------------------------------------
		template <class A, class B>
		friend bool operator==(const stack<A, B> &lhs, const stack<A, B> &rhs);
		template <class A, class B>
		friend bool operator!=(const stack<A, B> &lhs, const stack<A, B> &rhs);
		template <class A, class B>
		friend bool operator<(const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template <class A, class B>
		friend bool operator<=(const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template <class A, class B>
		friend bool operator>(const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
		template <class A, class B>
		friend bool operator>=(const ft::stack<A, B> &lhs, const ft::stack<A, B> &rhs);
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif
