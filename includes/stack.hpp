#ifndef STACK_HPP
#define STACK_HPP

#include "MyList.hpp"
#include <iostream>

namespace ft
{
	template <class T, class Container = ft::MyList<T>>
	class stack
	{
	public:
		// MEMBER TYPES --------------------------------------------------------
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	private:
		container_type c;
		// typedef struct s_list
		// {
		// 	T data;
		// 	struct s_list *next;
		// } t_list;
		// t_list *_lst_start;
		// t_list *_lst_last;

	public:
		// MEMBER FUNCTIONS ----------------------------------------------------
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
		~stack(void) {}
		// Stack(Stack &other); //copy constructor?

		// void push(const T &input);
		void pop(void)
		{
			c.pop();
		}
		// T top(void);
		// int size(void);
		// bool empty(void);

		// Temp
		// void print();
	};

	int value() { return 5; } // temp
}

// template <class T>
// ft::stack<T>::stack() : _lst_start(NULL), _lst_last(NULL) {}

// template <class T>
// ft::stack<T>::~stack()
// {
// 	std::allocator<t_list> alloc;
// 	t_list *temp;

// 	while (this->_lst_start)
// 	{
// 		temp = this->_lst_start->next;
// 		alloc.deallocate(this->_lst_start, 1);
// 		this->_lst_start = temp;
// 	}
// }

// template <class T>
// void ft::stack<T>::push(const T &input)
// {
// 	std::allocator<t_list> alloc;

// 	t_list *list = alloc.allocate(1);
// 	list->data = input;
// 	list->next = NULL;
// 	if (!this->_lst_last) // Empty stack
// 	{
// 		this->_lst_start = list;
// 		this->_lst_last = this->_lst_start;
// 	}
// 	else // Non-empty stack
// 	{
// 		this->_lst_last->next = list;
// 		_lst_last = list;
// 	}
// }

// template <class T>
// void ft::stack<T>::pop(void)
// {
// 	std::allocator<t_list> alloc;
// 	t_list *lst_copy;

// 	if (!this->_lst_start) // Empty stack
// 		return;
// 	else if (this->_lst_start == this->_lst_last) // Stack with only 1 node
// 	{
// 		alloc.deallocate(this->_lst_start, 1);
// 		this->_lst_start = NULL;
// 		this->_lst_last = NULL;
// 		return;
// 	}
// 	else // Stack with multiple nodes
// 	{
// 		lst_copy = this->_lst_start;
// 		while (lst_copy && lst_copy->next != this->_lst_last)
// 			lst_copy = lst_copy->next;
// 		alloc.deallocate(this->_lst_last, 1);
// 		this->_lst_last = lst_copy;
// 		this->_lst_last->next = NULL;
// 	}
// }

// // Lib function will just seg fault without freeing memory if stack is empty
// template <class T>
// T ft::stack<T>::top(void)
// {
// 	return (this->_lst_last->data);
// }

// template <class T>
// int ft::stack<T>::size(void)
// {
// 	t_list *lst_copy;
// 	int i;

// 	lst_copy = this->_lst_start;
// 	for (i = 0; lst_copy; i++)
// 		lst_copy = lst_copy->next;
// 	return (i);
// }

// template <class T>
// bool ft::stack<T>::empty(void)
// {
// 	return (!this->_lst_start);
// }

// // Temp
// template <class T>
// void ft::stack<T>::print()
// {
// 	t_list *lst_copy;

// 	lst_copy = this->_lst_start;
// 	while (lst_copy)
// 	{
// 		std::cout << lst_copy->data << ' ';
// 		lst_copy = lst_copy->next;
// 	}
// 	std::cout << '\n';
// }

#endif
