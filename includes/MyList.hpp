#ifndef MYLIST_HPP
#define MYLIST_HPP

/*
** Simple singly linked list
** Used as the underlying default container for ft::stack
*/

#include <iostream>

namespace ft
{
	template <class T>
	class MyList
	{
	public:
		// MEMBER TYPES --------------------------------------------------------
		typedef T value_type;
		typedef size_t size_type;
		typedef const value_type &const_reference;

	private:
		typedef struct s_list
		{
			value_type data;
			struct s_list *next;
		} t_list;
		t_list *_lst_start;
		t_list *_lst_last;
		std::allocator<t_list> _alloc;

	public:
		//MEMBER FUNCTIONS -----------------------------------------------------
		MyList(void) : _lst_start(NULL), _lst_last(NULL) {}

		MyList(MyList const &other)
		{
			*this = other;
		}

		~MyList(void)
		{
			t_list *tmp;

			while (_lst_start)
			{
				tmp = _lst_start->next;
				_alloc.deallocate(_lst_start, 1);
				_lst_start = tmp;
			}
		}

		MyList &operator=(MyList const &other)
		{
			t_list *tmp;
			t_list *list;

			_lst_start = NULL;
			_lst_last = NULL;
			tmp = other._lst_start;
			while (tmp != NULL)
			{
				list = _alloc.allocate(1);
				list->data = tmp->data;
				list->next = NULL;
				if (!this->_lst_last)
				{
					this->_lst_start = list;
					this->_lst_last = this->_lst_start;
				}
				else
				{
					this->_lst_last->next = list;
					this->_lst_last = list;
				}
				tmp = tmp->next;
			}
			return (*this);
		}

		// MODIFIERS -----------------------------------------------------------
		void push(const_reference input)
		{
			t_list *list;

			list = _alloc.allocate(1);
			list->data = input;
			list->next = NULL;
			if (!_lst_last) // Empty List
			{
				_lst_start = list;
				_lst_last = _lst_start;
			}
			else
			{
				_lst_last->next = list;
				_lst_last = list;
			}
		}

		void pop(void)
		{
			t_list *lst_copy;

			if (!_lst_start) // Empty List
				return;
			else if (_lst_start == _lst_last) // List with only 1 node
			{
				_alloc.deallocate(_lst_start, 1);
				_lst_start = NULL;
				_lst_last = NULL;
			}
			else // List with multiple nodes
			{
				lst_copy = _lst_start;
				while (lst_copy && lst_copy->next != _lst_last)
					lst_copy = lst_copy->next;
				_alloc.deallocate(_lst_last, 1);
				_lst_last = lst_copy;
				_lst_last->next = NULL;
			}
		}

		// Element Access ------------------------------------------------------
		const_reference top(void)
		{
			// Lib function will just seg fault without freeing memory
			return (_lst_last->data);
		}

		// Capacity ------------------------------------------------------------
		size_type size(void)
		{
			t_list *lst_copy;
			size_type i;

			lst_copy = _lst_start;
			for (i = 0; lst_copy; i++)
				lst_copy = lst_copy->next;
			return (i);
		}

		bool empty(void)
		{
			return (!_lst_start);
		}
	};
	/**************************NON-MEMBER FUNCTIONS****************************/
	template <class T>
	bool operator==(const ft::MyList<T> &lhs, const ft::MyList<T> &rhs)
	{
		(void)lhs;
		(void)rhs;
		return (true);
	}
}
#endif
