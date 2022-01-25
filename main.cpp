#include "stack.hpp"
#include "vector.hpp"
#include "VectorIterator.hpp"
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
	ft::vector<long> vector1;
	ft::vector<int>::iterator it; //<long> iterator not working

	vector1.push_back(10);
	vector1.push_back(20);
	vector1.push_back(30);
	vector1.push_back(40);

	// std::cout << "----- ITERATOR TEST -----\n";
	// it = vector1.begin();
	// std::cout << *it++ << '\n';
	// std::cout << *it++ << '\n';

	// it = vector1.end();
	// std::cout << *it-- << '\n';
	// std::cout << *it-- << '\n';

	// ft::vector<int>::iterator const const_it = vector1.begin() + 2;

	// std::cout << *const_it << '\n'; //handle this

	// Capacity Functions
	{
		std::cout << "---------- CAPACITY ----------\n";
		ft::vector<int> vec;

		std::cout << "max_size()\t: " << vec.max_size() << '\n';

		if (vec.empty())
			std::cout << "empty()\t\t: IS EMPTY\n";
		else
			std::cout << "empty()\t\t: NOT EMPTY\n";

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);

		vec.reserve(2);

		std::cout << "size()\t\t: " << vec.size() << '\n';
		std::cout << "capacity()\t: " << vec.capacity() << '\n';

		vec.reserve(10);

		std::cout << "size()\t\t: " << vec.size() << '\n';
		std::cout << "capacity()\t: " << vec.capacity() << '\n';

		if (vec.empty())
			std::cout << "empty()\t\t: IS EMPTY\n";
		else
			std::cout << "empty()\t\t: NOT EMPTY\n";

		std::cout << "Final arr\t: ";
	}
	// Modifiers Functions
	{
		std::cout << "---------- MODIFIERS ----------\n";
		ft::vector<int> vec;

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
	}
}

int main()
{
	// std::cout << "Hello" << std::endl;
	// std::cout << ft::value() << std::endl;

	// stack_int();
	// stack_str(); // works but got leaks

	vector_int();
}
