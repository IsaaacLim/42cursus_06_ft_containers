#include <stack.hpp>
#include <iostream>

int main()
{
	std::cout << "Hello" << std::endl;
	std::cout << ft::value() << std::endl;

	ft::stack<int> stack1;

	if (stack1.empty())
		std::cout << "Empty\n";
	else
		std::cout << "Not empty\n";
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);

	stack1.print();

	stack1.pop();

	if (stack1.empty())
		std::cout << "Empty\n";
	else
		std::cout << "Not empty\n";

	stack1.print();

	std::cout << stack1.top() << '\n';
	std::cout << "Size: " << stack1.size() << '\n';

	stack1.pop();
	stack1.pop();
	std::cout << "top: " << stack1.top() << '\n';

	stack1.pop();
	stack1.pop();
	stack1.pop();

	if (stack1.empty())
		std::cout << "Empty\n";
	else
		std::cout << "Not empty\n";

	stack1.push(300);
	stack1.push(200);
	stack1.push(100);

	if (stack1.empty())
		std::cout << "Empty\n";
	else
		std::cout << "Not empty\n";

	stack1.print();
	std::cout << "top: " << stack1.top() << '\n';

	// works but got leaks
	ft::stack<std::string> stack2;
	stack2.push("Hello");
	stack2.push("Stack");
	stack2.push("2");
	stack2.print();
}
