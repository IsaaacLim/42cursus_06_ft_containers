#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <limits.h>
#include <string>
#include <stdlib.h>
#define RED "\033[3;31m"
#define RESET "\033[0m"

#if 0 // CREATE A REAL STL EXAMPLE
#include <stack>
namespace ft = std;
#else
#include "stack.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);
void print_disclaimer()
{
	std::cout << RED "*Stack is displayed as FIFO, not LIFO*\n" RESET;
}

template <typename T>
void print_stack(T &stack, std::string str)
{
	// Print as FIFO, rather than LIFO
	T tmp_stack;

	if (!str.empty())
		std::cout << str;
	while (!stack.empty())
	{
		tmp_stack.push(stack.top());
		stack.pop();
	}
	while (!tmp_stack.empty())
	{
		std::cout << tmp_stack.top() << ' ';
		stack.push(tmp_stack.top());
		tmp_stack.pop();
	}
	std::cout << std::endl;
}

template <typename T>
void comparison_operator(const T &lhs, const T &rhs, std::string cont1, std::string cont2)
{
	std::cout << std::boolalpha << '\n';
	std::cout << cont1 << " == " << cont2 << "\t?\t: " << (lhs == rhs) << '\n';
	std::cout << cont1 << " != " << cont2 << "\t?\t: " << (lhs != rhs) << '\n';
	std::cout << cont1 << " < " << cont2 << "\t?\t: " << (lhs < rhs) << '\n';
	std::cout << cont1 << " <= " << cont2 << "\t?\t: " << (lhs <= rhs) << '\n';
	std::cout << cont1 << " > " << cont2 << "\t?\t: " << (lhs > rhs) << '\n';
	std::cout << cont1 << " >= " << cont2 << "\t?\t: " << (lhs >= rhs) << '\n';
	std::cout << std::noboolalpha;
}

void stack_int()
{
	print_title("Stack");
	print_disclaimer();

	ft::stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	print_stack(stack, "Stack: ");

	// Member Functions
	{
		print_subtitle("Member Functions");

		stack.push(-1);
		print_stack(stack, "stack.push(-1)\t\t\t\t: ");
		stack.pop();
		print_stack(stack, "stack.pop()\t\t\t\t: ");
		std::cout << "stack.back()\t\t\t\t: " << stack.top() << '\n';
		std::cout << "stack.size()\t\t\t\t: " << stack.size() << '\n';
		std::cout << std::boolalpha;
		std::cout << "stack.empty() ?\t\t\t\t: " << stack.empty() << '\n';
		while (!stack.empty())
			stack.pop();
		std::cout << "*pop until empty*, stack.empty() ?\t: " << stack.empty() << '\n';
		std::cout << std::noboolalpha;
	}

	// Non-member Functions
	{
		print_subtitle("Non-member Functions");
		print_disclaimer();

		ft::stack<int> stack2;
		ft::stack<int> stack3;
		ft::stack<int> stack4;
		ft::stack<int> stack5;

		stack.push(10);
		stack.push(20);
		stack.push(30);
		stack.push(40);
		stack.push(50);

		stack2 = stack;

		stack3.push(10);
		stack3.push(19); // SMALLER
		stack3.push(30);
		stack3.push(40);
		stack3.push(60); // larger

		stack4.push(10);
		stack4.push(21); // LARGER
		stack4.push(30);
		stack4.push(40);
		stack4.push(40); // smaller

		stack5.push(0);
		stack5.push(0);
		stack5.push(0);
		stack5.push(0);
		stack5.push(0);
		stack5.push(0); // extra (LARGER)

		print_stack(stack, "Stack1: ");
		print_stack(stack2, "Stack2: ");
		print_stack(stack3, "Stack3: ");
		print_stack(stack4, "Stack4: ");
		print_stack(stack5, "Stack5: ");

		comparison_operator(stack, stack2, "Stk1", "Stk2");
		comparison_operator(stack, stack3, "Stk1", "Stk3");
		comparison_operator(stack, stack4, "Stk1", "Stk4");
		comparison_operator(stack, stack5, "Stk1", "Stk5");
	}
	std::cout << std::endl;
}

void stack_other_types()
{
	print_title("Other data structures (simple test)");
	print_disclaimer();

	// Other container types
	{
		print_subtitle("Underlying STL containers");

		ft::stack<int, std::deque<int>> stack_deque;
		ft::stack<int, std::vector<int>> stack_vec;
		ft::stack<int, std::list<int>> stack_list;

		stack_deque.push(-10000000);
		stack_deque.push(-20000000);
		stack_deque.push(-30000000);
		print_stack(stack_deque, "stack<int, std::deque<int>>\t\t: ");

		stack_vec.push(10000000);
		stack_vec.push(20000000);
		stack_vec.push(30000000);
		print_stack(stack_vec, "stack<int, std::vector<int>>\t\t: ");

		stack_list.push(std::numeric_limits<int>::min());
		stack_list.push(0);
		stack_list.push(std::numeric_limits<int>::max());
		print_stack(stack_list, "stack<int, std::list<int>>\t\t: ");
		std::cout << std::endl;
	}

	// Other data types
	{
		print_subtitle("Diff data types");

		ft::stack<char> stack_char;
		ft::stack<float> stack_float;
		ft::stack<bool> stack_bool;
		ft::stack<std::string> stack_str;

		stack_char.push('a');
		stack_char.push(0);
		stack_char.push(68);
		print_stack(stack_char, "stack<char>\t\t\t\t: ");

		stack_float.push(42.42f);
		stack_float.push(std::numeric_limits<float>::max());
		stack_float.push(std::numeric_limits<float>::infinity());
		print_stack(stack_float, "stack<float>\t\t\t\t: ");

		stack_bool.push(true);
		stack_bool.push(0);
		stack_bool.push('a');
		print_stack(stack_bool, "stack<bool>\t\t\t\t: ");

		stack_str.push("stringszzz");
		stack_str.push("1234567890");
		stack_str.push("~!@#$%^&*()_+=-}{][:/,.");
		print_stack(stack_str, "stack<std::string>\t\t\t: ");
	}
}

int main()
{
	stack_int();
	stack_other_types();
	// system("leaks test_stack");
}
