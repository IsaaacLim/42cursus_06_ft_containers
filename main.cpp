#include <Stack.hpp>
#include <Vector.hpp>
#include <VectorIterator.hpp>
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
	vector1.push_back(30, 1);
	vector1.push_back(40);

	vector1.print();

	if (vector1.empty())
		std::cout << "IS EMPTY\n";
	else
		std::cout << "NOT EMPTY\n";

	std::cout << "Size\t: " << vector1.size() << '\n';
	std::cout << "Capacity: " << vector1.capacity() << '\n';

	// std::cout << "----- ITERATOR TEST -----\n";
	// it = vector1.begin();
	// std::cout << *it++ << '\n';
	// std::cout << *it++ << '\n';

	// it = vector1.end();
	// std::cout << *it-- << '\n';
	// std::cout << *it-- << '\n';

	std::cout << vector1.max_size() << '\n';


	// ft::vector<int>::iterator const const_it = vector1.begin() + 2;

	// std::cout << *const_it << '\n'; //handle this
}

void vector_iterator()
{
	int arr[5] = {10, 20, 30, 40, 50};
	ft::VectorIterator<int> i;
	ft::VectorIterator<int> j;

	std::cout << "Arr: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';

	i = arr;
	// std::cout << *i << '\n';
	// std::cout << *(i + 2) << '\n';
	// std::cout << *i << '\n';

	// i++;
	// std::cout << *i << '\n';
	// std::cout << *(i + -1) << '\n';
	// std::cout << *i << '\n';

	// i += 1;
	// std::cout << *i << '\n';
	// std::cout << *i << '\n';

	// i += -2;
	// std::cout << *i << '\n';
	// std::cout << *i << '\n';

	// i -= -2;
	// std::cout << *i << '\n';
	// std::cout << *(i - 2) << '\n';
	// std::cout << *i << '\n';

	// i -= 2;
	// std::cout << *i << '\n';
	// std::cout << *(i - -3) << '\n';
	// std::cout << *i << '\n';

	// i += 4;
	// std::cout << *i-- << '\n';
	// std::cout << *i << '\n';

	// std::cout << *++i << '\n';
	// std::cout << *--i << '\n';

	// i = arr;
	// std::cout << *i << '\n';
	// std::cout << i[2] << '\n';
	// i += 3;
	// std::cout << *i << '\n';
	// std::cout << i[-2] << '\n';

	i = arr;
	j = arr;

	// ++j;
	if (++i <= j)
		std::cout << "Less than\n";
	else
		std::cout << "opposite\n";

}


int main()
{
	// std::cout << "Hello" << std::endl;
	// std::cout << ft::value() << std::endl;

	// stack_int();
	// stack_str(); // works but got leaks

	vector_int();

	// vector_iterator();
}
