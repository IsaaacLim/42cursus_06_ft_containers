#include <stack.hpp>
#include <iostream>

void stack_int()
{
	ft::stack<int> stack1;

	if (stack1.empty())
		std::cout << "Stack empty\n";
	else
		std::cout << "Stack not empty\n";

	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);

	stack1.pop(); // remove 40

	std::cout << "Top\t: " << stack1.top() << '\n';
	std::cout << "Size\t: " << stack1.size() << '\n';

	stack1.pop(); // remove 30
	stack1.pop(); // remove 20
	std::cout << "Top\t: " << stack1.top() << '\n';

	stack1.pop(); // remove 10
	stack1.pop(); // remove nothing
	stack1.pop(); // remove nothing

	stack1.push(300);
	stack1.push(200);
	stack1.push(100);

	std::cout << "Stack\t: ";
	while (!stack1.empty())
	{
		std::cout << stack1.top() << ' ';
		stack1.pop();
	}
	std::cout << std::endl;
}

void stack_str()
{
	ft::stack<std::string> stack2;

	stack2.push("Hello");
	stack2.push("Stack");
	stack2.push("2");

	stack2.print();

	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
}

int main()
{
	// std::cout << "Hello" << std::endl;
	// std::cout << ft::value() << std::endl;

	// stack_int();
	stack_str(); // works but got leaks
}
