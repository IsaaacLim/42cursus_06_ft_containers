#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <limits.h>
#include "vector.hpp"

#define RED "\033[3;31m"
#define RESET "\033[0m"

#if 0 // CREATE A REAL STL EXAMPLE
#include <stack>
namespace ft = std;
#else
#include "stack.hpp"
#include "MyList.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);
void print_disclaimer()
{
	std::cout << RED "*List array is displayed as LIFO*\n" RESET;
}

template <typename T>
void print_list(T lst, std::string str)
{
	if (!str.empty())
		std::cout << str;
	while (!lst.empty())
	{
		std::cout << lst.back() << ' ';
		lst.pop_back();
	}
	std::cout << std::endl;
}

template <typename T>
void print_stack(T stack, std::string str)
{
	if (!str.empty())
		std::cout << str;
	while (!stack.empty())
	{
		std::cout << stack.top() << ' ';
		stack.pop();
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

void my_list(void)
{
	print_title("My List");
	print_disclaimer();

	ft::MyList<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	print_list(lst, "List: ");

	// Member Functions
	{
		print_subtitle("Member Functions");

		lst.push_back(-1);
		print_list(lst, "lst.push_back(-1)\t\t\t: ");
		lst.pop_back();
		print_list(lst, "lst.pop_back()\t\t\t\t: ");
		std::cout << "lst.back()\t\t\t\t: " << lst.back() << '\n';
		std::cout << "lst.size()\t\t\t\t: " << lst.size() << '\n';
		std::cout << std::boolalpha;
		std::cout << "lst.empty() ?\t\t\t\t: " << lst.empty() << '\n';
		while (!lst.empty())
			lst.pop_back();
		std::cout << "*pop_back until empty*, lst.empty() ?\t: " << lst.empty() << '\n';
		std::cout << std::noboolalpha;
	}
	// Non-member Functions
	{
		print_subtitle("Non-member Functions");
		print_disclaimer();

		ft::MyList<int> lst2;
		ft::MyList<int> lst3;
		ft::MyList<int> lst4;
		ft::MyList<int> lst5;

		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);

		lst2 = lst;

		lst3.push_back(10);
		lst3.push_back(19); // smaller
		lst3.push_back(30);
		lst3.push_back(40);
		lst3.push_back(60); // larger

		lst4.push_back(10);
		lst4.push_back(21); // larger
		lst4.push_back(30);
		lst4.push_back(40);
		lst4.push_back(40); // smaller

		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0); //extra

		print_list(lst, "List1: ");
		print_list(lst2, "List2: ");
		print_list(lst3, "List3: ");
		print_list(lst4, "List4: ");
		print_list(lst5, "List5: ");

		comparison_operator(lst, lst2, "List1", "List2");
		comparison_operator(lst, lst3, "List1", "List3");
		comparison_operator(lst, lst4, "List1", "List4");
		comparison_operator(lst, lst5, "List1", "List5");
	}
	std::cout << std::endl;
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
	std::cout << std::endl;
}

void stack_other_types()
{
	print_title("Stack, other data types (simple test)");
	print_disclaimer();

	// stack<int, std::container<int>>
	{
		print_subtitle("Stack with diff containers");

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

		stack_list.push(INT_MIN);
		stack_list.push(0);
		stack_list.push(INT_MAX);
		print_stack(stack_list, "stack<int, std::list<int>>\t\t: ");
		std::cout << std::endl;
	}

	// // stack<int, ft::vector<int>>
	// {
	// 	print_subtitle("stack<int, ft::vector<int>>");
	// 	ft::stack<int, ft::vector<int>> stack;

	// 	stack.push(INT_MIN);
	// 	stack.push(0);
	// 	stack.push(INT_MAX);
	// 	print_stack(stack, "");
	// 	std::cout << std::endl;
	// }
}

int main()
{
	my_list();
	// stack_int();
	// stack_other_types();
}
