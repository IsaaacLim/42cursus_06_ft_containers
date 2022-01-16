/*
** Illustration of std::stack container
** Available public member functions (c++ 98)
**	- operator=
**	- top
**	- empty
**	- size
**	- push
**	- pop
** Not required (c++ 11)
**	- emplace
**	- swap
*/


#include <iostream>
#include <stack>

int main()
{
	std::stack<int> stack;

	stack.push(21);
	stack.push(22);
	stack.push(24);
	stack.push(25);

	std::cout << "Size: " << stack.size() << '\n';
	stack.pop();
	stack.pop();

	while (!stack.empty())
	{
		std::cout <<  stack.top() << ' ';
		stack.pop();
	}
}
