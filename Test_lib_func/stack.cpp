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

void stack_int()
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
		std::cout << stack.top() << ' ';
		stack.pop();
	}

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();

	std::cout << stack.top() << '\n'; // Gives seg fault (no exception given)
}

void stack_str()
{
	std::stack<std::string> stack;

	stack.push("Hello");
	stack.push("Stack");
	stack.push("2");

	while (!stack.empty())
	{
		std::cout << stack.top() << ' ';
		stack.pop();
	}
	stack.pop(); // Gives seg fault
}

int main()
{
	// stack_int();
	stack_str();
}
