#include <stack.hpp>
#include <iostream>

int main()
{
	std::cout << "Hello" << std::endl;
	std::cout << ft::value() << std::endl;

	ft::stack stack1;
	stack1.push(10);
	stack1.push(10);
	stack1.push(10);
}
