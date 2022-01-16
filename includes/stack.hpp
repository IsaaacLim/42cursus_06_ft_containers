#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>

# define MAX 1000

namespace ft
{
	int value () {return 5;}

	// template <class T>
	class stack
	{
		private:
			int data;
			stack *next;
			// int a[MAX];
			int sizer;

		public:
			stack();
			~stack();
			// Stack(Stack &other); //copy constructor?

			bool push(int x);
			int pop();
			int top();
			bool empty();
			int size();
	};
}

ft::stack::stack()
{
	this->sizer = 0;
	this->next = NULL;
	// this->idx = -1;
	std::cout << "Constructor" << std::endl;
}

ft::stack::~stack()
{
	std::cout << "Destructor" << std::endl;
}

bool ft::stack::push(int x)
{
	stack *list = new stack();
	list->data = x;
	list->next = NULL;
	this->sizer++;
	if (this->sizer == 1)
	{
		this->next = list;
		std::cout << "First added" << '\n';
	}
	else
	{
		stack *list_copy = this->next;
		while (list_copy)
		{
			if (!list_copy->next)
				break;
			list_copy = list_copy->next;
		}
		// stack *last ;
		list_copy->next = list;
		std::cout << "Added more" << '\n';
	}
	// if (idx >= (MAX - 1))
	// {
	// 	std::cout << "Stack Overflow";
	// 	return false;
	// }
	// else
	// {
	// 	this->a[++idx] = x;
	// 	std::cout << x << " pushed into stack\n";
		return true;
	// }
}

#endif
