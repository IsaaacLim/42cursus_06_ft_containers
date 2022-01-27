#include "stack.hpp"
#include "vector.hpp"
#include "VectorIterator.hpp"
#include <iostream>
#include <stack>
#include <deque>

int main()
{
	std::stack<int> stack;
	std::stack<int> stack2;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(5);
	stack.push(5);

	stack2.push(1);
	stack2.push(2);
	stack2.push(4);
	stack2.push(4);
	stack2.push(5);

	std::cout << std::boolalpha;
	std::cout << "stack > stack2 ? " << (stack > stack2) << '\n';
	std::cout << std::noboolalpha;
}
