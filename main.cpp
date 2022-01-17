#include <stack.hpp>
#include <vector.hpp>
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

void vector_int()
{
	ft::vector<int> vector1;

	vector1.push_back(10);
	vector1.push_back(20);
	vector1.push_back(30, 1);
	vector1.push_back(40);

	vector1.print();

	if (vector1.empty())
		std::cout << "IS EMPTY\n";
	else
		std::cout << "NOT EMPTY\n";

	std::cout << "Size\t: " << vector1.size() << '\n';
	std::cout << "Capacity: " << vector1.capacity() << '\n';
}

int main()
{
	// std::cout << "Hello" << std::endl;
	// std::cout << ft::value() << std::endl;

	// stack_int();
	// stack_str(); // works but got leaks

	vector_int();
}
