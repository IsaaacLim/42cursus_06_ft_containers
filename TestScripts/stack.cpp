#include <iostream>
#include <deque>

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
	std::cout << RED "*List array is displayed as LIFO*\n\n" RESET;
}

template <typename T>
void print_list(T lst, std::string str)
{
	if (!str.empty())
		std::cout << str;
	while (!lst.empty())
	{
		std::cout << lst.top() << ' ';
		lst.pop();
	}
	std::cout << std::endl;
}

void my_list(void)
{
	print_title("My List");
	print_disclaimer();

	ft::MyList<int> lst;

	lst.push(10);
	lst.push(20);
	lst.push(30);
	lst.push(40);
	lst.push(50);

	print_list(lst, "List: ");

	// Member Functions
	{
		print_subtitle("Member Functions");
		int n;

		lst.push(-1);
		print_list(lst, "lst.push(-1)\t\t\t\t: ");
		lst.pop();
		print_list(lst, "lst.pop()\t\t\t\t: ");
		n = lst.top();
		std::cout << "lst.top()\t\t\t\t: " << n << '\n';
		n = (int)lst.size();
		std::cout << "lst.size()\t\t\t\t: " << n << '\n';
		std::cout << std::boolalpha;
		std::cout << "lst.empty() ?\t\t\t\t: " << lst.empty() << '\n';
		while (!lst.empty())
			lst.pop();
		std::cout << "*pop until empty*, lst.empty() ?\t: " << lst.empty() << '\n';
		std::cout << std::noboolalpha;
	}
}

void stack_int()
{
	print_title("Stack");
	print_disclaimer();

	// ft::stack<int, std::deque<int>> stack;
	ft::stack<int> stack;
}

int main()
{
	// my_list();
	stack_int();
}
