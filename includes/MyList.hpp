#ifndef MYLIST_HPP
#define MYLIST_HPP

/*
** Simple singly linked list
** Used as the underlying default container for ft::stack
*/

#include <iostream>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class MyList
	{
	public:
		// MEMBER TYPES --------------------------------------------------------
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef size_t size_type;

	private:
		typedef struct s_list
		{
			value_type data;
			struct s_list *next;
		} t_list;
		t_list *_lst_start;
		t_list *_lst_last;
	};
}
#endif
